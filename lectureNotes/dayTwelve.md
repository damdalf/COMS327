# **COM S 327 - DAY TWELVE: CODING WITH GENERICS, AND SOME MORE: | 02/24/2022 |**

## **NOTES:**
* Practice exam will be uploaded later today, which will be gone over in class on next Thursday.
* ```type const *p```
    * Means that we cannot change this pointer.

---

* Making a Generic Insertion Sort

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void insertion_sort(int *a, int n)
{
    int i, j, t;

    for (i = 1; i < n; i++)
    {
        for (t = a[i], j = i - 1; j > -1 && a[j] > t; j--)
        {
            a[j + 1] = a[j];
        }
        a[j + 1] = t;
    }
}

// Void pointers can point to anything, but they cannot be dereferenced.
//  * a - the array of generic items
//  * n - the number of items
//  * s - the size of an individual item
//  * compare - a comparator function
//      the parentheses are required because type casting is read right first, and then left.
//      Since there is a closing parentheses, we read left. So we see that compare is a pointer,
//      now we read right. So compare is a pointer that takes two arguments. Now, we read left.
//      Compare is a pointer that takes two arguments and returns an int. Removing the parentheses
//      would change this.
void generic_insertion_sort(void *a, int n, int s,
                            int (*compare)(void *v1, void *v2))
{
    int i, j;
    void *t;
    // Why character pointer? Character pointers are of 1 byte, which will allow us to index through this array of 'generics'.
    char *p = a;

    t = malloc(s);

    for (i = 1; i < n; i++)
    {
        for (memcpy(t, p + i * s, s), j = i - 1; j > -1 && compare(p + j * s, t) > 0; j--)x
        {
            memcpy(p + (j + 1) * s, p + j * s, s);
        }
        memcpy(p + (j + 1) * s, t, s);
    }

    free(t);
}

int int_reverse_cmp(void *v1, void *v2)
{
    return *((int *) v2) - *((int *) v1);
}

int char_cmp(const void *v1, const void *v2)
{
    return *((char *) v1) - *((char *) v2);
}

// This one is goofy. I need to ask about this during office hours or after the next lecture that I attend.
int str_cmp(const void *v1, const void *v2)
{
    return strcmp(*(char **) v1, *(char **) v2);
}

int main (int argc, char *argv[])
{
    int i;

    int a[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

    char s[] = "Welcome to COM S 327!";

    char *s_array[] = {"zero",
                "one",
                "two",
                "three",
                "four",
                "five",
                "six",
                "seven",
                "eight",
                "nine"};

    insertion_sort(sizeof (a) / sizeof (a[0]));

    generic_insertion_sort(a, 10, sizeof (a[0], int_reverse_cmp));

    for (i = 0; i < sizeof (a) / sizeof (a[0]); i++)
    {
        printf("%d," a[i]);
    }

    printf("\n");

    generic_insertion_sort(s, strlen(s), 1, char_cmp));

    for (i = 0; i < sizeof (a) / sizeof (a[0]); i++)
    {
        printf("%s\n," a[i]);
    }

    generic_insertion_sort(s, 10, sizeof(s_array[0]), str_cmp);

    for (i = 0; i < 10; i++)
    {
        printf("%s ", s_array[i]);
    }
    printf("\n");

    return 0;
}
```

* Working With the Preprocessor in C:
    * ```gcc -E```
        * Run CPP.
        * ```gcc -E fileName.h | less``` 

```c
#include <stdio.h>

// This symbol MAX_VAL has a value of 10.
// You cannot access the memory address of a value-type macro, because they become literally replaced with their defined value.

#define MAX_VAL 10 // Value-type macro.

#define MAX(x, y) x > y ? x : y // Function-type macro.

// Can escape being stuck to a single-line by avoiding the new-line character, by using a '\'.
// Basic blocks {} always take on the value of the final statement.
// Can treats 'blocks' as a single multi-line statement by wrapping the block in ().
#define MIN(x, y) ({ \
    typeof (x) _x = x; \ // Define a new variable with the type of x.
    typeof (y) _y = y; \ // Define a new variable with the type of y.
    _x < _y ? _x : _y; \
})


// One cool thing about function macros is that there are no type restrictions; magically / inherently allows us to use generics.
// NOTE: Macro names cannot be resued for ANYTHING.

int main(int argc, char *argv[])
{
    // Will print 10.
    printf("%d\n, MAX_VAL");
    // Will print 9.
    printf("%d\n", MAX(5, 9));
    // Will print 3.142.
    printf("%f\n", MAX(1.414, 3.142));
}
```