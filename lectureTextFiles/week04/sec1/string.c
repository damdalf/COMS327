#include <stdio.h>
#include <string.h>

int strcmp327(const char *s1, const char *s2)
{
  /*  
  int i;

  for (i = 0; s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]; i++)
    ;
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
  char *u = "bar";

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
  }

  if (!strcmp327(s, t)) {
    printf("s == t\n");
  } else {
    printf("s != t\n");
  }  

  strcat(s, u);
  printf("%s\n", s);
  /*
  while (1) {
    strcat(s, u);
    printf("%s\n", s);
  }
  */

  s[3] = 'c';
  printf("%s\n", s);

  /*
  s[6] = 'c';
  printf("%s\n", s);
  */

  /*
  t[0] = 'b';
  printf("%s\n", t);
  */

  t = s;
  t[0] = 'b';
  printf("%s\n", t);
  
  return 0;
}
