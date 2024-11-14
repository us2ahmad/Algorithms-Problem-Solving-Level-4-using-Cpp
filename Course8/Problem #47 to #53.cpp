//#include "DateLib.h"
//
//using namespace DateLib;
//
//void ShowIsDayEndOfWeek(const stDate& date ) 
//{
//	cout << "Is it End Of Week ? \n";
//
//	if (IsEndOfWeek(date))
//		cout << "Yes , it is end of week \n\n";
//	else
//		cout << "No , it is not end of week \n\n";
//
//}
//
//void ShowIsWeekEnd(const stDate& date)
//{
//	cout << "Is it Week End ? \n";
//
//	if (IsWeekEnd(date))
//		cout << "Yes , it is week end \n\n";
//	else
//		cout << "No , it is not week end \n\n";
//}
//
//void ShowIsBusinessDay(const stDate& date)
//{
//	cout << "Is it Business Day? \n";
//
//	if (IsBusinessDay(date))
//		cout << "Yes , it is Business Day \n\n";
//	else
//		cout << "No , it is not Business Day \n";
//}
//
//int main() 
//{
//	stDate date = GetDateNow();
//	
//	printf("Today Is %s , %d/%d/%d\n\n", GetDayName(GetDayOfWeekOrder(date)),date.Day,date.Month,date.Year);
//	
//	ShowIsDayEndOfWeek(date);
//
//	ShowIsWeekEnd(date);
//
//	ShowIsBusinessDay(date);
//
//	printf("Days Until The End Of Week : %d Day(s). \n ", DaysUntilTheEndOfWeek(date));
//
//	printf("Days Until The End Of Month : %d Day(s). \n" ,DaysUntilTheEndOfMonth(date));
//
//	printf("Days Until The End Of Year : %d Day(s). \n ", DaysUntilTheEndOfYear(date));
//
//
//
//	return 0;
//}