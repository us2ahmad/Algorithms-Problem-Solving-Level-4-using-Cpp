//#include <iostream>
//using namespace std;
//
//struct stDate 
//{
//	short Year;
//	short Month;
//	short Day;
//};
//
//short ReadNumber(const string& message) 
//{
//	printf( message.c_str());
//	short number;
//	cin >> number;
//	return number;
//}
//
//stDate ReadFullDate() 
//{
//	stDate date;
//	date.Day = ReadNumber("Please Enter a Day ? ");
//	cout << endl;
//	date.Month = ReadNumber("Please Enter a Month ? ");
//	cout << endl;
//	date.Year = ReadNumber("Please Enter a Year ? ");
//	cout << endl;
//
//	return date;
//}
//
//bool IsLeapYear(short year) 
//{
//	return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
//}
//
//short GetDaysNumberInMonth(short year, short month) 
//{
//	if (month < 1 || month>12)
//		return 0;
//
//	short daysNumberInMonth[]{31,28,31,30,31,30,31,31,30,31,30,31};
//
//	return month == 2 && IsLeapYear(year) ? 29 : daysNumberInMonth[month - 1];
//}
//
//bool IsLastDayInMonth(stDate date) 
//{
//	return GetDaysNumberInMonth(date.Year, date.Month) == date.Day;
//}
//
//bool IsLastMonthInYear(short month) 
//{
//	return month == 12;
//}
//
//int main() 
//{
//	stDate date = ReadFullDate();
//	
//	if (IsLastDayInMonth(date))
//		cout << "Yes, Day Is Last Day in Month\n";
//	else
//		cout << "No, Day Is Not Last Day in Month\n";
//
//	if (IsLastMonthInYear(date.Month))
//		cout << "Yes, Month Is Last Month in Year\n";
//	else
//		cout << "No, Month Is Not Last Month in Year\n";
//
//	return 0;
//}