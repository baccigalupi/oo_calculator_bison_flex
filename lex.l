%{

#include <stdio.h>
#include "parse.tab.h"

int yylval;
%}

%option noyywrap

%%

"+"     { return T_ADD; }
"-"     { return T_SUBTRACT; }
"*"     { return T_MULTIPLY; }
"/"     { return T_DIVIDE; }
[0-9]+  {
          yylval = atoi(yytext);
          return T_NUMBER;
        }
\n      { return T_EOL; }
[ \t]   {}
.       { printf("UNKNOWN TOKEN: %s\n", yytext); }

%%
