/*#include<iostream>
using namespace std;
class Vehicle
{
 public :
 Vehicle(){cout<<"In Vehicle constructor"<<endl;}
 void display(){cout<<"members of Vehicle\n";}
};

class HeavyVehicle : public Vehicle
{
 public:
 HeavyVehicle(){cout<<"In HeavyVehicle constructor"<<endl;}
 void display(){cout<<"members of HeavyVehicle\n";}
};

class Bus : public HeavyVehicle
{
 public :
 Bus(){cout<<"In Bus constructor"<<endl;}
 void display(){cout<<"members of Bus\n";}
};

int main()
{
Bus bus1,bus2;
bus1.display();
bus2.display();
return 0;
 }*/
 
 
 #include <iostream>
 using namespace std;
 class number
 {
 int num;
 public :
 number(){num=1000;}
 number(int x){num=x;}
 int getnumber(){return(num);}
 int magic()
 {
 int i,j,k,m,x,y;
 for (i=1;i<=9;i++)
 for (j=0;j<=9;j++)
 
 for (k=0;k<=9;k++)
 for (m=0;m<=9;m++)
 {
 x=i*1000+j*100+k*10+m;
 y=m*1000+k*100+j*10+i;
 if (y==(x*9))
 return x;
 }return (0);
 }
 };

 int main()
 {
 class number n1,n2(1069),n3(1098);
 int x,y;
 y=n1.magic();
 cin>>x;
 if (n1.getnumber()==y) cout<<"Correct"<<n1.getnumber(); else
cout<<"Wrong"<<n1.getnumber()<<endl;
 if (n2.getnumber()==y) cout<<"Correct"<<n2.getnumber(); else
cout<<"Wrong"<<n2.getnumber()<<endl;
 if (n3.getnumber()==y) cout<<"Correct"<<n3.getnumber(); else
cout<<"Wrong"<<n3.getnumber()<<endl;
 if (x==y) cout<<"Correct"<<x; else
 cout<<"Wrong"<<endl;
 return 0;
 } 
