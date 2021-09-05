#include <iostream.h>  
#include <conio.h>  
#include <graphics.h>  
#include <dos.h>  
class data  
{  
    int gd, gmode, x, y, xmin,ymin,ymax,xmax;  
    int a1,a2;  
    float x1, y1,x2,y2,x3,y3;  
    int xs, ys, xe, ye;  
    float maxx,maxy;  
    public:  
        void getdata ();  
        void find ();  
        void clip ();  
        void display (float, float,float,float);  
        void checkonof (int);  
        void showbit (int);  
};  
void data :: getdata ()  
{  
    cout<<"Enter the minimum and maximum coordinate of window (x, y) ";  
           cin >>xmin>>ymin>>xmax>>ymax;  
           cout<<"Enter the end points of the line to be clipped";  
           cin >>xs>>ys>>xe>>ye;  
           display (xs, ys, xe,ye);  
}  
void data :: display (float, xs, float, ys,float xe, float ye)  
{  
    int gd=DETECT;  
    initgraph (&gd,&gmode, "");  
    maxx=getmaxx();  
    maxy=getmaxy();  
    line (maxx/2,0,maxx/2,maxy);  
    line (0, maxy/2,maxx,maxy/2);  
    rectangle (maxx/2+xmin,maxy/2-ymax,maxx/2+xmax,maxy/2-ymin);  
    line (maxx/2+xs,maxy/2-ys,maxx/2+xe,maxy/2-ye);  
    getch();  
}  
void data :: find ()  
{  
    a1=0;  
    a2=0;  
    if ((ys-ymax)>0)  
               a1+=8;  
    if ((ymin-ys)>0)  
        a1+=4;  
    if ((xs-xmax)>0)  
         a1+=2;  
            if ((xmin-xs)>0)  
         a1+=1;  
     if ((ye-ymax)>0)  
        a2+=8;  
           if ((ymin-ye)>0)  
              a2+=4;  
          if ((xe-xmax)>0)  
               a2+=2;  
          if ((xmin-xe)>0)  
                a2+=1;  
         cout<<"\nThe area code of Ist point is ";  
                 showbit (a1);  
         getch ();  
         cout <<"\nThe area code of 2nd point is ";  
         showbit (a2);  
         getch ();  
}  
void data :: showbit (int n)  
{  
        int i,k, and;  
        for (i=3;i>=0;i--)  
        {  
              and =1<<i;  
       k = n?  
       k ==0?cout<<"0": cout<<"1\"";           
          }  
}  
void data ::clip()  
{  
         int j=a1&a2;  
         if (j==0)  
         {  
              cout<<"\nLine is perfect candidate for clipping";  
              if (a1==0)  
       {  
                    else  
             {  
                   checkonof(a1);  
                   x2=x1;y2=y1;  
             }  
             if (a2=0)  
            {  
                 x3=xe; y3=ye;  
            }  
           else  
           {  
                   checkonof (a2);  
                   x3=x1; y3=y1;  
            }  
            xs=x2; ys=y2;xe=x3;ye=y3;  
            cout << endl;  
            display (xs,ys,xe,ye);  
            cout<<"Line after clipping";  
            getch ()  
          }  
       else if ((a1==0) && (a2=0))  
       {  
               cout <<"\n Line is in the visible region";  
               getch ();  
       }  
}  
void data :: checkonof (int i)  
{  
      int j, k,l,m;  
      1=i&1;  
      x1=0;y1=0;  
       if (1==1)  
      {  
             x1=xmin;  
             y1=ys+ ((x1-xs)/ (xe-xs))*(ye-ys);  
      }  
      j=i&8;  
   if (j>0)  
   {  
             y1=ymax;  
      x1=xs+(y1-ys)/(ye-ys))*(xe-xs);  
    }  
    k=i & 4;  
    if (k==1)  
    {  
           y1=ymin;  
           x1=xs+((y1-ys)/(ye-ys))*(xe-xs);  
    }  
    m= i&2;  
     if (m==1)  
     {  
            x1=xmax;  
            y1=ys+ ((x1-xs)/ (xe-xs))*(ye-ys);  
      }  
      main ()  
      {  
             data s;  
             clrscr();  
             s.getdata();  
             s.find();  
             getch();  
             closegraph ();  
             return ();  
    }  
