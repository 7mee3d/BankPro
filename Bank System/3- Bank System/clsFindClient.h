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


class clsFindClient : protected clsSecreen {


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
	};

public : 

	static void findClient() {

		if (!clsSecreen::_CheakAccessSuccessfullyOrDenied(clsUserBank::enChoiseSectionsToAddPermission::ekFIND_CLIENT)) {
			return;
		}

		_DrawMainHeaderSecreen("Find Client Secren");


		string  accountNumber = clsInputValidate::readStringIncludeTab(3, "Enter the Account Number , Please : ");
		while (!clsBankClient::isFoundClient(accountNumber))
			accountNumber = clsInputValidate::readStringIncludeTab(3, "Please enter of the valid account number : ");



		clsBankClient clientBank = clsBankClient::Find(accountNumber);

		clsBankClient::enModeSave saveMode = clientBank.Save();

		switch (saveMode) {

		case clsBankClient::enModeSave::kFAILD_SAVE_EMPTY_OBJECT:
			cout << clsUtility::createNewLine(1) << clsUtility::createTabs(3) << "Error Not Save and Found this Client" << clsUtility::createNewLine(1);
			break;

		case clsBankClient::enModeSave::kSECCUESS_SAVE:
			cout << clsUtility::createNewLine(2) << clsUtility::createTabs(3) << "Found Client Seccussfully :-)" << clsUtility::createNewLine(3);

			_PrintClientCard(clientBank);

		};

		clsUtility::pauseIncludeTab(3, "Enter of any key to back of Main Menu (: ");
	}
};

