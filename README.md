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

Running the program
===================

There are two programs: `main` and `gui`.
Both versions accepts multiple databases as input,
so you must specify which database are you using.
Both programs accept other command-line arguments as input;
you can discover which using the option `--help`.

`main` is not-so-user-friendly command-line version of the program.
To run it with the acompanying database, `ine.db`,
navigate to the repository's root directory and type

    ./main ine.db

`gui` is an incomplete graphical user interface.
Altough is more user-friendly, it has no options for
adding new entities to the database nor for adding new questions.
You can run it via

    ./gui ine.db

The default database for the GUI is `ine.db`, which refers to
the disciplines of the Computer Science course at UFSC,
so, altough the prompt are in english,
the questions are in portuguese...

Font License
============

The repository includes the font `Lato-Regular.ttf`,
downloaded from [here](http://www.latofonts.com/)
and distributed under the
[OFL](http://scripts.sil.org/cms/scripts/page.php?item_id=OFL_web).
