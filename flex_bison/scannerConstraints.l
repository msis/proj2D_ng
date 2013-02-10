%{
#include "syntax_tree.h"
%}

DIGIT 		[0-9]
INTEGER		{DIGIT}+
REAL		{INTEGER}("."{INTEGER})?
LETTER		[A-Za-z]
VARIABLE	{LETTER}({LETTER}|{DIGIT})*

%%

{REAL}      {yylval.name=QString(yytext);   return(tk_real);}
[-+*/()=]   {yylval.name=QString(yytext);   return *yytext;}
"sin"       {yylval.name="sin";             return(tk_function);}
"cos"       {yylval.name="cos";             return(tk_function);}
"log"       {yylval.name="log";             return(tk_function);}
"exp"       {yylval.name="exp";             return(tk_function);}
"sqr"       {yylval.name="sqr";             return(tk_function);}
"sqrt"      {yylval.name="sqrt";            return(tk_function);}
{VARIABLE}  {yylval.name=QString(yytext);   return(tk_variable);}
\n          {return(tk_newConstraint);}

%%

int yywrap(void) {return 1 ;}
