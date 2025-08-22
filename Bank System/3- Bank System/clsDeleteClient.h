#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsSecreen.h"

#include <string>

using std::cout;
using std::cin; 
using std::endl; 
using std::string; 
using std::to_string; 


class clsDeleteClient : protected clsSecreen 
{

private : 

	static void _PrintClientCard(clsBankClient& informationClient) {

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

	static void deleteCleint(void) {

		if (!clsSecreen::_CheakAccessSuccessfullyOrDenied(clsUserBank::enChoiseSectionsToAddPermission::ekDELETE_CLIENT)) {
			return;
		}
		_DrawMainHeaderSecreen("Delete Client Secren");

		string  accountNumber{ clsInputValidate::readStringIncludeTab(3 , "Enter the Account Number , Please Sir : ") };

		while (!clsBankClient::isFoundClient(accountNumber)) {
			accountNumber = { clsInputValidate::readStringIncludeTab( 3 , "Aleart!! Please Enter Another Account Number Not Exixted : ") };
		};

		clsBankClient clientBank = clsBankClient::Find(accountNumber);
		_PrintClientCard(clientBank);

		char answer{};
		cout << clsUtility::createNewLine(1) << clsUtility::createTabs(3) << "Are you sure to be delete this client [Y/N] : ";
		clsBankClient::enModeSave saveMode = clsBankClient::enModeSave::kFAILD_DELETE_CLIENT;
		cin >> answer;


		if (answer == 'Y' || answer == 'y') {

			if (clientBank.deleteCleint()) {
				cout << clsUtility::createNewLine(2) << clsUtility::createTabs(3) << "Account Addeded Successfully :-) " << clsUtility::createNewLine(3); 
				_PrintClientCard(clientBank);
			}
			else {
				cout << clsUtility::createNewLine(2) << clsUtility::createTabs(3) <<  "Error Of the delete this client , Try agian :-( ";
			}
		}

		clsUtility::pauseIncludeTab(3 , "Enter of any key to back of Main Menu (: ");

	}
};

