//#include "Helper.h" 
//#include"ManageUserLib.h"
//
//using namespace HelperLib;
//using namespace ManageUserLib;
//
//const string  gClientFilePath = "C:\\Users\\ahmad\\Desktop\\ClientData.txt";
//
//stUser gCurrentUser;
//
//vector<stClient> gVClients;
//
//bool CheckPermission(enPermission permission)
//{
//	return  (gCurrentUser.Permission == enPermission::epFullAccess) || (gCurrentUser.Permission & permission) == permission;
//
//}
//
//enChooseMainMenu MainMenuScreen()
//{
//	system("cls");
//	cout << "===============================================\n";
//	cout << "\t\tMain Menu Screen\n";
//	cout << "===============================================\n";
//	cout << "\t[1] Show Client List.\n";
//	cout << "\t[2] Add New Client.\n";
//	cout << "\t[3] Delete Client.\n";
//	cout << "\t[4] Update Client Info.\n";
//	cout << "\t[5] Find Client.\n";
//	cout << "\t[6] Transactions.\n";
//	cout << "\t[7] Manage User.\n";
//	cout << "\t[8] Logout.\n";
//	cout << "===============================================\n";
//
//	cout << "Choose What do you want to do [1 to 8] ";
//	short choose = -1;
//	cin >> choose;
//	return enChooseMainMenu(choose);
//}
//
//#pragma region ShowClientScereen
//void ShowClientListScreen(const vector<stClient>& clients)
//{
//	if (!CheckPermission(enPermission::epShowClient))
//	{
//		NotAccess();
//		return;
//	}
//	system("cls");
//	PrintHeader(clients.size());
//	
//	for (const stClient& client : clients)
//	{
//		PrintClientRecord(client);
//		cout << endl;
//	}
//	WaitingForInput();
//}
//#pragma endregion
//
//#pragma region AddNewClient
//bool CheckAccountNumberIsExist(const string& accountNumber)
//{
//	for (const stClient& client : gVClients) 
//	{
//		if (client.accountNumber == accountNumber)
//		{
//			return true;
//		}
//	}
//
//	return false;
//}
//
//stClient ReadNewClient()		
//{
//	stClient client;
//
//	cout << "Enter Account Number ? ";
//	getline(cin >> ws, client.accountNumber); cout << endl;
//	
//	while (CheckAccountNumberIsExist(client.accountNumber))
//	{
//		cout << "Client With [" << client.accountNumber << "] Already exists , Enter another Account Number?";
//		getline(cin >> ws, client.accountNumber); cout << endl;
//	}
//	////////////////////////////
//
//	cout << "Enter PinCode ? ";
//	getline(cin, client.pinCode); cout << endl;
//	////////////////////////////
//
//	cout << "Enter Name ? ";
//	getline(cin, client.name); cout << endl;
//	////////////////////////////
//
//	cout << "Enter Phone Number ? ";
//	getline(cin, client.phoneNumber); cout << endl;
//	////////////////////////////
//
//	cout << "Enter Account Balance ? ";
//	cin >> client.accountBalance; cout << endl;
//	////////////////////////////
//
//	return client;
//}
//
//void AddClients()
//{
//	char addMore = 'y';
//	while (tolower(addMore) == 'y')
//	{
//		system("cls");
//		cout << "----------------------------\n";
//		cout << "\t\tAdd New Client Screen\n";
//		cout << "----------------------------\n";
//		cout << "Adding New Client : \n";
//
//		if (SaveDataInFlie(ConvertClientRecordToLine(ReadNewClient()), gClientFilePath))
//		{
//			cout << "Client Added Successfuly , do you want to add more client ? ";
//			cin >> addMore;
//		}
//		else
//		{
//			cout << "Failed to add client,Do you want to try adding again?";
//			cin >> addMore;
//		}
//	}
//}
//
//void AddNewClientScreen() 
//{
//	if (!CheckPermission(enPermission::epAddClient))
//	{
//		NotAccess();
//		return;
//	}
//	AddClients();
//	WaitingForInput();
//}
//
//#pragma endregion
//
//#pragma region DeleteClient
//
//void DeletedClientByAccountNumber(const string& accountNumber,vector<stClient>& vClients)
//{
//	stClient client;
//
//	if (FindClientByAccountNumber(vClients, client, accountNumber))
//	{
//		PrintClientData(client);
//
//		if (GetUserAnswerForDeletion("\nAre You sure want delete this client ? y/n ? "))
//		{
//			ChangeIsDeletedForClient(accountNumber, vClients);
//		
//			SaveClientDataInFlie(vClients,gClientFilePath);
//
//			cout << "\nClient Deleted Successfully .\n";
//		}
//	}
//	else
//	{
//		cout << "\nClient with Account Number (" << accountNumber << ") is Not Found!\n";
//	}
//}
//
//void DeleteClientScreen() 
//{
//	if (!CheckPermission(enPermission::epDeleteClient))
//	{
//		NotAccess();
//		return;
//	}
//	system("cls");
//	cout << "------------------------------------------\n";
//	cout << "\t\tDelete Client Screen\n";
//	cout << "------------------------------------------\n";
//	DeletedClientByAccountNumber(ReadClientAccountNumber(), gVClients);
//	WaitingForInput();
//}
//#pragma endregion
//
//#pragma region UpdateClient
//
//void UpdateClientByAccountNumber(const string& accountNumber,vector<stClient>& vClients)
//{
//	stClient client;
//
//	if (FindClientByAccountNumber(vClients, client, accountNumber))
//	{
//		PrintClientData(client);
//
//		if (GetUserAnswerForUpdate("\nAre You sure want Update this client ? y/n ?"))
//		{
//			UpdateDataClient(accountNumber,vClients);
//			SaveClientDataInFlie(vClients,gClientFilePath);
//
//			cout << "\nClient Update Successfully .\n";
//		}
//	}
//	else
//	{
//		cout << "\nClient with Account Number (" << accountNumber << ") is Not Found!\n";
//	}
//}
//
//void UpdateClientScreen() 
//{
//	if (!CheckPermission(enPermission::epUpdateClient))
//	{
//		NotAccess();
//		return;
//	}
//	system("cls");
//	cout << "-----------------------------------------------\n";
//	cout << "\t\tUpdate Client Info Screen\n";
//	cout << "-----------------------------------------------\n";
//	UpdateClientByAccountNumber(ReadClientAccountNumber(), gVClients);
//	WaitingForInput();
//}
//
//#pragma endregion
//
//#pragma region FindClient
//
//void FindClient(const string& accountNumber, vector<stClient>& vClients)
//{
//	stClient client;
//	if (FindClientByAccountNumber(vClients, client, accountNumber))
//	{
//		PrintClientData(client);
//	}
//	else
//	{
//		cout << "\nClient with Account Number (" << accountNumber << ") is Not Found!";
//	}
//}
//
//void FindClientScreen() 
//{
//	if (!CheckPermission(enPermission::epFindClient))
//	{
//		NotAccess();
//		return;
//	}
//	system("cls");
//	cout << "--------------------------------------------\n";
//	cout << "\t\tFind Client Screen\n";
//	cout << "--------------------------------------------\n";
//	FindClient(ReadClientAccountNumber(),gVClients);
//	WaitingForInput();
//}
//
//#pragma endregion
//
//#pragma region Transactions
//
//#pragma region Deposit
//void ProcessDeposit(const string& accountNumber)
//{
//	stClient client;
//
//	if (FindClientByAccountNumber(gVClients, client, accountNumber))
//	{
//		PrintClientData(client);
//		
//		double newBalance = AddDepositToClient(accountNumber, gVClients);
//		
//		if (GetUserAnswerForTransaction())
//		{
//			SaveClientDataInFlie(gVClients, gClientFilePath);
//			cout << "\nClient Add Deposit Successfully... new balance is : " << newBalance << "\n";
//		}
//	}
//	else
//	{
//		cout << "\nClient with Account Number (" << accountNumber << ") is Not Found!\n";
//	}
//}
//
//void DepositScreen() 
//{
//	system("cls");
//	cout << "-----------------------------\n";
//	cout << "\tDepsit Screen\n";
//	cout << "-----------------------------\n";
//	ProcessDeposit(ReadClientAccountNumber());
//	WaitingForInput();
//}
//
//#pragma endregion
//
//#pragma region WithDraw
//
//void ProcessWithdraw(const string& accountNumber)
//{
//	stClient client;
//
//	if (FindClientByAccountNumber(gVClients, client, accountNumber))
//	{
//		PrintClientData(client);
//
//		 double newBalance = AddWithDrawToClient(accountNumber, gVClients);
//
//		if (GetUserAnswerForTransaction())
//		{
//			SaveClientDataInFlie(gVClients, gClientFilePath);
//			cout << "\nClient Add withdraw Successfully... new balance is : "<< newBalance << "\n";
//
//		}
//
//	}
//	else
//	{
//		cout << "\nClient with Account Number (" << accountNumber << ") is Not Found!\n";
//	}
//}
//void WithdrawScreen()
//{
//	system("cls");
//	cout << "-----------------------------\n";
//	cout << "\tWithdraw Screen\n";
//	cout << "-----------------------------\n";
//	ProcessWithdraw(ReadClientAccountNumber());
//	WaitingForInput();
//}
//#pragma endregion
//
//#pragma region TotalBalance
//
//void TotalBalancesScreen()
//{
//	system("cls");
//	PrintHeaderWithTotalBalance(gVClients.size());
//	double totalBalance = 0.0;
//	for (const stClient &client : gVClients)
//	{
//		PrintClientRecordWithTotalBalance(client);
//		cout << endl;
//		totalBalance += client.accountBalance;
//	}
//	PrintFooterWithTotalBalance(totalBalance);
//	WaitingForInput();
//}
//
//#pragma endregion
//
//enChooseTransactionMenu TransactionsScreen()
//{
//	system("cls");
//	cout << "===============================================\n";
//	cout << "\t\tTransactions Menu Screen\n";
//	cout << "===============================================\n";
//	cout << "\t[1] Deposit.\n";
//	cout << "\t[2] Withdraw.\n";
//	cout << "\t[3] Total Balances.\n";;
//	cout << "\t[4] Main Menu.\n";
//	cout << "===============================================\n";
//	cout << "Choose What do you want to do [1 to 4] ";
//	
//	short choose = -1;
//	cin >> choose;
//
//	return enChooseTransactionMenu(choose);
//}
//
//void ProcessSelectionTransactiosMenu(enChooseTransactionMenu choose) 
//{
//	switch (choose)
//	{
//	case HelperLib::enChooseTransactionMenu::eDeposit:
//		DepositScreen();
//		break;
//	case HelperLib::enChooseTransactionMenu::eWithdraw:
//		WithdrawScreen();
//		break;
//	case HelperLib::enChooseTransactionMenu::eTotalBalances:
//		TotalBalancesScreen();
//		break;
//	default:
//		break;
//	}
//}
//
//void Transactions() 
//{
//	if (!CheckPermission(enPermission::epTransaction))
//	{
//		NotAccess();
//		return;
//	}
//	enChooseTransactionMenu choose;
//	while ((choose = TransactionsScreen()) != enChooseTransactionMenu::eMainMenu)
//	{
//		gVClients = LoadDataClientFromFile(gClientFilePath);
//		ProcessSelectionTransactiosMenu(choose);
//	}
//	system("cls");
//}
//
//#pragma endregion
//
//#pragma region ManageUser
//
//enChooseManageUserMenu ManageUsersScreen()
//{
//	system("cls");
//	cout << "===============================================\n";
//	cout << "\t\tManage Users  Menu Screen\n";
//	cout << "===============================================\n";
//	cout << "\t[1] List Users.\n";
//	cout << "\t[2] Add New User.\n";
//	cout << "\t[3] Delete User.\n";;
//	cout << "\t[4] Update User.\n";;
//	cout << "\t[5] Find User.\n";;
//	cout << "\t[6] Main Menu.\n";
//	cout << "===============================================\n";
//	cout << "Choose What do you want to do [1 to 6] ";
//
//	short choose = -1;
//	cin >> choose;
//
//	return enChooseManageUserMenu(choose);
//}
//
//#pragma region ListUserScreen
//void ListUser() 
//{
//	vector<stUser> vUsers = LoadDataUserFromFile(gUserFilePath);
//	
//	PrintUserHeader(vUsers.size());
//	
//	for(stUser& user : vUsers){
//
//		PrintUserRecord(user);
//		cout<<endl;
//	}
//}
//
//void ListUserScreen()
//{
//	system("cls");
//	ListUser();
//	WaitingForInputAndBackManageUserMenu();
//}
//
//#pragma endregion
//
//#pragma region AddNewUserScreen
//void AddNewUser() 
//{
//	char addMore = 'y';
//	while (tolower(addMore) == 'y')
//	{
//		system("cls");
//		cout << "----------------------------\n";
//		cout << "\t\tAdd New User Screen\n";
//		cout << "----------------------------\n";
//		cout << "Adding New User : \n";
//
//		if (SaveDataInFlie(ConvertUserRecordToLine(ReadUser()), gUserFilePath))
//		{
//			cout << "User Added Successfuly , do you want to add more client ? ";
//			cin >> addMore;
//		}
//		else
//		{
//			cout << "Failed to add User,Do you want to try adding again?";
//			cin >> addMore;
//		}
//	}
//
//}
//
//void AddNewUserScreen()
//{
//	system("cls");
//	AddNewUser();
//	WaitingForInputAndBackManageUserMenu();
//
//}
//#pragma endregion
//
//#pragma region DeleteUserScreen
//
//void DeleteUserByUserName(const string userName) 
//{
//	if (userName == "Admin")
//	{
//		cout << "This user Cannt Delete\n";
//		return;
//	}
//
//	stUser user;
//	vector<stUser> vUsers = LoadDataUserFromFile(gUserFilePath);
//
//	if (FindUserByUserName(vUsers, user, userName)) 
//	{
//		PrintUserData(user);
//		if (GetUserAnswerForDeletion("\nAre You sure want delete this User ? y/n ? "))
//		{
//			ChangeIsDeletedForClient(userName, vUsers);
//		
//			SaveUserDataInFlie(vUsers,gUserFilePath);
//		}
//	}
//	else 
//	{
//		cout << "\nUser with UserName (" << userName << ") is Not Found!\n";
//	}
//}
//
//void DeleteUserScreen()
//{
//	system("cls");
//	cout << "------------------------------------------\n";
//	cout << "\t\tDelete Client Screen\n";
//	cout << "------------------------------------------\n";
//	DeleteUserByUserName(ReadUserName());
//	WaitingForInput();
//
//}
//#pragma endregion
//
//#pragma region UpdateUserScreen
//void UpdateUser(const string& userName) 
//{
//	stUser user;
//	vector<stUser> vUsers = LoadDataUserFromFile(gUserFilePath);
//	if (FindUserByUserName(vUsers, user, userName))
//	{
//		PrintUserData(user);
//
//		if (GetUserAnswerForUpdate("\nAre You sure want Update this User ? y/n ?"))
//		{
//			UpdateDataUser(userName, vUsers);
//			SaveUserDataInFlie(vUsers, gUserFilePath);
//
//			cout << "\nUser Update Successfully .\n";
//		}
//	}
//	else
//	{
//		cout << "\nUser with UserName (" << userName << ") is Not Found!\n";
//	}
//}
//
//void UpdateUserScreen()
//{
//	system("cls");
//	cout << "-----------------------------------------------\n";
//	cout << "\t\tUpdate User Info Screen\n";
//	cout << "-----------------------------------------------\n";
//	UpdateUser(ReadUserName());
//	WaitingForInputAndBackManageUserMenu();
//}
//
//#pragma endregion
//
//#pragma region FindUserScreen
//void FindUser(const string& userName)
//{
//	stUser user;
//	vector<stUser> vUsers = LoadDataUserFromFile(gUserFilePath);
//
//	if (FindUserByUserName(vUsers, user, userName))
//	{
//
//		PrintUserData(user);
//	}
//	else
//	{
//	 	cout << "\nUser with UserName (" << userName << ") is Not Found!\n";
//	}
//}
//
//void FindUserScreen()
//{
//	system("cls");
//	cout << "--------------------------------------------\n";
//	cout << "\t\tFind User Screen\n";
//	cout << "--------------------------------------------\n";
//	FindUser(ReadUserName());
//	WaitingForInputAndBackManageUserMenu();
//}
//#pragma endregion
//
//void ProcessSelectionManageUsersMenu(enChooseManageUserMenu choose)
//{
//	switch (choose)
//	{
//	case ManageUserLib::enChooseManageUserMenu::enListUser:
//		ListUserScreen();
//		break;
//	case ManageUserLib::enChooseManageUserMenu::enAddNewUser:
//		AddNewUserScreen();
//		break;
//	case ManageUserLib::enChooseManageUserMenu::enDeleteUser:
//		DeleteUserScreen();
//		break;
//	case ManageUserLib::enChooseManageUserMenu::enUpdateUser:
//		UpdateUserScreen();
//		break;	
//	case ManageUserLib::enChooseManageUserMenu::enFindUser:
//		FindUserScreen();
//		break;
//	default:
//		break;
//	}
//}
//
//void ManageUsers()
//{
//	if (!CheckPermission(enPermission::epManageUser))
//	{
//		NotAccess();
//		return;
//	}
//	enChooseManageUserMenu choose;
//	while ((choose = ManageUsersScreen()) != enChooseManageUserMenu::enMainMenu)
//	{
//		ProcessSelectionManageUsersMenu(choose);
//	}
//	system("cls");
//}
//
//#pragma endregion
//
//void ProcessSelectionMainMenu(enChooseMainMenu choose)
//{
//	switch (choose)
//	{
//	case HelperLib::enChooseMainMenu::eShowClientList: 
//		ShowClientListScreen(LoadDataClientFromFile(gClientFilePath));
//		break;
//	case HelperLib::enChooseMainMenu::eAddNewClient:
//		AddNewClientScreen();
//		break;
//	case HelperLib::enChooseMainMenu::eDeleteClient:
//		DeleteClientScreen();
//		break;
//	case HelperLib::enChooseMainMenu::eUpdateClientInfo:
//		UpdateClientScreen();
//		break;
//	case HelperLib::enChooseMainMenu::eFindClient:
//		FindClientScreen();
//		break;
//	case HelperLib::enChooseMainMenu::eTransactions:
//		Transactions();	
//		break;
//	case HelperLib::enChooseMainMenu::eManageUser:
//		ManageUsers();
//	default:
//		break;
//	}
//}
//
//void StartProgram()
//{
//	enChooseMainMenu choose;
//	while ((choose = MainMenuScreen()) != enChooseMainMenu::eLogout)
//	{
//		gVClients = LoadDataClientFromFile(gClientFilePath);
//		ProcessSelectionMainMenu(choose);
//	}
//}
//
//#pragma region Login
//
//
//stUser ReadUserDataFromLogin() 
//{
//	stUser user;
//	cout << "UserName ? ";
//	getline(cin >> ws, user.UserName);
//	cout << "Password ? ";
//	getline(cin, user.Password);
//	return user;
//}
//
//bool CheckUserNameAndPassword(stUser &pUser)
//{
//	vector<stUser> vUsers = LoadDataUserFromFile(gUserFilePath);
//
//	for (stUser user : vUsers)
//	{
//		if (pUser.UserName == user.UserName && pUser.Password == user.Password) 
//		{
//			pUser.Permission = user.Permission;
//			return true;
//		}
//	}
//
//	return false;
//}
//
//void Login()
//{
//	while (true) 
//	{
//
//		system("cls");
//		cout << "--------------------------------------------\n";
//		cout << "\t\Login Screen\n";
//		cout << "--------------------------------------------\n";
//		stUser currentUser = ReadUserDataFromLogin();
//		while (!CheckUserNameAndPassword(currentUser)) 
//		{
//			cout << "Login failed, username or password is invalid\n";
//			currentUser = ReadUserDataFromLogin();
//		}
//		gCurrentUser = currentUser;
//		StartProgram();
//	}
//	
//}
//
//#pragma endregion Login
//
//int main() 
//{
//	Login();
//	return 0;
//}