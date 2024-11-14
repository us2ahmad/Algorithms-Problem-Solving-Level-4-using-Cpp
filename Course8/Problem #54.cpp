//#include "DateLib.h"
//
//using namespace DateLib;
//
//int main() 
//{
//	cout << "Vacation Sarts:\n";
//	stDate fromDate = ReadFullDate();
//
//	cout << "\nVacation Ends:\n";
//	stDate toDate = ReadFullDate();
//	
//	printf("\nVacation From : %s , %d/%d/%d\n\n", GetDayName(GetDayOfWeekOrder(fromDate)).c_str(), fromDate.Day, fromDate.Month, fromDate.Year);
//
//	printf("Vacation To : %s , %d/%d/%d\n\n", GetDayName(GetDayOfWeekOrder(toDate)).c_str(), toDate.Day, toDate.Month, toDate.Year);
//
//	printf("Actual Vacation Days is : %d\n", CalculateVacationDays(fromDate, toDate));
//	
//	return 0;
//}