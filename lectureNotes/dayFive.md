# **COM S 327: DAY FIVE - | 2/1/22 |**

## **MEMORY ALLOCATION:**
* Memory addresses in C are 8 characters long.
* char a [50] - String of char's that stores 50 bytes.
    * ```a``` itself is a pointer. The name of an array is always a pointer to itself.
* char m [3][3]
    * a 2D array has its memory allocated a bit differently:
    ``` 
    0 1 2
    3 4 5
    6 7 8
    ```
* ```char m [y][x]```
    * ```&m[q][p] == m + qx + p```
    * ```m[q][p] == *(m + qx + p)```
* The compiler always calculates the amount of bytes that is needed for the referenced object when doing pointer arithmetic, so there is never a need to manually multiply the amount you are moving when you are working with the memory address of a variable.
    * UNLESS the data holds several different kinds of variables, then you should use a char array as it will always have a single byte per variable (makes manipulation easier to keep track of).
* ```char m3d[z][y][x]```
    * ```m3d[r][q][p] == m3d + (ryx + qx + p)```
* ```malloc(sizeof(dataType))```
    * Parameter: the number of bytes to be allocated.
        * Rather than remembering the byte sizes, use sizeof().
    * Found in ```<stdlib.h>```.
    * **sizeof() is a compile time operator. It cannot tell you how big a dynamically-allocated variable is; only static information. THIS IS IMPORTANT.**
* ```int p;```
    * ```p = malloc(sizeof (*p));```
    * Even better than using the dataType inside of sizeof(), as the memory will continue to be allocatec correctly in the situation of the type of p being changed somewhere in your program.
    * ```*p = 5;```
# **FREEING UP ALLOCATED MEMORY:**
* C, as un managed language, does not have a garbage collector, so we must manually reclaim our memory. 
* ```free(p);```
    * Since ```free()``` does not automatically check if the memory address that you pass into it was ever actually allocated in memory. Thus, only ```free()``` things that have previously been returned by ```malloc()```.
    * Never continuously free a memory address more than once, as this will corrupt the memory of the program and cause issues.
    * Do not use pointers after they have been freed.
* For every constructor, one also needs a destructor.
* In C, the best way to validate code is using return values.
* There are no implicit parameters in C since it is not OOP. Everything must be explicit.

---

# **MAKING A STACK IN C:**
* Stacks are FILO.
    * First-in, last-out.
```C
#ifndef STACK_H
#define STACK_H

typedef struct stack_node stack_node_t;

struct stack_node
{
    int value;
    stack_node_t *prev;
};
typedef struct stack
{
    stack_node_t *top;
    int size;
}
    stack_t;

int stack_init(stack_t *s);
int stack_delete(stack_t *s);
stack_peek(stack_t *s);
int stack_push(stack_t *s, int v);
int stack_pop(stack_t *s);
int stack_size(stack_t *s);

#endif
```

```C
#include <stdlib.h>

#include "stack.h"

stack_t s;

stack_init(&s);

int stack_init(stack_t *s)
{
    s->top = NULL; // (void *) 0
    s->size = 0;

    return 0;
}

int stack_delete(stack_t *s)
{
    return 0;
}

int stack_peek(stack_t *s)
{
    return 0;
}

int stack_push(stack_t *s, int v)
{
    stack_node_t *n = malloc(sizeof (*n));

    n->value = v;
    n_prev = s->top;

    s->top = n;

    s->size++;

    return 0;
}

int stack_pop(stack_t *s)
{
    return 0;
}

int stack_size(stack_t *s)
{
    return 0;
}
```