#ifndef OPTION_H
#define OPTION_H
// Macros to use constants instead of variables.
#include <stdbool.h>
#include <stdlib.h>

// Used when assigning the unwrap
// to a variable to make it temporary.
#define UNWRAP_SECTION {
#define UNWRAP_SECTION_END }

// Macros for casting.
// Use the specific wrappings for constants.
#define WRAPINT(x) (&(int){x})
#define WRAPUINT(x) (&(unsigned int){x})
#define WRAPCHAR(x) (&(char){x})
#define WRAPDOUBLE(x) (&(double){x})
#define WRAPFLOAT(x) (&(float){x})

// Use the generic wrap macro for variables
#define WRAPVAR(x) ((void *)&x)

typedef enum {
  INT,
  UINT,
  FLOAT,
  DOUBLE,
  CHAR,
} Type;

#define UNWRAP(x, type)                         \
  type == INT? (int)x : (type == CHAR? (char)x : (unsigned int)x)

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

void option_nonify(Option *, Type);
void option_somify(Option *, void *);
bool option_none(const Option *);
bool option_some(const Option *);
void *option_get(const Option *);
Type option_type(const Option *);

#endif // OPTION_H

