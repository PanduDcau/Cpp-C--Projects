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
		Date(long);
		void showdate();	
};

Date::Date(int mm ,int dd ,int yyyy)
{
	month =mm;
	day = dd;
	year = yyyy;
	cout << "Created a new data Object with data Values "<< month<<", "<<day<<", "<<year << endl;
}

Date::Date(long yyyymmdd)
{
	year = int(yyyymmdd/10000.0);
	month = int((yyyymmdd -year*10000.0)/100.00);
	day = int(yyyymmdd -year*10000.0 -month*100.0);
}

void Date::showdate()
{
	cout<<"The Day is "<<setfill('0')<<setw(2)<<month<<'/'<<setw(2)<<day<<'/'<<setw(2)<<year
	<<endl;
	return;
}
int main(void)
{
	Date a, b (4,1,1998),c(20010515l);
	a.showdate();
	b.showdate();
	c.showdate();
	return 0;
}

