#include <stdio.h>

#include "stack.h"

int main(int argc, char *argv[])
{
  stack_t s;
  int i;

  stack_init(&s);

  stack_push(&s, 0);
  stack_push(&s, 1);
  stack_push(&s, 2);
  stack_push(&s, 3);
  stack_push(&s, 4);

  while (!stack_is_empty(&s)) {
    stack_pop(&s, &i);
    printf("Popped %d\n", i);
  }

  do {
    scanf("%d", &i);
    stack_push(&s, i);
  } while (i != -1);

  printf("Stack size: %d", stack_size(&s));

  while (!stack_is_empty(&s)) {
    stack_pop(&s, &i);
    printf("Popped %d\n", i);
  }

  return 0;
}
