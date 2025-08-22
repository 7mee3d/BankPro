#pragma once
#include <iostream>
#include "clsSecreen.h"
#include "clsUserBank.h"

#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::to_string;


class clsDeleteUser: protected clsSecreen
{

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

	static void deleteCleint(void) {


		_DrawMainHeaderSecreen("Delete User Secren");

		string  username{ clsInputValidate::readStringIncludeTab(3 , "Enter the Username, Please Sir : ") };

		while (!clsUserBank::isFoundUser(username)) {
			username = { clsInputValidate::readStringIncludeTab(3 , "Aleart!! Please Enter Another Username Not Exixted : ") };
		};

		clsUserBank userInfo = clsUserBank::Find(username);


		if (clsSecreen::_CheakTheUserAdminOrNot(username , "This account cannot be deleted because it is the system administrator")) {
			return;
		}

		_PrintUserCard(userInfo);

		char answer{};
		cout << clsUtility::createNewLine(1) << clsUtility::createTabs(3) << "Are you sure to be delete this User [Y/N] : ";
		clsUserBank::enModeSave saveMode = clsUserBank::enModeSave::kFAILD_DELETE_USER;
		cin >> answer;


		if (answer == 'Y' || answer == 'y') {

			if (userInfo.deleteUser()) {
				cout << clsUtility::createNewLine(2) << clsUtility::createTabs(3) << "User Deleted Successfully :-) " << clsUtility::createNewLine(3);
				_PrintUserCard(userInfo);
			}
			else {
				cout << clsUtility::createNewLine(2) << clsUtility::createTabs(3) << "Error Of the delete this User , Try agian :-( ";
			}
		}

		clsUtility::pauseIncludeTab(3, "Enter of any key to back of Main Menu Mange Users (: ");

	}
};

