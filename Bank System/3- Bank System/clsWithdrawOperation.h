#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsSecreen.h"


class clsWithdrawOperation : protected clsSecreen
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

	static void withdrawOperation(void) {


		_DrawMainHeaderSecreen("Withdraw Balance Secren", "Transaction Secren");

		string  accountNumber{ clsInputValidate::readStringIncludeTab(3 , "Enter the Account Number , Please Sir : ") };

		while (!clsBankClient::isFoundClient(accountNumber)) {
			accountNumber = { clsInputValidate::readStringIncludeTab(3 , "Aleart!! Please Enter Another Account Number Not Exixted : ") };
		};

		clsBankClient clientBank = clsBankClient::Find(accountNumber);
		_PrintClientCard(clientBank);
		cout << clsUtility::createNewLine(1);
		double const kAMOUNT = clsInputValidate::readNumberDoubleIncludeTab(3, "Enter the Amount To Be Withdraw : ", "Please Enter The Amount Valid : ");


		char answer{};
		cout << clsUtility::createNewLine(1) << clsUtility::createTabs(3) << "Are you sure to be withdraw Amount of this client [Y/N] : ";
		cin >> answer;

		if (answer == 'Y' || answer == 'y') {

			if (clientBank.withdraw(kAMOUNT)) {
				_PrintClientCard(clientBank);
				cout << clsUtility::createNewLine(2) << clsUtility::createTabs(3) << "Account withdraw Amount Successfully :-) " << clsUtility::createNewLine(1);
				cout << clsUtility::createNewLine(2) << clsUtility::createTabs(3) << "The New Balance After withdraw : " << clientBank.getAccountBalance() << clsUtility::createNewLine(3);
			}
			else {

				cout << clsUtility::createNewLine(3) << clsUtility::createTabs(3) << "Sorry Can't be perform this operation";
				cout << clsUtility::createNewLine(1) << clsUtility::createTabs(3) << "Becouse Balance do'nt Have Amount Enough";
				cout << clsUtility::createNewLine(1) << clsUtility::createTabs(3) << "Try again later :-( ";

			}
		}
		else {
			cout << clsUtility::createNewLine(3) << clsUtility::createTabs(3) << "The Operation was Consolled , Try Agian another Time :-( ";

		}

		clsUtility::pauseIncludeTab(3, "Enter of any key to back of Main Menu Transaction (: ");

	}
};

