GuiUnguesser - Linux Version
============================

This repository is a Linux adaptation of the
[GuiUnguesser](https://github.com/ebonywolf/ProjGaia),
a graphical user interface for the
[unguesser](https://github.com/royertiago/unguesser).
(It should really work with any POSIX-compatible operating system
with recently enough C++ compiler and GNU Makefiles.)

Building on Linux
=================

This program assumes the SFML library is installed and on the compiler seach path.
For most users, issuing

    sudo apt-get install libsfml-dev

(or the equivalent command for your favorite package manager)
should be enough.

Your compiler must also implement C++11. I tested only with `gcc 4.9.2`,
but `gcc 4.8.x` should work too.

Then, simply type

    make

The makefile will do the rest for you.
