class PlaysoundException(Exception):
    pass

def _playsoundWin(sound, block = True):
    '''
    Utilizes windll.winmm. Tested and known to work with MP3 and WAVE on
    Windows 7 with Python 2.7. Probably works with more file formats.
    Probably works on Windows XP thru Windows 10. Probably works with all
    versions of Python.

    Inspired by (but not copied from) Michael Gundlach <gundlach@gmail.com>'s mp3play:
    https://github.com/michaelgundlach/mp3play

    I never would have tried using windll.winmm without seeing his code.
    '''
    from ctypes import c_buffer, windll
    from random import random
    from time   import sleep

    def winCommand(*command):
        buf = c_buffer(255)
        command = ' '.join(command).encode()
        errorCode = int(windll.winmm.mciSendStringA(command, buf, 254, 0))
        if errorCode:
            errorBuffer = c_buffer(255)
            windll.winmm.mciGetErrorStringA(errorCode, errorBuffer, 254)
            exceptionMessage = ('\n    Error ' + str(errorCode) + ' for command:'
                                '\n        ' + command +
                                '\n    ' + errorBuffer.value)
            raise PlaysoundException(exceptionMessage)
        return buf.value

    alias = 'playsound_' + str(random())
    winCommand('open "' + sound + '" alias', alias)
    winCommand('set', alias, 'time format milliseconds')
    durationInMS = winCommand('status', alias, 'length')
    winCommand('play', alias, 'from 0 to', durationInMS)

    if block:
        sleep(float(durationInMS) / 1000.0)

def _playsoundOSX(sound, block = True):
    '''
    Utilizes AppKit.NSSound. Tested and known to work with MP3 and WAVE on
    OS X 10.11 with Python 2.7. Probably works with anything QuickTime supports.
    Probably works on OS X 10.5 and newer. Probably works with all versions of
    Python.

    Inspired by (but not copied from) Aaron's Stack Overflow answer here:
    http://stackoverflow.com/a/34568298/901641

    I never would have tried using AppKit.NSSound without seeing his code.
    '''
    from AppKit     import NSSound
    from Foundation import NSURL
    from time       import sleep

    if '://' not in sound:
        if not sound.startswith('/'):
            from os import getcwd
            sound = getcwd() + '/' + sound
        sound = 'file://' + sound
    url   = NSURL.URLWithString_(sound)
    sound = NSSound.alloc().initWithContentsOfURL_byReference_(url, True)
    sound.play()

    if block:
        sleep(sound.duration())

def _playsoundNix(sound, block = True):
    '''
    Utilizes ossaudiodev. Untested. Probably works with all version of Linux
    with Python 2.3 or newer.

    Inspired by, and more or less copied from, Bill Dandreta's post on
    this mailing list (since deleted, so I link to a web archive instead):
    https://web.archive.org/web/20080218155209/http://mail.python.org/pipermail/python-list/2004-October/288905.html
    '''
    import ossaudiodev
    from sys  import byteorder
    from wave import open as waveOpen, AFMT_S16_LE, AFMT_S16_BE
    
    with waveOpen(sound, 'rb') as sound:
        channelCount, sampleWidth, framerate, frameCount, compressionType, compressionName = sound.getparams()
        try:
            from ossaudiodev import AFMT_S16_NE
        except ImportError:
            if 'little' in byteorder.lower():
                AFMT_S16_NE = ossaudiodev.AFMT_S16_LE
            else:
                AFMT_S16_NE = ossaudiodev.AFMT_S16_BE
        data = sound.readframes(frameCount)

    speaker = ossaudiodev.open('/dev/dsp', 'w')
    speaker.setparameters(AFMT_S16_NE, channelCount, framerate)
    speaker.write(data)
    speaker.close()

from platform import system
system = system()

if system == 'Windows':
    playsound = _playsoundWin
elif system == 'Darwin':
    playsound = _playsoundOSX
else:
    playsound = _playsoundNix

del system