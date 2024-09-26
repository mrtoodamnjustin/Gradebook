#  Student Gradebook

Welcome to my object-oriented C++ implementation of a command line student gradebook!

## Overview

This project was created entirely by me in order to practice object oriented programming in C++. I also used this as an opportunity to learn more about using makefiles and git.

Note that not all algorithms in this project might be the most optimal solution, as I am merely a first semester college student looking to practice object-oriented programming. **That being said I am always open to constructive criticism!**

## Building

If you have make installed, you can simply run the make command. This requires an installation of g++ that is avaialable in the command line.

> This makefile was created with the intention of being ran on Windows. If you are building on a UNIX-like operating system, some refactoring might be necessary.

```
make
```

If you only have g++, you can run the following to succesfully build the program.

```
mkdir build
g++ -I include src/course.cpp src/gradebook.cpp src/main.cpp src/student.cpp -o build/Gradebook.exe
```