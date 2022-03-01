# COM S 327 - DAY THIRTEEN: FINISHING UP C | 03/01/2022 |

## **GENERAL NOTES:**
* Assignment 1.05 will be over two weeks due to Spring Break.
* Assignment 1.06 will be over two weeks.
* Average score on exams is between 60% - 70%.
* Assignment 1.04 has been extended one week.
* Section 2 of the manual page is for system calls.
* Dynamic in CS - allocated at runtime.
* Static in CS - allocated by the compiler.
* Scope and Lifetime:
    * **'auto'** - The default for variables inside of functions. Automatic variables go on the stack, and its lifetime is equal to the lifetime of the function. Rarely explicitly declared.
    * **'const'** - Declaring a variable as constant means that the variable is unable to be changed. Variables declared as constants are read-only.
    * **'extern'** - Means that the storage for the variable is created elsewhere; used to export data to other compilation units. It only makes sense to use an external declaration for variables in global scope, but usually only in header files.
    ```c
    // Inside exactly one file:
    int global_variable;

    //Inside header:
    extern int global_variable;
    ```
    * **'static'**
        * In functions, changes the variable's lifetime to be the lifetime of the program. Its scope is unaffected, because STATIC VARIABLES PERSIST.
        * On globals, prevents variables or functions from being exported from the compilation unit. This is useful for internal functions of an ADT. Think 'private'.
    * **'register'** - Doesn't affect lifetime or scope. The compiler will try to put the variable in a compiler.
    * **'volatile'** - Does not affect the lifetime or scope. Tells the compiler tha this value could change outside of the control normal program flow.
    * **'inline'** - Optimization. Does not affect lifetime or scope. Only for functions. Similar to function-type macros. Puts function body inside caller without function call.
* Reading and understanding declarations: The "right-left" rule:
    * Go right when you can, and go left when you must.


* **Lol, honestly not sure what the Hell is happening here.**
```c
typedef int(*fptr)(void);

int foo(void)
{
    return 0;
}

fptr f = foo;

f(f);

#define lu_table_entry(n) { #n, n }

typedef struct
{
    char *name;
    fptr func;
} lu_entry;

lu_entry lookup_table[] = 
{
    lu_table_entry(bar),
    lu_table_entry(baz),
    lu_table_entry(foo)
};

((lu_entry *) bsearch("foo", lookup_table, 3, sizeof(lookup_table[0]), compare_lu_names)) -> func();
```

* **Making a little brother of printf():**
```c
#include <stdio.h>
#include <stdarg.h>

// Variable-addity function, as it has a variable number of parameters

/*
* Simplified printf.
* little_printf("sdfc", string, int, float, char);
*/

void little_printf(const char *format, ...)
{
    /* 
    * Need a list of variables, often called ap as this how the manual pages do it.
    * The argument last is the name of the last parameter before the variable argument list, i.e., the last parameter of which the calling function knows the type.
    */

   va_list ap;

    char *s;
    int d;
    float f;
    char c;

    // Initialize argument pointer.
    va_start(ap, format);

    while (*format)
    {
        switch(*format)
        {
            case 's':
                s = va_arg(ap, char *);
                printf("String: %s\n", s);
                break;
            case 'd':
                d = va_arg(ap, int);
                printf("Int: %d\n", d);
                break;
            /*
            * While we've passed in a float, it is actually stored as a double because it is promoted, because the compiler doesn't know what the type will be, and promotes it based off the default promotion rules.
            * Could be avoided with a type parameter.
            * Floats become doubles, shorts and chars become ints.
            */
            case 'f':
                f = va_arg(ap, double);
                printf("Float: %f\n, f");
                break;
            /*
            * While we've passed in a char, it is actually stored as an int because it is promoted, because the compiler doesn't know what the type will be, and promotes it based off the default promotion rules.
            * Could be avoided with a type parameter.
            * Floats become doubles, shorts and chars become ints.
            */
            case 'c':
                c = va_arg(ap, int);
                printf("Char: %c\n", c);
                break;
        }
        format++;
    }
    // Signals that there are no further arguments, and causes ap to be invalidated..
    va_end(ap);
}

int main(int argc, char *argv[])
{

}
```

* **A better explanation of type promotion:**
    * Occurs anytime an operation is performed on certain data types because the compiler is stupid and lazy.
```c
    int main(int argc, char *argv[])
    {
        /*
        * At first look, the expression (a*b)/c seems to cause arithmetic overflow because signed characters can have values only from -128 to 127 (in most of the C compilers), and the value of subexpression ‘(a*b)’ is 1200 which is greater than 128. But integer promotion happens here in arithmetic done on char types and we get the appropriate result without any overflow.
        */

        char a = 30, b = 40, c = 10;
        char d = (a * b) / c;
        printf("%d\n", d);

        return 0;
    }
```