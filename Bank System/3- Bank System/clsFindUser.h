#pragma once
#include <iostream>
#include "clsUserBank.h"
#include "clsSecreen.h"
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::to_string;


class clsFindUser : protected clsSecreen {


private:

	static void _PrintUserCard(clsUserBank& informationUser) {

		cout << clsUtility::createTabs(3) << "|+--------------------------------------------------------------+|" << clsUtility::createNewLine(3);

		cout << clsUtility::createTabs(4) << "First Name     : " << informationUser.getFirstName() << clsUtility::createNewLine(2);
		cout << clsUtility::createTabs(4) << "Last Name      : " << informationUser.getLastName() << clsUtility::createNewLine(2);
		cout << clsUtility::createTabs(4) << "Email Client   : " << informationUser.getEmail() << clsUtility::createNewLine(2);
		cout << clsUtility::createTabs(4) << "Phone Number   : " << informationUser.getPhoneNUmber() << clsUtility::createNewLine(2);
		cout << clsUtility::createTabs(4) << "Username       : " << informationUser.getUsername() << clsUtility::createNewLine(2);
		cout << clsUtility::createTabs(4) << "Password       : " << informationUser.getPassword() << clsUtility::createNewLine(2);
		cout << clsUtility::createTabs(4) << "Permission     : " << informationUser.getPersmision() << clsUtility::createNewLine(2);


		cout << clsUtility::createTabs(3) << "|+--------------------------------------------------------------+|" << clsUtility::createNewLine(1);
	}


public:

	static void findUser() {

		_DrawMainHeaderSecreen("Find User Secren");


		string  username = clsInputValidate::readStringIncludeTab(3, "Enter the Username , Please : ");
		while (!clsUserBank::isFoundUser(username))
			username = clsInputValidate::readStringIncludeTab(3, "Please enter of the valid Username : ");



		clsUserBank userInfo = clsUserBank::Find(username);

		if (clsSecreen::_CheakTheUserAdminOrNot(username, "For your information : This account is the account responsible", "for controlling all divisions of the bank")) {
			return;
		}

		clsUserBank::enModeSave saveMode = userInfo.Save();

		switch (saveMode) {

		case clsUserBank::enModeSave::kFAILD_SAVE_EMPTY_OBJECT:
			cout << clsUtility::createNewLine(1) << clsUtility::createTabs(3) << "Error Not Save and Found this User" << clsUtility::createNewLine(1);
			break;

		case clsUserBank::enModeSave::kSECCUESS_SAVE:
			cout << clsUtility::createNewLine(2) << clsUtility::createTabs(3) << "Found User Seccussfully :-)" << clsUtility::createNewLine(3);

			_PrintUserCard(userInfo);

		};

		clsUtility::pauseIncludeTab(3, "Enter of any key to back of Main Menu Mange Users (: ");
	}
};

