#pragma once

#include <iostream>
#include <iomanip>
#include <string>
#include "clsBankClient.h"
#include "clsSecreen.h"


using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::to_string;
using std::setw;
using std::fixed;

class clsAddNewClient : protected clsSecreen   {

private : 
	
	static void _ReadInformationClient(clsBankClient& infoClient) {

		infoClient.setFirstName(clsInputValidate::readStringIncludeTab(3, "Enter the First Name : "));
		infoClient.setLastName(clsInputValidate::readStringIncludeTab(3, "Enter the Last Name : "));
		infoClient.setEmail(clsInputValidate::readStringIncludeTab(3, "Enter the Email : "));
		infoClient.setPhoneNumber(clsInputValidate::readStringIncludeTab(3, "Enter the Phone Number : "));
		infoClient.setPinCode(clsInputValidate::readStringIncludeTab(3, "Enter the Pin Code : "));
		infoClient.setAccountBalance(clsInputValidate::readNumberDoubleIncludeTab(3, "Enter the Account Balance : ", "Please Sir , Enter the Account Balance Valid : "));

	};

	 static void _PrintClientCard(clsBankClient & informationClient) {

		cout << clsUtility::createTabs(3) << "|+--------------------------------------------------------------+|" << clsUtility::createNewLine(3);

		cout << clsUtility::createTabs(4) << "First Name     : " << informationClient.getFirstName() << clsUtility::createNewLine(2);
		cout << clsUtility::createTabs(4) << "Last Name      : " << informationClient.getLastName() << clsUtility::createNewLine(2);
		cout << clsUtility::createTabs(4) << "Email Client   : " << informationClient.getEmail() << clsUtility::createNewLine(2);
		cout << clsUtility::createTabs(4) << "Phone Number   : " << informationClient.getPhoneNUmber() << clsUtility::createNewLine(2);
		cout << clsUtility::createTabs(4) << "Account Number : " << informationClient.getAccountNumber() << clsUtility::createNewLine(2);
		cout << clsUtility::createTabs(4) << "Pin Code       : " << informationClient.getPinCode() << clsUtility::createNewLine(2);
		cout << clsUtility::createTabs(4) << "Account Balance: " << informationClient.getAccountBalance() << clsUtility::createNewLine(3);

		cout << clsUtility::createTabs(3) << "|+--------------------------------------------------------------+|" << clsUtility::createNewLine(1);
	}


public : 



	static inline void AddNewClients() {


		_DrawMainHeaderSecreen("Add new Client Secren");

		if (!clsSecreen::_CheakAccessSuccessfullyOrDenied(clsUserBank::enChoiseSectionsToAddPermission::ekADD_NEW_CLIENT)) {
			return;
		}
		string  accountNumber{ clsInputValidate::readStringIncludeTab(3 , "Enter the Account Number , Please Sir : ") };

		while (clsBankClient::isFoundClient(accountNumber)) {
			accountNumber = { clsInputValidate::readStringIncludeTab(3, "Aleart!! Please Enter Another Account Number Not Exixted : ") };
		};

		clsBankClient clientBank = clsBankClient::getObjectStoredAccountNumber(accountNumber);

		_DrawMainHeaderSecreen("Welcome Section Add" , "Information New Client");
		_ReadInformationClient(clientBank);

		cout << clsUtility::createNewLine(3) << clsUtility::createTabs(3)  << "Information Client After Added : " << clsUtility::createNewLine(2) ;


		clsBankClient::enModeSave saveMode = clientBank.Save();

		switch (saveMode) {


		case clsBankClient::enModeSave::kFAILD_SAVE_EMPTY_OBJECT:

			cout << "\nError Not Save and update this Client \n";
			break;

		case clsBankClient::enModeSave::kSECCUESS_SAVE:

			_PrintClientCard(clientBank);
			cout <<clsUtility::createNewLine(2) << clsUtility::createTabs(3) <<  "Account Addeded Successfully :-)\n";
			break;

		case clsBankClient::enModeSave::kFAILD_ACCOUNT_NUMBER_IS_EXIXTED:
			cout << "\nError account was not saved because account number is used!\n";

		};

		clsUtility::pauseIncludeTab(3 , "Enter of any key to back of main menu(: ");
	}


};

