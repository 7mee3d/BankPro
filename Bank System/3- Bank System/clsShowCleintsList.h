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

class clsShowCleintsList : protected clsSecreen 
{

private : 

	static inline void _printInformationOneClientShowListClients(clsBankClient& infoClient) {

		cout << "| " << left << setw(17) << infoClient.getAccountNumber() << "| ",
			cout << left << setw(11) << infoClient.getPinCode() << "| ",
			cout << left << setw(23) << infoClient.getFullName() << "| ",
			cout << left << setw(36) << infoClient.getEmail() << "| ",
			cout << left << setw(18) << infoClient.getPhoneNUmber() << "| ",
			cout << left << setw(16) << infoClient.getAccountBalance() << "|";
	
		
		cout << clsUtility::createNewLine(1); 
		
	};

	static inline void _HeaderShowClientsList() {

		cout << "|+__________________________________________________________________________________________________________________________________+|" << clsUtility::createNewLine(1);
		cout << "|  Account Number  |  Pin Code  |       Client Name      |                Email                |       Phone       |    Balance ($)  |" << clsUtility::createNewLine(1);
		cout << "|+__________________________________________________________________________________________________________________________________+|" << clsUtility::createNewLine(1);

	};

	static inline void _FooterShowClientsList(void) {

		cout << "|+__________________________________________________________________________________________________________________________________+|" << clsUtility::createNewLine(1);

	}

public : 

	static inline void showListClients() {

		if (!clsSecreen::_CheakAccessSuccessfullyOrDenied(clsUserBank::enChoiseSectionsToAddPermission::ekSHOW_LIST_CLIENT)) {
			return; 
		}
		vector<clsBankClient> infoClients = clsBankClient::loadDataFromFileToShowClient();

		string const kTITLE = "Show Clients List Secren";
		string const kSUB_TITLE =   "Client list ( " + to_string(infoClients.size()) +  " ) Client(s)";

		_DrawMainHeaderSecreen(kTITLE, kSUB_TITLE);
		_HeaderShowClientsList();

		if (infoClients.size() == 0)
			cout <<clsUtility::createTabs(4) <<  "No Client Available in the System!" << clsUtility::createNewLine(1);
		else
			for (clsBankClient infoClient : infoClients) {

				_printInformationOneClientShowListClients(infoClient);

			};


		_FooterShowClientsList();
		clsUtility::pauseIncludeTab( 5, "Press any key to back of the Main Menu (:"); 
	
	};

};

