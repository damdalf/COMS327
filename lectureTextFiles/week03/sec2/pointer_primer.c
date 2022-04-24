#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct foo {
  int i;
  float f;
  char a[80];
} foo_t;

void swap_wrong(int x, int y)
{
  int tmp;
  tmp = x;
  x = y;
  y = tmp;

  printf("%d, %d\n", x, y);
}

void swap_right(int *x, int *y)
{
  int tmp;
  tmp = *x;
  *x = *y;
  *y = tmp;

  printf("%d, %d\n", *x, *y);
}

void populate_foo(struct foo *f)
{
  f->i = 50011;
  f->f = 6.02e23;
  strcpy(f->a, "changed!");
}

int main(int argc, char *argv[])
{
  int x, y;
  foo_t f;
  int *p;

  p = malloc(sizeof (*p));
  // sizeof is a static operator
  // Gives the size of the type associated with the expression
  *p = 5;

  f.i = 10;
  f.f = 3.1415;
  strcpy(f.a, "string");

  printf("%d %f %s\n", f.i, f.f, f.a);

  populate_foo(&f);
  printf("%d %f %s\n", f.i, f.f, f.a);


  x = 0;
  y = 1;

  printf("%d, %d\n", *p, y);
  swap_right(p, &y);
  printf("%d, %d\n", *p, y);

  free(p);
  // free returns storage to the heap
  // Only call on addresses returned by malloc
  // Don't double free

  return 0;
}
