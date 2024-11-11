//#include <iostream>
//#include <string>
//
//using namespace std;
//
//long long int ReadNumber()
//{
//	cout << "Enter a Number ? ";
//	int number = 0;
//	cin >> number;
//	return number;
//}
//
//string Numbers[] = { "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine" 
//					,"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };
//
//string Numbers2[] =  {"","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
//
//string NumberToText(long long int number)
//{
//	if (number == 0)
//		return "";
//
//	if (number >= 1 && number <= 19)
//		return Numbers[number] + " ";
//
//	if (number >= 20 && number <= 99)
//		return Numbers2[number / 10] + " " + NumberToText(number % 10);
//
//	if (number >= 100 && number <= 199)
//		return "One Hundred " + NumberToText(number % 100);
//	
//	if (number >= 200 && number <= 999)
//		return NumberToText(number / 100) + " Hundred " + NumberToText(number % 100);
//
//	if (number >= 1000 && number <= 1999)
//		return  "One Thousand " + NumberToText(number % 1000);
//
//	if (number >= 2000 && number <= 999999)
//		return  NumberToText(number / 1000) + " Thousand " + NumberToText(number % 1000);
//
//	if (number >= 1000000 && number <= 1999999)
//		return  "One Million " + NumberToText(number % 1000000);
//
//	if (number >= 2000000 && number <= 999999999)
//		return NumberToText(number /1000000) + " Million " + NumberToText(number % 1000000);
//	
//	if(number >= 1000000000 && number <= 1999999999 )
//		return  "One Billion " + NumberToText(number % 1000000000);
//	
//	else 
//		return NumberToText(number / 1000000000) + " Billion " + NumberToText(number % 1000000000);
//
//}
//
//int main() 
//{
//
//	string number = NumberToText(ReadNumber());
//
//	cout << number;
//
//	return 0;
//}