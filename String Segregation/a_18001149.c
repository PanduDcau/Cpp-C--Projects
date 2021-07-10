#include <stdio.h>
#define SIZE 200 //Intializing String Token array Size 
#include <stdlib.h>

int CToken(char* st);
void TokenResult(char tok_type,char* st,int begin,int end);
void tokening(char *ft, char *st);


int CToken(char* st){
	
	int Digit,begin,end; //Starting from the beginning of a letter sequance of Same Genre (String , Float, Integer)
	char c,token_type; //Token type can be categorized like this -> 'f' for float, 'i' for integer and 's' for string
	
	begin=0; //Initialize begin point and end point is zero to use in index calculation
	end=0;
	
	int z;
	for(z=0;z<SIZE;z++) 
	{
	//Segregating the token inside the Text file using this conditioned loop

		c=st[z];
		Digit=isdigit(c); //Checking the String pattern is Letter or a Digit
		
		//Now from character array , chcking the characters one by one we can identify whether it's a integer, decimal
		//or a string character by looking into the special characters
		if(c=='.')
		
		{     // When Token is a float
				if(token_type=='f')
			{
				 //Error Will Occur Because Double decimal Points
				token_type='e';
				TokenResult(token_type,st,0,SIZE);
				return;
			}
			
			token_type='f';
			end++;
			
		}
		
		else if(c==!1)
		{
			
			TokenResult(token_type,st,begin,end); //character array neither recognized as any of desinated tokens.So we tell it as a end of token
			return;// not an error
			
		
		}
		
		else if(Digit==!0)
		{
			//Letter is recognized as a String
				if(token_type=='s')
			{
				TokenResult(token_type,st,begin,end);
				begin=end;
			}
			
			else if(token_type!='f') // Make sure that Decimal point isn't recognized as an Integer
			{
				token_type='i';
			}
				end++;
		}
		
		else
		{
			if(token_type=='i' || token_type=='f') //When Token is String
			{
				TokenResult(token_type,st,begin,end);
				begin=end;
	
			}
			token_type='s';
			end++;
		}
	}
	
}



int main(){
	
	char st[SIZE],file[40];// Creating a Char Array for String Tokens
	FILE *ft;
	
	printf("Enter name of a file you wish to see\n");
    gets(file);//My inputed file name is constantine.txt
		
	 ft = fopen(file, "r");//File Pointer initializing the File Reading
 // read mode

   if (ft == NULL)
   {
      perror("Error while opening the file.\n");
      exit(EXIT_FAILURE);
   }
   
	
	int eof;
	
	while(!0){
		
		eof=fscanf(ft, "%s", st); //Tokenizing is done 
		if(eof==1){
		
			CToken(st); // Identify the integers decimals and strings
		}else{
			break;
		}	
	}
	

   // tokening(ft,st); //Runtime error occured in pointer allocation
		
	fclose(ft);// Closing the Relevant File
}

void TokenResult(char token,char* st,int begin,int end){
	
	if(token=='i'){
		printf("<INTEGER,");	
	}else if(token=='f'){
		printf("<FLOAT,");
	}else if(token=='s'){
		printf("<STRING,");
	}else{
		printf("<ERROR,");
	}
	
	
	int i;
	for(i=begin;i<end;i++){
		
		char value=st[i];
		
		if(value!=0){
			printf("%c",value);
		}else{
			break; //When Character Array is larger than Actual String , needed to break 
		}
	}
	
	printf(">");
	
}

//Got Some Runtime errors in this function

//void tokening(char *filep,char *st_array)
//{
//		int eof;
//	
//	while(!0) 
//	{
//		
//		eof=fscanf(filep, "%s", st_array); //Tokenizing is done 
//		if(eof==1){
//		
//			CToken(st_array); // Identify the integers decimals and strings
//		}else{
//			break;
//		}	
//	}
//}



