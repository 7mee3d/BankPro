#pragma once
#include <iostream>
#include "clsSecreen.h"
#include "clsInputValidate.h" 
#include "clsShowCleintsList.h"
#include "clsAddNewClient.h"
#include "clsDeleteClient.h"
#include "clsUpdateClient.h"
#include "clsFindClient.h"
#include "clsTransaction.h"
#include "clsMangeUserSecren.h"
#include "clsRegisterLogUsers.h"
#include "clsMainMenuCurrencyExchange.h"

using namespace std; 


class clsMainMenuSecreen : protected clsSecreen 
{


private : 

	enum enChoiseSectionPerform {


		ekSHOW_MAIN_LIST_CLEINTS = 1,
		ekADD_NEW_CLIENT = 2,
		ekDELETE_CLEINT = 3,
		ekUPDATE_CLEINT = 4,
		ekFIND_CLEINT = 5,
		ekTRANSACTION = 6,
		ekMANGE_USERS = 7,
		ekREGISTER_LOGIN_INFORMATION_USERS = 8 , 
		ekCUREENCY = 9 ,
		ekLOGOUT_BANK = 10 
	};


	static inline unsigned short int _ReadChoiseSectionToBePerform() {

		unsigned short int  choiseSection = clsInputValidate::readNumberIntegerBetweenIncludeTabs(3, 1, 10, "Enter the Choise Between [ 1 - 10 ] : ", "Please Sir , Enter a valid Choise : ");

		return choiseSection;

	};

	static inline void _HeaderMainMenu(void) {

		cout << clsUtility::createNewLine(1);
		cout << clsUtility::createTabs(3) << "|+---------------------------------------------------------------+|" << clsUtility::createNewLine(1);
		cout << clsUtility::createTabs(3) << "|+                         Main Menu Secreen                     +|" << clsUtility::createNewLine(1);
		cout << clsUtility::createTabs(3) << "|+---------------------------------------------------------------+|" << clsUtility::createNewLine(2);

	};

	static inline void _BodyMainMenu(void) {

									   
		cout << clsUtility::createNewLine(1);
		cout << clsUtility::createTabs(3) << "|+ [01]- Show Client List                                        +|" << clsUtility::createNewLine(1);
		cout << clsUtility::createTabs(3) << "|+ [02]- Add New Client                                          +|" << clsUtility::createNewLine(1);
		cout << clsUtility::createTabs(3) << "|+ [03]- Delete Client                                           +|" << clsUtility::createNewLine(1);
		cout << clsUtility::createTabs(3) << "|+ [04]- Update Client                                           +|" << clsUtility::createNewLine(1);
		cout << clsUtility::createTabs(3) << "|+ [05]- Find Client                                             +|" << clsUtility::createNewLine(1);
		cout << clsUtility::createTabs(3) << "|+ [06]- Transaction                                             +|" << clsUtility::createNewLine(1);
		cout << clsUtility::createTabs(3) << "|+ [07]- Mange Users                                             +|" << clsUtility::createNewLine(1);
		cout << clsUtility::createTabs(3) << "|+ [08]- Register Login                                          +|" << clsUtility::createNewLine(1);
		cout << clsUtility::createTabs(3) << "|+ [09]- Currency Exchange                                       +|" << clsUtility::createNewLine(1);
		cout << clsUtility::createTabs(3) << "|+ [10]- Logout                                                  +|" << clsUtility::createNewLine(2);

	};

	static inline void _FooterMainMenu(void) {


		cout << clsUtility::createTabs(3) << "|+---------------------------------------------------------------+|" << clsUtility::createNewLine(2);

	};


	static void _ShowListClientSecren() {

		clsShowCleintsList::showListClients(); 
	}

	static void _AddNewClientSecren() {

		clsAddNewClient::AddNewClients();

	}

	static void _DeleteCleintSecren() {

		clsDeleteClient::deleteCleint(); 

	}

	static void _UpdateCleintSecren() {

		clsUpdateClient::updateClientInformation();
	}

	static void _FindCleintSecren() {

		clsFindClient::findClient(); 

	}


	static void _TransactionSecren() {
		clsTransaction::mainMenuTransacion();
	}

	static void _MnageUserSecren() {
		clsMangeUserSecren::mangeUserMainMenuSecren(); 
	}

	static void _RegisterLoginInformation(void) {

		clsRegisterLogUsers::showListRegistersLoginUsers();
	};

	static void _CurrencyList (void) {

		clsMainMenuCurrencyExchange::mainMenuCurrencyExchange(); 
	};

	static void _LogoutSecren() {

		currentUser = clsUserBank::Find("", ""); 
	};



	static void _PerformSectionMainMenu(enChoiseSectionPerform const& kCHOISE_SECTION_TO_BE_PERFORM) {

		//Clear All Dateiles in the secren 
		clsUtility::clearDetailesInSecren();


		switch (kCHOISE_SECTION_TO_BE_PERFORM) {

		case enChoiseSectionPerform::ekSHOW_MAIN_LIST_CLEINTS:
			_ShowListClientSecren();
		  	mainMenuSecren();
			break;

		case enChoiseSectionPerform::ekADD_NEW_CLIENT:
			_AddNewClientSecren();
			mainMenuSecren();
			break;

		case enChoiseSectionPerform::ekDELETE_CLEINT:
			_DeleteCleintSecren();
			mainMenuSecren();
			break;

		case enChoiseSectionPerform::ekUPDATE_CLEINT:
			_UpdateCleintSecren();
			mainMenuSecren();
			break;

		case enChoiseSectionPerform::ekFIND_CLEINT:

			_FindCleintSecren();
			mainMenuSecren();

			break;

		case enChoiseSectionPerform::ekTRANSACTION:
			_TransactionSecren();
			mainMenuSecren();
			break;

		case enChoiseSectionPerform::ekMANGE_USERS:
			_MnageUserSecren();
			mainMenuSecren();
			break;

		case enChoiseSectionPerform::ekREGISTER_LOGIN_INFORMATION_USERS:
			_RegisterLoginInformation();
			mainMenuSecren();
			break;

		case enChoiseSectionPerform::ekCUREENCY:
			_CurrencyList();
			mainMenuSecren();
			break;
		case enChoiseSectionPerform::ekLOGOUT_BANK:
			_LogoutSecren();

		}
	};

public : 

	static inline void mainMenuSecren (void) {

		//First Step : Clear All any dateiles in the Secren 
		//Secound Step : Print the Header Secren 
		clsUtility::clearDetailesInSecren();
		clsSecreen::_DrawMainHeaderSecreen("Welcome Main Menu Secren", "Welcome Sir");

		//Third Step : Print Header Main Menu
		_HeaderMainMenu();
		//Fourth Step : Print the Body Main Menu 
		_BodyMainMenu();
		//Fiveth Step : Print the Footer Main Menu 
		_FooterMainMenu();
		

		//Perform The Operation after the enterd option to be you need
		_PerformSectionMainMenu((enChoiseSectionPerform)_ReadChoiseSectionToBePerform());
	};



};

