#include "option.h"
#include <stdio.h>

int main(void) {

  int arr[] = {1,2,3,4,5};
  int sz = 5;

  Option idx;
  option_nonify(&idx, INT);

  for (int i = 0; i < 5; i++) {
    if (arr[i] == 4) {
      option_somify(&idx, WRAPVAR(i));
    }
  }

  UNWRAP_SECTION;
  int x = UNWRAP(option_get(&idx), option_type(&idx));
  printf("%d\n", x);
  UNWRAP_SECTION_END;


  return 0;
}
