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
//	int arrayMonth31Days[]{1,3,5,7,8,10,12};
//
//	if (month == 2)
//		return IsLeapYear(year) ? 29 : 28;
//	
//	for (short i = 0; i < 7; i++)
//	{
//		if (arrayMonth31Days[i] == month)
//			return 31;
//	}
//
//	return 30;
//}
//
//int GetHoursFromMonth(short year,short month)
//{
//	return GetDaysFromMonth(year, month) * 24;
//}
//
//int GetMinutesFromMonth(short year, short month)
//{
//	return GetHoursFromMonth(year, month) * 60;
//
//}
//
//int GetSecondsFromMonth(int year, short month)
//{
//	return GetMinutesFromMonth(year, month) * 60;
//}
//
//int main() 
//{
//	short year = ReadYearFromScreen();
//	short month = ReadMonthFromScreen();
//
//	cout << "\nNumber Of Days		in Month[" << month << "] is " << GetDaysFromMonth(year, month) << endl;
//	cout << "Number Of Hours		in Month[" << month << "] is " << GetHoursFromMonth(year, month) << endl;
//	cout << "Number Of Minutes	in Month[" << month << "] is " << GetMinutesFromMonth(year, month) << endl;
//	cout << "Number Of Seconds	in Month[" << month << "] is " << GetSecondsFromMonth(year, month) << endl;
//
//	return 0;
//}