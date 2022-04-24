#include <stdio.h>
#include <string.h>

int strcmp327(const char *s1, const char *s2)
{
  /*
  int i;

  for (i = 0; s1[i] && s2[i] && s1[i] == s2[i]; i++)
    ;

  return s1[i] - s2[i];
  */

  while (*s1 && *s2 && *s1 == *s2) {
    s1++;
    s2++;
  }

  return *s1 - *s2;
}

int main(int argc, char *argv[])
{
  char s[7] = "foo";
  char *t = "foo";

  if (s == t) {
    printf("s == t\n");
  } else {
    printf("s != t\n");
    printf("%p %p\n", s, t);
  }

  if (!strcmp(s, t)) {
    printf("s == t\n");
  } else {
    printf("s != t\n");
    printf("%p %p\n", s, t);
  }

  if (!strcmp327(s, t)) {
    printf("s == t\n");
  } else {
    printf("s != t\n");
    printf("%p %p\n", s, t);
  }

  strcat(s, t);
  printf("%s\n", s);

  /*
  t[0] = 'b';
  printf("%s\n", t);
  */

  s[0] = 'b';
  s[3] = 'h';
  printf("%s\n", s);

  t = s;
  t[3] = 'b';
  printf("%s\n", t);


  return 0;
}
