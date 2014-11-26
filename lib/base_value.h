#ifndef __BaseValue
#define __BaseValue

typedef struct BaseValue {
  int type;
  void *value; // Number, String
} BaseValue;

#define base_value_value(B)  ((B)->value)
#define base_value_number(B) (number_value((Number *)((B)->value)))

BaseValue *BaseValue_create(int type, char *val);
BaseValue *base_value_add(BaseValue *a, BaseValue *b);
BaseValue *base_value_subtract(BaseValue *a, BaseValue *b);
BaseValue *base_value_multiply(BaseValue *a, BaseValue *b);
BaseValue *base_value_divide(BaseValue *a, BaseValue *b);

#endif
