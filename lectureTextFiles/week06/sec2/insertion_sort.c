#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct foo {
  int nt;
  int sn;
};

void insertion_sort(int *a, int n)
{
  int i, j, t;

  for (i = 1; i < n; i++) {
    for (t = a[i], j = i - 1; j > -1 && a[j] > t; j--) {
      a[j + 1] = a[j];
    }
    a[j + 1] = t;
  }
}

int int_reverse_cmp(const void *v1, const void *v2)
{
  return *((int *) v2) - *((int *) v1);
}

void generic_insertion_sort(void *v, int n, int s,
                            int (*compare)(const void *v1, const void *v2))
{
  int i, j;
  char *t = malloc(s);
  char *a = v;

  for (i = 1; i < n; i++) {
    for (memcpy(t, a + s * i, s), j = i - 1;
         j > -1 && compare(a + s * j, t) > 0;
         j--) {
      memcpy(a + s * (j + 1), a + s * j, s);
    }
    memcpy(a + s * (j + 1), t, s);
  }

  free(t);
}

int char_cmp(const void *v1, const void *v2)
{
  return *((char *) v1) - *((char *) v2);
}

int str_compare(const void *v1, const void *v2)
{
  return strcmp(*(char **) v1, *(char **) v2);
}

int foo_cmp(const void *v1, const void *v2)
{
  if (((struct foo *)v1)->nt == ((struct foo *)v2)->nt) {
    return ((struct foo *)v1)->sn - ((struct foo *)v2)->sn;
  }
  return ((struct foo *)v1)->nt - ((struct foo *)v2)->nt;
}

int main(int argc, char *argv[])
{
  int a[] = {9,8,7,6,5,4,3,2,1,0};
  int i;
  char s[] = "Welcome to COM S 327!";
  char *sa[] = {
    "zero",
    "one",
    "two",
    "three",
    "four",
    "five",
    "six",
    "seven",
    "eight",
    "nine",
  };
  char c;
  char *p;

  struct foo f[] = {
    {0,1},
    {1,2},
    {3,5},
    {2,3},
    {6,9},
    {3,4},
    {0,0},
    {3,6},
    {5,8},
    {4,7},
  };
  insertion_sort(a, sizeof (a) / sizeof (a[0]));

  generic_insertion_sort(a, 10, sizeof (a[0]), int_reverse_cmp);

  for (i = 0; i < 10; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");

  qsort(s, strlen(s), 1, char_cmp);
  printf("%s\n", s);

  generic_insertion_sort(sa, 10, sizeof (sa[0]), str_compare);

  for (i = 0; i < 10; i++) {
    printf("%s ", sa[i]);
  }
  printf("\n");

  for (c = 'a'; c <= 'z'; c++) {
    if ((p = bsearch(&c, s, strlen(s), 1, char_cmp))) {
      printf("%s ", p);
    }
  }
  printf("\n");

  qsort(f, 10, sizeof (f[0]), foo_cmp);

  for (i = 0; i < 10; i++) {
    printf("%d %d\n", f[i].nt, f[i].sn);
  }

  return 0;
}
