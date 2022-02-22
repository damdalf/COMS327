# **COM S 327 - DAY ELEVEN: | 02/22/2022 |**

## **NOTES:**
* For assignment 1.04, we will need to use a priority queue where we add each type of character and their turn times, and then pulling out the top item in the priority queue and updating the map accordingly. 
    * To ensure that there is some ordering for when characters share a turn time, simply add a secondary comparing sequence where if turn times are equal, then compare the 'sequence number' of the two characters.
* To keep track of the terrain type that was present prior to a character being on said terrain block, create a data structure for characters, and create a map-sized array of 'character_t pointers'. When it comes to printing the map, simply add a check for all map indices to see where the characters are present.
* Add movement for the two NPC's, and randomly teleport the PC somewhere in the map whenever the NPC's get next to the PC. Then, generate new distance maps for this new position of the PC.

* **C WILL BE FINISHED NEXT WEEK, AND A WEEKEND EXAM NEXT WEEKEND.**
    * **OPEN BOOK OPEN NOTES, TWO HOURS LONG. SEVERAL DAYS TO BEGIN IT.**
    * **PRACTICE EXAM BEFORE THE END OF THIS WEEK, NEXT THURSDAY WOULD BE SPENT REVIEWING.**

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
    // Why character pointer? Character pointers are of 1 byte, which will allow us to index through this array of chars.
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

int char_cmp(void *v1, void *v2)
{
    return *((char *) v1) - *((char *) v2);
}

int main (int argc, char *argv[])
{
    int i;

    int a[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};

    char s[] = "Welcome to COM S 327!";

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

    return 0;
}
```