# ProTest — A free powerful program for educational tests
## Overview
**ProTest** is a revolution in a world of testing systems. Testing has become easier than ever before.
ProTest supports two interfaces: graphical UI _(powered by Qt5)_ and text UI

Make your life easier. Install it now for free _(under GPLv2 copyleft)_

## Brief usage description
### General info:
Program runs in two modes: teacher's mode and student's mode. First, you have to authorize in our system. Then, mode will be selected automatically (if you are using graphical UI).

### Teacher's mode allows you to:
* Add/Edit/Delete questions
* Show/Edit students info
  
### Student's mode allows you to:
* Pass the training
* Pass the testing on the topic
* Pass the final test
    
### Notes:
* Our system uses `SQLite` as a database system
* You can find all necessary documentation in `doc` folder
* Contact anton2920@gmail.com if any issue occurs
* Enjoy! :)

## Installation guide
### General stuff
In general, ProTest `configure` script will try to find `Qt5` _(Qt4 isn't supported)_.
Perform: 
```bash
sh ./autogen.sh
./configure
make
sudo make install
```
After that, run `ldconfig(8)`.  Do `sudo ldconfig`, there's no harm in it.

### Installaton notes
* You have ability to build **ProTest** without Qt5. For that instead of `./configure` run `./configure --without-Qt` _(see `./configure --help` for greater details)_
* `AX_HAVE_QT` `m4` macro will find your Qt5 path using `qmake` (especially `qmake --version` command). If you have your Qt5 installed in a path, that this macro aren't able to find out, remove `qmake` and add `/path/to/your/custom/qmake/and/Qt/bin` to your `$PATH` variable.
> **Note.** You can check Qt path manually by executing `qmake --version` and see its path
* Our program can be built only under systems, that have Qt5 support (if you are building with Qt5 support _[see notes above]_).
> **Warning!** It's better to have the newest version of Qt5 downloaded from [official webpage](https://www.qt.io/download "Qt5 download page"). _For example **Ubuntu 14.04** are no longer supported. Thus, **ProTest** can't be built under this system_
* If you don't want to built it from source files by yourself, you can use binaries for **RHEL-_based_**, **Debian-_based_** systems.

## Licence
It distributes only under GPLv2 licence. Go to https://www.gnu.org/licenses/ for more information

## Copyright 
© 2019 Tushino Software LLC
