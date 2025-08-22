#pragma once
#include <iostream>
#include <string> 
#include <fstream>
#include "clsPerson.h"
#include "clsString.h"
#include "clsInputValidate.h"
#include <vector> 
 


using namespace std; 

class clsBankClient : public clsPerson 
{



private :

	enum enTypeMode {

		kEMPTY_MODE = 0 , 
		kUPDATE_MODE = 1 ,
		kADD_CLEINT_MODE = 2 ,
		kDELETE_CLEINT_MODE = 3 
	};

	string _AccountNumber{ "" };
	string _PinCode{ "" };
	double  _AccountBalance{  }; 

	bool _MarkForDelete{ false }; 

	enTypeMode _ModeType; 

	static inline clsBankClient _ConvertLineToObjectCleint(string const &kLINE, string const kSEPARATOR = "#//#") {

		vector <string> lineAfterSplit = clsString::splitWordInText(kLINE, kSEPARATOR);

		return clsBankClient(lineAfterSplit[0], lineAfterSplit[1], lineAfterSplit[2], lineAfterSplit[3], lineAfterSplit[4], lineAfterSplit[5],  stod( lineAfterSplit[6 ] )   , enTypeMode::kUPDATE_MODE);
	}

	static inline clsBankClient _GetEmptyObject() {

		return clsBankClient("", "", "", "", "", "", 0, enTypeMode::kEMPTY_MODE);

	};

	static inline string  _ConvertDateToLineObject(clsBankClient& cleintBankObject , string const kSEPARATOR = "#//#") {

		string line{ "" };

		line += cleintBankObject.getFirstName() + kSEPARATOR;
		line += cleintBankObject.getLastName() + kSEPARATOR;
		line += cleintBankObject.getEmail() + kSEPARATOR;
		line += cleintBankObject.getPhoneNUmber() + kSEPARATOR;
		line += cleintBankObject.getAccountNumber() + kSEPARATOR;
		line += cleintBankObject.getPinCode() + kSEPARATOR;
		line += to_string ( cleintBankObject.getAccountBalance() ) ;

		return line;
	};

	static inline vector <clsBankClient> _LoadLineOfDataFromFile() {

		fstream file; 
		file.open("Client.txt", ios::in); 

		vector< clsBankClient> informationClients; 

		if (file.is_open()) {

			string line{ "" };

			clsBankClient infoClientOne = _GetEmptyObject() ; 

			while (getline(file, line)) {

				infoClientOne = _ConvertLineToObjectCleint(line, "#//#");

				informationClients.push_back(infoClientOne);


			}

			file.close(); 

		}
		return informationClients;


	}


	static inline void _LoadLineDataToFile(vector <clsBankClient> &infoClients) {


		fstream file;

		file.open("Client.txt", ios::out);

		vector< clsBankClient> informationClients;

		if (file.is_open()) {

			string line{ "" };

			for (clsBankClient& infoClient : infoClients) {
				if (infoClient.getMarkForDelete() == false) {
					line = _ConvertDateToLineObject(infoClient, "#//#");
					file << line << endl;
				}
			}

			file.close();

		}

	

	};



	 void _UpdateClientInformation() {

		vector<clsBankClient> loadLinesFromFile = _LoadLineOfDataFromFile();


		for (clsBankClient& infoClient : loadLinesFromFile) {
			if (infoClient.getAccountNumber() == getAccountNumber()) {
				infoClient = *this;
			}
		}

		_LoadLineDataToFile(loadLinesFromFile);


	};


	static inline void _LoadDataLineToFileAppend(string const kLINE) {

		fstream file; 

		file.open("Client.txt", ios::out | ios::app); 

		if (file.is_open()) {


			file << kLINE << endl;

		}

		file.close(); 

	}

	 void _AddNewClient() {

		_LoadDataLineToFileAppend(_ConvertDateToLineObject(*this));

	}

	  inline string _ConvertDataRecordToLineTransferLog( clsBankClient& DestenationClinet, double const kAMOUNT, string const kSEPARATOR = "#//#") {

		 string line{ "" };

		 line += clsDate::DateOfSystem() + " - ";
		 line += clsDate::dateTimeLocal() + kSEPARATOR;

		 line += _AccountNumber + kSEPARATOR;
		 line += DestenationClinet.getAccountNumber() + kSEPARATOR;
		 line += to_string(kAMOUNT) + kSEPARATOR;
		 line += to_string(_AccountBalance) + kSEPARATOR;
		 line += to_string(DestenationClinet.getAccountBalance()) + kSEPARATOR;
		 line += currentUser.getUsername() ;

		 return line;
	 };

	  inline void loadLineToFileTransferHistory( clsBankClient& DestenationClinet, double const kAMOUNT, string const kSEPARATOR = "#//#") {

		 fstream file;
		 file.open("TransferLog.txt", ios::out | ios::app);

		 if (file.is_open()) {

			 string line = _ConvertDataRecordToLineTransferLog( DestenationClinet, kAMOUNT, kSEPARATOR);
			 file << line << clsUtility::createNewLine(1);

		 }
		 file.close();

	 };
	
public : 

	clsBankClient(string const kFIRST_NAME, string const kLAST_NAME, string const kEMAIL, string const kPHONE_NUMBER, string const kACCOUNT_NUMBER, string const kPIN_CODE, double const kACCOUNT_BALANCE , enTypeMode const kTYPE_MODE )

		:clsPerson(kFIRST_NAME, kLAST_NAME, kEMAIL, kPHONE_NUMBER)

	{
		_AccountNumber = kACCOUNT_NUMBER;
		_PinCode = kPIN_CODE;
		_AccountBalance = kACCOUNT_BALANCE;
		_ModeType = kTYPE_MODE; 

	};



	string getAccountNumber() {
		return _AccountNumber; 
	}

	void setPinCode(string const kPIN_CODE) {
		_PinCode = kPIN_CODE;
	}

	string getPinCode() {
		return _PinCode; 
	}

	void setAccountBalance(double const kACCOUNT_BALANCE) {
		_AccountBalance = kACCOUNT_BALANCE; 
	}

	double getAccountBalance() {
		return _AccountBalance; 
	}

	bool isEmpty() {

		return (_ModeType == enTypeMode::kEMPTY_MODE);
	}

	bool getMarkForDelete() {
		return _MarkForDelete; 
	}


	static inline clsBankClient Find (string const kACCOUNT_NUMBER) {

		fstream file; 

		file.open("Client.txt", ios::in); 

		if (file.is_open()) {


			string lineOfFile{ "" };

			while (getline(file, lineOfFile)) {

				clsBankClient clientBank = _ConvertLineToObjectCleint(lineOfFile, "#//#"); 

				if (kACCOUNT_NUMBER == clientBank.getAccountNumber()) {
					file.close();
					return clientBank; 
					
					
				}
			}
			file.close();
		
		}

		return _GetEmptyObject();

	}

	static inline clsBankClient Find(string const kACCOUNT_NUMBER , string const kPIN_CODE) {

		fstream file;

		file.open("Client.txt", ios::in);

		if (file.is_open()) {


			string lineOfFile{ "" };

			while (getline(file, lineOfFile)) {

				clsBankClient clientBank = _ConvertLineToObjectCleint(lineOfFile, "#//#");

				if ((kACCOUNT_NUMBER == clientBank.getAccountNumber()) && (kPIN_CODE == clientBank.getPinCode())) {
					return clientBank;
					file.close();

				}
			}


		}

		return _GetEmptyObject();

	}

	static inline bool isFoundClient(string const kACCOUNT_NUMBER) {

		clsBankClient bankClient = clsBankClient::Find(kACCOUNT_NUMBER);

		return (!bankClient.isEmpty());

	};

	static clsBankClient getObjectStoredAccountNumber(string const kACCOUNT_NUMBER) {

		return clsBankClient("", "", "", "", kACCOUNT_NUMBER, "", 0, enTypeMode::kADD_CLEINT_MODE); 

	}

	static void printClientCard(clsBankClient& informationClient) {

		cout << clsUtility::createTabs(3) << "|+--------------------------------------------------------------+|" << clsUtility::createNewLine(3);

		cout << clsUtility::createTabs(4) << "First Name     : " << informationClient.getFirstName() << clsUtility::createNewLine(2);
		cout << clsUtility::createTabs(4) << "Last Name      : " << informationClient.getLastName() << clsUtility::createNewLine(2);
		cout << clsUtility::createTabs(4) << "Email Client   : " << informationClient.getEmail() << clsUtility::createNewLine(2);
		cout << clsUtility::createTabs(4) << "Phone Number   : " << informationClient.getPhoneNUmber() << clsUtility::createNewLine(2);
		cout << clsUtility::createTabs(4) << "Account Number : " << informationClient.getAccountNumber() << clsUtility::createNewLine(2);
		cout << clsUtility::createTabs(4) << "Pin Code       : " << informationClient.getPinCode() << clsUtility::createNewLine(2);
		cout << clsUtility::createTabs(4) << "Account Balance: " << informationClient.getAccountBalance() << clsUtility::createNewLine(3);

		cout << clsUtility::createTabs(3) << "|+--------------------------------------------------------------+|" << clsUtility::createNewLine(1);
	}

	enum enModeSave {

		kFAILD_SAVE_EMPTY_OBJECT = 0 , 
		kSECCUESS_SAVE = 1,
		kFAILD_ACCOUNT_NUMBER_IS_EXIXTED = 2, 
		kFAILD_DELETE_CLIENT = 3 
	};



	void deposite(double const Amount) {

		_AccountBalance += Amount;
		Save();

	}

	bool withdraw(double const Amount) {

		if (Amount <= this->_AccountBalance) {
			this->_AccountBalance -= Amount;
			Save();
			return true;
		}
		else
		return false; 

	}

	bool transferBalance(double const& kAMOUNT, clsBankClient& DestenationClient) {

		if (kAMOUNT > _AccountBalance)return false; 

		withdraw(kAMOUNT);
		DestenationClient.deposite(kAMOUNT); 
		loadLineToFileTransferHistory(DestenationClient, kAMOUNT, "#//#"); 
		return true; 
	}

	 enModeSave Save() {

		switch (_ModeType) {

		case enTypeMode::kEMPTY_MODE : 

			return enModeSave::kFAILD_SAVE_EMPTY_OBJECT; 
			break; 

		case enTypeMode::kUPDATE_MODE : 

			_UpdateClientInformation(); 

			return enModeSave::kSECCUESS_SAVE; 
			break; 

		case enTypeMode::kADD_CLEINT_MODE : 

			if (clsBankClient::isFoundClient(getAccountNumber())) {
				return enModeSave::kFAILD_ACCOUNT_NUMBER_IS_EXIXTED; 
			}
			else {

				_AddNewClient(); 
				_ModeType = enTypeMode::kUPDATE_MODE; 
				return enModeSave::kSECCUESS_SAVE;
			}

			break; 

		case enTypeMode::kDELETE_CLEINT_MODE : 

			if (!clsBankClient::isFoundClient(getAccountNumber())) {
				return enModeSave::kFAILD_DELETE_CLIENT ;
			}
			else {

				deleteCleint ();
				return enModeSave::kSECCUESS_SAVE;
			}
		}
	}

	 bool deleteCleint() {

		 vector<clsBankClient> vClient = _LoadLineOfDataFromFile();
		 bool flagDeleteClient = false;

		 for (clsBankClient& clientInfo : vClient) {

			 if (clientInfo.getAccountNumber() == _AccountNumber) {
				 clientInfo._MarkForDelete = true;
				 flagDeleteClient = true;
				 break;
			 };
		 }

		 if (flagDeleteClient) {
			 _LoadLineDataToFile(vClient);
			 *this = _GetEmptyObject();
			 return true;
		 }
		 else
			 return false;

	 }; 


	 static inline vector< clsBankClient > loadDataFromFileToShowClient() {

		 return  _LoadLineOfDataFromFile();

	 };

	 static long double getTotalBalanceAllClients() {

		 vector <clsBankClient > infoClients = _LoadLineOfDataFromFile(); 
		 long double totalBalance{};

		 for (clsBankClient infoClient : infoClients) {
			 totalBalance += infoClient._AccountBalance;
		 };

		 return  (totalBalance);
	 }
};


