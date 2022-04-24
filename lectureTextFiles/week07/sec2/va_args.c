#include <stdio.h>
#include <stdarg.h>

/*
 * little_printf("fcsd", float, char, char *, int);
 */
void little_printf(const char *format, ...)
{
  va_list ap;
  char *s;
  extern float f;
  int d;
  char c;

  va_start(ap, format);
  while (*format) {
    switch (*format) {
    case 's':
      s = va_arg(ap, char *);
      printf("string: %s\n", s);
      break;
    case 'd':
      d = va_arg(ap, int);
      printf("int: %d\n", d);
      break;      
    case 'f':
      f = va_arg(ap, double);
      printf("float: %f\n", f);
      break;
    case 'c':
      c = va_arg(ap, int);
      printf("char: %c\n", c);
      break;
    }
    format++;
  }
  va_end(ap);
}

#define littler_printf(...) printf(__VA_ARGS__)

int main(int argc, char *argv[])
{
  little_printf("cdfscd", 'f', 42, 1.414, "Hello World!", 'h', 'y');

  littler_printf("Hello %s!\n", "World");

  return 0;
}
