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
//short GetNumberDaysFromBeginYearToEnteredDate(short year, short month, short day)
//{
//	short totalDays = 0;
//
//	for (short i = 1; i <= month - 1; i++)
//		totalDays += GetDaysCountInMonth(year, i);
//
//	return totalDays + day;
//
//}
//int main() 
//{
//	short day = ReadNumber("Please Enter a Day ? ");
//	cout << endl;
//	short month = ReadNumber("Please Enter a Month ? ");
//	cout << endl;
//	short year = ReadNumber("Please Enter a Year ? ");
//	cout << endl;
//
//	cout << "\nNumber of Days from the begining of the year is " << GetNumberDaysFromBeginYearToEnteredDate(year, month, day);
//
//	system("pause > 0");
//
//	return 0;
//}