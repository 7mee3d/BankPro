#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsSecreen.h"

using namespace std; 


class clsDepositeOperation : protected clsSecreen 
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


	static void depositeOperation(void) {


		_DrawMainHeaderSecreen("Deposite Balance Secren" , "Transaction Secren");

		string  accountNumber{ clsInputValidate::readStringIncludeTab(3 , "Enter the Account Number , Please Sir : ") };

		while (!clsBankClient::isFoundClient(accountNumber)) {
			accountNumber = { clsInputValidate::readStringIncludeTab(3 , "Aleart!! Please Enter Another Account Number Not Exixted : ") };
		};

		clsBankClient clientBank = clsBankClient::Find(accountNumber);
	     _PrintClientCard(clientBank);
		 cout << clsUtility::createNewLine(1); 
		 double const kAMOUNT = clsInputValidate::readNumberDoubleIncludeTab(3, "Enter the Amount To Be Deposite : ", "Please Enter The Amount Valid : ");

		 
		char answer{};
		cout << clsUtility::createNewLine(1) << clsUtility::createTabs(3) << "Are you sure to be Deposite Amount of this client [Y/N] : ";
		cin >> answer;

		if (answer == 'Y' || answer == 'y') {

			    clientBank.deposite(kAMOUNT);
				_PrintClientCard(clientBank);
				cout << clsUtility::createNewLine(2) << clsUtility::createTabs(3) << "Account Addeded Amount Successfully :-) " << clsUtility::createNewLine(1);
				cout << clsUtility::createNewLine(2) << clsUtility::createTabs(3) << "The New Balance After Deposite : " << clientBank.getAccountBalance() << clsUtility::createNewLine(3);
			
		}
		else {
			cout << clsUtility::createNewLine(3) << clsUtility::createTabs(3) << "The Operation was Consolled , Try Agian another Time :-( ";

		}

		clsUtility::pauseIncludeTab(3, "Enter of any key to back of Main Menu Transaction (: ");

	}
};

