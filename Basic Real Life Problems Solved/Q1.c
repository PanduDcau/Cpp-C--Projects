#include<stdio.h>
int main(){
	int num[10]={1,2,3,4,5,6,7,8,9,10};
	int x,y;
	printf("\t\t\t\t******** MULTIPICATION TABLE ********\n\n");
	printf("		");
	for(x=0;x<10;x++){
		printf("%d	",num[x]);
	}
	printf("\n");
	printf("		");
	for(x=0;x<10;x++){
		printf("~	");
	}
	printf("\n");
	for(y=1;y<=10;y++){
		printf("\n");
		printf("   %d >		",y);
		for(x=0;x<10;x++){
				printf("%d	",y*num[x]);
		}
		printf("\n");
		printf("	    ");
		
		
			for(x=1;x<10;x++){
				printf("---------");
			
		}
	}
	printf("\n\n");
	return 0;
}
