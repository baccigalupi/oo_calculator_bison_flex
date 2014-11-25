%{

#include <stdio.h>
#include "parse.tab.h"

// char *yylval;
%}

%option noyywrap

%%

"+"     { return T_ADD; }
"-"     { return T_SUBTRACT; }
"*"     { return T_MULTIPLY; }
"/"     { return T_DIVIDE; }
"="     { return T_EQUAL; }
[0-9]+  {
          yylval = atoi(yytext);
          return T_NUMBER;
        }
\n      { return T_EOL; }
[a-z]   {
          // yylval = yytext;
          return T_VARIABLE;
        }
[ \t]   {}
.       { printf("UNKNOWN TOKEN: %s\n", yytext); }

%%
