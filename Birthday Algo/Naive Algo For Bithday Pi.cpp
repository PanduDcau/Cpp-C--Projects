#include<iostream>
#include<bits/stdc++.h>
#include<fstream>
#include<cstdio>
#include<conio.h>
#include<string.h>
#include <sstream>
#include<vector>
#include<algorithm>
#include <iostream> 
#include <string> 

using namespace std;

int main()

{   vector<char>birth;

    string txtline;
    int linenum=0;
	
	
	bool flag=false;
	ifstream birthpi;
	birthpi.open("pi.txt");
	
		
	ofstream result;
    result.open("results.txt",ios_base::app);
    
	while(getline(birthpi,txtline))
	{
		
	linenum++;
	if(linenum>21){

	txtline.erase(remove(txtline.begin(), txtline.end(), ' '), txtline.end()); // birth.push_back(line);
	
	    int length=txtline.size(); 
	
	
	for(int i=0;i<length;i++){
		
			if(txtline[i]==':'){
				break;
			}
			birth.push_back(txtline[i]);
			
 		 }
	  }
		
}
	
	for(int i=0;i<birth.size();i++)  //Just to clarify the text reading is done finely
	{	    
	//	cout<<birth[i]<<endl;  
	}

	
	result<<"\n My Birthday Pattern is (980206)  \n" << endl; 
    result<<"Pattern Matching In Naive Algorithm \n" << endl; 
	
	char pat[6];
	cout<<"Enter Your Birthday in 6 digits :";
	for(int j=0;j<6;j++){
	cin>>pat[j];
	}
	
	 int count =1;
	
    //	char pat[] = "980206"; 
   
   int M = strlen(pat);
   int N = birth.size(); 
     
    /* A loop to slide the entered pat[] one by one */
    
    for (int i = 0; i <= N - M; i++) { 
        int j; 
        
       
        for (j = 0; j < M; j++) 
            if (birth[i + j] != pat[j]) 
                break; 
                
                
        if (j == M)  
        
            //cout << " Pattern Found At Index "<< i << endl;
             result<<"No "<< count++<< " Pattern Found At Index : " << i << endl;
            
			
    } 
    
    result<< "\t No of Matches is "<<count -1 <<endl;
    return 0; 	
}

//1415926535 8979323846 2643383279 5028841971 6939937510  : 50 
//This format text need to me indice


