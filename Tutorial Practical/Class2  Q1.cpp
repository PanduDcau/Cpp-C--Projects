#include<iostream>
using namespace std;

//class Rectangle;
class Shape
{
	protected:
	float width, height;

	public:
	void set_dimensions (float a, float b)
	{
	width = a;
	height = b;
     }
     
     //friend void Rectangle::showS(Shape &s);
};

class Rectangle: public Shape
{
	protected:
	float Area ()
	{
	return (width * height);
    }
	public :
		//void showS(Shape &);
	void DisplayArea()
	{cout<<Area()<<endl;
      
	}
};

/*void Rectangle::showS(Shape &s)
{
	cout<<s.width + 5<<endl;
}*/

class Triangle: public Shape
{
	private:
	float Area ()
	{
		return (width * height / 2);
	}
	public :
	void DisplayArea()
	{cout<<Area()<<endl;}
};


int main ()
{
	Shape s;
	Rectangle rect;
	Triangle tri;
	//rect.showS(s);
	rect.set_dimensions (10,3.5);
	tri.set_dimensions (3,7);
	rect.DisplayArea();
	tri.DisplayArea();
	return 0;
}
