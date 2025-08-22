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



class clsUpdateUser : protected clsSecreen
{


private:

	enum enChoiseSectionsToAddPermission {

		ekFULL_ACCESS = -1,
		ekSHOW_LIST_CLIENT = 1,
		ekADD_NEW_CLIENT = 2,
		ekDELETE_CLIENT = 4,
		ekUPDATE_CLEINT = 8,
		ekFIND_CLIENT = 16,
		ekTRANSACTION = 32,
		ekMANGE_USERS = 64

	};

	static short int _ReadPersmission() {

		short int persmission{};

		if (clsString::convertionUpperCharToLower(clsInputValidate::readCharacterIncludeTab(3, "Do you want to give Full Access of this user [Y/N] : ")) == 'y') {
			return enChoiseSectionsToAddPermission::ekFULL_ACCESS;
		}
		else {

			cout << clsUtility::createNewLine(2) << clsUtility::createTabs(3) << "Do you want to give Access to : " << clsUtility::createNewLine(2);


			if (clsString::convertionUpperCharToLower(clsInputValidate::readCharacterIncludeTab(3, "Do you want to give Access Show Clients List [Y/N] : ")) == 'y') {
				persmission += enChoiseSectionsToAddPermission::ekSHOW_LIST_CLIENT;
			};

			if (clsString::convertionUpperCharToLower(clsInputValidate::readCharacterIncludeTab(3, "Do you want to give Access Add New Clients [Y/N] : ")) == 'y') {
				persmission += enChoiseSectionsToAddPermission::ekADD_NEW_CLIENT;
			};

			if (clsString::convertionUpperCharToLower(clsInputValidate::readCharacterIncludeTab(3, "Do you want to give Access Update Clients [Y/N] : ")) == 'y') {
				persmission += enChoiseSectionsToAddPermission::ekUPDATE_CLEINT;
			};

			if (clsString::convertionUpperCharToLower(clsInputValidate::readCharacterIncludeTab(3, "Do you want to give Access Delete Clients [Y/N] : ")) == 'y') {
				persmission += enChoiseSectionsToAddPermission::ekDELETE_CLIENT;
			};

			if (clsString::convertionUpperCharToLower(clsInputValidate::readCharacterIncludeTab(3, "Do you want to give Access Find Clients [Y/N] : ")) == 'y') {
				persmission += enChoiseSectionsToAddPermission::ekFIND_CLIENT;
			};

			if (clsString::convertionUpperCharToLower(clsInputValidate::readCharacterIncludeTab(3, "Do you want to give Access Transaction [Y/N] : ")) == 'y') {
				persmission += enChoiseSectionsToAddPermission::ekTRANSACTION;
			};

			if (clsString::convertionUpperCharToLower(clsInputValidate::readCharacterIncludeTab(3, "Do you want to give Access Mange Users [Y/N] : ")) == 'y') {
				persmission += enChoiseSectionsToAddPermission::ekMANGE_USERS;
			};
			if (clsString::convertionUpperCharToLower(clsInputValidate::readCharacterIncludeTab(3, "Do you want to give Access Register Login Users [Y/N] : ")) == 'y') {
				persmission += clsUserBank::enChoiseSectionsToAddPermission::ekREGISTER_LOGIN_USERS;
			};
		};

		//127 == full access to convert 255 --> -1 
		if (persmission == 255)
			persmission = enChoiseSectionsToAddPermission::ekFULL_ACCESS;

		return persmission;
	}

	static inline void _HeaderSectionPermissions(void) {

		cout << clsUtility::createNewLine(2);
		cout << clsUtility::createTabs(3) << "|+--------------------------------------------------------------+|" << clsUtility::createNewLine(1);
		cout << clsUtility::createTabs(3) << "|+                       Permission Section                     +|" << clsUtility::createNewLine(1);
		cout << clsUtility::createTabs(3) << "|+--------------------------------------------------------------+|" << clsUtility::createNewLine(2);

	};


	static inline void _FooterPermissionSection(void) {

		cout << clsUtility::createTabs(3) << "|+--------------------------------------------------------------+|" << clsUtility::createNewLine(2);
	}
	static void _ReadInformationClient(clsUserBank& infoUser) {

		infoUser.setFirstName(clsInputValidate::readStringIncludeTab(3, "Enter the First Name : "));
		infoUser.setLastName(clsInputValidate::readStringIncludeTab(3, "Enter the Last Name : "));
		infoUser.setEmail(clsInputValidate::readStringIncludeTab(3, "Enter the Email : "));
		infoUser.setPhoneNumber(clsInputValidate::readStringIncludeTab(3, "Enter the Phone Number : "));
		//infoUser.setUsername(clsInputValidate::readStringIncludeTab(3, "Enter the Username : "));
		infoUser.setPassword(clsInputValidate::readStringIncludeTab(3, "Enter the Password : "));


		_HeaderSectionPermissions();
		infoUser.setPersmision(_ReadPersmission());
		_FooterPermissionSection();
	};



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


	static void updateUserInformation(void) {

		_DrawMainHeaderSecreen("Update User Secren");

		string  username = clsInputValidate::readStringIncludeTab(3, "Enter the Username , Please : ");
		while (!clsUserBank::isFoundUser(username))
			username = clsInputValidate::readStringIncludeTab(3, "Please enter of the valid Username : ");

		clsUserBank userInfo = clsUserBank::Find(username);

		if (clsSecreen::_CheakTheUserAdminOrNot(username, "This account cannot be Updated because it is the system administrator")) {
			return;
		}

		_PrintUserCard(userInfo);
		cout << clsUtility::createNewLine(2) << clsUtility::createTabs(3) << "Update Client information : " << clsUtility::createNewLine(2);

		_DrawMainHeaderSecreen("Welcome Section Update", "New Information User");
	
		_ReadInformationClient(userInfo);

		clsUserBank::enModeSave saveMode = userInfo.Save();

		switch (saveMode) {

		case clsUserBank::enModeSave::kFAILD_SAVE_EMPTY_OBJECT:
			cout << clsUtility::createNewLine(1) << clsUtility::createTabs(3) << "Error Not Save and update this Client" << clsUtility::createNewLine(1);
			break;

		case clsUserBank::enModeSave::kSECCUESS_SAVE:
			cout << clsUtility::createNewLine(2) << clsUtility::createTabs(3) << "Update This Client Seccussfully :-)" << clsUtility::createNewLine(3);

			_PrintUserCard(userInfo);

		};

		clsUtility::pauseIncludeTab(3, "Enter of any key to back of Main Menu Mange Users (: ");


	}
};

