#include <stdlib.h>
#include "bricks.h"
#include "classes.h"
#include "../parse.tab.h"

// Classes is an array of class definitions
// currently they are all pointers to native C functions
// in future could be AST stored proceedures

/* Calling native C code, not yet storing AST and translating to proceedures */
// only two classes at the moment, Integer and Float
operator_method IntegerClass[4] = {
  integer_add_unknown,
  integer_subtract_unknown,
  integer_multiply_unknown,
  float_divide
};

operator_method FloatClass[4] = {
  float_add,
  float_subtract,
  float_multiply,
  float_divide
};

operator_method *Classes[2] = {
  IntegerClass,
  FloatClass
};

LiteralValue *operator_call(LiteralValue *a, int operator_type, LiteralValue *b) {
  // only two class yo, would need to make a hash lookup table for more stuff
  operator_method *class;
  if (literal_value_type(a) == T_INTEGER) {
    class = Classes[0];
  } else {
    class = Classes[1];
  }

  // also, the operator_type is mapped directly to the class indexes
  // classes would also be a lookup

  operator_method operator = class[operator_type - T_ADD];
  return operator(a, b);
}
