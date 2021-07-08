#include<stdio.h>
#include<stdlib.h>
#define MSize 25000


char Memory[MSize] = {'\0'}; //Intialize the 25000 array to 0 for allocate Memory


struct MemorySB
{ 
	int starAdr;//4 bytes Allocated
	int endAdr;//4 bytes Allocated
	int IsFree;//4 Bytes Allocated
		
	struct MemorySB *next;  //Initialize a Doubly link list to store Memory Chunks
	struct MemorySB *prev;
};

 
typedef struct MemorySB node; //Memory Storage block struct renamed to node

node *start = NULL;

node *CreateNode (int AllocOrFree ,int stAdr , int endAdr)
{   //Intializing New Node with Parameters
	node *Newnode =(node *)malloc(sizeof(node));
	Newnode->next = NULL;
	Newnode->prev = NULL;
	Newnode->starAdr = stAdr; //Starting Address
	Newnode->endAdr = endAdr;
	Newnode->IsFree = AllocOrFree;
	
	return Newnode;
	
}

void InsertNodeEnd(int AllocOrFree , int stAdr , int endAdr) 
{
	//Every Memory Chunk is beign added to end of the allocated/used space.
	
	node *Newnode = CreateNode (AllocOrFree,stAdr,endAdr); 
	if(start==NULL)
	{
		 start = Newnode;
	}
	else
	{
		node* ptr = start;
		while(ptr->next!=NULL)
		{
			ptr = ptr->next;
			ptr->next = Newnode;
			Newnode->prev = ptr;
		}
	}
}

void MemoryPL() //Memory Displaying Unit
{
	printf("---------WELCOME TO THE MEMORY MANAGEMENT UNIT-----------\n");
	printf("**********************************************************\n");
	printf("---------THIS IS THE OS ARCHITETURE FOR MEMORY ALLOCATION-----------\n");
	printf("--------------------------------------------------------------------\n");
	//If Data is allocated (Free) Displays 1 else (Free) Displays 0
	 node *ptr = start;
	
	while(ptr!=NULL)
	{   //Giving the Out Put of the Memory Management unit
		 printf("Free :- %d\t  | StartAdd :- %d\t  |  EndAdd :- %d\t \n", ptr->IsFree, ptr->starAdr, ptr->endAdr);
		 ptr = ptr->next;
	}
	
}

