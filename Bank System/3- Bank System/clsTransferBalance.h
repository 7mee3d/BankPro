#pragma once
#include <iostream>
#include <string>
#include "clsBankClient.h"
#include "clsDate.h"
#include "clsSecreen.h"
#include "GlobalVarablesAndConstants.h"
using namespace std; 


class clsTransferBalance : protected clsSecreen 
{

private : 




public : 

	static void transferBalanceBetweenCleints (void) {


		_DrawMainHeaderSecreen("Transfer Balance Secren", "Transaction Secren");


		string  accountNumberFrom{ clsInputValidate::readStringIncludeTab(3 , "Enter the Account Number From, Please Sir : ") };

		while (!clsBankClient::isFoundClient(accountNumberFrom)) {
			accountNumberFrom = { clsInputValidate::readStringIncludeTab(3 , "Aleart!! Please Enter Another Account Number Not Exixted : ") };
		};

		clsBankClient SoruseAccountNumber  = clsBankClient::Find(accountNumberFrom);
		clsBankClient::printClientCard(SoruseAccountNumber);
		cout << clsUtility::createNewLine(2);

		string  accountNumberTo{ clsInputValidate::readStringIncludeTab(3 , "Enter the Account Number To, Please Sir : ") };
		while (!clsBankClient::isFoundClient(accountNumberTo)) {
			accountNumberTo = { clsInputValidate::readStringIncludeTab(3 , "Aleart!! Please Enter Another Account Number Not Exixted : ") };
		};


		//Cheak Soruse Account Number Equal Destenation Account number if the equal read destenation account number agian
		if (accountNumberFrom == accountNumberTo) {

			cout << clsUtility::createNewLine(3) 
				<< clsUtility::createTabs(3) 
				<< "Sorry , Not to Transfer Of the Same Cleints , Try Again : " 
				<< clsUtility::createNewLine(2);


			string  accountNumberTo{ clsInputValidate::readStringIncludeTab(3 , "Enter the Account Number To, Please Sir : ") };
			while (!clsBankClient::isFoundClient(accountNumberTo)) {
				accountNumberTo = { clsInputValidate::readStringIncludeTab(3 , "Aleart!! Please Enter Another Account Number Not Exixted : ") };
			};

		};
	

		clsBankClient DestenationAccountNumber  = clsBankClient::Find(accountNumberTo);
		clsBankClient::printClientCard(DestenationAccountNumber);

		bool flagAmount = true ; 
		double  kAMOUNT; 

		
		
		//Cheak Balance
		do {

			cout << clsUtility::createNewLine(3);
			  kAMOUNT = clsInputValidate::readNumberDoubleIncludeTab(3, "Enter Transfer Amount : ", "Enter of the Valid Amount , Please : ");

			if (SoruseAccountNumber.getAccountBalance() < kAMOUNT) {

				cout << clsUtility::createNewLine(2)
					<< clsUtility::createTabs(3) 
					<< "Sorry ,The Amount Grather Of the Balance, Try Again : " 
					<< clsUtility::createNewLine(2);
			}
			else flagAmount = false; 

		} while (flagAmount);

		

		char answer{};
		cout << clsUtility::createNewLine(1) << clsUtility::createTabs(3) << "Are you sure to be Deposite Amount of this client [Y/N] : ";
		cin >> answer;

		//Perform The Operation is Successfully 
		if (answer == 'Y' || answer == 'y') {
			if (SoruseAccountNumber.transferBalance(kAMOUNT, DestenationAccountNumber)) {

				cout << clsUtility::createNewLine(1)
					<< clsUtility::createTabs(3)
					<< "Transfer is Done ";

				clsUtility::pauseIncludeTab(3, "Enter of any key to back of Main Menu Transaction (: ");
			};
		}
		else {

			cout << clsUtility::createNewLine(1) << clsUtility::createTabs(3) << "Transfer is Faild";
			clsUtility::pauseIncludeTab(3, "Enter of any key to back of Main Menu Transaction (: ");
		};
		


	}
};

