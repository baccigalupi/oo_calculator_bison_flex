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

Float *Float_create(float f) {
  Float *number = calloc(1, sizeof(Float));
  check_mem(number);

  number->value = f;
  return number;
error:
  return NULL;
}

Float *Float_create_from_str(const char *str) {
  Float *number = Float_create(atof(str));
  check_mem(number);
  return number;
error:
  return NULL;
}

Integer  *Integer_create(int i) {
  Integer *number = calloc(1, sizeof(Integer));
  check_mem(number);

  number->value = i;
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

LiteralValue *literal_add(LiteralValue *a, LiteralValue *b) {
  LiteralValue *literal = calloc(1, sizeof(Float));
  check_mem(literal);

  if (literal_value_type(a) == T_INTEGER && literal_value_type(b) == T_INTEGER) {
    literal->type = T_INTEGER;
    Integer *value = Integer_create(literal_value(a) + literal_value(b));
    check_mem(value);
    literal->value = value;
  } else {
    literal->type = T_FLOAT;
    Float *value = Float_create(literal_value(a) + literal_value(b));
    check_mem(value);
    literal->value = value;
  }

  return literal;
error:
  return NULL;
}

LiteralValue *literal_subtract(LiteralValue *a, LiteralValue *b) {
  LiteralValue *literal = calloc(1, sizeof(Float));
  check_mem(literal);

  if (literal_value_type(a) == T_INTEGER && literal_value_type(b) == T_INTEGER) {
    literal->type = T_INTEGER;
    Integer *value = Integer_create(literal_value(a) - literal_value(b));
    check_mem(value);
    literal->value = value;
  } else {
    literal->type = T_FLOAT;
    Float *value = Float_create(literal_value(a) - literal_value(b));
    check_mem(value);
    literal->value = value;
  }

  return literal;
  error:
  return NULL;
}

LiteralValue *literal_multiply(LiteralValue *a, LiteralValue *b) {
  LiteralValue *literal = calloc(1, sizeof(Float));
  check_mem(literal);

  if (literal_value_type(a) == T_INTEGER && literal_value_type(b) == T_INTEGER) {
    literal->type = T_INTEGER;
    Integer *value = Integer_create(literal_value(a) * literal_value(b));
    check_mem(value);
    literal->value = value;
  } else {
    literal->type = T_FLOAT;
    Float *value = Float_create(literal_value(a) * literal_value(b));
    check_mem(value);
    literal->value = value;
  }

  return literal;
  error:
  return NULL;
}

LiteralValue *literal_divide(LiteralValue *a, LiteralValue *b) {
  LiteralValue *literal = calloc(1, sizeof(Float));
  check_mem(literal);

  literal->type = T_FLOAT;
  Float *value = Float_create(literal_value(a) * literal_value(b));
  check_mem(value);
  literal->value = value;

  return literal;
  error:
  return NULL;
}

void print_literal_value(LiteralValue *a) {
  if (literal_value_type(a) == T_INTEGER) {
    Integer *i = literal_value_value(a);
    int value = i->value;
    printf("= %d\n", value);
  } else {
    Float *f = literal_value_value(a);
    float value = f->value;
    printf("= %f\n", value);
  }
}
