//#include <iostream>
// 
//using namespace std;
//
//short ReadYearFromScreen() 
//{
//	short year;
//	cout << "Please Enter Year ? ";
//	cin >> year;
//	return year;
//}
//
//bool IsLeapYear(int year) 
//{
//	if (year % 400 == 0)
//		return true;
//	
//	if (year % 4 == 0 && year % 100 != 0)
//		return true;
//
//	return false;
//}
//
//int main() 
//{
//	short year = ReadYearFromScreen();
//	
//	if(IsLeapYear(year))
//		cout << "\nYes, Year [" << year << "] is a leap year.\n";
//	else
//		cout << "\nNo, Year [" << year << "] is NOT a leap year.\n";
//
//	return 0;
//}