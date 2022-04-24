#include <stdlib.h>

#include "stack.h"

int stack_init(stack_t *s)
{
  s->top = NULL; // NULL == (void *) 0
  s->size = 0;

  return 0;
}

int stack_delete(stack_t *s)
{
  stack_node_t *n;

  //  while (!stack_pop(s, &i));

  while (s->top) {
    n = s->top;
    s->top = n->prev;
    free(n);
  }

  s->size = 0;

  return 0;
}

int stack_push(stack_t *s, int v)
{
  stack_node_t *n = malloc(sizeof (*n));

  n->value = v;
  n->prev = s->top;

  s->top = n;
  s->size++;

  return 0;
}

int stack_pop(stack_t *s, int *v)
{
  stack_node_t *n;

  if (!s->size) {
    return 1;
  }

  n = s->top;
  *v = n->value;
  s->top = s->top->prev; // s->top = n->prev
  s->size--;
  free(n);

  return 0;
}

int stack_peek(stack_t *s, int *v)
{
  if (!s->size) {
    return 1;
  }

  *v = s->top->value;

  return 0;
}

int stack_is_empty(stack_t *s)
{
  return !s->size;
}

int stack_size(stack_t *s)
{
  return s->size;
}
