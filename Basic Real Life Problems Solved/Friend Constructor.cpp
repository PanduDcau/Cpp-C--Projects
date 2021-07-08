#include<iostream>
#include<iomanip>
using namespace std;

class Date
{
	private:
		int month;
		int day;
		int year;
	public:
	    Date(int = 3,int = 14 ,int = 2006);
		Date(const Date&);
		void showdate();	
};

Date::Date(int mm ,int dd ,int yyyy)
{
	month =mm;
	day = dd;
	year = yyyy;
}

Date::Date(const Date& olddate)
{
  month = olddate.month;
  day = olddate.day;
  year = olddate.year;

}

void Date::showdate()
{
	cout<<"The Day is "<<setfill('0')<<setw(2)<<month<<'/'<<setw(2)<<day<<'/'<<setw(4)<<year
	<<endl;
	return;
}
int main(void)
{
	Date a(4,1,1998), b (6,1,2001);
	Date c(a);
	Date d=b;
	cout << "\nThe date stored in a is ";
  a.showdate();
  cout << "\nThe date stored in b is ";
  b.showdate();
  cout << "\nThe date stored in c is ";
  c.showdate();
  cout << "\nThe date stored in d is ";
  d.showdate();

	return 0;
}

