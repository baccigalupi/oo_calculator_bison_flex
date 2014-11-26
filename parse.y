%{

  #include <stdio.h>

  extern int yylex(void);
  void yyerror(char const *s) { fprintf(stderr, "%s\n", s); }

  #include "lib/literal_value.h"
  #include "lib/classes.h"

  #define YYERROR_VERBOSE 1

%}

/* tokens */

// %define api.token.prefix { TOKEN_ }
%define api.value.type { LiteralValue* }


%token T_NUMBER T_INTEGER T_FLOAT
%token T_VARIABLE
%token T_EQUAL
%token T_ADD T_SUBTRACT T_MULTIPLY T_DIVIDE
%token T_EOL

%%

calculation
  :
  | calculation expression T_EOL { print_literal_value($2); }
  ;

expression
  : factor
  | expression T_ADD factor       { $$ = operator_call($1, T_ADD, $3); }
  | expression T_SUBTRACT factor  { $$ = operator_call($1, T_SUBTRACT, $3); }
  ;

factor
  : term
  | factor T_MULTIPLY term        { $$ = operator_call($1, T_MULTIPLY, $3); }
  | factor T_DIVIDE term          { $$ = operator_call($1, T_DIVIDE, $3); }
  ;

term
  : T_INTEGER
  | T_FLOAT
  ;

// assignment:
//   T_VARIABLE T_EQUAL calculation
//   ;

%%
