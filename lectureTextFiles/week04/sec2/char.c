#include <stdio.h>
#include <ctype.h>

char *a[] = {
  "apple",
  "bee",
  "cat",
  "dog",
  "elephant",
  "fan",
  "garbage",
  "hello",
  "igloo",
  "java",
  "kottlin",
  "lemon",
  "maven",
  "no",
  "octopus",
  "python",
  "quit",
  "ruby",
  "shrimp",
  "turtle",
  "umbrella",
  "virus",
  "waltz",
  "xylophone",
  "yodel",
  "zebra",
};

int main(int argc, char *argv[])
{
  int i;

  if (!((argv[1][0] >= 'a' && argv[1][0] <= 'z') ||
        (argv[1][0] >= 'A' && argv[1][0] <= 'Z'))) {
    fprintf(stderr, "Invalid input.\n");

    return 1;
  }

  fprintf(stdout, "%x is for %s.\n", toupper(argv[1][0]), a[tolower(argv[1][0]) - 'a']);

  /*
  scanf("%d", &i);
  printf("%c\n", i);
  */

  return 0;
}
