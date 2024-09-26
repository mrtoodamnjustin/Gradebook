#  Student Gradebook

Welcome to my OOP C++ implementation of a command line student gradebook!

## Purpose

This project was created entirely by me in order to practice object oriented programming in C++. I also used this as an opportunity to learn more about using makefiles and git.

## Building

If you have make installed, you can simply run the make command. This requires an installation of g++ that has it put into path.

> This makefile was created with the intention to be used on Windows. If you are building on a UNIX operating system, some refactoring will be necessary.

```
make
```

If you only have g++, you can run the following to succesfully build the program.

```
mkdir build
g++ -I include src/course.cpp src/gradebook.cpp src/main.cpp src/student.cpp -o build/Gradebook.exe
```