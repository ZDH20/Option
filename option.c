#include "option.h"
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

// Set the `Option` to NONE and set the
// type that it holds.
void option_nonify(Option *op, Type type) {
  op->state = NONE;
  op->type  = type;
}

// Return the type that the `Option` contains.
Type option_type(const Option *op) {
  return op->type;
}

// Put data into `Option`.
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

// Check if the `Option` is NONE.
bool option_none(const Option *op) {
  return op->state == NONE;
}

// Returns the type that the `Option` is holding.
bool option_some(const Option *op) {
  return op->state == SOME;
}

// Returns the value the `Option` is holding
// in `void *` format. This needs to be
// unwrapped by calling the UNWRAP() macro
// to get the actual data in a useble form.
void *option_raw(const Option *op) {
  assert(op->state == SOME);
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

