#pragma once
#include <iostream>
#include <time.h> 
#include <string>
#include "clsUillity.h" 
#include "clsUserBank.h" 
#include "GlobalVarablesAndConstants.h" 

using std::cout; 
using std::cin; 
using std::endl; 
using std::string;
using std::to_string; 


class clsSecreen
{

protected : 

	static inline void _DrawMainHeaderSecreen(string const& MAIN_TITLE, string const& kSUB_TITLE = "") {

		cout << clsUtility::createNewLine(3)
			<< clsUtility::createTabs(3)
			<< "||--------------------------------------------------------------||"
			<< clsUtility::createNewLine(2);

		cout << clsUtility::createTabs(6) << MAIN_TITLE << clsUtility::createNewLine(1);
		if (kSUB_TITLE != "") {
			cout << clsUtility::createTabs(6) << kSUB_TITLE;
			_ShowCureentUserAndDate();
			cout << clsUtility::createNewLine(2) << clsUtility::createTabs(3) << "||______________________________________________________________||" << clsUtility::createNewLine(3);

		}
		else {
			_ShowCureentUserAndDate();
			cout << clsUtility::createNewLine(1)
				<< clsUtility::createTabs(3)
				<< "||______________________________________________________________||"
				<< clsUtility::createNewLine(3);
		}

	};

	static inline bool _CheakAccessSuccessfullyOrDenied(clsUserBank::enChoiseSectionsToAddPermission const kPERMISSION ){

		if (!currentUser.cheakPermission(kPERMISSION)) {
			cout<<clsUtility::createNewLine(2) << clsUtility::createTabs(3)   << "|+--------------------------------------------------------------+|" << clsUtility::createNewLine(2);
			cout <<  clsUtility::createTabs(3) << "                 Access Denied! Contact your Admin.              ";
			cout << clsUtility::createNewLine(2) << clsUtility::createTabs(3) << "|+--------------------------------------------------------------+|" << clsUtility::createNewLine(2);
			clsUtility::pauseIncludeTab(3, "Enter of any key to back of Main Menu (:");
			return false; 
		}
		else {
			return true; 
		}

		};

	static inline void _ShowCureentUserAndDate() {

		cout << clsUtility::createNewLine(2) << clsUtility::createTabs(6) << "User : " << currentUser.getUsername() << clsUtility::createNewLine(1);
		cout << clsUtility::createTabs(6) << "Date : " <<
			clsDate::DateOfSystem();
		//	cout << clsUtility::createNewLine(1) << clsUtility::createTabs(5)  << "Clock : ";
		//	clsDate::clockSystem();



	};


	static inline bool _CheakTheUserAdminOrNot(string username , string const kMESSAGE_WARNING , string const kSUB_MESSAGE_WARNING ="") {

		if (clsUserBank::isAdminBankSystem(username)) {
			cout << clsUtility::createNewLine(2) << clsUtility::createTabs(3) << "|+--------------------------------------------------------------+|" << clsUtility::createNewLine(2);
			cout << clsUtility::createTabs(3) << kMESSAGE_WARNING << clsUtility::createNewLine(1) ;
			cout << clsUtility::createTabs(3) << kSUB_MESSAGE_WARNING;
			cout << clsUtility::createNewLine(2) << clsUtility::createTabs(3) << "|+--------------------------------------------------------------+|" << clsUtility::createNewLine(2);
			clsUtility::pauseIncludeTab(3, "Enter of any key to back of Main Menu (:");
			return true;
		}
		else {
			return false;
		}

	};

};

