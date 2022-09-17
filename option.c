#include "option.h"
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

void option_nonify(Option *op, Type type) {
  op->state = NONE;
  op->type  = type;
}

Type option_type(const Option *op) {
  return op->type;
}

void option_somify(Option *op, void *data) {
  switch (op->type) {
  case INT:
    op->data._int = *(int *)data;
    break;
  case UINT:
    op->data._uint = *(unsigned int *)data;
    break;
  case FLOAT:
    assert(false && "UNIMPLEMENTED\n");
    op->data._float = *(float *)data;
    break;
  case DOUBLE:
    assert(false && "UNIMPLEMENTED\n");
    op->data._double= *(double*)data;
    break;
  case CHAR:
    op->data._char = *(char *)data;
    break;
  default:
    assert(false && "UNREACHABLE\n");
  }
  op->state = SOME;
}

bool option_is_none(const Option *op) {
  return op->state == NONE;
}

bool option_is_some(const Option *op) {
  return op->state == SOME;
}

void *option_get(const Option *op) {
  switch (op->type) {
  case INT:
    return (void *)op->data._int;
  case UINT:
    return (void *)op->data._uint;
  case FLOAT:
    assert(false && "UNIMPLEMENTED\n");
  case DOUBLE:
    assert(false && "UNIMPLEMENTED\n");
  case CHAR:
    return (void *)op->data._char;
  default:
    assert(false && "UNREACHABLE\n");
  }
  return NULL;
}

