#pragma once
#include <iostream>
using namespace std; 
#include "clsCurrency.h" 
#include "clsInputValidate.h" 
#include "clsSecreen.h" 

class clsFindCurrency : protected clsSecreen 
{

private : 
	enum enChoiseTypeFindCurrency {

		ekFIND_BY_CODE_COUNTRY = 1 , 
		ekFIND_BY_NAME_COUNTRY = 2 
	}; 


	static inline unsigned short int _ReadChoiseFindSection(void) {

		unsigned short int choise = clsInputValidate::readNumberIntegerBetweenIncludeTabs
		(3
			, 1
			, 2
			, "Please Enter the Choise Find By [1]- Code # [2]- Name  Country : "
			, "Please , Enter the Valid Choise : ");
		return choise;
	};

	static inline void _PrintInformationCurrency(clsCurrency currencyInformation) {

		cout << clsUtility::createTabs(3) << "|+--------------------------------------------------------------+|" << clsUtility::createNewLine(2);

		cout << clsUtility::createTabs(4) << "Country               : " << currencyInformation.getNameCountry() << clsUtility::createNewLine(2);
		cout << clsUtility::createTabs(4) << "Code Country          : " << currencyInformation.getCountryCode() << clsUtility::createNewLine(2);
		cout << clsUtility::createTabs(4) << "Name Coin Of Country  : " << currencyInformation.getNameCountryCoin() << clsUtility::createNewLine(2);
		cout << clsUtility::createTabs(4) << "Rate Country          : " << currencyInformation.getRateCurrency() << clsUtility::createNewLine(2);


		_FooterSectionFindCurrency();
	};

	static inline void _HeaderSectionFindCurrency (void) {

		cout << clsUtility::createNewLine(1);
		cout << clsUtility::createTabs(3) << "|+---------------------------------------------------------------+|" << clsUtility::createNewLine(1);
		cout << clsUtility::createTabs(3) << "|+                          Find Currency                        +|" << clsUtility::createNewLine(1);
		cout << clsUtility::createTabs(3) << "|+---------------------------------------------------------------+|" << clsUtility::createNewLine(2);

	};

	static inline void _FooterSectionFindCurrency(void) {

		cout << clsUtility::createNewLine(1);
		cout << clsUtility::createTabs(3) << "|+---------------------------------------------------------------+|" << clsUtility::createNewLine(1);

	};


public : 


	static inline void findCurrency() {

		_DrawMainHeaderSecreen("Find Currency Section");
		_HeaderSectionFindCurrency();

		enChoiseTypeFindCurrency const kCHOISE_FIND_BY = (enChoiseTypeFindCurrency) _ReadChoiseFindSection();

		if (kCHOISE_FIND_BY == enChoiseTypeFindCurrency::ekFIND_BY_CODE_COUNTRY) {
			string  codeCountry = clsInputValidate::readStringIncludeTab(3, "Enter the Choise Code Country To Find Currency : ");

			while (!clsCurrency::IsCurrencyExistByCode(codeCountry)) {
				codeCountry = clsInputValidate::readStringIncludeTab(3, "Enter the Choise Code Country To Find Currency : ");
			};

			clsCurrency const kINFORMATION_CURRENCY_BY_CODE = clsCurrency::FindByCode(codeCountry);
			_PrintInformationCurrency(kINFORMATION_CURRENCY_BY_CODE);
		}
		else if (kCHOISE_FIND_BY == enChoiseTypeFindCurrency::ekFIND_BY_NAME_COUNTRY) {
			string  nameCountry = clsInputValidate::readStringIncludeTab(3, "Enter the Choise Name Country To Find Currency : ");

			while (!clsCurrency::IsCurrencyExistByName(nameCountry)) {
				nameCountry = clsInputValidate::readStringIncludeTab(3, "Enter the Choise Name Country To Find Currency : ");
			};

			clsCurrency const kINFORMATION_CURRENCY_BY_NAME = clsCurrency::FindByCountry(nameCountry);
			_PrintInformationCurrency(kINFORMATION_CURRENCY_BY_NAME);

		};

		clsUtility::pauseIncludeTab(3, "Enter of the any key in the Keyboard ti back Main Menu Currency Exchange.."); 
	}
};

