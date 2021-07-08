#include <stdio.h>
#include <stdbool.h>

char MalArray[25000] = {'\0'};

char  *Base =  MalArray;

char fflag = 'f';  //Putting a flag to find the free Space
char Alloc = 'a'; //Flag to find out the Allocated Space



void SegregateMB (char* m, int c)
{
    char* tem;
    int Chunk  = *(int *)(m + 1);

    Chunk = Chunk - c - 5; 
    //500 - 100 -5

    tem = m + c + 5;

    *tem = fflag;

    *(int *)(tem + 1) =  Chunk;
    *(int *)(m + 1) =  c+5;
    
    *m =  Alloc;


}

char *MyMalloc(int Capacity)
{
    if(Capacity <= 0)
    {
        return NULL;
    }

    if(!*Base)
    {
        *Base = fflag;
        *(int *)(Base+1) = 24999 - 5;

    }

    int c = Capacity;

   /* char* m to find available spaces

    if(m)
    {

       if(*(int *)(m+1) >= Capacity)
       {
           SegregateMB(m,c);

       }
    }else{
        return NULL;
    }

    return (m);*/

return (Capacity);
}


void MyFree(char* address)
{
    char *carrier, *prev, *next;

    carrier = Base;

    int num = *(int *)(carrier + 1);

    while(!false)
    {
        num = *(int *)(carrier + 1);

        if(carrier == address)
        {
            break;
        }else if(!*carrier)
        {
            break;
        }else{

            prev = carrier;
            carrier = carrier + num;
            next = carrier + *(int *)(carrier + 1);
        }
    }//end loop

    if(*next == fflag)
    {
        *carrier = fflag;
        *(int *)(carrier + 1) = *(int *)(carrier + 1) + *(int *)(carrier + 1);
    }

    if(*prev == fflag)
    {
        *carrier = fflag;
        *(int *)(prev + 1) = *(int *)(carrier + 1) + *(int *)(carrier + 1);
    }else{
        *address = fflag;
    }
}

void main()
{
	printf("********WELCOME TO THE MEMORY MANAGEMENT UNIT*************\n");
	printf("***********************************************************\n");
    char* Adr1 = MyMalloc(8);
    char* Adr2 = MyMalloc(8900);
    char* Adr3 = MyMalloc(6500);
    
    printf("Alloc Data    Memory Address\n");
    printf("************  ****************\n");
    printf(" 8           %p \n",Adr1);
    printf(" 8900        %p \n",Adr2);
    printf(" 6500        %p \n",Adr3);
    printf("************************************************************\n");
    printf(" Tracker for 4th Location in Array   %p  \n",(MalArray+4));
    printf("************************************************************\n");
	//Prove That Data is stored in the given array
	
    MyFree(Adr3);//8900
    MyFree(Adr2);//6500
    
    char* Adr4 = MyMalloc(500);
    printf(" 500         %p \n",Adr4);
    SegregateMB(Adr4,300);

    char* Adr5 = MyMalloc(12000);
    printf(" 12000       %p \n",Adr5);
    MyFree(Adr4);//400
    
    printf(" 12000       %p \n",Adr4);
}




