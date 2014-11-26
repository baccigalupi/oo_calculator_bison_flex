#ifndef __LiteralValue
#define __LiteralValue

typedef struct LiteralValue {
  int type;
  void *value;
} LiteralValue;

typedef struct Integer {
  int value;
} Integer;

typedef struct Float {
  float value;
} Float;

#define literal_value_type(LV)  ((LV)->type)
#define literal_value_value(LV) ((LV)->value)

#define literal_value(LV)       (                                                       \
                                  (literal_value_type(LV) == T_INTEGER) ?               \
                                    ( ((Integer *)(literal_value_value(LV)))->value ) : \
                                    ( ((Float *)(literal_value_value(LV)))->value )     \
                                )

LiteralValue  *LiteralValue_create_from_str(int type, const char *str);
Float         *Float_create_from_str(const char *str);
Integer       *Integer_create_from_str(const char *str);

LiteralValue *literal_add(LiteralValue *a, LiteralValue *b);
LiteralValue *literal_subtract(LiteralValue *a, LiteralValue *b);
LiteralValue *literal_multiply(LiteralValue *a, LiteralValue *b);
LiteralValue *literal_divide(LiteralValue *a, LiteralValue *b);

#endif
