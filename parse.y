%{

  #include <stdio.h>

  extern int yylex(void);
  void yyerror(char const *s) { fprintf(stderr, "%s\n", s); }

  #include "lib/literal_value.h"

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
  | calculation expression T_EOL { printf("= %d\n", literal_value($2)); }
  ;

expression
  : factor
  | expression T_ADD factor       { $$ = literal_add($1, $3); }
  | expression T_SUBTRACT factor  { $$ = literal_subtract($1, $3); }
  ;

factor
  : term
  | factor T_MULTIPLY term        { $$ = literal_multiply($1, $3); }
  | factor T_DIVIDE term          { $$ = literal_divide($1, $3); }
  ;

term
  : T_NUMBER
  ;

// assignment:
//   T_VARIABLE T_EQUAL calculation
//   ;

%%
