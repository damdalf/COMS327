#include <stdio.h>
#include <stdarg.h>


/*
//Inside exactly one file:

int global_variable;

//inside header
extern int global_variable;
*/

#define littler_printf(...) printf(__VA_ARGS__)

/* Simplified printf.
 * little_printf("sdfc", string, int, float, char);
 */
void little_printf(const char *format, ...)
{
  va_list ap;
  char *s;
  int d;
  extern float f;
  char c;

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
      printf("float %f\n", f);
      break;
    case 'c':
      c = va_arg(ap, int);
      printf("char %c\n", c);
      break;
    }
    format++;
  }

  va_end(ap);
}

int main(int argc, char *argv[])
{
  little_printf("cdsf", 'g', 42, "COM S 327", 1.414);

  littler_printf("Hello %s\n", "World");

  return 0;
}
