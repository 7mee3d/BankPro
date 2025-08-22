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



class clsUpdateClient : protected clsSecreen 
{


private:

	static void _ReadInformationClient(clsBankClient& infoClient) {

		infoClient.setFirstName(clsInputValidate::readStringIncludeTab(3, "Enter the First Name : "));
		infoClient.setLastName(clsInputValidate::readStringIncludeTab(3, "Enter the Last Name : "));
		infoClient.setEmail(clsInputValidate::readStringIncludeTab(3, "Enter the Email : "));
		infoClient.setPhoneNumber(clsInputValidate::readStringIncludeTab(3, "Enter the Phone Number : "));
		infoClient.setPinCode(clsInputValidate::readStringIncludeTab(3, "Enter the Pin Code : "));
		infoClient.setAccountBalance(clsInputValidate::readNumberDoubleIncludeTab(3, "Enter the Account Balance : ", "Please Sir , Enter the Account Balance Valid : "));

	};

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


	static void updateClientInformation(void) {

		if (!clsSecreen::_CheakAccessSuccessfullyOrDenied(clsUserBank::enChoiseSectionsToAddPermission::ekUPDATE_CLEINT)) {
			return;
		}
		_DrawMainHeaderSecreen("Update Client Secren");


		string  accountNumber = clsInputValidate::readStringIncludeTab(3 , "Enter the Account Number , Please : ");
		while (!clsBankClient::isFoundClient(accountNumber)) 
			accountNumber = clsInputValidate::readStringIncludeTab( 3 , "Please enter of the valid account number : ");



		clsBankClient clientBank = clsBankClient::Find(accountNumber);
		_PrintClientCard(clientBank);
		cout << clsUtility::createNewLine(2) << clsUtility::createTabs(3) << "Update Client information : "<< clsUtility::createNewLine(2);

		_DrawMainHeaderSecreen("Welcome Section Update", "New Information Client");
		_ReadInformationClient(clientBank);

		clsBankClient::enModeSave saveMode = clientBank.Save();

		switch (saveMode) {

		case clsBankClient::enModeSave::kFAILD_SAVE_EMPTY_OBJECT:
			cout << clsUtility::createNewLine(1) << clsUtility::createTabs(3) << "Error Not Save and update this Client" << clsUtility::createNewLine(1);
			break;

		case clsBankClient::enModeSave::kSECCUESS_SAVE:
			cout <<  clsUtility::createNewLine(2) << clsUtility::createTabs(3) <<  "Update This Client Seccussfully :-)" << clsUtility::createNewLine(3);

			_PrintClientCard(clientBank);

		};

		clsUtility::pauseIncludeTab(3 , "Enter of any key to back of Main Menu (: ");


	}
};

