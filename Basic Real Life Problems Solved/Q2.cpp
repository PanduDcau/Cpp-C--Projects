#include<iostream>
#define N 100000
using namespace std;

int main()
{
	int n=0; //No of students
	int x=0, y=0, tot=0, i=0, j=0;
	int score[N]; //Array to store the marks of students 
	int masks[N]; //Array to store the no of masks given to each student

	cin>>n; //getting the no of students
	
	for(i=0;i<n;i++)//getting the scores of each student
	{
		masks[i]=1; //initializing each student with the minimum possible number of masks
		cin>>score[i]; //(CANDIDATE SET)
	}
	
	for(i=1;i<n;i++) //(SELECTION FUNCTION)Each student is considered in the order in which they are seated
	{
		if(score[i]>score[i-1]) //(FEASIBILITY FUNCTION) The scores of students seated next to each other are compared to identify the student with the higher score 
			masks[i]=masks[i-1]+1; //If the student has a higher score than the student seated to the left we increase the no of masks allocated to that student 
	}
	
	for(i=n-2;i>=0;i--) 
	{
		if(score[i]>score[i+1] && masks[i]<=masks[i+1]) //(FEASIBILITY FUNCTION) The scores of students seated next to each other are compared to identify the student with the higher score 
			masks[i]=masks[i+1]+1; //If the student has a higher score than the student seated to the right we increase the no of masks allocated to that student 
	}
	
	for(i=0;i<n;i++)
		tot+=masks[i]; //(OBJECTIVE FUNCTION)Get the total number of masks
		
	cout<<tot; //(SOULTION FUNCTION)
	
	return 0;
}
