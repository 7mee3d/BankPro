#pragma once
#include <iostream>
#include "clsString.h"
#include "clsSecreen.h"
#include "clsUserBank.h"
#include "GlobalVarablesAndConstants.h"
#include "clsDate.h"

class clsRegisterLogUsers  : protected clsSecreen 
{

private : 

	
	static inline void _HeaderShowRegisterLoginUsers() {

		cout << clsUtility::createTabs(1) << "|+_________________________________________________________________________________________+|" << clsUtility::createNewLine(1);
		cout << clsUtility::createTabs(1) << "|              Date/Time            |      Username      |     Password     |   Permission  |" << clsUtility::createNewLine(1);
		cout << clsUtility::createTabs(1) << "|+_________________________________________________________________________________________+|" << clsUtility::createNewLine(2);

	};

	static inline void _printInformationOneUserRegisterLoginTime (clsUserBank::stInformationRegister infoUser) {

			cout << "| " << left << setw(34) << infoUser.dateTime << "| ",
			cout <<  left << setw(19) << infoUser.username << "| ",
			cout << left << setw(17) << infoUser.password << "| ",
			cout <<  left << setw(14) << infoUser.permission << "| ";
		


		cout << clsUtility::createNewLine(1);

	};

	static inline void _FooterShowRegisterLoginUsers(void) {

		cout << clsUtility::createNewLine(1) <<  clsUtility::createTabs(1) << "|+_________________________________________________________________________________________+|" << clsUtility::createNewLine(2);

	}



public : 

	static inline void showListRegistersLoginUsers () {

		if (!clsSecreen::_CheakAccessSuccessfullyOrDenied(clsUserBank::enChoiseSectionsToAddPermission::ekREGISTER_LOGIN_USERS)) {
			return;
		}

		vector<clsUserBank::stInformationRegister> infoUsers = clsUserBank::LoadLineFromFile ( );

		string const kTITLE = "Show Register Login Secren";
		string const kSUB_TITLE = "User list ( " + to_string(infoUsers.size()) + " ) User(s)";

		_DrawMainHeaderSecreen(kTITLE, kSUB_TITLE);
		_HeaderShowRegisterLoginUsers();

		if (infoUsers.size() == 0)
			cout << clsUtility::createTabs(4) << "No User Available in the System!" << clsUtility::createNewLine(1);
		else
			for (clsUserBank::stInformationRegister infoUser : infoUsers) {
				cout << clsUtility::createTabs(1); 
				_printInformationOneUserRegisterLoginTime(infoUser);

			};


		_FooterShowRegisterLoginUsers();
		clsUtility::pauseIncludeTab(5, "Press any key to back of the Main Menu (:");

	};

};

