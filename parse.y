%{

#include <stdio.h>

extern int yylex(void);
void yyerror(char const *s) { fprintf(stderr, "%s\n", s); }

#include "lib/valuables.h"

#define YYERROR_VERBOSE 1

%}

/* tokens */

// %define api.token.prefix { TOKEN_ }
// %define api.value.type { BaseValue } // string:string/atom/id/class_id, number, regex (two strings, value and modifier)
%define api.value.type { int }


%token T_NUMBER
%token T_VARIABLE
%token T_EQUAL
%token T_ADD T_SUBTRACT T_MULTIPLY T_DIVIDE
%token T_EOL

%%

calculation
  :
  | calculation expression T_EOL { BaseValue; printf("= %d\n", $2); }
  ;

expression
  : factor
  | expression T_ADD factor       { $$ = $1 + $3; }
  | expression T_SUBTRACT factor  { $$ = $1 - $3; }
  ;

factor
  : term
  | factor T_MULTIPLY term        { $$ = $1 * $3; }
  | factor T_DIVIDE term          { $$ = $1 / $3; }
  ;

term
  : T_NUMBER
  ;

// assignment:
//   T_VARIABLE T_EQUAL calculation
//   ;

%%
