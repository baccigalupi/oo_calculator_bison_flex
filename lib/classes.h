#ifndef __Classes
#define __Classes

#include "literal_value.h"

typedef LiteralValue *(*operator_method)(LiteralValue *a, LiteralValue *b);
// typedef operator_method* Class; // array of operator methods

LiteralValue *operator_call(LiteralValue *a, int operator_type, LiteralValue *b);

#endif
