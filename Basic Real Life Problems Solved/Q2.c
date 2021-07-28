#include<stdio.h>
int main(){
	int m1[3][3]={{3,5,7},{1,6,5},{4,9,8}};
	int m2[3][3]={{6,0,2},{4,7,1},{7,2,1}};
	int i,j;
	printf("Matrix Addition\n\n");
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf("	%d",m1[i][j]+m2[i][j]);
		}
		printf("\n");
	}
	printf("\n\nMatrix Subtraction\n\n");
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf("	%d",m1[i][j]-m2[i][j]);
		}
		printf("\n");
	}
	printf("\n\nMatrix Multiplication\n\n");
	for(i=0;i<3;i++){
		for(j=0;j<3;j++){
			printf("	%d",m1[i][j]*m2[j][i]);
		}
		printf("\n");
	}
	return 0;
}
