#pragma once
#include <iostream>
#include "clsUserBank.h"
#include "clsSecreen.h"


class clsShowUserList : protected clsSecreen {

private : 


	static inline void _HeaderShowListUsers(void) {


		cout << "|+_______________________________________________________________________________________________________________________________________________+|" << clsUtility::createNewLine(1);
		cout << "|     Username     |        Full Name User         |                Email               |       Phone       |       Password      |   Permission  |" << clsUtility::createNewLine(1);
		cout << "|+_______________________________________________________________________________________________________________________________________________+|" << clsUtility::createNewLine(1);
	};

	static inline void _PrintInformationOneUserShowListUser(clsUserBank &informationUser ) {

		string const kADMIN_USERNAME = informationUser.getUsername() + " *"; 
		
		cout << "| " << left << setw(17) <<( (informationUser.getUsername() == "Admin") ? kADMIN_USERNAME :  informationUser.getUsername() )<< "| ",
			cout << left << setw(30) << informationUser.getFullName() << "| ",
				cout << left << setw(35) << informationUser.getEmail() << "| ",
				cout << left << setw(18) << informationUser.getPhoneNUmber() << "| ",
				cout << left << setw(20) << informationUser.getPassword() << "| ",
				cout << left << setw(14) << informationUser.getPersmision() << "|";
		


		cout << clsUtility::createNewLine(1);

	};


	static inline void _FooterShowUserList(void) {

		cout << "|+_______________________________________________________________________________________________________________________________________________+|" << clsUtility::createNewLine(1);

	};

public : 

	static inline void showListUsers(void) {

		vector<clsUserBank> const kINFORMATION_USERS = clsUserBank::loadDataFromFileToShowUsers();

		string const kSUB_TITLE = "( " + to_string(kINFORMATION_USERS.size()) + " ) User(s).";
		_DrawMainHeaderSecreen("User List Secren", kSUB_TITLE);


		_HeaderShowListUsers();
		for (clsUserBank infoUser : kINFORMATION_USERS)
			_PrintInformationOneUserShowListUser(infoUser);

		_FooterShowUserList();

		cout << clsUtility::createNewLine(3); 
		clsUtility::pauseIncludeTab(3, "Enter the any key in the Keyboard to back Main Menu Mange User"); 
	}
};

