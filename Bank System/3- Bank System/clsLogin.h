#pragma once
#include <iostream> 
#include "clsSecreen.h" 
#include "clsUillity.h" 
#include "clsInputValidate.h" 
#include "clsUserBank.h" 
#include "GlobalVarablesAndConstants.h" 
#include "clsMainMenuSecreen.h" 
#include "clsRegisterLogUsers.h" 



using namespace std; 
class clsLogin : protected clsSecreen 
{

private : 

	static inline void _Login() {



		bool loginFlag = false;
		unsigned short int counterFiald = 1; 
		
		do {

			if (counterFiald == 3) {
				cout << clsUtility::createNewLine(1) << clsUtility::createTabs(3) << "Your are locked 3 Faild Trials " << clsUtility::createNewLine(1);
				exit(0); 
			} 
			
			if (loginFlag) {
				cout << clsUtility::createNewLine(2) << clsUtility::createTabs(3) << "Invalid Username/Password ,Try Again : ";
				++counterFiald; 
			}
			
		
			cout << clsUtility::createNewLine(2); 
			string const kUSERNAME = clsInputValidate::readStringIncludeTab(3, "Enter the Username : ");
			string const kPASSWORD = clsInputValidate::readStringIncludeTab(3, "Enter the Password : ");

			currentUser = clsUserBank::Find(kUSERNAME, kPASSWORD);
			loginFlag = currentUser.isEmpty();

		} while (loginFlag);

		clsUserBank::SaveRegisterUserLoginTheBank(currentUser);

		clsMainMenuSecreen::mainMenuSecren();
	};

	static inline void _HeaderLoginSecren (void) {

		cout << clsUtility::createNewLine(1);
		cout << clsUtility::createTabs(3) << "|+--------------------------------------------------------------+|" << clsUtility::createNewLine(1);
		cout << clsUtility::createTabs(3) << "|+                           Login Secreen                      +|" << clsUtility::createNewLine(1);
		cout << clsUtility::createTabs(3) << "|+--------------------------------------------------------------+|" << clsUtility::createNewLine(2);

	};
	static inline void _FooterLoginSecren(void) {

		cout << clsUtility::createTabs(3) << "|+--------------------------------------------------------------+|" << clsUtility::createNewLine(2);
	};


public : 

	static inline void loginBank (){

		clsUtility::clearDetailesInSecren();

		_DrawMainHeaderSecreen("     Login Secren ");
		_HeaderLoginSecren();
		_Login();
		_FooterLoginSecren();
	}

};

