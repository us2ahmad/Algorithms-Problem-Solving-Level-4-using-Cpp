//#include "DateLib.h"
//using namespace DateLib;
//
//int main() 
//{
//	stDate date = ReadFullDate();
//
//	
//	cout << "Date After : \n";
//	
//	date = IncreaseDateByOneDay(date);
//	cout << "\n01-Adding One Day is : " 
//		<< date.Day << "/" << date.Month << "/"<< date.Year << endl;
//			 
//	date = IncreaseDateByXDays(date,10);
//	cout << "\n02-Adding 10  Days is : " 
//		<< date.Day << "/" << date.Month << "/"<< date.Year << endl;
//	
//	date = IncreaseDateByOneWeek(date);
//	cout << "\n03-Adding One Week is : "
//		<< date.Day << "/" << date.Month << "/"<< date.Year << endl;
//			 
//	date = IncreaseDateByXWeeks(date,10);
//	cout << "\n04-Adding 10  Weeks is : "
//		<< date.Day << "/" << date.Month << "/"<< date.Year << endl;
//	
//	date = IncreaseDateByOneMonth(date);
//	cout << "\n05-Adding One Month is : " 
//		<< date.Day << "/" << date.Month << "/"<< date.Year << endl;
//	
//	date = IncreaseDateByXMonths(date, 5);
//	cout << "\n06-Adding 5   Months is : "
//		<< date.Day << "/" << date.Month << "/"<< date.Year << endl;	
//
//	date = IncreaseDateByOneYear(date);
//	cout << "\n07-Adding One Year is : "
//		<< date.Day << "/" << date.Month << "/"<< date.Year << endl;
//	
//	date = IncreaseDateByXYears(date, 10);
//	cout << "\n08-Adding 10  Years is : "
//		<< date.Day << "/" << date.Month << "/"<< date.Year << endl;
//
//	date = IncreaseDateByXYearsFaster(date, 10);
//	cout << "\n09-Adding 10  Years (Faster) is : " 
//		<< date.Day << "/" << date.Month << "/"<< date.Year << endl;
//			 
//	date = IncreaseDateByOneDecade(date);
//	cout << "\n10-Adding One Decade is : " 
//		<< date.Day << "/" << date.Month << "/"<< date.Year << endl;
//
//	date = IncreaseDateByXDecades(date, 10);
//	cout << "\n11-Adding 10  Decades is : " 
//		<< date.Day << "/" << date.Month << "/"<< date.Year << endl;
//	
//	date = IncreaseDateByXDecadesFaster(date, 10);
//	cout << "\n12-Adding 10  Decades (Faster) is : "
//		<< date.Day << "/" << date.Month << "/"<< date.Year << endl;
//	
//	date = IncreaseDateByOneCentury(date);
//	cout << "\n13-Adding One Century is : " 
//		<< date.Day << "/" << date.Month << "/"<< date.Year << endl;
//	
//	date = IncreaseDateByOneMillennium(date);
//	cout << "\n14-Adding One Millennium is : " 
//		<< date.Day << "/" << date.Month << "/"<< date.Year << endl;
//	
//	system("pause>0");
//	return 0;
//}