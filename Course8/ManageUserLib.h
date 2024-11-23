//#pragma once
//#include <iostream> 
//#include <string> 
//#include <vector> 
//#include <fstream> 
//#include <iomanip> 
//
//using namespace std;
//
//namespace ManageUserLib
//{
//	const string  gUserFilePath = "C:\\Users\\ahmad\\Desktop\\UserData.txt";
//
//#pragma region Structures
//
//	struct stUser
//	{
//		string UserName = "";
//		string Password = "";
//		short Permission;
//		bool IsDeleted = false;
//	};
//
//#pragma endregion
//
//#pragma region Enums
//
//	enum enChooseManageUserMenu
//	{
//		enListUser = 1,
//		enAddNewUser = 2,
//		enDeleteUser = 3,
//		enUpdateUser = 4,
//		enFindUser = 5,
//		enMainMenu = 6
//	};
//
//	enum enPermission
//	{
//		epFullAccess = -1,
//		epShowClient = 1,
//		epAddClient = 2,
//		epDeleteClient = 4,
//		epUpdateClient = 8,
//		epFindClient = 16,
//		epTransaction = 32,
//		epManageUser = 64
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
//	stUser ConvertLineUserToRecord(string line, string seperator = "#//#")
//	{
//		vector<string> record = SplitString(line, seperator);
//		stUser user;
//
//		if (!record.empty())
//		{
//			user.UserName = record[0];
//			user.Password = record[1];
//			user.Permission = stoi(record[2]);
//		}
//		return user;
//	}
//
//	vector<stUser> LoadDataUserFromFile(const string& filePath)
//	{
//		vector<stUser> users;
//		fstream myFile;
//		myFile.open(filePath, ios::in);
//
//		if (myFile.is_open())
//		{
//			string line = "";
//			while (getline(myFile, line))
//			{
//				users.push_back(ConvertLineUserToRecord(line));
//			}
//			myFile.close();
//		}
//
//		return users;
//	}
//
//	string ConvertUserRecordToLine(stUser user, string seperator = "#//#")
//	{
//		string userRecord = "";
//
//		userRecord += user.UserName + seperator;
//		userRecord += user.Password + seperator;
//		userRecord += to_string(user.Permission);
//
//		return userRecord;
//	}
//
//	bool SaveUserDataInFlie(const vector<stUser>& vUsers, const string& filePath)
//	{
//		fstream myFile;
//		myFile.open(filePath, ios::out);
//
//		if (myFile.is_open())
//		{
//			for (const stUser& user : vUsers)
//			{
//				if(!user.IsDeleted)
//				myFile << ConvertUserRecordToLine(user) << endl;
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
//
//	void ChangeIsDeletedForClient(const string& userName, vector<stUser>& vUsers)		
//	{
//		for (stUser& user : vUsers)
//		{
//			if (user.UserName == userName)
//			{
//				user.IsDeleted = true;
//				break;
//			}
//		}
//	}
//
//	bool FindUserByUserName(vector<stUser> vUsers, stUser& user, const string& userName)
//	{
//		for (const stUser& searchUser : vUsers)
//		{
//			if (searchUser.UserName == userName)
//			{
//				user = searchUser;
//				return true;
//			}
//		}
//
//		return false;
//	}
//
//	short ReadPermissionFromScreen()
//	{
//		cout << "Do you want to give full Access? y/n?";
//		char answer;
//		short permission = 0;
//
//		cin >> answer;
//
//		if (tolower( answer) == 'y')
//			return enPermission::epFullAccess;
//
//		cout << "Do you want to give access to:\n";
//
//		cout << "\nShow Client List? y/n?";
//		cin >> answer;
//		if (tolower(answer) == 'y')
//			permission += enPermission::epShowClient;
//
//		cout << "\nAdd New Client? y/n?";
//		cin >> answer;
//		if (tolower(answer) == 'y')
//			permission += enPermission::epAddClient;
//
//		cout << "\nDelete Client? y/n?";
//		cin >> answer;
//		if (tolower(answer) == 'y')
//			permission += enPermission::epDeleteClient;
//
//		cout << "\nUpdate Client? y/n?";
//		cin >> answer;
//		if (tolower(answer) == 'y')
//			permission += enPermission::epUpdateClient;
//
//		cout << "\nFind Client? y/n?";
//		cin >> answer;
//		if (tolower(answer) == 'y')
//			permission += enPermission::epFindClient;
//
//		cout << "\nTransaction? y/n?";
//		cin >> answer;
//		if (tolower(answer) == 'y')
//			permission += enPermission::epTransaction;
//
//		cout << "\nManage User? y/n?";
//		cin >> answer;
//		if (tolower(answer) == 'y')
//			permission += enPermission::epManageUser;
//
//		return permission;
//	}
//
//	void UpdateDataUser(const string& userName, vector<stUser>& vUsers)
//	{
//		for (stUser& user : vUsers)
//		{
//			if (user.UserName == userName)
//			{
//				cout << "\n\nEnter Password? ";
//				getline(cin >> ws, user.Password); cout << endl;
//				////////////////////////////
//				
//				user.Permission = ReadPermissionFromScreen();
//
//				break;
//			}
//		}
//	}
//
//	void PrintUserRecord(stUser user)					//·ÿ»«⁄… „⁄·Ê„«  «·⁄„Ì· ⁄·Ï «·‘«‘…
//	{
//		cout << "| " << setw(15) << left << user.UserName;
//		cout << "| " << setw(10) << left << user.Password;
//		cout << "| " << setw(40) << left << user.Permission;
//	}
//
//	void PrintUserHeader(short count)
//	{
//		cout << "\n\t\t\t\t\tUsers List (" << count << ") User(s).\n";
//		cout << "________________________________________________________________________________________________\n" << endl;
//		cout << "| " << left << setw(15) << "UserName";
//		cout << "| " << left << setw(10) << "Password";
//		cout << "| " << left << setw(40) << "Permission";
//		cout << "\n________________________________________________________________________________________________\n";
//	}
//
//	void PrintUserData(const stUser& user)			
//	{
//		cout << "\n\nThe following are the User details:\n";
//		cout << "-----------------------------------------------";
//		cout << "\nUserName : " << user.UserName;
//		cout << "\nPassword : " << user.Password;
//		cout << "\nPermission : " << user.Permission;
//		cout << "\n-----------------------------------------------\n";
//	}
//
//	void WaitingForInputAndBackManageUserMenu()
//	{
//		cout << "\n\npress any key to go back to Manage User Menu...";
//		system("pause > 2");
//		system("cls");
//	}
//
//
//	bool CheckUserNameIsExist(const string& userName)
//	{
//		vector<stUser> vUsers = LoadDataUserFromFile(gUserFilePath);
//			
//		for (const stUser& user : vUsers)
//		{
//			if (user.UserName == userName)
//			{
//				return true;
//			}
//		}
//
//		return false;
//	}
//
//	stUser ReadUser() 
//	{
//		stUser user;
//
//		cout << "Enter UserName ? ";
//		getline(cin >> ws, user.UserName); cout << endl;
//		
//		while (CheckUserNameIsExist(user.UserName))
//		{
//			cout << "UserName With [" << user.UserName << "] Already exists , Enter another UserName?";
//			getline(cin >> ws, user.UserName); cout << endl;
//		}
//		
//		cout << "Enter Password?";
//		getline(cin,user.Password);
//
//		cout << "Do you want to give full Access? y/n?";
//		char answer;
//		cin >> answer;
//
//		user.Permission = ReadPermissionFromScreen();
//
//		return user;
//	}
//	
//	string ReadUserName() 
//	{
//		cout << "Please Enter User Name ? ";
//		string accountNumber;
//		cin >> accountNumber;
//		return accountNumber;
//
//	}
//
//#pragma endregion 
//}