//#pragma once
//#include <iostream> 
//#include <string> 
//#include <vector> 
//#include <fstream> 
//#include <iomanip> 
//
//using namespace std;
//
//namespace HelperLib		 // HelperLib ( Project 1 - Bank1(My Solution))
//{
//#pragma region Structures
//	struct stClient			// »‰Ì… «·⁄„Ì· 
//	{
//		string accountNumber = "";
//		string pinCode = "";
//		string name = "";
//		string phoneNumber = "";
//		double accountBalance = 0.0;
//		bool IsDeleted = false;
//	};
//
//#pragma endregion
//
//#pragma region Enums
//
//	enum  enChooseMainMenu			// ·„⁄—›… «·ŒÌ«—«  «·Ÿ«Â—… ··„” Œœ„ ›Ì «·‘«‘… «·—∆Ì”Ì…
//	{
//		eShowClientList = 1,
//		eAddNewClient = 2,
//		eDeleteClient = 3,
//		eUpdateClientInfo = 4,
//		eFindClient = 5,
//		eTransactions = 6,
//		eManageUser = 7,
//		eLogout =8
//	};
//
//	enum enChooseTransactionMenu
//	{
//		eDeposit = 1 ,
//		eWithdraw = 2 ,
//		eTotalBalances = 3,
//		eMainMenu = 4
//	};
//
//#pragma endregion
//
//#pragma region BasicCodes
//
//	vector<string> SplitString(string text, string delim = " ")			// · Ã“∆… «·‰’ ≈·Ï ⁄œ… ﬂ·„«  Õ”» «·›«’· «·„—«œ 
//	{
//		vector<string> vWords;
//		short pos = 0;
//		string sWord = "";
//
//		while ((pos = text.find(delim)) != string::npos)
//		{
//			sWord = text.substr(0, pos);
//
//			if (sWord != "")
//				vWords.push_back(sWord);
//
//			text.erase(0, pos + delim.length());
//		}
//
//		if (text != "" && !vWords.empty())
//			vWords.push_back(text);
//
//		return vWords;
//	}
//	
//	stClient ConvertClientLineToRecord(string line, string seperator = "#//#")		// · ÕÊÌ· «·”ÿ— „‰ «·„·› «·Ï »‰Ì… «·⁄„Ì· 
//	{
//		vector<string> record = SplitString(line, seperator);
//		stClient client;
//
//		if (!record.empty())
//		{
//			client.accountNumber = record[0];
//			client.pinCode = record[1];
//			client.name = record[2];
//			client.phoneNumber = record[3];
//			client.accountBalance = stod(record[4]);
//		}
//
//		return client;
//	}
//
//	vector<stClient> LoadDataClientFromFile(const string& filePath)		// · Õ„Ì· «·»Ì«‰«  „‰ «·„·› 
//	{
//		vector<stClient> clients;
//		fstream myFile;
//		myFile.open(filePath, ios::in);
//
//		if (myFile.is_open())
//		{
//			string line = "";
//			while (getline(myFile, line))
//			{
//				clients.push_back(ConvertClientLineToRecord(line));
//			}
//			myFile.close();
//		}
//
//		return clients;
//	}
//		
//	string ConvertClientRecordToLine(stClient client,string seperator = "#//#")		// · ÕÊÌ· »‰Ì… «·⁄„Ì· «·Ï ”ÿ— ·«÷«› Â ≈·Ï «·„·›
//	{
//		string clientRecord = "";
//
//		clientRecord += client.accountNumber + seperator;
//		clientRecord += client.pinCode + seperator;
//		clientRecord += client.name + seperator;
//		clientRecord += client.phoneNumber + seperator;
//		clientRecord += to_string( client.accountBalance);
//	
//		return clientRecord;
//	}
//
//	bool SaveDataInFlie(const string& line,const string& filePath)		//··Õ›Ÿ ›Ì «·„·› «·‰’Ì 
//	{
//		fstream myFile;
//		myFile.open(filePath,ios::app);
//
//		if (myFile.is_open())
//		{
//			myFile << line << endl;
//
//			myFile.close();
//
//			return true;
//		}
//	
//		return false;
//	}
//
//	bool SaveClientDataInFlie(const vector<stClient>& vClients, const string& filePath)	
//	{
//		fstream myFile;
//		myFile.open(filePath,ios::out);
//
//		if (myFile.is_open())
//		{
//			for (const stClient & client : vClients) 
//			{
//				if (!client.IsDeleted) 
//				{
//					myFile << ConvertClientRecordToLine(client) << endl;
//				}
//			}
//		
//			myFile.close();
//
//			return true;
//		}
//	
//		return false;
//	}
//
//	void ChangeIsDeletedForClient(const string& accountNumber, vector<stClient>& vClients)			//· €Ì— Õ«·… «·⁄„Ì· «·Ï „Õ–Ê› 
//	{
//		for (stClient& client : vClients)
//		{
//			if (client.accountNumber == accountNumber)
//			{
//				client.IsDeleted = true;
//				break;
//			}
//		}
//	}
//		
//	bool GetUserAnswerForDeletion(const string& message)				
//	{
//		char deleted = 'y';
//		cout << message;
//		cin >> deleted;
//		return tolower(deleted) == 'y';
//	}
//	
//	void WaitingForInput()
//	{
//		cout << "\n\npress any key to go back to Main Menu...";
//		system("pause > 0");
//		system("cls");
//	}
//
//	bool FindClientByAccountNumber(vector<stClient> vClients,stClient& client, const string& accountNumber)
//	{	
//		for (const stClient & searchClient : vClients)
//		{
//			if (searchClient.accountNumber == accountNumber)
//			{
//				client = searchClient;
//				return true;
//			}
//		}
//
//		return false;
//	}
//
//	string ReadClientAccountNumber() 
//	{
//		cout << "Please Enter Account Number ? ";
//		string accountNumber;
//		cin >> accountNumber;
//		return accountNumber;
//	}
//
//	bool GetUserAnswerForUpdate(const string& message)		// ·”ƒ«· «·„” Œœ„ ⁄·Ï  √ﬂÌœ  ⁄œÌ· «·⁄„Ì· 
//	{
//		char deleted = 'y';
//		cout << message;
//		cin >> deleted;
//		
//		return tolower(deleted) == 'y';
//	}
//
//	void UpdateDataClient(const string& accountNumber, vector<stClient>& vClients)
//	{
//		for (stClient& client : vClients)
//		{
//			if (client.accountNumber == accountNumber)
//			{
//				cout << "\n\nEnter PinCode ? ";
//				getline(cin >> ws, client.pinCode); cout << endl;
//				////////////////////////////
//
//				cout << "Enter Name ? ";
//				getline(cin, client.name); cout << endl;
//				////////////////////////////
//
//				cout << "Enter Phone Number ? ";
//				getline(cin, client.phoneNumber); cout << endl;
//				////////////////////////////
//
//				cout << "Enter Account Balance ? ";
//				cin >> client.accountBalance; cout << endl;
//				////////////////////////////	
//				break;
//			}
//		}
//	}
//
//	double AddDepositToClient(const string& accountNumber, vector<stClient>& vClients)
//	{
//		for (stClient& client : vClients)
//		{
//			if (client.accountNumber == accountNumber)
//			{
//				double amount = 0.0;
//				cout << "Please Enter Deposit Amount ? ";
//				cin >> amount; cout << endl;
//				client.accountBalance += amount;
//				return client.accountBalance;
//			}
//		}
//		return 0;
//	}
//
//	double AddWithDrawToClient(const string& accountNumber, vector<stClient>& vClients)
//	{
//		for (stClient& client : vClients)
//		{
//			if (client.accountNumber == accountNumber)
//			{
//				double amount = 0.0;
//				cout << "Please Enter withdraw Amount ? ";
//				cin >> amount; cout << endl;
//			
//				while (amount > client.accountBalance)
//				{
//					cout << "Amount Exceeds the balance , you can withdraw up to : " << client.accountBalance << endl;
//					cout << "Please Enter another Amount ? ";
//					cin >> amount; cout << endl;
//				}
//				client.accountBalance -= amount;
//				return client.accountBalance;
//				////////////////////////////	
//			}
//		}
//		return 0;
//	}
//
//	bool GetUserAnswerForTransaction()		// ·”ƒ«· «·„” Œœ„ ⁄·Ï  √ﬂÌœ «·⁄„·Ì… ··⁄„Ì· 
//	{
//		char deleted = 'y';
//		cout << "\nAre You sure want perform this Transaction ? y/n ? ";
//		cin >> deleted;
//
//		return tolower(deleted) == 'y';
//	}
//
//
//#pragma endregion
//
//#pragma region PrintsOfScreen
//
//	void PrintClientData(const stClient & client)			//·ÿ»«⁄… „⁄·Ê„«  «·⁄„Ì· ⁄·Ï «·‘«‘…
//	{
//		cout << "\n\nThe following are the client details:\n";	
//		cout << "-----------------------------------------------";	
//		cout << "\nAccount Number : " << client.accountNumber;
//		cout << "\nPin Code : " << client.pinCode;
//		cout << "\nName : " << client.name;
//		cout << "\nPhone Number : " << client.phoneNumber;
//		cout << "\nAccount Balance : " << client.accountBalance;
//		cout << "\n-----------------------------------------------\n";	
//	}
//
//	void PrintClientRecord(stClient client)					//·ÿ»«⁄… „⁄·Ê„«  «·⁄„Ì· ⁄·Ï «·‘«‘…
//	{
//		cout << "| " << setw(15) << left << client.accountNumber;
//		cout << "| " << setw(10) << left << client.pinCode;
//		cout << "| " << setw(40) << left << client.name;
//		cout << "| " << setw(12) << left << client.phoneNumber;
//		cout << "| " << setw(12) << left << client.accountBalance;
//	}
//
//	void PrintHeader(short countClient)
//	{
//		cout << "\n\t\t\t\t\tClient List (" << countClient << ") Client(s).\n";
//		cout << "________________________________________________________________________________________________\n" << endl;
//		cout << "| " << left << setw(15) << "Accout Number";
//		cout << "| " << left << setw(10) << "Pin Code";
//		cout << "| " << left << setw(40) << "Client Name";
//		cout << "| " << left << setw(12) << "Phone";
//		cout << "| " << left << setw(12) << "Balance";
//		cout << "\n________________________________________________________________________________________________\n";
//	}
//
//	void PrintHeaderWithTotalBalance(short countClient)
//	{
//		cout << "\n\t\t\t\t\tClient List (" << countClient << ") Client(s).\n";
//		cout << "________________________________________________________________________________________________\n" << endl;
//		cout << "| " << left << setw(15) << "Accout Number";
//		cout << "| " << left << setw(40) << "Client Name";
//		cout << "| " << left << setw(12) << "Balance";
//		cout << "\n________________________________________________________________________________________________\n";
//	}
//
//	void PrintClientRecordWithTotalBalance(stClient client)					//·ÿ»«⁄… „⁄·Ê„«  «·⁄„Ì· ⁄·Ï «·‘«‘…
//	{
//		cout << "| " << setw(15) << left << client.accountNumber;
//		cout << "| " << setw(40) << left << client.name;
//		cout << "| " << setw(12) << left << client.accountBalance;
//	}
//	void PrintFooterWithTotalBalance(const double& totalBalance ) 
//	{
//		cout << "\n________________________________________________________________________________________________\n";
//		cout << "\t\t\t\t Total  Balances = " << totalBalance;
//	}
//#pragma endregion
//	void NotAccess()
//	{
//		system("cls");
//		cout << "--------------------------------------------\n";
//		cout << "Access Denied,\n";
//		cout << "You do not have permissions for this Command,\n";
//		cout << "Please Conact Your Admin\n";
//		cout << "--------------------------------------------\n";
//		WaitingForInput();
//	}
//}
//
