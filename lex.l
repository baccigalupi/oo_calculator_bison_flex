%{

#include <stdio.h>
#include "lib/base_value.h"
#include "parse.tab.h"

BaseValue *yylval;
%}

%option noyywrap

%%

"+"     { return T_ADD; }
"-"     { return T_SUBTRACT; }
"*"     { return T_MULTIPLY; }
"/"     { return T_DIVIDE; }
"="     { return T_EQUAL; }
[0-9]+  {
          yylval = BaseValue_create(T_NUMBER, yytext);
          return T_NUMBER;
        }
\n      { return T_EOL; }
[a-z]   {
          yylval = BaseValue_create(T_VARIABLE, yytext);
          return T_VARIABLE;
        }
[ \t]   {}
.       { printf("UNKNOWN TOKEN: %s\n", yytext); }

%%
