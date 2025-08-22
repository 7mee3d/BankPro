#pragma once
#include <iostream> 
#include <string> 

using namespace std; 
#include "clsBankClient.h" 
#include "clsSecreen.h"

class clsShowTotalBalance : protected clsSecreen 
{

private : 

	static inline void _PrintInformationOneClientShowListClientsBalance(clsBankClient& infoClient) {

		cout << clsUtility::createTabs(1); 
		cout << "| " << left << setw(21) << infoClient.getAccountNumber() << "| ";
		cout << left << setw(45) << infoClient.getFullName() << "| ";
		cout << left << setw(21) << infoClient.getAccountBalance() << "|";
		cout << clsUtility::createNewLine(1);
	};

	static inline void _HeaderShowTotalBalanceAllClients() {

		cout << clsUtility::createTabs(1) << "|+__________________________________________________________________________________________+|" << clsUtility::createNewLine(2);
		cout << clsUtility::createTabs(1) << "|    Account Number    |                    Client Name               |        Balance ($)   |" << clsUtility::createNewLine(2);
		cout << clsUtility::createTabs(1) << "|+__________________________________________________________________________________________+|" << clsUtility::createNewLine(2);

	};

	static inline void _FooterTotalBalanceClients(void) {

		cout << clsUtility::createTabs(1) << "|+__________________________________________________________________________________________+|" << clsUtility::createNewLine(2);
		cout << clsUtility::createTabs(8) << "Total Balance : " << clsBankClient::getTotalBalanceAllClients();
	};


public : 

	static void showListTotalBalanceAllClients(void) {

		vector<clsBankClient> infoClients = clsBankClient::loadDataFromFileToShowClient();

		string const kSUB_TITLE = "Balance list ( " + to_string ( infoClients.size()) +   " ) Client(s)";
		_DrawMainHeaderSecreen("Total Balance Secren" , kSUB_TITLE);
		_HeaderShowTotalBalanceAllClients();

		if (infoClients.size() == 0)
			cout << clsUtility::createNewLine(2) << clsUtility::createTabs(5) << "No Client Available in the System!" << clsUtility::createNewLine(2);
		else
			for (clsBankClient infoClient : infoClients)
				_PrintInformationOneClientShowListClientsBalance(infoClient);




		_FooterTotalBalanceClients();
		cout << clsUtility::createNewLine(3);
		clsUtility::pauseIncludeTab(3, "Enter of any key to back the Main Menu Transaction");

	};

};

