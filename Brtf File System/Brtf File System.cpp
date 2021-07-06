#include<iostream>
#include<vector>
#include<string>

using namespace std;

void listFiles();
void insertFile();
void copyFiles();
void viewFiles();
void editFiles();
void createSnapshot();
void restoreSnapshot();

struct fileNameToFileMap{     //Struct to mapping the file name with meta data as well        
	int fileName;
	string s;
	int size;
	fileNameToFileMap(){
		s="";
	}
}typedef fileNameToFileMap;

vector<fileNameToFileMap>original;
vector<fileNameToFileMap>snapshot;

//Data struct to create the Btree for Intializing the Btrf

struct BTree//node declaration 
{
   int *d;
   BTree **child_ptr;    //An Array Of Child Pointers
   bool l;           //True when the node is leaf & empty
   int n;            //Count out number of Keys in the Node
   int cap;
   BTree *search(int k)
   {
	
	int q=0;
	while(q<n && k>d[q]) q++;
	
	if(d[q]==k)
	{
		return this;
	}
	
	if(l)
	return NULL;
	
	return child_ptr[q]->search(k);
}
}

*r = NULL, *np = NULL, *x = NULL, *r2=NULL;


BTree* init()//creation of node 
{
   int i;
   np = new BTree;   //Creating pointer to the Btree's Root
   np->d = new int[6];  //order 6 btree
   np->child_ptr = new BTree *[7]; //7 pointers for the node
   np->l = true;
   np->n = 0;
   for (i = 0; i < 7; i++) {
      np->child_ptr[i] = NULL;
   }
   return np;
}

int findSize(){    //Just to keep a reminder of the intiated root node
		
}

void traverse(BTree *p)//traverse the btree 
{
   int copyArr[p->n];
   cout<<endl;
   int i;
   for (i = 0; i < p->n; i++) {
      if (p->l == false) {
         traverse(p->child_ptr[i]);
      }
      cout << "\n" << p->d[i];
      cout<<"\t Dictionary Size in Bytes: "<<sizeof*(p->child_ptr[i]);
   }
   if (p->l == false) 
   {
      traverse(p->child_ptr[i]);
   }
   cout<<endl;
}


void sort(int *p, int n)//sort the tree 
{
   int i, j, t;
   for (i = 0; i < n; i++) {
      for (j = i; j <= n; j++) {
         if (p[i] >p[j]) {
            t = p[i];
            p[i] = p[j];
            p[j] = t;
         }
      }
   }
}

int split_child(BTree *x, int i) {    //When the keys of the node >m/2
   int j, mid;
   BTree *np1, *np3, *y;
   np3 = init();//create new node
   np3->l = true;
   if (i == -1) {
      mid = x->d[2];//find the middle 
      x->d[2] = 0;
      x->n--;
      np1 = init();
      np1->l= false; //leaf node is not available
      x->l= true;
      for (j = 3; j < 6; j++) {
         np3->d[j - 3] = x->d[j];
         np3->child_ptr[j - 3] = x->child_ptr[j];
         np3->n++;
         x->d[j] = 0;
         x->n--;
      }
      for (j = 0; j < 6; j++) {
         x->child_ptr[j] = NULL;
      }
      np1->d[0] = mid;
      np1->child_ptr[np1->n] = x;
      np1->child_ptr[np1->n + 1] = np3;
      np1->n++;
      r = np1;
   } else {
      y = x->child_ptr[i];
      mid = y->d[2];
      y->d[2] = 0;
      y->n--;
      for (j = 3; j <6 ; j++) {
         np3->d[j - 3] = y->d[j];
         np3->n++;
         y->d[j] = 0;
         y->n--;
      }
      x->child_ptr[i + 1] = y;
      x->child_ptr[i + 1] = np3;
   }
   return mid;
}

//Inserting New file to the File Hierarchy

void insert(int a) 
{ 
   int i, t;
   x = r;
   if (x == NULL) {
      r = init();
      x = r;
   } else {
      if (x->l== true && x->n == 6) {
         t = split_child(x, -1);
         x = r;
         for (i = 0; i < (x->n); i++) {
            if ((a >x->d[i]) && (a < x->d[i + 1])) {
               i++;
               break;
            } else if (a < x->d[0]) {
               break;
            } else {
               continue;
            }
         }
         x = x->child_ptr[i];
      } else {
         while (x->l == false) {
            for (i = 0; i < (x->n); i++) {
               if ((a >x->d[i]) && (a < x->d[i + 1])) {
                  i++;
                  break;
               } else if (a < x->d[0]) {
                  break;
               } else {
                  continue;
               }
            }
            if ((x->child_ptr[i])->n == 6) {
               t = split_child(x, i);
               x->d[x->n] = t;
               x->n++;
               continue;
            } else {
               x = x->child_ptr[i];
            }
         }
      }
   }
   x->d[x->n] = a;
   sort(x->d, x->n);
   x->n++;
}

//This insertion is beign used for the snapshot process /cloning the entire file system as a backup
void insert2(int a) {
   int i, t;
   x = r2;
   if (x == NULL) {
      r2 = init();
      x = r2;
   } else {
      if (x->l== true && x->n == 6) {
         t = split_child(x, -1);
         x = r2;
         for (i = 0; i < (x->n); i++) {
            if ((a >x->d[i]) && (a < x->d[i + 1])) {
               i++;
               break;
            } else if (a < x->d[0]) {
               break;
            } else {
               continue;
            }
         }
         x = x->child_ptr[i];
      } else {
         while (x->l == false) {
            for (i = 0; i < (x->n); i++) {
               if ((a >x->d[i]) && (a < x->d[i + 1])) {
                  i++;
                  break;
               } else if (a < x->d[0]) {
                  break;
               } else {
                  continue;
               }
            }
            if ((x->child_ptr[i])->n == 6) {
               t = split_child(x, i);
               x->d[x->n] = t;
               x->n++;
               continue;
            } else {
               x = x->child_ptr[i];
            }
         }
      }
   }
   x->d[x->n] = a;
   sort(x->d, x->n);
   x->n++;
}


int main() {
  	cout<<"\t\t **Pandu's BTRFS File System**"<<endl;
	while(1){
		int x;
	
		cout<<"1.Create New File"<<endl;
		cout<<"2.List Files"<<endl;
		cout<<"3.Copy Files"<<endl;
		cout<<"4.View Files"<<endl;
		cout<<"5.Edit files"<<endl;	
		cout<<"6.Create Snapshot"<<endl;
		cout<<"7.Restore Snapshot"<<endl;
		cout<<"8.Exit programme"<<endl;
		cout<<"\nEnter Choice:"<<endl;
		cin>>x;
		
		switch(x){
			case 1:
				insertFile();
				break;
			case 2:
				listFiles();
				break;
			case 3:
				copyFiles();
				break;
			case 4:
				viewFiles();
				break;
			case 5:
				editFiles();
				break;
			case 6:
				createSnapshot();
				break;
			case 7:
				restoreSnapshot();
				break;
			case 8:
				exit(0);
					
			default:
				cout<<"Wrong choice... Try again"<<endl;
		}
		
	}
   return 0;
}

void insertFile(){
	int fileName,capacity;
	cout<<endl<<endl<<"Enter the file Name as an Integer:";
	cin>>fileName;
	insert(fileName);
	cout<<"File was Created successfully !! \n"<<endl<<endl;
}

void listFiles(){
	cout<<"Available files are:";
	traverse(r);
	cout<<endl<<endl;
}

void editFiles(){  //Editing File Content Of the Data
	int fileName;
	string text;
	int capacity;
	cout<<"Enter The File Needed To Be Edited :";
	cin>>fileName;
	cout<<"Enter Text:"<<endl;
	cin>>text;
	fileNameToFileMap mp;
	mp.fileName=fileName;
	mp.s=text;
	mp.size=capacity;
	original.push_back(mp);
	cout<<"File Size is : "<<mp.size;
	cout<<"\nFile edited sucessfully \n"<<endl;
	
}

void copyFiles(){
	int k,newName,capacity;
	cout<<"Enter the file to be copied:";
	cin>>k;
	if(r->search(k)==NULL){
		cout<<"File not found!!"<<endl;
	}
	
	else{
		string temp="";
		cout<<"Enter the new name:";
		cin>>newName;
		insert(newName);
		for(int i=0;i<original.end()-original.begin();i++){
			if(original[i].fileName==k){
				temp=original[i].s;
			}
		}
		fileNameToFileMap mp;
		mp.fileName=newName;
		mp.s=temp;
		mp.size=capacity;
		original.push_back(mp);
		cout<<"File Size is : "<<mp.size;
		cout<<"\n File copied successfully !!! \n"<<endl;
		
	}
	
	cout<<endl;	
}

void viewFiles(){    //Traversing Through the file hierarchy
	int fileName,capacity;
	
	cout<<"Enter The File Name To View Content:"<<endl;
	cin>>fileName;
	if(r->search(fileName)==NULL){
		cout<<"File was not found !!"<<endl;
	}
	else{
		
		for(int i=0;i<original.end()-original.begin();i++){
			if(original[i].fileName==fileName){
				cout<<original[i].s;
			//	cout<<original[i].size();
				break;
			}
		}
		cout<<endl;
	}
	
}
void createSnapshot(){   //Creating a snapshot for clone the file hierarchy
	snapshot.clear();
	for(int i=0;i<original.end()-original.begin();i++){
		int x = original[i].fileName;
		insert2(x);
		fileNameToFileMap temp = original[i];
		snapshot.push_back(temp);
	}
	
	cout<<"Snapshot created !!\n"<<endl;
}

void restoreSnapshot(){
	delete(r);
	r =NULL;                       //When the root file is got deleted it can be backed up by this particular function
	original.clear();
	for(int i=0;i<snapshot.end()-snapshot.begin();i++){
		int x = snapshot[i].fileName;
		insert(x);
		fileNameToFileMap temp = snapshot[i];
		original.push_back(temp);
	}
	
		cout<<"Snapshot Restored Successfully  !!\n"<<endl;
}

