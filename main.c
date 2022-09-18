#include "option.h"
#include <assert.h>
#include <stdio.h>

void test() {
  Option op;

  option_nonify(&op, INT);
  option_somify(&op, WRAPINT(999));

  UNWRAP_SECTION;
  int x = UNWRAP(option_raw(&op), option_type(&op));
  assert(x == 999);
  UNWRAP_SECTION_END;

  int x = 998;

  option_somify(&op, WRAPVAR(x));

  UNWRAP_SECTION;
  int y = UNWRAP(option_raw(&op), option_type(&op));
  assert(y == 998);
  UNWRAP_SECTION_END;

  option_nonify(&op, CHAR);
  option_somify(&op, WRAPCHAR('z'));
  UNWRAP_SECTION;
  char y = UNWRAP(option_raw(&op), option_type(&op));
  assert(y == 'z');
  UNWRAP_SECTION_END;

  char c = 'e';
  option_nonify(&op, CHAR);
  option_somify(&op, WRAPVAR(c));
  UNWRAP_SECTION;
  char y = UNWRAP(option_raw(&op), option_type(&op));
  assert(y == 'e');
  UNWRAP_SECTION_END;
}

int main(void) {
  test();
  return 0;
}
