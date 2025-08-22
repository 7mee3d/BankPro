#pragma once
#include <iostream>

#include "clsBankClient.h"
#include "clsMainMenuSecreen.h"
#include "clsSecreen.h"
#include "clsDepositeOperation.h"
#include "clsWithdrawOperation.h"
#include "clsShowTotalBalance.h"
#include "clsTransferBalance.h"
#include "clsShowTransferLog.h"

using namespace std; 



class clsTransaction : protected clsSecreen 
{

private : 

	static enum enTransactionChoise {
			
		ekDEPOSITE_OPERATION = 1 , 
		ekWITHDRAW_OPERATION = 2 ,
		ekSHOW_TOTAL_BALANCE = 3 ,
		ekTRANSFER_BETWEEN_CLEINTS  = 4 ,
		ekSHOW_TRANSFER_HISTORY   = 5 ,
		ekBACT_MAIN_MENU_SECREN = 6 

	};

	static inline unsigned short int _ReadChoiseSectionToBePerformTransaction() {

		unsigned short int  choiseSection = clsInputValidate::readNumberIntegerBetweenIncludeTabs(3, 1, 6, "Enter the Choise Between [ 1 - 6 ] : ", "Please Sir , Enter a valid Choise : ");

		return choiseSection;

	};

	static inline void _HeaderMainMenuTransaction(void) {

		cout << clsUtility::createNewLine(1);
		cout << clsUtility::createTabs(3) << "|+--------------------------------------------------------------+|" << clsUtility::createNewLine(1);
		cout << clsUtility::createTabs(3) << "|+                    Transaction Menu Secreen                  +|" << clsUtility::createNewLine(1);
		cout << clsUtility::createTabs(3) << "|+--------------------------------------------------------------+|" << clsUtility::createNewLine(2);

	};

	static inline void _BodyTransactionMenu(void) {


		cout << clsUtility::createNewLine(1);
		cout << clsUtility::createTabs(3) << "|+ [1]- Deposite Operation                                      +|" << clsUtility::createNewLine(1);
		cout << clsUtility::createTabs(3) << "|+ [2]- Withdraw Operation                                      +|" << clsUtility::createNewLine(1);
		cout << clsUtility::createTabs(3) << "|+ [3]- Total Balance                                           +|" << clsUtility::createNewLine(1);
		cout << clsUtility::createTabs(3) << "|+ [4]- Transfer Between Clients                                +|" << clsUtility::createNewLine(1);
		cout << clsUtility::createTabs(3) << "|+ [5]- Show Transfer History                                   +|" << clsUtility::createNewLine(1);
		cout << clsUtility::createTabs(3) << "|+ [6]- Back To Main Menu                                       +|" << clsUtility::createNewLine(2);


	};

	static inline void _FooterTransactionMenu(void) {


		cout << clsUtility::createTabs(3) << "|+--------------------------------------------------------------+|" << clsUtility::createNewLine(2);

	};


	static void depositeOperation() {
		clsDepositeOperation::depositeOperation();
	}

	static void WithdrawOperation() {

		clsWithdrawOperation::withdrawOperation(); 
	}

	static void showTotalBalance() {
		clsShowTotalBalance::showListTotalBalanceAllClients(); 
	}

	static void _TransferBetweenClients() {
		clsTransferBalance::transferBalanceBetweenCleints();

	};

	static void _ShowTransferHistoryBetweenCleints () {
		clsShowTransferLog::printTransferHistoryBalances(); 
	}
	static void _PerformTransactionOperation(enTransactionChoise const& kTRANSACTION_CHOISE_OPERATION) {


		clsUtility::clearDetailesInSecren();

		switch (kTRANSACTION_CHOISE_OPERATION) {

		case enTransactionChoise::ekDEPOSITE_OPERATION: {
			depositeOperation();
			mainMenuTransacion();
			break;
		}
		case enTransactionChoise::ekWITHDRAW_OPERATION: {
			WithdrawOperation();
			mainMenuTransacion();
			break;
		}

		case enTransactionChoise::ekSHOW_TOTAL_BALANCE: {
			showTotalBalance();
			mainMenuTransacion();
			break;

		}
		case enTransactionChoise::ekTRANSFER_BETWEEN_CLEINTS: {
			_TransferBetweenClients();
			mainMenuTransacion();
			break;

		}

		case enTransactionChoise::ekSHOW_TRANSFER_HISTORY: {
			_ShowTransferHistoryBetweenCleints();
			mainMenuTransacion();
			break;

		}
		//case enTransactionChoise::ekBACT_MAIN_MENU_SECREN:

			//clsMainMenuSecreen::mainMenuSecren(); 


		}
	};


public : 


	static void mainMenuTransacion() {

		clsUtility::clearDetailesInSecren(); 

		if (!clsSecreen::_CheakAccessSuccessfullyOrDenied(clsUserBank::enChoiseSectionsToAddPermission::ekTRANSACTION)) {
			return;
		}
		_DrawMainHeaderSecreen( "Transaction Secren"); 

		//Header And Bidy Transaction Menu 
		_HeaderMainMenuTransaction();
		_BodyTransactionMenu();
		_FooterTransactionMenu();

		_PerformTransactionOperation((enTransactionChoise) _ReadChoiseSectionToBePerformTransaction ());
	 }

};

