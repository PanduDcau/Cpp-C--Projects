#include<stdio.h>
int main(){
	char data[20];
	printf("Enter Value : ");
	scanf("%s",&data);
	int i=0;
	int s=0;
	while(data[i]!='\0'){
		if(data[i]>=48 & data[i]<=57)
			s=0;
		else{
			s=1;
			break;
		}
		i++;	
	}
	if(s==0)
		printf("it is a number.");
	else
		printf("it is not a number.");
	return 0;
}
