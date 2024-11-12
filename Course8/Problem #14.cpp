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
//bool IsDate1EqualDate2(stDate date1,stDate date2)
//{
//	return date2.Year == date1.Year && date2.Month == date1.Month && date2.Day == date1.Day;
//}
//
//int main() 
//{
//	stDate date1 = ReadFullDate();
//	cout<<"\n";
//	stDate date2 = ReadFullDate();
//
//	if (IsDate1EqualDate2(date1, date2))
//		cout << "\nYes , Date1 is Equal Date2\n";
//	else
//		cout << "\No , Date1 is Not Equal Date2\n";
//
//	return 0;
//}