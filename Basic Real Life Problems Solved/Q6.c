#include<stdio.h>
int main(){
	char word[30];
	printf("Enter a word : ");
	scanf("%s",&word);
	int i=0;
	//this not work for sentences but it works for words...
	while(word[i+3]!='\0'){
		if(word[i]=='c' & word[i+1]=='o' & word[i+2]=='r' & word[i+3]=='d'){
			printf("This centence contain 'cord'.");
			break;
			i++;	
		}
	}
	return 0;
}
