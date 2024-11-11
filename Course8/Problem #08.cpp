//#include <iostream>
//using namespace std;
//
//short ReadNumber(const string& message) 
//{
//	cout << message;
//	short number;
//	cin >> number;
//	return number;
//}
//
//string GetMonthName(short month)
//{
//	
//	string arrayMonth[]{ "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov",  "Dec" };
//	return arrayMonth[month - 1];
//}
//
//bool IsLeapYear(short year) 
//{
//	return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
//}
//
//short GetDaysCountInMonth(short year,short month)
//{
//	if (month < 1 || month >12)
//		return 0;
//
//	short arrayNumberDaysInMonth[]{31,28,31,30,31,30,31,31,30,31,30,31};
//
//	return month == 2 && IsLeapYear(year) ? 29 : arrayNumberDaysInMonth[month - 1];
//}
//
//short GetDayOrderInMonth(short year, short month, short day = 1)
//{
//	short a = (14 - month) / 12;
//	short y = year - a;
//	short m = month + (12 * a) - 2;
//
//	return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
//}
//
//void PrintCalender(short year,short month) 
//{
//	short firstDayOrderInMonth = GetDayOrderInMonth(year,month);
//	short countDaysInMonth = GetDaysCountInMonth(year,month);
//
//	printf("\n-------------------%s-------------------\n", GetMonthName(month).c_str());
//	printf("\n  Sun  Mon  Tue  Wed  Thu  Fri  Sat \n");
//	
//	short i = 0;
//	for (i = 0; i < firstDayOrderInMonth; i++)
//		printf("     ");
//	
//	for (short j = 1; j <= countDaysInMonth; j++)
//	{ 
//		printf("%5d", j);
//		if (++i == 7)
//		{
//			i = 0;
//			printf("\n");
//		}
//	}
//
//	printf("\n-----------------------------------------\n");
//
//}
//
//int main() 
//{
//
//	short year = ReadNumber("Please Enter a Year ? ");
//	cout << endl;
//	short month = ReadNumber("Please Enter a Month ? ");
//	PrintCalender(year,month);
//	return 0;
//}