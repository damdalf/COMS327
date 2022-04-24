#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[])
{
  while (1) {
    srand(time(NULL));

    printf("%d\n", rand());
  }
}
