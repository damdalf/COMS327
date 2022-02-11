# **COMS 327: Week One - Day Two | 1/20/22 |**
## **Notes:**
* Sentinel value
    * A sentinel is a dummy value, used to distinguish between values that are supposed to be there (e.g. user input) and control values (values that need to be handled specially).
* There is no bounds checking in C, as this makes array-access take twice as long. 
    * Remember, in C, the programmer is right - no need to check bounds then, right?
* Flags to always be used when creating a Make file:
    * -Wall
        * Catches and displays all warnings.
    * -Werror
        * Treats warnings like errors, best for nontrivial programs. Philosophically, writing code that generates errors is sloppy. Additionally, when working in C you cannot count on the C compiler to protect you from your mistakes like you can with many modern programming languages.
* Helpful Commands in Linux / UNIX-based operating systems:
    * man 'command'
        * Displays the manual / documentation for the given command. Press 'Q' to close the manual.
    * pwd
        * Displays the current working path.
    * ls
        * Lists the directory.
    * cd 'path'
        * Moves to the specified directory.
    * cd
        * Moves to your home directory.
    * cd -
        * Moves to the previous directory.
    * cp 'fileName'
        * Copies the specified file.
    * mv 'fileOne' 'fileTwo'
        * Moves file one to the same directory as file two.
    * mv 'fileOne' 'path'
        * Moves file one to the specified directory.
    * cat 'fileOne'
        * Concatenate files together, but if used on a single file then the contents of the file are displayed in the terminal.
    * less 'fileName'
        * Allows you to page a file, and scroll up and down. Press 'Q' to quit.
            * Can then use '/' to search for specific text.
    * |
        * Piping. Pipe is used to combine two or more commands, and in this, the output of one command acts as input to another command.
    * ..
        * Means the directory above the current one.
---
## **Code:**
```C
#include <stdio.h>
#define DIM 12
// functions should be declared above main, or you should provide a function prototype
int fib(unsigned i);
void gen_times_table(int table[DIM][DIM])
{
    for (j = 0; j < DIM; j++){
        for (i = 0; i < DIM; i++){
            table[j][i] = (i + 1) * (j + 1);
        }
    }
}
int main(int argc, char *argv[])
{
    int table[DIM][DIM];
    int j, i;
    gen_times_table(table);
    for (j = 0; j < DIM; j++){
        for (i = 0; i < DIM; i++){
            printf("%3d ", table[j][i])
        }
        print("\n");
    }
    for (i = 0; i < 25; i++){
        printf("%d: %d\n", i, fib(i));
    }
    return 0;
}
// really bad example of a recursive function in C
int fib(unsigned i)
{
    if (i < 2){
        return i;
    }
    return (fib(i - 1) + fib(i - 2));
}
```
---
## **Compiling:**
* gcc -E fileName.c
    * Stops the compiling after pre-processing. Lines written in C that begin with '#' are pre-processor commands.
* gcc -S fileName.c
    * Stops compiling after the compiling stage. Our code is now translated to GNU assembly code.
        * Creates fileName.s
* gcc -c fileName.c
    * Stops compiling after the assembly stage. Our code is now translated from GNU assembly code to machine code.
        * Creates fileName.o
* gcc fileName.c
    * Stops compiling after linking the passed file to a C executable.
---
## **Why You Should Learn C, and its History:**
* C, even after 50 years, still remains one of the top three most popular programming languages: jobs aren't going anywhere.
* Almost all systems programming is done in C.
* Thompson and UNIX
    * Finished first UNIX 1969, but wanted a new language. Started with BCPL, modified it, and named it B. Around this time, there were no formal compilers. Teams of programmers had to create their own from the ground up.
    * Ritchie joined the project, added types, flow control structures, records, and some other things. The result was a new language called C. 
    * C was then used to rewrite UNIX.
* Philosophy
    * No feature should impact the performance of programs that don't use it, because systems were weak (and they still are).
    * Easy to compile, because we want to understand our code fully and compiler technology was in its infancy.
    * Programmer is right, and the compiler will not second guess! However, this leads to security issues.
---
## **Things You Need to Know for the First Assignment:**
* Functions.
* Arrays.
* Printing.
* Compiling.
* Make files.
* DO NOT need to know how to handle memory allocation yet.