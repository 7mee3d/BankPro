#pragma once
#include <iostream>
using namespace std; 

class clsPerson
{

private : 

	string _FirstName{ "" };
	string _LastName{ "" }; 
	string _Email{ "" }; 
	string _PhoneNumber{ "" };

public : 

	clsPerson(string const kFIRST_NAME, string const kLAST_NAME, string const kEMAIL, string const kPHONE_NUMBER) {
		
		_FirstName = kFIRST_NAME;
		_LastName = kLAST_NAME; 
		_Email = kEMAIL; 
		_PhoneNumber = kPHONE_NUMBER; 

	};

	void setFirstName(string const kFIRST_NAME) {
		_FirstName = kFIRST_NAME; 
	}

	string getFirstName() {
		return _FirstName;
	}

	void setLastName(string const kLAST_NAME) {
		_LastName = kLAST_NAME; 
	}

	string getLastName() {
		return _LastName; 
	}

	void setEmail(string const kEMAIL) {
		_Email = kEMAIL; 
	}

	string getEmail() {
		return _Email; 
	}

	void setPhoneNumber(string const kPHONE_NUMBER) {
		_PhoneNumber = kPHONE_NUMBER; 
	}

	string getPhoneNUmber() {
		return _PhoneNumber;
	};


	string getFullName() {
		return _FirstName + " " + _LastName;
	}

};

