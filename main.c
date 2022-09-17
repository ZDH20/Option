#include "option.h"
#include <stdio.h>

int main(void) {

  int arr[] = {1,2,3,4,5};
  int sz = 5;

  Option idx;
  option_nonify(&idx, CHAR);

  option_somify(&idx, WRAPCHAR('j'));

  char c = UNWRAP(option_raw(&idx), option_type(&idx));

  printf("%c\n", c);

  return 0;
}
