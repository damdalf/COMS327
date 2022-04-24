#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct foo {
  char c;
  int i;
  float f;
  char a[80];
} foo_t;

typedef int somethingelse;


void swap_wrong(int a, int b)
{
  int tmp;

  tmp = a;
  a = b;
  b = tmp;

  printf("%d, %d\n", a, b);
}

void swap_right(int *, int *);

void populate_foo(foo_t *f)
{
  f->i = 20;
  f->f = 6.02e23;
  strcpy(f->a, "changed!");
}

int main(int argc, char *argv[])
{
  int x, y;
  int *p;

  struct foo f;

  f.i = 10;
  f.f = 3.14;
  strcpy(f.a, "string");

  printf("%d %f %s\n", f.i, f.f, f.a);

  populate_foo(&f);
  printf("%d %f %s\n", f.i, f.f, f.a);

  //  return 0;

  x = 0;
  y = 1;

  p = malloc(sizeof (*p)); // Sizeof is a compile-time operator!
                           // Tells me only static info!

  // p = malloc(50 * sizeof (*p)); // allocates an array of 50 ints
  // *(p + x) == p[x]

  *p = 5;  // p[0] = 5;

  printf("%d, %d\n", *p, y);
  swap_right(p, &y);
  printf("%d, %d\n", *p, y);

  free(p);
  //Don't double free!
  //Free only things previously returned by malloc
  //Don't use pointers after they have been freed

  printf("%lu\n", sizeof (p));
  printf("%lu\n", sizeof (*p));

  return 0;
}

void swap_right(int *a, int *b)
{
  int tmp;

  tmp = *a;
  *a = *b;
  *b = tmp;

  printf("%d, %d\n", *a, *b);
}

