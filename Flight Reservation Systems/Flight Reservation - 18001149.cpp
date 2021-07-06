#include <iostream>
#include <conio.h>
#include <fstream>
#include <iomanip>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include<math.h>
#include <string> 
#include<sstream>

using namespace std;
int arrayIndex=0;            //Creating GLobal variables for used in my options after data is beign declared.
int globalObjectCount; 		 //global 1
void reserve_seat (); 
void flight_reserve(); 
void flight_schedule (); 
void main_menu (); 	   		//main control Panel
void seat_available(); 		//Finding available seats in a particular flight 
void reserve();
void validFunc(int,string);   
void deleteElement(int,int) ; 	//delete the elements after the allocation is beign done.
void emptyInit(string *);   	//Check Out the Empty strings
void exit1();                   //Exit Function After the seats Are Allocated
void freeup(int *,int *);
void deleteRow(struct seat *,int );
void flight_det();             //Display the Seats with available flights

struct seat
{
    string row;
    string column;   //Seat structure used for define the seat arrangements
    string cell;
};

class Flight1
{	
		public:
		int seatRows;     //flight class that declare all the attributes in a particlar fight directory that we wanted to find Informaation
		string fl_n;
		string date;
		string origin;
		string dest;
		int numE,numB;
		seat seatset[100];
			char *clas;
			void display_p()
			{
				cout<<fl_n<<endl;   //Display the requied flight details
				cout<<date<<endl;
				cout<<origin<<endl;
				cout<<dest<<endl;
			}
			
			void setting(string f1,string date1,string ori,string des,seat lm[],int n)
			{
			   	fl_n=f1;             
			   	date=date1;                    //This loop contain to display available seats in the selected flight
			   	origin=ori;
			   	dest=des;
			   	for(int i =0;i<=n;i++)
			   	{
			   		seatset[i].row=lm[i].row;
			   		seatset[i].cell=lm[i].cell;
			   		seatset[i].column=lm[i].column;
				   }
				   	
			}	
};


Flight1 *flGlobal; //Create a pointer to call the class to the functions



void allocate()     //Allocating the Seats to the respective flight
{
	char *ch;
	ifstream read("flight.txt");
	cout<<"Flight Schedule :"<<endl;
	string flName;
	cout<<"Enter Flight Number:";//Allow us to Find the details in a flight according to the seat number
	cin>>flName;
	int flag=0;
		
	int tempVar=-1;
	for(int i=0;i<globalObjectCount;i++){         //By compairing the flight number it will select the targeted flight that we wanted.
		if(flGlobal[i].fl_n.compare(flName)==0){
			tempVar = i;
		}
	}
	
	if(tempVar==-1)
	{
		cout<<"Not found!!"<<endl;
		getch();
		main_menu();
	}
	
	cout<<"Enter The Preferred Class :";//Enter the preferred Class "B" or "E"
	string r,str;
	int s;
	//int i=0;
	cin>>r;
	cout<<"Enter Number Of Seats : "<<endl;
	cin>>s;
	
		if(r=="B") {

		int k=0;
	 	cout<<s<<" Seats Have Been Booked In Business Class"<<endl;
	 
		if(flGlobal[tempVar].numB < s)
	 		{
	 			cout<<"Error !! Seats Are Insufficient"<<endl;
	 			main_menu();
			 }
			 
	 			flGlobal[tempVar].numB = flGlobal[tempVar].numB-s;
	 		
	 		cout<<" Seat Reserving Is Success !! Avalable seats in class B:"<<"\n"<<flGlobal[tempVar].numB;
	 		
	 		while(s>0){
	 			
	 			if(flGlobal[tempVar].seatset[k].column.length()<=s && flGlobal[tempVar].seatset[k].cell.compare("B")==0){
	 				
	 				s = s - flGlobal[tempVar].seatset[k].column.length();
	 				deleteElement(k,tempVar);
	 	
	 				
				 }
				 else if(flGlobal[tempVar].seatset[k].column.length()>s && flGlobal[tempVar].seatset[k].cell.compare("B")==0){
				 	flGlobal[tempVar].seatset[k].column.erase(0,s);
				 	break;
				 }
				 	k++;
			 }
			 
		}
		
 else if(r=="E"){
	 	int i=0;
	 	cout<<s<<" Seats Have Been Booked In Economy Class"<<endl;
	
			  	if(flGlobal[tempVar].numE  < s)
	 		{
	 			cout<<"Error !!! Seats Are Insufficient"<<endl;
	 			main_menu();
			 }
			 	flGlobal[tempVar].numE = flGlobal[tempVar].numE-s;
			
			 	
	 		cout<<" Seat Reserving Is Success ! Avalable seats in class E:"<<flGlobal[tempVar].numE;
	 		
	 		while(s>0){
	 			if(flGlobal[tempVar].seatset[i].column.length()<=s && flGlobal[tempVar].seatset[i].cell.compare("E")==0){
	 				
	 				s = s - flGlobal[tempVar].seatset[i].column.length();
	 				deleteElement(i,tempVar);
	 	
	 				
				 }
				 else if(flGlobal[tempVar].seatset[i].column.length()>s && flGlobal[tempVar].seatset[i].cell.compare("E")==0){
				 	flGlobal[tempVar].seatset[i].column.erase(0,s);
				 	break;
				 }
				 	i++;
			 }
	 	}


		
		else
		{
			cout<<"Given Class is Not Founded In this Selected Flight";
		}
	getch (); 
	main_menu ();	
	
}


void copyFunc(seat *ar,string chr,int index){
	string wor;
	int count=0;
	stringstream ss(chr);
	while(ss>>wor)
	{
		if(count==0){
			ar[index].row=wor;//Getting the Row Number 
		}
		
		else if(count ==1){
				ar[index].cell=wor; //Getting The Customers Prefer Flight Class
		}
		
		else{
			ar[index].column=wor; //Getting the respective seats when the prefered class given
		}
		count++;
	}
}


void classChecker(struct seat *srt,int *e,int *b,int li) //This function is used for get the count of the seats according to the given class
{
	for(int i=0;i<li;i++){
		if(srt[i].cell=="B") {
			*b=*b+srt[i].column.length();	
		}
		else{
		*e = *e+srt[i].column.length();//This function is used for get the count of the Economy class
		}
	}
}

void iteration(int *p)//iteration is done in here due to segmentation faults occured in file reading
{
	*p=*p+1;
}

void seat_available()
{
	int q=0;
	int count =0;
	char *ch;
	string flName;
	
	ifstream read("flight.txt");
	ifstream read2("flight.txt");
	
	while(!read.eof())
	{
	read.getline(ch,100);
	if(strcmp(ch,"")==0) count++;	
	
	}
	
	read.close();

	Flight1 customer[count];
	globalObjectCount = count;
	string arr[100];
	while(!read2.eof())
	{
	
		read2.getline(ch,100);
		customer[q].fl_n=ch;
		read2.getline(ch,100);
		customer[q].date=ch;
		read2.getline(ch,100);
		customer[q].origin=ch;
		read2.getline(ch,100);
		customer[q].dest=ch;
		int i=0;
		
		while(read2.getline(ch,100) && strcmp(ch,"")!=0)
		{
			copyFunc(customer[q].seatset,ch,i);
			iteration(&i);
		}
		customer[q].seatRows=i;
		q++;
		
		continue;
		
	
	}
	read2.close();

	
	flGlobal=customer;
	
	cout<<"Enter flight Number:";
	cin>>flName;
	validFunc(count,flName);

	getch (); 
	main_menu ();
};


int main (){

	main_menu (); 
	getch ();

return 0;
}

void main_menu(){   
   
	Flight1 customer[5];
	int code; 
	cout<<"\n";
	cout<<"\t*********************************************************************"<<endl;
	cout<<"\t+++++++++++++++Virgin's Flight Reservation System++++++++++++++++++++"<<endl;
	cout<<"\t*********************************************************************"<<endl;  
	cout<<endl;
	cout<<"\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
	cout<<"\t\t       Welcome To the Airline Reservation System :"<<endl;
	cout<<"\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
	
	cout<<"1.  \tDisplay Avialable Flights :"<<endl;
	cout<<"2.	View Flight :"  <<endl; 
	cout<<"3.	Seat Availability :" <<endl; 
	cout<<"4.	Seat Booking :"<<endl;
	cout<<"5.	Exit *"<<endl<<endl;
	 
	 
	cout<<"\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
	cout<< "Please, *****Enter 0 Option & Press Enter*****  When You First Using This System "<<endl; 
    cout<<"\t+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;

	cout<< "Please, Then Enter Any Of Those Codes To Select That Specific Option: ";
	
	cin>>code;
	if (code == 0)
	{
		cout<<endl; 
		flight_det(); //Object array Intializing
		getch( );
	}
	
	if (code == 1)
	{
		cout<<endl; 
		flight_reserve (); //Display Full Available Flights
		getch( );
	}
	
	if (code == 2)
	{
		cout<<endl;
		flight_schedule();//View Flight details According to flight details
	}
	
	if (code==3)
	{
		cout<<endl;
		seat_available();//Finding the Available Seats in the Selected Flight
	}
	
	if (code==4)
	{
	
		allocate(); //Use to allocate the data after the seats begin allocated
		cout<<endl;
	}

	if (code==5)
	{
	   exit1();
	   exit(1); //Closing the reservation System and writing into an another file with the seat reservations
	}

	if (code>=6){
	
	cout<<endl;
	cout<<"Code Error! Please Enter From Any Of The Above Given Options"<<endl;
	
	getch();
	main_menu ();
	}

}


void flight_reserve()  //Finding the Available flights with their available flights
{
	Flight1 customer;
	class seat seats;
	//clrscr ();
	char ch[100];
	char flName[6];
	int count3=0;
	ifstream read ("flight.txt",ios::app);
	ifstream read2("flight.txt");
	cout<<"Available Flights With Seat Reservations: " <<endl;

while(!read.eof())
{
	if(flName)
	read.getline(ch,100);
	cout<<ch; 
	cout<<endl;
}
	read.close();
	
	while(!read2.eof())
	{
	read2.getline(ch,100);
	if(strcmp(ch,"")==0) count3++;	
	
	}
	read2.close();
	     
	    int k=0;
	   int countE=0,countB=0;
	    
			
          while(k<count3){
		   
			classChecker(flGlobal[k].seatset,&countE,&countB,flGlobal[k].seatRows);
			flGlobal[k].numB=countB;
			flGlobal[k].numE=countE;
			cout<<"Flight Number :"<<flGlobal[k].fl_n<<endl;
		
			
            cout<<"Number of B class seats:"<<flGlobal[k].numB<<endl;
			cout<<"Number of E class seats:"<<flGlobal[k].numE<<endl;
			freeup(&flGlobal[k].numB,&flGlobal[k].numE);
			 	iteration(&k);
			 	countE=0;countB=0;
			 	cout<<"\n";
			
}
	
	cout<<"\n";
	cout<<"No Of Available Flights :"<<count3<<endl;
	cout<<"Press Any Key To Go Back To The Main Menu !"<<endl; 
	getch();
	main_menu ();
}

void freeup(int *q,int *r) //Data re initialized to 0 , after the data is allocted to some value
{
	*q=0;
	*r=0;

}

void flight_det()
{
		int q=0;
	int count =0;
	char *ch;
	string flName;
	
	ifstream read("flight.txt");
	ifstream read2("flight.txt");
	
	while(!read.eof())
	{
	read.getline(ch,100);
	if(strcmp(ch,"")==0) count++;	
	
	}
	
	read.close();

	Flight1 customer[count];
	globalObjectCount = count;
	string arr[100];
	while(!read2.eof())
	{
	
		read2.getline(ch,100);
		customer[q].fl_n=ch;
		read2.getline(ch,100);
		customer[q].date=ch;
		read2.getline(ch,100);
		customer[q].origin=ch;
		read2.getline(ch,100);
		customer[q].dest=ch;
		int i=0;
		
		while(read2.getline(ch,100) && strcmp(ch,"")!=0)
		{
			copyFunc(customer[q].seatset,ch,i);
			iteration(&i);
		}
		customer[q].seatRows=i;
		q++;
		
		continue;
		
	
	}
	read2.close();

	
	flGlobal=customer;
	
	getch();
	main_menu();
}

void flight_schedule() //Getting flight details According to the input flight Number
{
	int q=0;
	
	char *ch;
	ifstream read("flight.txt");
	cout<<"Flight Schedule :"<<endl;
	string flName;
	cout<<"Enter Flight Number:";
	cin>>flName;
	int flag=0;
	
	while(!read.eof())
	{
	read.getline(ch,100);
	if(flName.compare(ch)==0){		
		flag=1;
	}
	if(flag)
	{
			if(strcmp(ch,"")==0) break;
			cout<<ch<<endl;	
		}
	}
	
	if(!flag) cout<<"Not found";
	read.close();
	cout<<endl;
	cout<<"Press Any Key To Go Back To The Main Menu !"<<endl;
	getch();
	main_menu ();
}
                 
void validFunc(int count,string flName)
{    //This function is used for derived data from the File respective to the flight Number
	int k=0,flag=0;
	while(k<count){
			int countE=0,countB=0;
			classChecker(flGlobal[k].seatset,&countE,&countB,flGlobal[k].seatRows);
			flGlobal[k].numB=countB;
			flGlobal[k].numE=countE;
		if(flGlobal[k].fl_n.compare(flName)==0){
			cout<<"Flight found!!!"<<endl;
			cout<<flGlobal[k].fl_n<<endl;
			cout<<flGlobal[k].date<<endl;
			cout<<flGlobal[k].origin<<endl;
			cout<<flGlobal[k].dest<<endl;
			cout<<"Number of B class seats:"<<flGlobal[k].numB<<endl;
			cout<<"Number of E class seats:"<<flGlobal[k].numE<<endl;
			flag=1;
			break;
		}
		iteration(&k);
	}
	if(!flag) cout<<"Flight not found!!"<<endl;
	cout<<"\n";
	
}

void deleteElement(int x,int objectNo) 
{ 
  for(int i=x;i<59;i++)                //There are 60 rows in each plane and iterate until the whole rows are checked.
  {
  	flGlobal[objectNo].seatset[i]=flGlobal[objectNo].seatset[i+1];
  }
}


void emptyInit(string *str)
{
	*str=" "; //Empty the Seats and the Entire row if the seats of the entire seats already occupied
}


void exit1()
{

 // Create and open a text file
  ofstream MyFile("f1.txt");     //Writing entire flight file into new file f1
	int i=0;
	string f;
  // Write to the file
  while(i<globalObjectCount)
  {
  int k=0;
  MyFile << flGlobal[i].fl_n+"\n";
  MyFile << flGlobal[i].date+"\n";
  MyFile << flGlobal[i].origin+ "\n";
  MyFile << flGlobal[i].dest + "\n";
   
  while(k<60)
   {
   		if(flGlobal[i].seatset[k].row.compare("")==0){
   			break;
		   }
		else{
			 MyFile << flGlobal[i].seatset[k].row + " " ;    //Deleting entire row ,column and seats after seat allocation is Done
			 MyFile << flGlobal[i].seatset[k].cell+ " ";
			 MyFile << flGlobal[i].seatset[k].column+ "\n";
			k++;
		}
	
			
		}
		MyFile <<"\n";
			i++;
     
}


  // Close the file
  MyFile.close();	
  exit(EXIT_SUCCESS);

}
