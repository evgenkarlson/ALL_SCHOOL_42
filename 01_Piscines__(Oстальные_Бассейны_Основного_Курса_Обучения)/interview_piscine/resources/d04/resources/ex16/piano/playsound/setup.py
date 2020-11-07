from codecs     import open
from inspect    import getsource
from os.path    import abspath, dirname, join
from setuptools import setup

here = abspath(dirname(getsource(lambda:0)))

with open(join(here, 'README.rst'), encoding='utf-8') as f:
    long_description = f.read()

setup(name             = 'playsound',
      version          = '1.2.1',
      description      = long_description.splitlines()[2][1:-1],
      long_description = long_description,
      url              = 'https://github.com/TaylorSMarks/playsound',
      author           = 'Taylor Marks',
      author_email     = 'taylor@marksfam.com',
      license          = 'MIT',
      classifiers      = ['Development Status :: 5 - Production/Stable',
                          'Intended Audience :: Developers',
                          'License :: OSI Approved :: MIT License',
                          'Operating System :: OS Independent',
                          'Programming Language :: Python :: 2',
                          'Programming Language :: Python :: 2.3',
                          'Programming Language :: Python :: 2.4',
                          'Programming Language :: Python :: 2.5',
                          'Programming Language :: Python :: 2.6',
                          'Programming Language :: Python :: 2.7',
                          'Programming Language :: Python :: 3',
                          'Programming Language :: Python :: 3.1',
                          'Programming Language :: Python :: 3.2',
                          'Programming Language :: Python :: 3.3',
                          'Programming Language :: Python :: 3.4',
                          'Programming Language :: Python :: 3.5',
                          'Topic :: Multimedia :: Sound/Audio :: MIDI',
                          'Topic :: Multimedia :: Sound/Audio :: Players',
                          'Topic :: Multimedia :: Sound/Audio :: Players :: MP3'],
      keywords         = 'sound playsound music wave wav mp3 media song play audio',
      py_modules       = ['playsound'])