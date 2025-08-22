#pragma once
#include <iostream> 
#include "clsPerson.h" 
#include <vector> 
#include "clsUillity.h"
#include "clsInputValidate.h" 

using namespace std; 


class clsUserBank : public clsPerson 
{

private : 

	struct stInformationRegister;

	enum enTypeMode {

		kEMPTY_MODE = 0,
		kUPDATE_MODE = 1,
		kADD_CLEINT_MODE = 2,
		kDELETE_CLEINT_MODE = 3
	};

	enTypeMode _Mode{}; 

	string _Username{ "" };
	string _Password{ "" }; 
	short int _Persmission{}; 
	bool _MarkForDelete{ false };



	static inline clsUserBank _ConvertLineToObjectUser(string const& kLINE, string const kSEPARATOR = "#//#") {

		vector <string> lineAfterSplit = clsString::splitWordInText(kLINE, kSEPARATOR);

		return clsUserBank(lineAfterSplit[0], lineAfterSplit[1], lineAfterSplit[2], lineAfterSplit[3], enTypeMode::kUPDATE_MODE, lineAfterSplit[4] , clsUtility::Decryption( lineAfterSplit[5] , 2 )  , stoi (lineAfterSplit[6]));
	}

	static inline clsUserBank _GetEmptyObjectUser() {

		return clsUserBank("", "", "", "", enTypeMode::kEMPTY_MODE , "" , "" , 0 );

	};


	static inline string  _ConvertDateToLineObjectUser(clsUserBank& userObject , string const kSEPARATOR = "#//#") {

		string line{ "" };

		line += userObject.getFirstName() + kSEPARATOR;
		line += userObject.getLastName() + kSEPARATOR;
		line += userObject.getEmail() + kSEPARATOR;
		line += userObject.getPhoneNUmber() + kSEPARATOR;
		line += userObject._Username + kSEPARATOR;
		line += clsUtility::Encryption(userObject._Password, 2) + kSEPARATOR;
		line += to_string ( userObject._Persmission) ;


		return line;
	};

	static inline vector <clsUserBank> _LoadLineOfDataFromFile() {

		fstream file;
		file.open("Users.txt", ios::in);

		vector< clsUserBank> informationUsers;
		if (file.is_open()) {

			string line{ "" };

			clsUserBank informationUserOne = _GetEmptyObjectUser();

			while (getline(file, line)) {

				informationUserOne = _ConvertLineToObjectUser(line, "#//#");
			 
				informationUsers.push_back(informationUserOne);


			}

			file.close();

		}
		return informationUsers;

	};

	static inline void _LoadLineDataToFileUserObject(vector <clsUserBank>& informationUser) {

		fstream file;
		file.open("Users.txt", ios::out);

		if (file.is_open()) {

			string line{ "" };

			for (clsUserBank& infoUser : informationUser) {
				if (infoUser.getMarkForDelete() == false) {
					line = _ConvertDateToLineObjectUser(infoUser, "#//#");
					file << line << endl;
				}
			}

			file.close();
		}
	};



	void _UpdateUserInformation() {

		vector<clsUserBank> informationClients  = _LoadLineOfDataFromFile();


		for (clsUserBank& infoUser : informationClients) {
			if (infoUser.getUsername() == getUsername()) {
				infoUser = *this;
			}
		};

		_LoadLineDataToFileUserObject(informationClients);

	};

	static inline void _LoadDataLineToFileAppendUsers(string const kLINE) {

		fstream file;

		file.open("Users.txt", ios::out | ios::app);

		if (file.is_open()) {


			file << kLINE << endl;

		}

		file.close();

	}

	void _AddNewUser() {

		_LoadDataLineToFileAppendUsers(_ConvertDateToLineObjectUser(*this));

	};

	static inline stInformationRegister _ConvertLineToDataRecord(string line) {

		stInformationRegister info;
		vector <string> information = clsString::splitWordInText(line, "#//#");

		info.dateTime = information[0];
		info.username = information[1];
		info.password = information[2];
		info.permission = stoi(information[3]);

		return info;
	};

	static inline void _LoadDataLineToFileAppendRegisterLoginsUsers(string const kLINE) {

		fstream file;

		file.open("RegisterLoginsUsers.txt", ios::out | ios::app);

		if (file.is_open()) {

			file << kLINE << endl;

		}

		file.close();

	};




	static inline string  _ConvertDataRecordToLine(clsUserBank userInformation, string const& kSEPARATOR = "#//#") {

		string line{ "" };

		line += clsDate::DateOfSystem() + " - ";
		line += clsDate::dateTimeLocal() + kSEPARATOR;
		line += userInformation.getUsername() + kSEPARATOR;
		line += userInformation.getPassword() + kSEPARATOR;
		line += to_string(userInformation.getPersmision());

		return line;

	};

public :



	clsUserBank(string const kFIRST_NAME, string const kLAST_NAME, string const kEMAIL, string const kPHONE_NUMBER ,enTypeMode const kTYPE_MODE, string const kUSERNAME, string const kPASSWORD, short int const kPERSMISSION)
		: clsPerson(kFIRST_NAME, kLAST_NAME, kEMAIL, kPHONE_NUMBER) {

		_Mode = kTYPE_MODE;
		_Username = kUSERNAME;
		_Password = kPASSWORD;
		_Persmission = kPERSMISSION;
	};

	bool isEmpty() {
		return (_Mode == enTypeMode::kEMPTY_MODE);
	};
	void setUsername(string const& kUSERNAME) {
		_Username = kUSERNAME; 
	}
	string getUsername() {
		return _Username;
	};
	void setPassword(string const& kPASSWORD) {
		_Password = kPASSWORD;
	};

	string getPassword() {
		return _Password;
	};
	void setPersmision(short int  const& kPERSMISSION) {

		_Persmission = kPERSMISSION;
	};
	short int getPersmision() {
		return _Persmission;
	};


	bool getMarkForDelete() {
		return _MarkForDelete; 
	}

	bool deleteUser() {

		vector<clsUserBank> vUsers = _LoadLineOfDataFromFile();
		bool flagDeleteClient = false;

		for (clsUserBank& infoUser : vUsers) {

			if (infoUser.getUsername() == _Username ) {
				infoUser._MarkForDelete = true;
				flagDeleteClient = true;
				break;
			};
		}

		if (flagDeleteClient) {
			_LoadLineDataToFileUserObject(vUsers);
			*this = _GetEmptyObjectUser();
			return true;
		}
		else
			return false;

	};
	static inline clsUserBank Find(string const kUSERNAME) {

		fstream file;

		file.open("Users.txt", ios::in);

		if (file.is_open()) {


			string lineOfFile{ "" };

			while (getline(file, lineOfFile)) {

				clsUserBank infoUser = _ConvertLineToObjectUser(lineOfFile, "#//#");

				if (kUSERNAME == infoUser.getUsername()) {
					file.close();
					return infoUser;


				}
			}
			file.close();

		}

		return _GetEmptyObjectUser();

	}
	static inline clsUserBank Find(string const kUSERNAME , string const kPASSWORD) {

		fstream file;

		file.open("Users.txt", ios::in);

		if (file.is_open()) {


			string lineOfFile{ "" };

			while (getline(file, lineOfFile)) {

				clsUserBank infoUser = _ConvertLineToObjectUser(lineOfFile, "#//#");

				if (kUSERNAME == infoUser.getUsername() && kPASSWORD == infoUser.getPassword()) {
					file.close();
					return infoUser;


				}
			}
			file.close();

		}

		return _GetEmptyObjectUser();

	}
	static inline bool isFoundUser(string const kUSERNAME ) {

		clsUserBank userInfo = clsUserBank::Find(kUSERNAME);

		return (!userInfo.isEmpty());

	};


	enum enModeSave {

		kFAILD_SAVE_EMPTY_OBJECT = 0,
		kSECCUESS_SAVE = 1,
		kFAILD_USERNAME_IS_EXIXTED = 2,
		kFAILD_DELETE_USER = 3
	};
	enModeSave Save() {

		switch (_Mode) {

		case enTypeMode::kEMPTY_MODE:

			return enModeSave::kFAILD_SAVE_EMPTY_OBJECT;
			break;

		case enTypeMode::kUPDATE_MODE:

			_UpdateUserInformation();

			return enModeSave::kSECCUESS_SAVE;
			break;

		case enTypeMode::kADD_CLEINT_MODE:

			if (clsUserBank::isFoundUser(getUsername())) {
				return enModeSave::kFAILD_SAVE_EMPTY_OBJECT;
			}
			else {

				_AddNewUser();
				_Mode = enTypeMode::kUPDATE_MODE;
				return enModeSave::kSECCUESS_SAVE;
			}

			break;

		case enTypeMode::kDELETE_CLEINT_MODE:

			if (!clsUserBank::isFoundUser(getUsername())) {
				return enModeSave::kFAILD_DELETE_USER;
			}
			else {

				deleteUser();
				return enModeSave::kSECCUESS_SAVE;
			}
		}
	};

	static inline vector<clsUserBank> loadDataFromFileToShowUsers() {

		return  _LoadLineOfDataFromFile();

	};

	static inline clsUserBank getEmptyObjectUserIncludeUsername(string const& kUSERNAME) {

		return clsUserBank("", "", "", "", enTypeMode::kADD_CLEINT_MODE, kUSERNAME, "", 0);

	};


	enum enChoiseSectionsToAddPermission {

		ekFULL_ACCESS = -1,
		ekSHOW_LIST_CLIENT = 1,
		ekADD_NEW_CLIENT = 2,
		ekDELETE_CLIENT = 4,
		ekUPDATE_CLEINT = 8,
		ekFIND_CLIENT = 16,
		ekTRANSACTION = 32,
		ekMANGE_USERS = 64 ,
		ekREGISTER_LOGIN_USERS = 128

	};

	inline bool cheakPermission(enChoiseSectionsToAddPermission const kPERMISSION) {

		if (this->getPersmision() == enChoiseSectionsToAddPermission::ekFULL_ACCESS)
			return true;
		else {

			if ((kPERMISSION & this->getPersmision()) == kPERMISSION)
				return true;
			else
				return false;
		};

	};

	static inline bool isAdminBankSystem(string const kUSERNAME) {
		return (kUSERNAME == "Admin");
	}


	struct stInformationRegister {

		string dateTime{ "" };
		string username{ "" };
		string password{ "" };
		short permission{};

	};


	static inline vector<stInformationRegister> LoadLineFromFile() {

		vector<stInformationRegister> linesRegisterLogin;

		fstream file;

		file.open("RegisterLoginsUsers.txt", ios::in);

		if (file.is_open()) {

			stInformationRegister info;
			string line;

			while (getline(file, line)) {

				info = _ConvertLineToDataRecord(line);
				linesRegisterLogin.push_back(info);

			}

			file.close();
		}
		return linesRegisterLogin;
	};

	static inline void SaveRegisterUserLoginTheBank(clsUserBank& const kCURRENT_USER) {
		_LoadDataLineToFileAppendRegisterLoginsUsers(_ConvertDataRecordToLine(kCURRENT_USER, "#//#"));
	}

};

