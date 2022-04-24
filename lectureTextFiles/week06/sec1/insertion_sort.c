#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void generic_insertion_sort(void *a, int n, int s,
                            int (*compare)(const void *v1, const void *v2))
{
  int i, j;
  void *t;
  char *p = a;

  t = malloc(s);

  for (i = 1; i < n; i++) {
    for (memcpy(t, p + i * s, s), j = i - 1;
         j > -1 && compare(p + j * s, t) > 0;
         j--) {
      memcpy(p + (j + 1) * s, p + j * s, s);
    }
    memcpy(p + (j + 1) * s, t, s);
  }  

  free(t);
}

int int_reverse_compare(const void *v1, const void *v2)
{
  return *((int *) v2) - *((int *) v1);
}

int char_compare(const void *v1, const void *v2)
{
  return *((char *) v1) - *((char *) v2);
}

int str_compare(const void *v1, const void *v2)
{
  return strcmp(*(char **) v1, *(char **) v2);
}

int main(int argc, char *argv[])
{
  int a[] = {9,8,7,6,5,4,3,2,1,0};
  int i;
  char *sa[] = { "zero",
                 "one",
                 "two",
                 "three",
                 "four",
                 "five",
                 "six",
                 "seven",
                 "eight",
                 "nine", };
  char c;
  char s[] = "Welcome to COM S 327!";
  char *p;

  insertion_sort(a, sizeof (a) / sizeof (a[0]));

  generic_insertion_sort(a, 10, sizeof (a[0]), int_reverse_compare);

  for (i = 0; i < 10; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");

  //  generic_insertion_sort(s, strlen(s), 1, char_compare);
  qsort(s, strlen(s), 1, char_compare);

  printf("%s\n", s);

  generic_insertion_sort(sa, 10, sizeof (sa[0]), str_compare);

  for (i = 0; i < 10; i++) {
    printf("%s ", sa[i]);
  }
  printf("\n");
  

  for (c = 'a'; c <= 'z'; c++) {
    if ((p = bsearch(&c, s, strlen(s), sizeof (s[0]), char_compare))) {
      printf("%s ", p);
    }
  }
  printf("\n");

  return 0;
}
