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
//bool IsLeapYear(const short& year)
//{
//	return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0 );
//}
//
//int GetDaysFromYear(short year) 
//{
//	return IsLeapYear(year) ? 366 : 365 ;
//}
//
//int GetHoursFromYear(short year) 
//{
//	return GetDayFromYear(year) * 24;
//}
//
//int GetMinutesFromYear(short year)
//{
//	return GetHoursFromYear(year) * 60;
//
//}
//
//int GetSecondsFromYear(int minutes)
//{
//	return GetMinutesFromYear(minutes) * 60;
//}
//
//int main() 
//{
//	short year = ReadYearFromScreen();
//
//	cout << "\nNumber Of Days		in Year[" << year << "] is " << GetDaysFromYear(year) << endl;
//	cout << "Number Of Hours		in Year[" << year << "] is " << GetHoursFromYear(year) << endl;
//	cout << "Number Of Minutes	in Year[" << year << "] is " << GetMinutesFromYear(year) << endl;
//	cout << "Number Of Seconds	in Year[" << year << "] is " << GetSecondsFromYear(year) << endl;
//
//	return 0;
//}