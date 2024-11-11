//#include <iostream>
//
//using namespace std;
//
//short ReadNumber(const string& message) 
//{
//	cout << message;
//	short number;
//	cin >> number;
//	return number;
//}
//
//string GetDayName(short day) 
//{
//	string arrayDays[]{"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
//	return arrayDays[day];
//}
//
//short GetDayOrder(short year,short month,short day)
//{
//	short a = (14 - month) / 12;
//	short y = year - a;
//	short m = month + (12 * a) - 2;
//	
//	return (day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
//}
//
//int main() 
//{
//	short year = ReadNumber("Please Enter a Year ? ");
//	cout << endl;
//
//	short month = ReadNumber("Please Enter a Month ? ");
//	cout << endl;
//	
//	short day = ReadNumber("Please Enter a Day ? ");
//	cout << endl;
//	
//	short dayOrder = GetDayOrder(year,month,day);
//
//	printf("Date: %d/%d/%d \n",day,month,year);
//	printf("Day Order: %d \n",dayOrder);
//	printf("Day Name : %s \n",GetDayName(dayOrder).c_str());
//	return 0;
//}
