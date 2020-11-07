#!/usr/bin/env python
# -*- coding: latin-1 -*-

# Mix two mono files to get a stereo file

import sys, wave, struct

def mix_files(a, b, c, chann = 2, phase = -1.):
	f1 = wave.open(a,'r')
	f2 = wave.open(b,'r')
	f3 = wave.open(c,'w')
	f3.setnchannels(chann)
	f3.setsampwidth(2)
	f3.setframerate(44100)
	f3.setcomptype('NONE','Not Compressed')
	frames = min(f1.getnframes(), f2.getnframes())

	print "Mixing files, total length %.2f s..." % (frames / 44100.)
	d1 = f1.readframes(frames)
	d2 = f2.readframes(frames)
	for n in range(frames):
		if not n%(5*44100): print n // 44100, 's'
		if chann < 2:
			d3 = struct.pack('h',
				.5 * (struct.unpack('h', d1[2*n:2*n+2])[0] +
				struct.unpack('h', d2[2*n:2*n+2])[0]))
		else:
			d3 = ( struct.pack('h',
				phase * .3 * struct.unpack('h', d1[2*n:2*n+2])[0] +
				.7 * struct.unpack('h', d2[2*n:2*n+2])[0]) +
				struct.pack('h',
				.7 * struct.unpack('h', d1[2*n:2*n+2])[0] +
				phase * .3 * struct.unpack('h', d2[2*n:2*n+2])[0]) )
		f3.writeframesraw(d3)
	f3.close()

if __name__ == '__main__':
	if len(sys.argv) == 4:
		a, b, c = sys.argv[1:]
		print "Mixing %s and %s, output will be %s" % (a, b, c)
		mix_files(a, b, c)

