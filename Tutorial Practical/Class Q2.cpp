#include<stdio.h>
#include<iostream>
#define size 27

using namespace std;
char c;
class stack
{
	char st[size];
	int top;
    
    public:
    	stack();
    	void push(char c);
    	char pop();
    	void show(stack s);
    	void load();
};

stack::stack()
{
	cout<<"Implementing a Stack ";
	top=0;
}


void stack::push(char c)
{
	char l;
	if(top>=size){
	printf("Stack is Full");
	return;
}
	printf("%c");
	scanf("%c",&l);
	st[top]=l;
	top++;
}

char stack::pop()
{
	char c;
	if(top<=0)
	{
		cout<<"Stack is Empty";
		return 0;
	}
	c=st[top];
	top--;
	return st[top];
	
}

void stack::show(stack s)
{
	char c;
	while(c=s.pop())
	{
		cout<<c<<'\n';
	}
	cout<<'\n';
}

void stack::load()
{
	stack b;
	char n;
	int i =0;
	for(n='a';n<='z';n++)
	{
		st[i++]=n;
	}
		st[i]='\0';
		top=i--;
	
}

int main()
{
	stack s1;
	int op;
	cout<<"\n*********Welcome To Our Alphabetz Dictionary System*********** \n";
	do{
	printf("Enter your Option :");
	scanf("%d",&op);
	
		printf(" 1)Push : \n");
		printf(" 2)Pop : \n");
		printf(" 3)Display : \n");
		printf(" 4)Load Alphabet : \n");
		switch(op)
		{
			case 1:
				s1.push(c);
				break;
            case 2:
				s1.pop();
				break;
			case 3:				
				s1.show(s1);
				break;
			case 4:
				s1.load();
				break;
			default:
				printf(" *******Enter Valid Choice: *********\n");
				break;
						
		}
	}while(op!=5);
	return 0;
}



