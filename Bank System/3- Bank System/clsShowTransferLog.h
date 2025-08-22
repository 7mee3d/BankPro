#pragma once
#include<iostream>
#include "clsBankClient.h" 
#include <string> 
#include <vector> 
#include "clsSecreen.h" 
#include "clsString.h" 


class clsShowTransferLog : protected clsSecreen 
{

private : 

	struct _StInformationTransferHistory {

		string dateTime{ "" }; 
		string  soruseAccountNumberClient{ "" };
		string  destenationAccountNumberClient{ "" };
		double amount{};
		double soruseAccountBalanceAfterTransferClient{};
		double destenationAccountBalanceAfterTransferClient{};
		string username{ "" };

	};

	static inline vector <_StInformationTransferHistory> _LoadInformationLinesFromFile() {

		vector < _StInformationTransferHistory > vInformationTransferHistory;
		fstream file;
		file.open("TransferLog.txt", ios::in);

		if (file.is_open()) {


			string line;
			_StInformationTransferHistory informationTransferOne;

			while (getline(file, line)) {

				informationTransferOne = _ConvertLineToDataRecord(line, "#//#");
				vInformationTransferHistory.push_back(informationTransferOne);


			}

			file.close();

		}

		return vInformationTransferHistory;
	}

	static inline _StInformationTransferHistory  _ConvertLineToDataRecord(string const kLINE, string const& kSEPARATOR) {

		_StInformationTransferHistory infoTransfer;

		vector<string> inforamtionLineTransfer = clsString::splitWordInText(kLINE, kSEPARATOR);

		infoTransfer.dateTime = inforamtionLineTransfer[0];
		infoTransfer.soruseAccountNumberClient = inforamtionLineTransfer[1];
		infoTransfer.destenationAccountNumberClient = inforamtionLineTransfer[2];
		infoTransfer.amount = stod(inforamtionLineTransfer[3]);
		infoTransfer.soruseAccountBalanceAfterTransferClient = stod(inforamtionLineTransfer[4]);
		infoTransfer.destenationAccountBalanceAfterTransferClient = stod(inforamtionLineTransfer[5]);
		infoTransfer.username = inforamtionLineTransfer[6];

		return infoTransfer;


	};

	static inline void _HeaderShowRegisterLoginUsers() {

		cout <<  "|+__________________________________________________________________________________________________________________________________________________________________+|" << clsUtility::createNewLine(1);
		cout <<  "|              Date/Time            | Source Acc.Number |Destination Acc.Number|    Amount    |Source Balance A.Transfer|Destenation Balance A.Transfer|   Username  |" << clsUtility::createNewLine(1);
		cout << "|+__________________________________________________________________________________________________________________________________________________________________+|" << clsUtility::createNewLine(2);

	};

	static inline void _PrintInformationOneTransferLog (_StInformationTransferHistory infoTransferHistory ) {


		cout << "| " << left << setw(34) << infoTransferHistory.dateTime << "| ",
			cout << left << setw(18) << infoTransferHistory.soruseAccountNumberClient << "| ",
			cout << left << setw(21) << infoTransferHistory.destenationAccountNumberClient << "| ",
			cout << left << setw(13) << infoTransferHistory.amount << "| ",
			cout << left << setw(24) << infoTransferHistory.soruseAccountBalanceAfterTransferClient << "| ",
			cout << left << setw(29) << infoTransferHistory.destenationAccountBalanceAfterTransferClient << "| ",
			cout << left << setw(12) << infoTransferHistory.username << "| ";



		cout << clsUtility::createNewLine(1);

	};

	static inline void _FooterShowRegisterLoginUsers() {
		cout << clsUtility::createNewLine(1) <<  "|+__________________________________________________________________________________________________________________________________________________________________+|" << clsUtility::createNewLine(2);

	}



public:


	static inline void printTransferHistoryBalances(void) {

		vector < _StInformationTransferHistory> infoTransferHistory = _LoadInformationLinesFromFile();

		string const kSUB_TITIL = "( " + to_string(infoTransferHistory.size()) + " ) Record(s) .";
		_DrawMainHeaderSecreen("Transfer History", kSUB_TITIL);
		_HeaderShowRegisterLoginUsers();
		for (_StInformationTransferHistory const infoOneTransferHistory : infoTransferHistory)
			_PrintInformationOneTransferLog(infoOneTransferHistory);

		_FooterShowRegisterLoginUsers();
		clsUtility::createNewLine(2); 
		clsUtility::pauseIncludeTab(4, "Enter of the any key in the Keyborad to back a Main Menu Transaction"); 
	}


};

