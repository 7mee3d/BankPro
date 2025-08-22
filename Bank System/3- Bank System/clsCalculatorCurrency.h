#pragma once
#include <iostream>
#include <iomanip>
using namespace std; 

#include "clsString.h"
#include "clsSecreen.h" 
#include "clsCurrency.h" 

class clsCalculatorCurrency : protected clsSecreen 

{

private : 

	static inline void _HeaderSectionCalclatorCurrency(void) {

		cout << clsUtility::createNewLine(1);
		cout << clsUtility::createTabs(3) << "|+---------------------------------------------------------------+|" << clsUtility::createNewLine(1);
		cout << clsUtility::createTabs(3) << "|+                       Calclator Currency                      +|" << clsUtility::createNewLine(1);
		cout << clsUtility::createTabs(3) << "|+---------------------------------------------------------------+|" << clsUtility::createNewLine(2);

	};

	static inline void _PrintInformationCurrency(clsCurrency currencyInformation) {

		cout << clsUtility::createTabs(3) << "|+--------------------------------------------------------------+|" << clsUtility::createNewLine(2);

		cout << clsUtility::createTabs(4) << "Country               : " << currencyInformation.getNameCountry() << clsUtility::createNewLine(2);
		cout << clsUtility::createTabs(4) << "Code Country          : " << currencyInformation.getCountryCode() << clsUtility::createNewLine(2);
		cout << clsUtility::createTabs(4) << "Name Coin Of Country  : " << currencyInformation.getNameCountryCoin() << clsUtility::createNewLine(2);
		cout << clsUtility::createTabs(4) << "Rate Country          : " << currencyInformation.getRateCurrency() << clsUtility::createNewLine(2);


		_FooterSectionCalclatorCurrency();
	};

	static inline void _FooterSectionCalclatorCurrency(void) {

		cout << clsUtility::createNewLine(1);
		cout << clsUtility::createTabs(3) << "|+---------------------------------------------------------------+|" << clsUtility::createNewLine(1);

	};

	static inline clsCurrency _GetObjectCurrency(string const kTITLE = "Enter the code Currency : ") {


		string CodeCountry = clsInputValidate::readStringIncludeTab(3, kTITLE);

		while (!clsCurrency::IsCurrencyExistByCode(CodeCountry)) {
			CodeCountry = clsInputValidate::readStringIncludeTab(3, kTITLE);
		};

		clsCurrency objCodeCountry = clsCurrency::FindByCode(CodeCountry);

		return objCodeCountry;
	}

	static inline void _PrintInformationResults(double const kAMOUNT , clsCurrency objSorcueCodeCountry , clsCurrency DestenationCodeCountry ) {
	
		if (clsString::ConvertLetter(DestenationCodeCountry.getCountryCode(), clsString::enChoiseLetter::kCAPITAL_LETTERS) == "USD") {

			double resultCalcCurrency = objSorcueCodeCountry.CalculateCurrencyToConvertDollar_Loacally(kAMOUNT);

			cout << clsUtility::createNewLine(2) << clsUtility::createTabs(3) << kAMOUNT << " " << objSorcueCodeCountry.getCountryCode() << " = " << resultCalcCurrency << " " << clsString::ConvertLetter(DestenationCodeCountry.getCountryCode(), clsString::enChoiseLetter::kCAPITAL_LETTERS);
		}
		else {


			double resultCalcCurrencyCircleTwoLastConvert = objSorcueCodeCountry.CalculateCurrencyToConvertDollarToAntherCurrency(kAMOUNT, DestenationCodeCountry);
			cout << clsUtility::createNewLine(2) << clsUtility::createTabs(3) << kAMOUNT << " " << clsString::ConvertLetter(objSorcueCodeCountry.getCountryCode(), clsString::enChoiseLetter::kCAPITAL_LETTERS) << " = " << resultCalcCurrencyCircleTwoLastConvert << " " << clsString::ConvertLetter(DestenationCodeCountry.getCountryCode(), clsString::enChoiseLetter::kCAPITAL_LETTERS);


		}

	}
public : 

	static inline void calcalatorCurrency(void) {

	
		char choiseTryAgain = { 'Y' };

		while (clsString::convertionUpperCharToLower(choiseTryAgain) == 'y') {

			clsUtility::clearDetailesInSecren(); 
			_DrawMainHeaderSecreen("Calclator Currency");

			clsCurrency objSorcueCodeCountry = _GetObjectCurrency("Enter the code Currency One : ");
			clsCurrency DestenationCodeCountry = _GetObjectCurrency("Enter the code Currency Two : ");


			cout << clsUtility::createNewLine(2);

			_PrintInformationCurrency(objSorcueCodeCountry);

			cout << clsUtility::createNewLine(2);

			double const kAMOUNT = clsInputValidate::readNumberDoubleIncludeTab(3, "Enter the Amount to be Calc : ", "Please , Enter of the Valid Input : ");

			_PrintInformationResults(kAMOUNT, objSorcueCodeCountry, DestenationCodeCountry);

			cout << clsUtility::createNewLine(3) << clsUtility::createTabs(3) << "Do you want to perform another calculation? [Y/N] ? ";
			cin >> choiseTryAgain;
		}

		clsUtility::pauseIncludeTab(3, "Enter of the any key in the Keyboard ti back Main Menu Currency Exchange..");
	}

};

