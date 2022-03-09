#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	// Testing pointer arithmetic beginning with addition:

	int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, *ap = a;
	
	/* 
	Pointers to arrays naturally point to the first element of an 
	array, because the variable representing an array is a pointer to
	the first element of said array.
	*/

	printf("Expecting 0:\n");
	printf("Result: %d\n\n", *ap);

	// Using pointer arithmetic, lets print the 6th value in our array.
	// This is the 6th element, since we are starting at 0.

	printf("Expecting 5:\n");
	printf("Result Using Pointer to Array: %d\n", *(ap + 5));
	printf("Result Using Array as a Pointer: %d\n\n", *(a + 5));

	// Okay, now how about for a 2D array?

	int b[3][3] = {{1,2,3}, {4, 5, 6}, {7, 8 ,9}};
	printf("Expecting: 8:\n");
	printf("Result: %d\n\n", (*(b + 2))[1]);

	printf("Expecting: 3\n");
	printf("Result: %d\n\n", (*b)[2]);

	printf("Expecting: 6\n");
	printf("Result: %d\n\n", (*(b + 1))[2]);
 

	return 0;
}
