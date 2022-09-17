#include "option.h"
#include <stdio.h>
int main(void) {

  Option op;
  option_none(&op, INT);

  for (int i = 0; i < 10; i++) {
    if (i == 5) {
      option_some(&op, WRAP(i));
    }
  }

  if (option_is_some(&op)) {
    printf("found value: %d\n", (int *)option_get(&op));
  } else {
    printf("value not found :(.\n");
  }

  return 0;
}
