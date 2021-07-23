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

void computeLPSprefix(int M, int* prefix,char* pat);  //KMP Algorithm

int main()

{   vector<char>birth;

	string txtline;
    int linenum=0;
	
	
	ifstream birthpi;
	birthpi.open("pi.txt");
	
	ofstream result;
    result.open("results.txt",ios_base::app);
	
	bool flag=false;
	
	while(getline(birthpi,txtline)){
	//	cout<<data<<endl;
	
	linenum++;
	if(linenum>21){
		

	txtline.erase(remove(txtline.begin(), txtline.end(), ' '), txtline.end()); //Removing unnessacery lines in the beginning
	int length=txtline.size(); 
	//int nlen;
	
	//cout<<len<<endl;
	for(int i=0;i<length;i++){
			if(txtline[i]==':'){
				break;
			
			}
			birth.push_back(txtline[i]);
	}
	
  }
	
	
}
	
	for(int i=0;i<birth.size();i++){  //Find out the text line will be printed
	//	cout<<birth[i]<<endl;
	}
	
	char pat[6];
	cout<<"Enter Your Birthday in 6 digits :";
	for(int j=0;j<6;j++){
	cin>>pat[j];
	}
    int count =1;
	
//	char pat[] = "980206"; 
    result<<"\n My Birthday Pattern is (980206)  \n" << endl; 
    result<<"Pattern Matching In KMP Algorithm \n" << endl; 
  
    int M = strlen(pat);
    int N = birth.size(); 
	
	int Lps[M]; 

	// Preprocess the pattern (calculate lps[] array) 
	computeLPSprefix(M, Lps, pat); 

	int i = 0; // index for birth.txt[] 
	int j = 0; // index for pat[] 
	while (i < N) { 
		if (pat[j] == birth[i]) { 
			j++; 
			i++; 
		} 
		
	
		if (j == M) { 
			printf("No %d Found pattern at index %d \n",count, i - j); 
		    result<<"No "<< count++<<" Found pattern at index : " << i - j  << endl; 
			j = Lps[j - 1]; 
		} 

		// mismatch after j matches 
		else if (i < N && pat[j] != birth[i]) { 
			// Do not match lps[0..lps[j-1]] characters, 
			if (j != 0) 
				j = Lps[j - 1]; 
			else
				i = i + 1; 
		} 
	} 
  
    result<< "\t No of Matches is "<<count -1 <<endl;
    return 0; 
	
}

void computeLPSprefix(int M, int* Lps ,char* pat) 
{ 
	// length of the previous longest prefix suffix 
	int length = 0; 
  	
	Lps[0] = 0; // lps[0] is equals to Zero	
	
	 // the loop calculates lps[i] for i = 1 to M-1 
	int i = 1; 
	
	while (i < M) { 
		if (pat[i] == pat[length]) { 
			length++; 
			Lps[i] = length; 
			i++; 
		} 
		
		else 
		{ 
			if (length != 0) { 
				length = Lps[length - 1]; 
			} 
			else // if (len == 0) 
			{ 
				Lps[i] = 0; 
				i++; 
			} 
		} 
	} 
} 

//1415926535 8979323846 2643383279 5028841971 6939937510  : 50
//This format text need to me indice

