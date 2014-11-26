#include <stdlib.h>

#include "error_handling.h"

#include "base_value.h"
#include "number.h"
#include "string.h"

#include "../parse.tab.h"

BaseValue *BaseValue_create(int type, char *val) {
  BaseValue *value = calloc(1, sizeof(BaseValue));
  check_mem(value);

  value->type = type;

  if (type == T_VARIABLE) {
    value->value = String_create(val);
  } else if (type == T_NUMBER) {
    value->value = Number_create(val);
  }

  return value;
error:
  return NULL;
}
