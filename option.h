#ifndef OPTION_H
#define OPTION_H
// Macros to use constants instead of variables.
#define WRAPINT(x) (&(int){x})
#define WRAPUINT(x) (&(unsigned int){x})
#define WRAPCHAR(x) (&(char){x})
#define WRAPDOUBLE(x) (&(double){x})
#define WRAPFLOAT(x) (&(float){x})
#define WRAP(x) ((void *)&x)
#include <stdbool.h>
#include <stdlib.h>

typedef enum {
  INT,
  UINT,
  FLOAT,
  DOUBLE,
  CHAR,
} Type;

typedef struct {
  enum {
    NONE,
    SOME
  } state;
  union {
    int          _int;
    unsigned int _uint;
    char         _char;
    double       _double;
    float        _float;
  } data;
  Type type;
} Option;

void option_none(Option *, Type);
void option_some(Option *, void *);
bool option_is_none(const Option *);
bool option_is_some(const Option *);
void *option_get(const Option *);

#endif // OPTION_H

