#!/usr/bin/env python

from distutils.core import setup

setup(name="PySynth",
        version="1.1",
        description="A simple music synthesizer for Python",
        author="Martin C. Doege",
        author_email="mdoege@compuserve.com",
	url="http://home.arcor.de/mdoege/pysynth/",
        py_modules=["pysynth", "pysynth_b", "pysynth_s", "pysynth_e", "pysynth_beeper","play_wav"],
	scripts=["read_abc.py", "nokiacomposer2wav.py", "test_nokiacomposer2wav.py", "menv.py", "mixfiles.py"],
)
