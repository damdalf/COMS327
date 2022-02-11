# **COM S 327: DAY EIGHT - TOPIC | 2/10/22 |**

* ASSIGNMENT 1.03 WILL NEED: 
    * PRIORITY QUEUE.
    * DIJKSTRA'S ALGORITHM.
        * BOTH ARE INCLUDED WITHIN PROFESSOR SHEAFER'S SOLUTION DROPS.
            * WHEN A SHORTEST PATH IS FOUND, WILL WANT TO USE THE LATTER DECREASE KEY FUNCTION.
---

## **NOTES:**
* Void pointers can point to anything, but they CANNOT be dereferenced.
* Static variables - persist across calls of functions and scopes.
    * Belong to the file.
* Very general idea of Dijkstra's algorithm:
    * While the queue is not empty.
        * Pull out the neighbors (ALL 8 NEIGHBORS).
        * Randomly choose one of the smallest neighbors.
            * This creates a shortest path.
* pathCompare function is named (pathCmp).
* It is important to insert every position of the map into the heap.
* Two main types of NPC's that will use the cost maps.
    * Hikers:
        * Movement advantage.
    * Rivals:
        * No movement advantage.

## **WORKING WITH STRINGS:**
```c

// One implementation of strcmp.
int strcmp327_1(const char *s1, const char *s2)
{
    int i;

    for (i = 0; s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]; i++){};

    return s1[i] - s2[i];
}

// Another implementation of strcmp.
int strcmp327_2(const char *s1, const char *s2)
{
    while (*s1 && *s2 && *s1 == *s2)
    {
        s1++;
        s2++;
    }

    return *s1 - *s2;
}

int main(int argc, char *agrv[])
{
    char s[7] = "foo";
    char *t = "foo";
    char *u = "bar";

    if (s == t)
    {
        printf("s == t\n");
    }
    else
    {
        printf("s != t\n");
        // Will print the memory addresses.
        printf("%p \n %p", s, t);
    }

// Will print s != t, because you are comparing memory addresses.
// Unlike in Java, Strings cannot be compared like this in C.

// We must use a function called strcmp!
// Acts like a comparator, returns -1, 0, or 1. 
//  * Comparators (such from Java) originated in C.

if (!strcmp(s, t))
{
    printf("s != t\n");
}
else
{
    printf("s == t\n");
}

// strcmp works like this:
//  * iterate through both strings and compare characters until there
//  is either a difference or a sentinel value (null byte: '\0').

strcat(s, u);
// Expecting: 'foobar'.
printf("%s\n", s);
// Expecting buffer overflow, as s can only contain six characters,
// including the seventh being used for the null terminating value.
/*
while (1)
{
    strcat(s, u);
    printf("%s\n", s);
}
*/

// Expecting 'foocar'.
    s[3] = 'c';
    printf("%s\n", s);
// Overwrote the null-terminating byte, which is a requirement of Strings.
//  * Will either crash, or print with random values from memory.
/*
    s[6] = 'c';
    printf("%s\n", s);
*/

// Won't even get to print, this will crash instantly. We're trying to
// change data that we don't have access to.
/*
    t[0] == 'b';
    printf("%s\n", s);
*/

// This is okay, because now t points to something that can be modified.
// Expecting 'boocar'.
    t = s;
    t[0] == 'b';
    printf("%s\n", s);

    return 0;
}
```