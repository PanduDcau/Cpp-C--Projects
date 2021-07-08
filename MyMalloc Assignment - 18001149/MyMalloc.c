#include<stdio.h>
#include<stdbool.h>
#include "MyMalloc.h"

int end,chunk;

int count = 0;

char* MyMalloc (int Capacity)
{
	//Search for free segments
	node *ptr = start;
	count++; //this variable used for track the number of nodes used to create memory chunks and calculate the size of that 
	//because linked list used memory to allocate the chunks in the Memory array as well.
	do
	{
		int block = ptr->endAdr - ptr->starAdr + 1 - 12*count;
		//In Every Linked List Created We also need 12 Bytes in the Memory To Store Linked List
		//calculating the size of the Block Chunk & Also we use meta that 12 size to show meta data.
		if(ptr->IsFree ==0 && Capacity <= block)
		break;
		
		/*if(ptr->starAdr>=25000)
		printf("Memory Fully Occupied && Cannot Be Allocated");*/

		ptr = ptr->next;
	}
	while(ptr!=NULL);
	
	
	//Allocatation Of Memory Blocks
	ptr->IsFree = 1; //Putting a flag that it is being allocated
	end = ptr->endAdr;
	chunk =ptr->starAdr +  Capacity  - 1  ; //calculating Starting address & Respectively Ed Address
	ptr->endAdr = chunk;
	node *New = CreateNode(0,chunk+1,end);
	
	New->next = ptr->next;
	New->prev = ptr;
	
	if (ptr->next!=NULL)
      ptr->next->prev = New;
      
	ptr->next =	New;
	
	return (&Memory[ptr->starAdr]);
	
}

char* MyFree (int adr)//When using My Free Function We have to Give the Starting address to terminate that process
{
	node *ptr = start;
	
	while((ptr->starAdr!= adr && ptr!=NULL))//Finding out the starting Address
	{
		ptr = ptr->next;
	}
	
	if (ptr == NULL) //When The Memory Is Empty
	{
		printf("Not Eligiable Argument or Address isn't Allocated");
	}
	
   else
   {
   	   ptr->IsFree = 1;//Finding the allocated spaces using space flag
   	   
   	    if(ptr->next!=NULL)
   	    //if the previous memory chunk also free it has to merge
   	    //When the Memory Chunks beign freeing at start and in the end
   	    {
   	    	if (ptr->next->IsFree == 0) 
   	    	{  //When the next memoery chunk is beign freed allocted chunks beign merged
   	    		ptr->next->starAdr=ptr->starAdr;
   	    		
   	    		if(ptr = start)
   	    		{
   	    			ptr->next->prev = NULL;
   	    			start = ptr->next;
				   }
				 else
				 {
				 	ptr->next->prev = ptr->prev;//internal procedures to inter connect linked list nodes
				 	ptr->prev->next = ptr->next;
				   } 
				   free(ptr); 
			   }
   	    	
		   }
		   
		   if((ptr->prev!=NULL) && (ptr->next!=NULL))
		   //When we wanted to free a memory Chunk in the Middle
		   {
		   	if((ptr->next->IsFree == 0) && (ptr->prev->IsFree == 0))
		   	{
		   		//intermediate node is free and merge the one before and one after the free chunk
		   		node *tempBB =ptr->next;//another pointer to free the intermediate node
		   		
		   		ptr->prev->endAdr = tempBB->endAdr;
		   		ptr->prev->next = tempBB->next;
		   		
		   		if(tempBB->next!=NULL)
		   		{
		   			  tempBB->next->prev = ptr->prev;
				   }
				   
				    free(ptr);//Deallocte the pointer ptr
				   
				    free(tempBB);//deallocate the pointer tempBB
			   }
		   }
	   }
	   	count--;	
	return (&Memory[ptr->starAdr]);
}

//Do Not Consider The Below lines. Just comments for my Program


int main()
{
    InsertNodeEnd(0, 0, MSize - 1);
    printf("---------HERE WE REPRESENT THE STARTING MEMORY ADDRESSES OF MEMORY CHUNKS-----------\n");
    printf("************************************************************************************\n");
    printf("100        :- %p\n" ,MyMalloc(100));
    printf("5000       :- %p\n" ,MyMalloc(5000));
    printf("300        :- %p\n" ,MyMalloc(300));
    printf("(-Adr 5100):- %p\n" ,MyFree(5100));//starting address of the 300 size block is given to delete
    printf("200        :- %p\n" ,MyMalloc(200));
    printf("6000       :- %p\n" ,MyMalloc(6000));
    printf("(-Adr 5300):- %p\n" ,MyFree(5300));
    
    //After The allocations and free processers all done last segment print the
    //available data in the memory array
    
    //Prove that memory allocation is done in the char array that is beign implemented
    printf("********************************\n");
    printf("Tracker 1 For Find The Address %p \n ",(Memory + 4));
    printf("Tracker 2 For Find The Address %p \n ",(Memory + 16200));
    printf("********************************\n");
    
    
    
    
   MyMalloc(19652);//When We Exceed this level memory fully used include the linked list used for tracking
  // printf("(-Adr 6400) :- %p\n" ,MyFree(6400));
    //MyMalloc(50);
   /* MyMalloc(260);
     MyMalloc(300);*/
    MemoryPL();
    
    return 0; 
}   



