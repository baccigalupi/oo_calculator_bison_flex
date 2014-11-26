#include <stdlib.h>

#include "error_handling.h"
#include "literal_value.h"
#include "../parse.tab.h"

LiteralValue  *LiteralValue_create_from_str(int type, const char *str) {
  LiteralValue *literal = calloc(1, sizeof(LiteralValue));
  check_mem(literal);

  literal->type = type;

  if (type == T_INTEGER) {
    Integer *value = Integer_create_from_str(str);
    check(value, "Unable to allocate integer");
    literal->value = value;
  } else {
    Float *value = Float_create_from_str(str);
    check(value, "Unable to allocate integer");
    literal->value = value;
  }

  return literal;
error:
  return NULL;
}

Float *Float_create_from_str(const char *str) {
  Float *number = calloc(1, sizeof(Float));
  check_mem(number);

  number->value = atof(str);
  return number;
error:
  return NULL;
}

Integer  *Integer_create_from_str(const char *str) {
  Integer *number = calloc(1, sizeof(Integer));
  check_mem(number);

  number->value = atoi(str);
  return number;
error:
  return NULL;
}

// LiteralValue *literal_add(LiteralValue *a, LiteralValue *b);
// LiteralValue *literal_subtract(LiteralValue *a, LiteralValue *b);
// LiteralValue *literal_multiply(LiteralValue *a, LiteralValue *b);
// LiteralValue *literal_divide(LiteralValue *a, LiteralValue *b);
