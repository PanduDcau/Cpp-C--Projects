#include<stdio.h>
char stack[30];
int top=-1;
int main(){
	char exp[30];
	printf("Enter Expression : ");
	scanf("%s",&exp);
	int i=0;
	while(exp[i]!='\0'){
		if(exp[i]=='(' | exp[i]=='[' | exp[i]=='{'){
			push(exp[i]);
		}else if(exp[i]==')' | exp[i]==']' | exp[i]=='}'){
			if(exp[i]==')' & stack[top]=='('){
				top--;
			}else if(exp[i]=='}' & stack[top]=='{'){
				top--;
			}else if(exp[i]==']' & stack[top]=='['){
				top--;
			}
		}
		i++;
	}
	if(top==-1)
		printf("Parentheses are balanced.");
	else
		printf("Parentheses are not balanced.");
	return 0;
}

void push(char c){
	if(top<30){
		top++;
		stack[top]=c;
	}else{
		printf("stack overflow");
	}
}
