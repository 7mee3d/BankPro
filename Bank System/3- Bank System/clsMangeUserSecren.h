#pragma once
#include <iostream>
#include"clsBankClient.h" 
#include"clsMainMenuSecreen.h" 
#include"clsSecreen.h" 
#include"clsShowUserList.h" 
#include"clsAddNewUser.h" 
#include"clsDeleteUser.h" 
#include"clsUpdateUser.h" 
#include"clsFindUser.h" 

using namespace std; 


class clsMangeUserSecren : protected clsSecreen 
{


private:

	static enum enMangeUserChoise {

		ekSHOW_LIST_USER = 1,
		ekADD_NEW_USER = 2 , 
		ekDELETE_USER = 3 , 
		ekUPDATE_USER = 4 , 
		ekFIND_USER = 5 , 
		ekBACK_TO_MAIN_MENU = 6 
	};

	static inline unsigned short int _ReadChoiseSectionToBePerformMangeUser(void) {

		unsigned short int  choiseSection = clsInputValidate::readNumberIntegerBetweenIncludeTabs(3, 1, 8, "Enter the Choise Between [ 1 - 6 ] : ", "Please Sir , Enter a valid Choise : ");

		return choiseSection;

	};

	static inline void _ShowListUsers(void) {

		clsShowUserList::showListUsers(); 
	}
	static inline void _AddNewUser (void) {
		clsAddNewUser::AddNewUser(); 
	}
	static inline void _DeleteUser(void) {
		clsDeleteUser::deleteCleint(); 
	}

	static inline void _UpdateUser(void) {
		clsUpdateUser::updateUserInformation();
	}
	static inline void _FindUser(void) {
		clsFindUser::findUser();
	}
	

	static inline void _HeaderMainMenuMangeUser(void) {

		cout << clsUtility::createNewLine(1);
		cout << clsUtility::createTabs(3) << "|+--------------------------------------------------------------+|" << clsUtility::createNewLine(1);
		cout << clsUtility::createTabs(3) << "|+                     Mange User Menu Secreen                  +|" << clsUtility::createNewLine(1);
		cout << clsUtility::createTabs(3) << "|+--------------------------------------------------------------+|" << clsUtility::createNewLine(2);

	};


	static inline void _BodyMangeUserMenu(void) {


		cout << clsUtility::createNewLine(1);
		cout << clsUtility::createTabs(3) << "|+ [1]- List Users                                              +|" << clsUtility::createNewLine(1);
		cout << clsUtility::createTabs(3) << "|+ [2]- Add New User                                            +|" << clsUtility::createNewLine(1);
		cout << clsUtility::createTabs(3) << "|+ [3]- Delete User                                             +|" << clsUtility::createNewLine(1);
		cout << clsUtility::createTabs(3) << "|+ [4]- Update User                                             +|" << clsUtility::createNewLine(1);
		cout << clsUtility::createTabs(3) << "|+ [5]- Find User                                               +|" << clsUtility::createNewLine(1);
		cout << clsUtility::createTabs(3) << "|+ [6]- Back To Main Menu                                       +|" << clsUtility::createNewLine(2);


	};

	static inline void _FooterMangeUserMenu(void) {


		cout << clsUtility::createTabs(3) << "|+--------------------------------------------------------------+|" << clsUtility::createNewLine(2);

	};


	static void _PerformMangeUserSection(enMangeUserChoise const& kMANGE_USER_CHOISE) {


		clsUtility::clearDetailesInSecren();

		switch (kMANGE_USER_CHOISE) {

		case enMangeUserChoise::ekSHOW_LIST_USER: {

			_ShowListUsers();
			mangeUserMainMenuSecren();

			break;
		};
		case enMangeUserChoise::ekADD_NEW_USER: {
			_AddNewUser();
			mangeUserMainMenuSecren();

			break;
		};

		case enMangeUserChoise::ekDELETE_USER: {
			_DeleteUser();
			mangeUserMainMenuSecren();

			break;
		};

		case enMangeUserChoise::ekUPDATE_USER: {
			_UpdateUser();
			mangeUserMainMenuSecren();
			break;

		};
		case enMangeUserChoise::ekFIND_USER: {
			_FindUser();
			mangeUserMainMenuSecren();
			break;

		};
		case enMangeUserChoise::ekBACK_TO_MAIN_MENU: {};

		}
	};

	public : 

		static inline void mangeUserMainMenuSecren(void) {

			clsUtility::clearDetailesInSecren();
			if (!clsSecreen::_CheakAccessSuccessfullyOrDenied(clsUserBank::enChoiseSectionsToAddPermission::ekMANGE_USERS)) {
				return;
			}
			_DrawMainHeaderSecreen("Mange User Secren");

			_HeaderMainMenuMangeUser();
			_BodyMangeUserMenu();
			_FooterMangeUserMenu();

			_PerformMangeUserSection((enMangeUserChoise)_ReadChoiseSectionToBePerformMangeUser());
		};

};

