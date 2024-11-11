//#include <iostream>
//using namespace std;
//
//short ReadNumber(const string& message) 
//{
//	printf( message.c_str());
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
//void PrintCalendarMonth(short year,short month) 
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
//void PrintCalendarYear(short year)
//{
//	printf("\n-----------------------------------------\n");
//	printf("\t  Calendar - %d\n",year);
//
//	printf("\n-----------------------------------------\n");
//	for (short i = 1; i <= 12; i++)
//	{
//		printf("\n");
//		PrintCalendarMonth(year, i);
//		printf("\n");
//	}
//}
//
//int main() 
//{
//	PrintCalendarYear(ReadNumber("Please Enter a Year ? "));
//	system("pause > 0");
//	return 0;
//}