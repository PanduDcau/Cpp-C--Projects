%option noyywrap
Whitespace [\t \n]+
Digit [+-]?[0-9]+
Identifier [a-zA-Z][a-zA-Z0-9]*
Float {Digit}+"."{Digit}*
Data_Type ("int")|("str")
Terminator ;
Operator "-"|"+"|"*"|"/"|"%"|"="|"<"|">"|"("|")"|"{"|"}"|","|">="|"<="|"=="|"!="
Flow_Control ("if")|("while")|("else")
Keyword ("print")|("return")
String [/'][^/"/']+[/'][/"][^/"]+[/"]
Logical_Operator ("and")|("or")|("not")|("nand")|("xor")|("nor")|("xnor")

%{
    #include<stdio.h>
    char *yytext;
%}

%%
{Whitespace} printf("<WHITESPACE,%s>",yytext);
{Keyword} printf("<KEYWORD,%s>",yytext);
{Flow_Control} printf("<FLOW CONTROL,%s>", yytext);
{Data_Type} printf("<DATATYPE,%s>",yytext);
{Terminator} printf("<TERMINATOR,%s>",yytext);
{Operator} printf("<OPERATOR,%s>",yytext);
{Logical_Operator} printf("<LOGICAL OPERATOR,%s>",yytext);
{String} printf("<STRING,%s>",yytext);
{Identifier} printf("<IDENTIFIER,%s>",yytext);
{Digit} printf("<DIGIT,%s>",yytext);
{Float} printf("<FLOAT,%s>",yytext);
. printf("<ERROR, %s>",yytext);
%%

int main(int argc,char *argv[]){

    argv++;
	--argc;
	
	if(argc!=1){
		printf("Please mention the input file name \n");
		return 0;
	}
	
	if(( yyin =fopen(argv[0],"r"))==NULL){
		printf("Unable to open the input file!");
		return 0;
    }

	yylex();
    fclose(yyin);
    printf("SUCESSFULL EXECUTION"); 
	return 0;
	
}