//#include <iostream>
//#include <string>
//#include <vector>
//#include <fstream>
//
//using namespace std;
//
//void ATMMainMenuScreen();
//void Login();
//void ShowQuickWithdrawScreen();
//void ShowNormalWithDrawScreen();
//const string gFilePath = "C:\\Users\\ahmad\\Desktop\\ClientData.txt";
//
//struct stClient 
//{
//	string AccountNumber = "";
//	string PinCode= "";
//	string Name = "";
//	string PhoneNumber = "";
//	double Balance= 0.0;
//};
//
//stClient CurrentClient;
//
//enum enATMMainMenu 
//{
//	eQuickWithdraw = 1,
//	eNormalWithdraw = 2,
//	eDeposit = 3,
//	eCheckBalance= 4,
//	eLogout=5
//};
//
//
//vector<string> SplitString(string text, string delim = " ")			
//{
//	vector<string> vWords;
//	short pos = 0;
//	string sWord = "";
//
//	while ((pos = text.find(delim)) != string::npos)
//	{
//		sWord = text.substr(0, pos);
//
//		if (sWord != "")
//			vWords.push_back(sWord);
//
//		text.erase(0, pos + delim.length());
//	}
//
//	if (text != "" && !vWords.empty())
//		vWords.push_back(text);
//
//	return vWords;
//}
//
//stClient ConvertClientLineToRecord(string line, string seperator = "#//#")		
//{
//	vector<string> record = SplitString(line, seperator);
//	stClient client;
//
//	if (!record.empty())
//	{
//		client.AccountNumber = record[0];
//		client.PinCode = record[1];
//		client.Name = record[2];
//		client.PhoneNumber = record[3];
//		client.Balance = stod(record[4]);
//	}
//
//	return client;
//}
//
//string 	ConvertClientRecordToLine(stClient client, string seperator = "#//#")
//{
//	string clientLine = "";
//
//	clientLine += client.AccountNumber + seperator;
//	clientLine += client.PinCode + seperator;
//	clientLine += client.Name + seperator;
//	clientLine += client.PhoneNumber + seperator;
//	clientLine += to_string (client.Balance);
//
//	return clientLine;
//}
//
//vector<stClient> LoadClientsFromFile(const string& filePath) 
//{
//	fstream myFile;
//	vector<stClient> vClient;
//
//	myFile.open(filePath,ios::in);
//
//	if (myFile.is_open()) 
//	{
//		string line = "";
//
//		while (getline(myFile,line))
//		{
//			vClient.push_back(ConvertClientLineToRecord(line));
//		}
//	
//		myFile.close();
//	}
//
//	return vClient;
//}
//
//void SaveClientDataInFile(string gFilePath,stClient currentClient)
//{
//	vector<stClient> vClients = LoadClientsFromFile(gFilePath);
//
//	fstream MyFile;
//	MyFile.open(gFilePath, ios::out);
//	string DataLine;
//	if (MyFile.is_open())
//	{
//		for (stClient& client : vClients)
//		{
//			if (client.AccountNumber == currentClient.AccountNumber)
//				client = currentClient;
//
//			MyFile << ConvertClientRecordToLine(client) << endl;
//		}
//
//		MyFile.close();
//	}
//}
//
//void GoBackToATMMainMenue()
//{
//	cout << "\n\nPress any key to go back to ATM Main Menue...";
//	system("pause>0");
//	ATMMainMenuScreen();
//}
//
//#pragma region QuickWithdraw
//
//void DepositBalanceToClient(double Amount)
//{
//	char Answer = 'n';
//	cout << "\n\nAre you sure you want perfrom this transaction? y / n ? ";
//	cin >> Answer;
//	if (Answer == 'y' || Answer == 'Y')
//	{
//		CurrentClient.Balance += Amount;
//		SaveClientDataInFile(gFilePath, CurrentClient);
//		cout << "\n\nDone Successfully. New balance is: " << to_string(CurrentClient.Balance);
//	}
//}
//
//short ReadQuickWithdrawOption()
//{
//	short Choice = 0;
//	while (Choice < 1 || Choice>9)
//	{
//		cout << "\nChoose what to do from [1] to [9] ? ";
//		cin >> Choice;
//	}
//	return Choice;
//}
//
//int GetQuickWithDrawAmount(short choice)
//{
//	int arr[]{20,50,100,200,400,600,800,1000};
//	return arr[choice - 1];
//}
//
//void PerfromQuickWithdrawOption(short quickWithdrawOption) 
//{
//	if (quickWithdrawOption == 9)
//		return;
//	int ammount = GetQuickWithDrawAmount(quickWithdrawOption);
//	
//	if (ammount > CurrentClient.Balance)
//	{
//		cout << "\nThe amount exceeds your balance, make another choice.\n";
//		cout << "Press Anykey to continue...";
//		system("pause>0");
//		ShowQuickWithdrawScreen();
//		return;
//	}
//	DepositBalanceToClient(-1 * ammount);
//}
//
//void ShowQuickWithdrawScreen()
//{
//	system("cls");
//	cout << "===========================================\n";
//	cout << "\t\tQucik Withdraw\n";
//	cout << "===========================================\n";
//	cout << "\t[1] 20\t\t[2] 50\n";
//	cout << "\t[3] 100\t\t[4] 200\n";
//	cout << "\t[5] 400\t\t[6] 600\n";
//	cout << "\t[7] 800\t\t[8] 1000\n";
//	cout << "\t[9] Exit\n";
//	cout << "===========================================\n";
//	cout << "Your Balance is " << to_string(CurrentClient.Balance);
//	PerfromQuickWithdrawOption(ReadQuickWithdrawOption());
//}
//#pragma endregion
//
//#pragma region NormalWithdraw
//
//int ReadWithdrawAmmount()
//{
//	int Amount;
//	cout << "\nEnter an amount multiple of 5's ? ";
//	cin >> Amount;
//	while (Amount % 5 != 0)
//	{
//		cout << "\nEnter an amount multiple of 5's ? ";
//		cin >> Amount;
//	}
//	return Amount;
//}
//
//void PerfromNormalWithdrawOption()
//{
//	int ammount = ReadWithdrawAmmount();
//	if (ammount > CurrentClient.Balance)
//	{
//		cout << "\nThe amount exceeds your balance, make another choice.\n";
//		cout << "Press Anykey to continue...";
//		system("pause>0");
//		ShowNormalWithDrawScreen();
//		return;
//	}
//	
//	DepositBalanceToClient(-1 * ammount);
//}
//
//void ShowNormalWithDrawScreen() 
//{
//	system("cls");
//	cout << "================================\n";
//	cout << "\tNormal Withdraw Screen\n";
//	cout << "================================\n";
//	PerfromNormalWithdrawOption();
//}
//#pragma endregion
//
//#pragma region Deposit
//
//double ReadDepositAmmount()
//{
//	double Amount;
//	cout << "\nEnter a positive Deposit Amount? ";
//	cin >> Amount;
//	while (Amount <= 0)
//	{
//		cout << "\nEnter a positive Deposit Amount? ";
//		cin >> Amount;
//	}
//	return Amount;
//}
//
//void PerfromDepositOption()
//{
//	double ammount = ReadDepositAmmount();
//	DepositBalanceToClient(ammount);
//}
//
//void ShowDepositScreen()
//{
//	system("cls");
//	cout << "===========================================\n";
//	cout << "\t\tDeposit Screen\n";
//	cout << "===========================================\n";
//	PerfromDepositOption();
//}
//
//#pragma endregion
//
//#pragma region CheckBalance
//
//void ShowCheckBalanceScreen()
//{
//	system("cls");
//	cout << "=============================\n";
//	cout << "\tCheck Balance Screen\n";
//	cout << "=============================\n";
//	cout <<"Your Balance is " << to_string(CurrentClient.Balance) <<endl;
//}
//
//#pragma endregion
//
//void PerformATMMainMenuOption(enATMMainMenu ATMMainMenuOption)
//{
//	switch (ATMMainMenuOption)
//	{
//	case eQuickWithdraw:
//		ShowQuickWithdrawScreen();
//		GoBackToATMMainMenue();
//		break;
//	case eNormalWithdraw:
//		ShowNormalWithDrawScreen();
//		GoBackToATMMainMenue();
//		break;
//	case eDeposit:
//		ShowDepositScreen();
//		GoBackToATMMainMenue();
//		break;
//	case eCheckBalance:
//		ShowCheckBalanceScreen();
//		GoBackToATMMainMenue();
//		break;
//	case eLogout:
//		Login();
//		break;
//	default:
//		break;
//	}
//}
//
//enATMMainMenu  ReadATMMainMenueOption()
//{
//	cout << "Choose what do you want to do? [1 to 5]? ";
//	short Choice = 0;
//	cin >> Choice;
//	return enATMMainMenu(Choice);
//}
//
//void ATMMainMenuScreen() 
//{
//	system("cls");
//	cout << "===========================================\n";
//	cout << "\t\tATM Main Menue Screen\n";
//	cout << "===========================================\n";
//	cout << "\t[1] Qiuck Withdraw.\n";
//	cout << "\t[2] Normal Withdraw.\n";
//	cout << "\t[3] Deposit.\n";
//	cout << "\t[4] Check Balance.\n";
//	cout << "\t[5] Logout.\n";
//	cout << "===========================================\n";
//	PerformATMMainMenuOption(ReadATMMainMenueOption());
//}
//
//bool FindClientByAccountNumberAndPinCode(const string& accountNumber,const string& pinCode,stClient& currentClient)
//{
//	vector<stClient> vClients = LoadClientsFromFile(gFilePath);
//
//	for (stClient client : vClients)
//	{
//		if (client.AccountNumber == accountNumber && client.PinCode == pinCode)
//		{
//			currentClient = client;
//			return true;
//		}
//	}
//	return false;
//}
//
//void Login() 
//{
//	
//	string accountNumber, pinCode;
//	bool LoginFaild = false;
//	do
//	{
//		system("cls");
//		cout << "--------------------------\n";
//		cout << "Login Screen\n";
//		cout << "--------------------------\n";
//		if (LoginFaild)
//			cout << "Invlaid Username/Password!\n";
//
//		cout << "Enter Account Number ? ";
//		getline(cin >> ws, accountNumber);
//	
//		cout << "Enter PinCode ? ";
//		getline(cin >> ws, pinCode);
//
//		LoginFaild = !FindClientByAccountNumberAndPinCode(accountNumber, pinCode, CurrentClient);
//	} while (LoginFaild);
//	
//	ATMMainMenuScreen();
//}
//
//int main() 
//{
//	Login();
//	return 0;
//}
//
//
//
