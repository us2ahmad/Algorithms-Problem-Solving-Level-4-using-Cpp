//#include "DateLib.h"
//
//using namespace DateLib;
//
//int main() 
//{
//	stDate date = ReadFullDate();
//
//	cout << "Date After : \n";
//	
//	date = DecreaseDateByOneDay(date);
//	cout << "\n01-Subtracting One Day is : " 
//		<< date.Day << "/" << date.Month << "/"<< date.Year << endl;
//			 
//	date = DecreaseDateByXDays(date,10);
//	cout << "\n02-Subtracting 10  Days is : " 
//		<< date.Day << "/" << date.Month << "/"<< date.Year << endl;
//	
//	date = DecreaseDateByOneWeek(date);
//	cout << "\n03-Subtracting One Week is : "
//		<< date.Day << "/" << date.Month << "/"<< date.Year << endl;
//			 
//	date = DecreaseDateByXWeeks(date,10);
//	cout << "\n04-Subtracting 10  Weeks is : "
//		<< date.Day << "/" << date.Month << "/"<< date.Year << endl;
//	
//	date = DecreaseDateByOneMonth(date);
//	cout << "\n05-Subtracting One Month is : " 
//		<< date.Day << "/" << date.Month << "/"<< date.Year << endl;
//	
//	date = DecreaseDateByXMonths(date, 5);
//	cout << "\n06-Subtracting 5   Months is : "
//		<< date.Day << "/" << date.Month << "/"<< date.Year << endl;	
//
//	date = DecreaseDateByOneYear(date);
//	cout << "\n07-Subtracting One Year is : "
//		<< date.Day << "/" << date.Month << "/"<< date.Year << endl;
//	
//	date = DecreaseDateByXYears(date, 10);
//	cout << "\n08-Subtracting 10  Years is : "
//		<< date.Day << "/" << date.Month << "/"<< date.Year << endl;
//
//	date = DecreaseDateByXYearsFaster(date, 10);
//	cout << "\n09-Subtracting 10  Years (Faster) is : " 
//		<< date.Day << "/" << date.Month << "/"<< date.Year << endl;
//			 
//	date = DecreaseDateByOneDecade(date);
//	cout << "\n10-Subtracting One Decade is : " 
//		<< date.Day << "/" << date.Month << "/"<< date.Year << endl;
//
//	date = DecreaseDateByXDecades(date, 10);
//	cout << "\n11-Subtracting 10  Decades is : " 
//		<< date.Day << "/" << date.Month << "/"<< date.Year << endl;
//	
//	date = DecreaseDateByXDecadesFaster(date, 10);
//	cout << "\n12-Subtracting 10  Decades (Faster) is : "
//		<< date.Day << "/" << date.Month << "/"<< date.Year << endl;
//	
//	date = DecreaseDateByOneCentury(date);
//	cout << "\n13-Subtracting One Century is : " 
//		<< date.Day << "/" << date.Month << "/"<< date.Year << endl;
//	
//	date = DecreaseDateByOneMillennium(date);
//	cout << "\n14-Subtracting One Millennium is : " 
//		<< date.Day << "/" << date.Month << "/"<< date.Year << endl;
//	
//	system("pause>0");
//	return 0;
//}