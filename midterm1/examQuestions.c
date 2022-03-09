#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swapchar(char *x, char*y)
{
	char temp = *x;
	*x = *y;
	*y = temp;
}

char *strndup(const char *s, size_t n)
{
	int i;
	char *t = malloc(n);
	
	// Check if there is an insufficient amount of memory available to the program, if there is,
	// then return NULL.
	if (t == NULL) return NULL;

	for (i = 0; i < n; i++)
	{
		// Copies the contents of s into t, one by one, while incrementing through each pointer
		// at the same time.
		*(t + i) = *(s + i);
	}

	// If s is longer than n, only n bytes are copied (handled above), and a terminating null byte
	// '\0' is added.

	if (strlen(s) > n)
	{
		*(t + n) = '\0';
	}

	return t;
}

int main (int argc, char *argv[])
{
	//void arr[10];
	//void **ptr;

	char x = 'a';
	char y = 'b';
	printf("x = %c, y = %c\n", x, y);

	swapchar(&x, &y);
	printf("x = %c, y = %c\n", x, y);
	
	const char *s = "Str";
	
	char *t = strndup(s, 3);
	char *r = strndup(s, 1);
	printf("%s\n", t); 
	printf("%s\n", r); 

	return 0;
}
