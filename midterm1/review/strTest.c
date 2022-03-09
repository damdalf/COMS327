#include <stdlib.h>
#include <stdio.h>

int main (int argc, char *argv[])
{
	char s[16] = "Hello, ass hat.";

	// Let's copy this String without using strcpy() or strdup()

	int i;

	// This reads: For s is the first index, and while s is not the null
	// byte, increment through the indices of x
	for (i = 0; s[i]; s++)
	{
	i++;
	}
	// This should terminate when we have reached the index of null byte.

	// i + 1 to add space for the null byte, since i was never incremented
	char *r = malloc(i + 1);

	// Time to copy the String
	for (i = s; s[i]; s++)
	{
		r[i] = s[i];
		//i++;
	}
	r[i + 1] = '\0';

	printf("%s", r);
}
