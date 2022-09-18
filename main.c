#include "option.h"
#include <stdio.h>

int main(void) {

  int arr[] = {1,2,3,4,5};
  int sz = 5;

  Option idx;
  option_nonify(&idx, CHAR);
  char a = 'j';
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
