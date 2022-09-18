#include "option.h"
#include <stdio.h>

int main(void) {

  char a = 'j';

  Option idx;
  option_nonify(&idx, CHAR);
  option_somify(&idx, WRAPVAR(a));

  UNWRAP_SECTION;
  char c = UNWRAP(option_raw(&idx), option_type(&idx));
  printf("%c\n", c);
  UNWRAP_SECTION_END;

  option_nonify(&idx, INT);
  option_somify(&idx, WRAPINT(5));
  printf("%d\n", UNWRAP(option_raw(&idx), option_type(&idx)));

  return 0;
}

