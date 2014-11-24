%{

#include <stdio.h>

extern int yylex(void);
void yyerror(char const *s) { fprintf(stderr, "%s\n", s); }

%}

/* tokens */

%token T_NUMBER
%token T_ADD T_SUBTRACT T_MULTIPLY T_DIVIDE
%token T_EOL

%%

calculation:
  | calculation expression T_EOL { printf("= %d\n", $2); }
  ;

expression: factor
  | expression T_ADD factor       { $$ = $1 + $3; }
  | expression T_SUBTRACT factor  { $$ = $1 - $3; }
  ;

factor: term
  | factor T_MULTIPLY term        { $$ = $1 * $3; }
  | factor T_DIVIDE term          { $$ = $1 / $3; }
  ;

term: T_NUMBER
  ;

%%

int main(int argc, char **argv) {
  yyparse();

  return 0;
}
