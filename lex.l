%{
  #include <stdio.h>
  #include "lib/literal_value.h"
  #include "parse.tab.h"

  LiteralValue *yylval;
%}

%option noyywrap

%%

"+"     { return T_ADD; }
"-"     { return T_SUBTRACT; }
"*"     { return T_MULTIPLY; }
"/"     { return T_DIVIDE; }
"="     { return T_EQUAL; }
[0-9]+  {
          yylval = LiteralValue_create_from_str(T_INTEGER, yytext);
          return T_INTEGER;
        }
\n      { return T_EOL; }
[a-z]   {
          yylval = LiteralValue_create_from_str(T_VARIABLE, yytext);
          return T_VARIABLE;
        }
[ \t]   {}
.       { printf("UNKNOWN TOKEN: %s\n", yytext); }

%%
