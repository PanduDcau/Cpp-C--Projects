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

#define y 256 

using namespace std;


int main()

{   
    vector<char>birth;
    
    string txtline;
    int linenum=0;
		
	
	ifstream birthpi;
	birthpi.open("pi.txt");
	
	bool flag=false;
	
	ofstream result;
    result.open("results.txt",ios_base::app);
	
	while(getline(birthpi,txtline))
	{
	
	linenum++;
	if(linenum>21){
				
	txtline.erase(remove(txtline.begin(), txtline.end(), ' '), txtline.end()); 
	int length=txtline.size(); 
	
	for(int i=0;i<length;i++){
			if(txtline[i]==':'){
				break;
			}
			
			birth.push_back(txtline[i]);
				
	          }
	
	    }
}
	
	result<<" \n My Birthday Pattern is (980206) \n "<< endl; 
    result<<"String Matching in Robin Karp Algorithm :\n" << endl; 
	
	char pat[6];
	cout<<"Enter Your Birthday in 6 digits :";
	for(int j=0;j<6;j++){
	cin>>pat[j];
	}
	
	int i, j; 
	int count = 1;
	
    int M = strlen(pat); 
	int N = birth.size(); 
	

	int h = 1; 
	int q = 107;
	int p = 0; // hash value for pattern 
	int bir = 0; // hash value for birth.txt
		

	// The value of h would be "pow(d, M-1)%q" 
	for (i = 0; i < M - 1; i++) 
		h = (h * y) % q; 

	for (i = 0; i < M; i++) 
	{ 
		p = (y * p + pat[i]) % q;         	// Calculate the hash value of pattern and first window of birth text                                                                                 	 
		bir = (y * bir + birth[i]) % q; 
	} 

	
	for (i = 0; i <= N - M; i++) // Slide the pattern over text one by one 
	{ 

		
		if ( p == bir )                  // Check the hash values of current window of text an pattern
		{ 
			/* Check for characters one by one */
			for (j = 0; j < M; j++) 
			{ 
				if (birth[i+j] != pat[j]) 
					break; 
			} 

			// if p == t and pat[0...M-1] = txt[i, i+1, ...i+M-1] 
			if (j == M) 
				//cout<<"Pattern Found at Index "<< i<<endl; 
				 result<<"No "<< count++<<" Pattern Found At Index :" <<i << endl;
				
		} 
          
		// Calculate hash value for next window of text: Remove 
		if ( i < N-M ) 
		{ 
			bir = (y*(bir - birth[i]*h) + birth[i+M])%q; 

			// We might get negative value of t, converting it to Positive one
			if (bir < 0) 
			bir = (bir + q); 
		} 
	} 
	 result<< "\t No of Matches is "<<count -1 <<endl;
	return 0;	
}


//1415926535 8979323846 2643383279 5028841971 6939937510  : 50
//This format text need to me indice

