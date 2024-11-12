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
//stDate IncreaseDateByOneDay(stDate date) 
//{
//	if (IsLastDayInMonth(date))
//	{
//		if (IsLastMonthInYear(date.Month))
//		{
//			date.Month = 1;
//			date.Year++;
//		}
//		else
//			date.Month++;
//		
//		date.Day = 1;
//	}
//	else
//		date.Day++;
//
//	return date;
//}
//
//bool IsDate1EqualDate2(stDate date1,stDate date2)
//{
//	return date2.Year == date1.Year && date2.Month == date1.Month && date2.Day == date1.Day;
//}
//
//bool IsDate1BeforeDate2(stDate date1,stDate date2)
//{
//	return date2.Year > date1.Year ? true : (date2.Year == date1.Year ? date2.Month > date1.Month ? true : ( date2.Month == date1.Month ? date2.Day > date1.Day : false ): false);
//}
//
//void SwapDate(stDate &date1, stDate &date2) 
//{
//	stDate temp;
//	temp = date1;
//	date1 = date2;
//	date2 = temp;
//}
//
//short GetDifferenceInDays(stDate date1, stDate date2, bool includingEndDay = false) 
//{
//	short days = 0;
//	short swapFlagValue = 1;
//
//	if (!IsDate1BeforeDate2(date1, date2)) 
//	{
//		swapFlagValue = -1;
//		SwapDate(date1, date2);
//	}
//
//	while (!IsDate1EqualDate2(date1,date2))
//	{
//		date1 = IncreaseDateByOneDay(date1);
//		days++;
//	}
//	return  (includingEndDay ? ++days : days) *swapFlagValue;
//}
//
//int main() 
//{
//	stDate date1 = ReadFullDate();
//	cout << endl;
//	stDate date2 = ReadFullDate();
//
//	cout << "\nDiffrence is: " << GetDifferenceInDays(date1, date2) << " Day(s).\n";
//
//	cout << "\nDiffrence (Including End Day) is: "<< GetDifferenceInDays(date1, date2, true) << " Day(s).\n";
//
//	system("pause>0");
//	return 0;
//}