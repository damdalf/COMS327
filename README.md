# **COMS 327: Day One | Welcome to Procedural Programming - 1/18/22**

* No assigned readings, but two books.
    * C Programming - 1971.
        * GREAT book.
    * C++ Programming.
        * Good book.
* MUD - Multi User Dungeon - old text-based adventure game.
    * Written in C.
* The purpose of the class is to learn an unmanaged language. 
    * Unmanaged - does not manage memory for you.
* Rogue-like game - turn-based top-down adventure game, usually text-based graphics.
    * However, we will be doing a Pokemon style game this semester.
    * We will be simplifying some of the mechanics as Pokemon games are pretty mechanic-heavy, which can be tedious.
    * Will be provided a database consisting of all of the Pokemon but we will have to parse the database.
    * After each deadline for the weekly projects the professor will drop his solution to the project, to ensure that you are able to continue if you encounter bugs.
        * Meant to help with bugs that will arise when creating a project while learning the language you are using to write the project.
        * Also helps with the skill of working with other people's code.
    * If you find a bug in the professor's code and are able to fix it, you will recieve a letter-grade bump in your final grade.
        * Find bug, demonstrate how to find the bug, fix the bug, and post it to Piazza.
    * To connect to the Pyrite server:
        * ssh djamdahl@pyrite.cs.iastate.edu
    * IDE:
        * Emacs
    * Other software
        * GCC
        * Valgrind
        * GNU Make
---
    
## **Course Objectives:**
* Understand differences between managed and unmanaged programming languages.
* Understand and be capable of using simple build systems (Make).
* Be able to design and build large programs from specifications.
* Be able to use third-party libraries in programs.
* Be able to read, write, and modify C programs.
* Understand memory-management techniques for C.
* Be able to read, write, and modify C++ programs.
* Understand memory-management techniques for C++.
* Understand C++ templates and the standard template library.
---

## **First Assignment Information and Some Basic C Information:**
* Knight's Tour
    * Recursive backtracking
    * Own solution
```C
#include <stdio.h>

int main(int argc, char *argv[])
{
    printf("Hello World!\n");

    return 0;
}
```
* argc - argument count, the number of arguments given to main.
* char *argv[] - array of char characters,  a string.
    * The "*" means that these are pointers.
    * The first argument is the name of the program, so argc is always AT LEAST equal to one.
* main returns a int, 0, to tell the computer that the program has completed successfully.
* To compile / run from the terminal:
    * gcc fileName.c -o fileName
        * Compiles the file.
    * ./fileName
        * Runs the file.
        * The files saved with a "~" at the end of the extension are just backups of the files that are automatically saved.
* To print warnings:
    * gcc -Wall fileName.c -o fileName
* Working left-to-right is always faster than working from top-to-bottom as it performs better in the processor's cache.
    * C and C++ are all about making the most efficient programs.
```c
#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc == 2){
        printf("Hello %s!\n", argv[1]);
    } else {
        printf("Hello World!");
    }

    int table[10][10];
    int j, i;
    for(j = 0; j < 10; j++){
        for(i = 0; i < 10; i++){
            table[j][i] = (i + 1) * (j + 1);
        }
    }

    for(j = 0; j < 10; j++){
        for(i = 0; i < 10; i++){
            printf("%3d ", table[j][i]);
        }
        printf("\n");
    }

    return 0;
}
```
---
