#include<stdio.h>
char pop();
void push(char);
char stack[20];
int top=-1;
int main(){
	char str[20];
	printf("Enter any string : ");
	scanf("%s",&str);
	int i=0;
	
	while(str[i]!='\0'){
		push(str[i]);
		i++;
	}
	printf("Reverse of that string : ");
	for(i=0;i<20;i++){
		char rv=pop();
		if(rv=='E'){
			break;
		}else{
			printf("%c",rv);
		}
		i++;
	}
	return 0;
	
}
void push(char c){
	if(top<20){
		top++;
		stack[top]=c;
	}else{
		printf("stack overflow");
	}
}

char pop(){
	if(top>-1){
		char rv=stack[top];
		top--;
		return rv;
	}else{
		return 'E';
	}
}
