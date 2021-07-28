#include<stdio.h>
#include <string.h>

int i,c,pos,val,a[40],size,val;
void print(int A[],int size);
int main()
{
 printf("Enter The Number Of Elements:\n");
 scanf("%d",&size);
 
 printf("Elements:");
 for(i=0;i<size;i++)
 {
 	scanf("\n%d",&a[i]);
 }
 
	printf("Enter The Location for Delete;\n");
	scanf("%d",&pos);
	
	if(pos>=size+1)
	{
		printf("Deletion Cannot Be Done");
		
	}
	
	else
	{
		for(c=pos-1;c<size-1;c++)
		{
			a[c]=a[c+1];
		}
	}
	printf("Result Array:\n");
	
		for(c=0;c<size-1;c++)
		{
			printf("%d\n",a[c]);
		}
		
		
	printf("Enter The Location for Insert;\n");
	scanf("%d",&pos);
	
	printf("Enter The value for Insert;\n");
	scanf("%d",&val);
	
		
	
	if(pos>=size+1)
	{
		printf("Insertion Cannot Be Done");
		
	}
	
		for(c=size;c>=pos-1;c--)
		{
				a[c+1]=a[c];
			
		}
	a[pos-1]=val;
				

	printf("Result Array:\n");
	
		for(c=0;c<size;c++)
		{
			printf("\n%d",a[c]);
		}
	
}

void print(int A[],int size)
{
	for(i=0;i<size;i++)
	{
		printf("%d\n",a[i]);
	}
}
