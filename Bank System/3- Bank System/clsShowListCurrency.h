#pragma once
#include <iostream>
#include "clsString.h" 
#include "clsSecreen.h" 
#include "clsCurrency.h" 
#include <vector> 
 
class clsShowListCurrency : protected clsSecreen 
{

	static inline void _HeaderShowListCurrency( ){


		cout << "|+___________________________________________________________________________________________________________+|" << clsUtility::createNewLine(1);
		cout << "|                Country               |   Code  |                  Name                  |     Rate/(1$)     |" << clsUtility::createNewLine(1);
		cout << "|+___________________________________________________________________________________________________________+|" << clsUtility::createNewLine(2);

	};

	static inline void _PrintInformationOneCountry(clsCurrency crruncryInfo) {


			cout <<"| " << left << setw(37) << crruncryInfo.getNameCountry() << "| ",
			cout << left << setw(8) << crruncryInfo.getCountryCode() << "| ",
			cout << left << setw(39) << crruncryInfo.getNameCountryCoin() << "| ",
			cout << left << setw(18) << crruncryInfo.getRateCurrency() << "| ";



		cout << clsUtility::createNewLine(1);

	};

	static inline void _FooterShowListCrunrncy(void) {

		cout << clsUtility::createNewLine(1) << "|+___________________________________________________________________________________________________________+|" << clsUtility::createNewLine(1);

	};

public : 


	static inline void showListCrruncyInformation(void) {

		clsUtility::clearDetailesInSecren();

		vector<clsCurrency> infoCurrency = clsCurrency::GetCurrenciesList();

		string const kSUB_TITLE = "( " + to_string(infoCurrency.size()) + " ) Currency(s).";
		_DrawMainHeaderSecreen("Show Currency List", kSUB_TITLE);
		_HeaderShowListCurrency();

		for (clsCurrency const kINFO_COUNTRY_ONE : infoCurrency)
			_PrintInformationOneCountry(kINFO_COUNTRY_ONE);

		_FooterShowListCrunrncy();

		cout << clsUtility::createNewLine(3);
		clsUtility::pauseIncludeTab(3, "Enter the any key in the Keyboard to back Main Menu Currency Exchange");
	}
};

