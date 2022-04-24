#include <stdio.h>
#include <ctype.h>

const char *a[] = {
  "apple",
  "bear",
  "coconut",
  "donut",
  "euphonium",
  "fig",
  "giraffe",
  "hole",
  "igloo",
  "jaguar",
  "kangaroo",
  "lemon",
  "money",
  "niche",
  "opposum",
  "python",
  "quiz",
  "random",
  "stairs",
  "turtle",
  "umbrella",
  "valgrind",
  "winning",
  "x-ray",
  "yes",
  "zipper",
};

int main(int argc, char *argv[])
{
  if (!((argv[1][0] >= 'A' && argv[1][0] <= 'Z') ||
        (argv[1][0] >= 'a' && argv[1][0] <= 'z'))) {
    fprintf(stderr, "Input out of range.\n");
    return -1;
  }

  printf("%c is for %s\n", toupper(argv[1][0]), a[tolower(argv[1][0]) - 'a']);

  return 0;
}
