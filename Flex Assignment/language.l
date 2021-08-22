%option noyywrap
%{
   // noyywrap is used to initialize the header File
   #include<stdio.h>
   //Importing the C Header file to the flex file
   int no_of_chars = 0;
%}



%{
// Initilaize the data types and variables to be identfied in given text segment
%}


VARIABLE_TYPE     "str"|"int"
STRING            \"([^\\\"]|\\.)*\"
FLOW_CONTROL      "if"|"else"|"while"
LOGICAL_OPERATORS "=="|"<"|">"|"<="|">="|"!="
INTERGER          [0-9]
WHITE_SPACE       [ \n\t]+
OPERATORS         "+"|"-"|"*"|"/"|"%"|"="
BRACKETS          "["|"]"|"("|")"
SCOPE             "{"|"}"
SYSTEM_METHOD     "print"|"main"|"return"
IDENTIFIER        [_a-zA-Z]+[_a-zA-Z0-9]*

%{
// Print the Differntiated Tokens , When the Text inserted
/* ++no_of_chars;
end	 return 0; */
%}


%%
%{
// Print the Tokens 
%}

{VARIABLE_TYPE}         {printf("<Variable Type,%s>",yytext);}
{STRING}                {printf("<String,%s>",yytext);}
{FLOW_CONTROL}          {printf("<Keyword,%s>",yytext);}
{LOGICAL_OPERATORS}     {printf("<Logical Operation,%s>",yytext);}
{WHITE_SPACE}           {printf("<Whitespace,%s>",yytext);}
{OPERATORS}             {printf("<Operator,%s>",yytext);}
{BRACKETS}              {printf("<Bracket,%s>",yytext);}
{SCOPE}                 {printf("<Scope,%s>",yytext);}
{SYSTEM_METHOD}         {printf("<System Method,%s>",yytext);}
{INTERGER}+             {printf("<Integer,%s>",yytext);}
";"                     {printf("<Seperator,%s>",yytext);}
","                     {printf("<Punctuation,%s>",yytext);}
.                       {printf("<Invalid,%s>",yytext);}
{IDENTIFIER}            {printf("<Identifier,%s>",yytext);}



%%
int main(int argc, char *argv[]) { 

   printf("\n");
   // Reading the First Arguments array in the Cmd 
   yyin = fopen(argv[1], "r");
   //fucntion Called
   yylex();

  // printf("Terminating the Compilation !!!=> %d\n",no_of_chars);

   fclose(yyin);

   return 0;
}
