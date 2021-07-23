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
# define no_char 256 

using namespace std;

void badStringHeuristic(string strbirth, int size, int badchar[no_char])   //Boyer Moore Algorithm					
{ 
	int i; 

	// Initialize all occurrences as -1 
	for (i = 0; i < no_char; i++) 
		badchar[i] = -1; 

	// Fill the actual value of last occurrence 
	for (i = 0; i < size; i++) 
	
		badchar[(int) strbirth[i]] = i; 
				
} 

int main()

{   vector<char>birth;
   
    string txtline;
    int linenum=0;
	
	ifstream birthpi;
	birthpi.open("pi.txt");
	
	bool flag=false;
	ofstream result;
    result.open("results.txt",ios_base::app);
	
	while(getline(birthpi,txtline)){
	
	linenum++;
	if(linenum>21){
		
		
	//	Pushiing back the lines 
	txtline.erase(remove(txtline.begin(), txtline.end(), ' '), txtline.end()); //Removing unnessacery lines in the beginning
	int length=txtline.size(); 
	
	for(int i=0;i<length;i++){
			if(txtline[i]==':'){
				break;	
			}
			birth.push_back(txtline[i]);				
	}
	
  }
	
	
}
	
	 result<<"\n My Birthday Pattern is (980206) \n "<< endl; 
	 result<<"String Matching in Boyer Moore Algorithm :\n" << endl; 
	
	char pat[6];
	cout<<"Enter Your Birthday in 6 digits :";
	for(int j=0;j<6;j++){
	cin>>pat[j];
	}
	
	int count=1;
	
//	char pat[] = "980206";   My Birthday in 6 digits
  
	int n = birth.size(); 
	
	int badchar[no_char];
    int m = strlen(pat); 

	badStringHeuristic(pat, m, badchar); 
	
	int set = 0; 
	
	while(set <= (n - m)) 
	{ 
		int j = m - 1; 

		/* Keep reducing index j of pattern while characters of match in the relevant shift s */
		
		while(j >= 0 && pat[j] == birth[set + j])  //Keep reducing index j of pattern 
			j--; 

		/* If the pattern is present at current 
		shift, then index j --> becomes -1 */
		if (j < 0) 
		{ 
			cout <<"No " <<count<<" Pattern Occurs At Shift = " << set << endl; 
            result<<"No "<< count++<<" Pattern Occurs At Shift : " << set  << endl; 
			/*The condition s+m < n is necessary for 
			the case when pattern occurs at the end 
			of text */
			set += (set + m < n)? m-badchar[birth[set + m]] : 1; 

		} 

		else
			/* Shift the pattern so that the bad character 
			in text aligns with last occur in the Pattern  */
			set += max(1, j - badchar[birth[set + j]]); 
	} 
	
	 result<< "\t No of Matches is "<<count -1 <<endl;
     return 0; 
	
}

//1415926535 8979323846 2643383279 5028841971 6939937510  : 50
//This format text need to me indice


