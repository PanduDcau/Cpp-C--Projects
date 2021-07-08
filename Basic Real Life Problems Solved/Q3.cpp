#include<iostream>
#include<bits/stdc++.h>
using namespace std; 

//void IntSort(int weightunit[], int w) ;
  
int main ()
{
    int num, i,weightclass[100000];//Array weight includes the order items weight
    
    int CountItem = 0; //Intialize to count the number of cans
   // cout << "Enter The Number Of Ordered Items: "; //Input the Size of the array
    cin >> num;    
    cout<<"\n";
    
    //cout << "\n Enter the weight Of each order item : "; //Entering the elements to the array
    
     for (i = 0; i < num; i++)
    cin >> weightclass[i]; //Initializing all the elements
    
    int j;
	  
    sort(weightclass,weightclass + num);
    
    cout<<"\n";
    for(i=0;i<num;i++)
    {
    //	cout<<weightclass[i] <<"\t";//Print the ordered array items
	}
 //Traversing through array to select items to put it in the container
    //[Selection Function]
    	for (int i = 0; i < num; i++) {
            
            int max= weightclass[i] + 4 ; //[Objective Function] initalizing the ending point to segregate Items
            
            //[Feasibility Function]
            for (j = i+1; j < num ; j++){
            	
                if(max >= weightclass[j] ){    //[Fesibility Function]  In the selected list from the begininng point to max point if the items available in 
                //in between the weights all the items will put to one container
                    i++;                     //when max isn't reach we allocate items to 
                    
                }else{     //  [Feaibility Function] 
                    break;  //when all the items selected in the first round fully filled in a container we skipped the round
                }
            }
            CountItem++;  //[Objective Function] After the selected items allocated to the containers, increase container number by 1     
        }
        
    cout<<"\n Number of Containers :"<< CountItem; //[Solution Fucntion]
	//when all the items being allocated to containers, number of containers needed to fill all items will provided
    return 0;
    
}



