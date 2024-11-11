//#include<iostream>
//
//using namespace std;
//
//short ReadYearFromScreen() 
//{
//	cout << "Please enter a your to check ? ";
//	short year;
//	cin >> year;
//	return year;
//}
//
//short ReadMonthFromScreen()
//{
//	cout << "Please enter Month to Check ? ";
//	short month;
//	cin >> month;
//	return month;
//}
//
//bool IsLeapYear(const short& year)
//{
//	return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0 );
//}
//
//int GetDaysFromMonth(short year,short month) 
//{
//	if (month < 1 || month >12)
//		return 0;
//
//	int arrayMonth[]{31,28,31,30,31,30,31,31,30,31,30,31};
//
//	return month == 2 ? (IsLeapYear(year) ? 29 : 28 ) : arrayMonth[month - 1];
//
//}
//
//int main() 
//{
//	short year = ReadYearFromScreen();
//	short month = ReadMonthFromScreen();
//
//	cout << "\nNumber Of Days		in Month[" << month << "] is " << GetDaysFromMonth(year, month) << endl;
//
//	return 0;
//}