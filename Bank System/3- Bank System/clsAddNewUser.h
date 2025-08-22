#pragma once
#include <iostream>
#include "clsSecreen.h"
#include "clsUserBank.h"
#include "clsString.h"

using namespace std; 

class clsAddNewUser : protected clsSecreen 
{


private : 


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


	static inline void _HeaderSectionPermissions (void) {

		cout << clsUtility::createNewLine(2);
		cout << clsUtility::createTabs(3) << "|+--------------------------------------------------------------+|" << clsUtility::createNewLine(1);
		cout << clsUtility::createTabs(3) << "|+                       Permission Section                     +|" << clsUtility::createNewLine(1);
		cout << clsUtility::createTabs(3) << "|+--------------------------------------------------------------+|" << clsUtility::createNewLine(2);

	};

	static inline void _FooterPermissionSection(void) {

		cout << clsUtility::createTabs(3) << "|+--------------------------------------------------------------+|" << clsUtility::createNewLine(2);
	}


	static short int _ReadPersmission() {

		short int persmission{};

		if (clsString::convertionUpperCharToLower(clsInputValidate::readCharacterIncludeTab(3, "Do you want to give Full Access of this user [Y/N] : ")) == 'y') {
			return clsUserBank::enChoiseSectionsToAddPermission::ekFULL_ACCESS  ;
		}
		else {

			cout << clsUtility::createNewLine(2) << clsUtility::createTabs(3) << "Do you want to give Access to : " << clsUtility::createNewLine(2); 


			if (clsString::convertionUpperCharToLower(clsInputValidate::readCharacterIncludeTab(3, "Do you want to give Access Show Clients List [Y/N] : ")) == 'y') {
				persmission += clsUserBank::enChoiseSectionsToAddPermission::ekSHOW_LIST_CLIENT;
			};

			if (clsString::convertionUpperCharToLower(clsInputValidate::readCharacterIncludeTab(3, "Do you want to give Access Add New Clients [Y/N] : ")) == 'y') {
				persmission += clsUserBank::enChoiseSectionsToAddPermission::ekADD_NEW_CLIENT;
			};

			if (clsString::convertionUpperCharToLower(clsInputValidate::readCharacterIncludeTab(3, "Do you want to give Access Update Clients [Y/N] : ")) == 'y') {
				persmission += clsUserBank::enChoiseSectionsToAddPermission::ekUPDATE_CLEINT;
			};

			if (clsString::convertionUpperCharToLower(clsInputValidate::readCharacterIncludeTab(3, "Do you want to give Access Delete Clients [Y/N] : ")) == 'y') {
				persmission += clsUserBank::enChoiseSectionsToAddPermission::ekDELETE_CLIENT;
			};

			if (clsString::convertionUpperCharToLower(clsInputValidate::readCharacterIncludeTab(3, "Do you want to give Access Find Clients [Y/N] : ")) == 'y') {
				persmission += clsUserBank::enChoiseSectionsToAddPermission::ekFIND_CLIENT;
			};

			if (clsString::convertionUpperCharToLower(clsInputValidate::readCharacterIncludeTab(3, "Do you want to give Access Transaction [Y/N] : ")) == 'y') {
				persmission += clsUserBank::enChoiseSectionsToAddPermission::ekTRANSACTION;
			};

			if (clsString::convertionUpperCharToLower(clsInputValidate::readCharacterIncludeTab(3, "Do you want to give Access Mange Users [Y/N] : ")) == 'y') {
				persmission += clsUserBank::enChoiseSectionsToAddPermission::ekMANGE_USERS;
			};

			if (clsString::convertionUpperCharToLower(clsInputValidate::readCharacterIncludeTab(3, "Do you want to give Access Register Login Users [Y/N] : ")) == 'y') {
				persmission += clsUserBank::enChoiseSectionsToAddPermission::ekREGISTER_LOGIN_USERS;
			};
		};

		//127 == full access to convert 255 --> -1 
		if (persmission == 255)
			persmission = clsUserBank::enChoiseSectionsToAddPermission::ekFULL_ACCESS ;

		return persmission; 
	}

	static void _ReadInformationClient(clsUserBank &infoUser) {

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


	public :


		static inline void AddNewUser() {


			_DrawMainHeaderSecreen("Add new User Secren");

			string  username { clsInputValidate::readStringIncludeTab(3 , "Enter the Username , Please Sir : ") };

			while (clsUserBank::isFoundUser(username)) {
				username = { clsInputValidate::readStringIncludeTab(3, "Aleart!! Please Enter Another Username Not Exixted : ") };
			};

			clsUserBank userInfo = clsUserBank::getEmptyObjectUserIncludeUsername(username);

			_DrawMainHeaderSecreen("Welcome Section Add", "Information New User");
			_ReadInformationClient(userInfo);

			cout << clsUtility::createNewLine(3) << clsUtility::createTabs(3) << "Information User After Added : " << clsUtility::createNewLine(2);


			clsUserBank::enModeSave saveMode = userInfo.Save();

			switch (saveMode) {


			case clsUserBank::enModeSave::kFAILD_SAVE_EMPTY_OBJECT:

				cout << "\nError Not Save this User \n";
				break;

			case clsUserBank::enModeSave::kSECCUESS_SAVE:

				_PrintUserCard(userInfo);
				cout << clsUtility::createNewLine(2) << clsUtility::createTabs(3) << "Account Addeded Successfully :-)\n";
				break;

			case clsUserBank::enModeSave::kFAILD_USERNAME_IS_EXIXTED:
				cout << "\nError account was not saved because Username is used!\n";

			};

			clsUtility::pauseIncludeTab(3, "Enter of any key to back of Main Menu Mange User(: ");
		}



};

