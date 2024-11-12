//#include <iostream>
//#include <ctime>
//
//#pragma warning(disable: 4996)
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
//stDate GetDateNow()
//{
//	stDate date;
//	time_t t = time(0);
//
//	tm* now = localtime(&t);
//	
//	date.Day = now->tm_mday;
//	date.Month = now->tm_mon+1;
//	date.Year = now->tm_year+1900;
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
//short GetDifferenceInDays(stDate date1, stDate date2, bool includingEndDay = false) 
//{
//	short days = includingEndDay ? 1 : 0;
//
//	while (!IsDate1EqualDate2(date1,date2))
//	{
//		date1 = IncreaseDateByOneDay(date1);
//		days++;
//	}
//	return days;
//}
//
//int main() 
//{
//	cout << "Please Enter Your Date Of Birth : \n";
//	stDate dateOfBirth = ReadFullDate();
//	cout << endl;
//	stDate date2 = GetDateNow();
//
//	cout << "\Your Age  is : " << GetDifferenceInDays(dateOfBirth, date2,true) << " Day(s).\n";
//
//
//	system("pause>0");
//	return 0;
//}