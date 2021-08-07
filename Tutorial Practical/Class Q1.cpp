#include<stdio.h>
#include<iostream>

using namespace std;

class counter
{
	int count;
	public:
		counter(){count=0;}
	
	void increment()
	{
		count++;
		}	
	
	void decrement()
	{
		count--;
		}	
	
	void reset()
	{
		count=0;
	}
	
	void display()
	{
	cout<<"The Count Is : " <<count<<endl;	
	}
	
};

int main()
{
	counter c1;
	int op;
	cout<<"*********Welcome To The Counter Process*********** \n";
	do{
	printf("Enter your Option :");
	scanf("%d",&op);
	
		printf(" 1)Increment : \n");
		printf(" 2)Decrement : \n");
		printf(" 3)Reset : \n");
		printf(" 4)Display : \n");
		switch(op)
		{
			case 1:
				c1.increment();
				break;
            case 2:
				c1.decrement();
				break;
			case 3:				
				c1.reset();
				break;
			case 4:
				c1.display();
				break;
			default:
				printf(" *******Enter Valid Choice: *********\n");
				break;
						
		}
	}while(op!=5);
	return 0;
}











