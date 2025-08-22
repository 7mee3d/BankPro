#pragma once
#include <iostream>
using namespace std; 
#include "clsString.h" 
#include "clsCurrency.h" 
#include "clsSecreen.h" 

class clsUpdateRate : protected clsSecreen {

private : 

	enum enChoiseTypeFindCurrency {

		ekFIND_BY_CODE_COUNTRY = 1,
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

	static inline void _HeaderSectionUpdateCurrency(void) {

		cout << clsUtility::createNewLine(1);
		cout << clsUtility::createTabs(3) << "|+---------------------------------------------------------------+|" << clsUtility::createNewLine(1);
		cout << clsUtility::createTabs(3) << "|+                      Update Rate Currency                     +|" << clsUtility::createNewLine(1);
		cout << clsUtility::createTabs(3) << "|+---------------------------------------------------------------+|" << clsUtility::createNewLine(2);

	};

	static inline void _PrintInformationCurrency(clsCurrency currencyInformation) {

		cout << clsUtility::createTabs(3) << "|+--------------------------------------------------------------+|" << clsUtility::createNewLine(2);

		cout << clsUtility::createTabs(4) << "Country               : " << currencyInformation.getNameCountry() << clsUtility::createNewLine(2);
		cout << clsUtility::createTabs(4) << "Code Country          : " << currencyInformation.getCountryCode() << clsUtility::createNewLine(2);
		cout << clsUtility::createTabs(4) << "Name Coin Of Country  : " << currencyInformation.getNameCountryCoin() << clsUtility::createNewLine(2);
		cout << clsUtility::createTabs(4) << "Rate Country          : " << currencyInformation.getRateCurrency() << clsUtility::createNewLine(2);


		_FooterSectionFindCurrency();
	};

	static inline void _FooterSectionFindCurrency(void) {

		cout << clsUtility::createNewLine(1);
		cout << clsUtility::createTabs(3) << "|+---------------------------------------------------------------+|" << clsUtility::createNewLine(1);

	};

	static inline void _UpdateRate(enChoiseTypeFindCurrency const kCHOISE_FIND_BY ) {

		if (kCHOISE_FIND_BY == enChoiseTypeFindCurrency::ekFIND_BY_CODE_COUNTRY) {

			string  codeCountry = clsString::trimString(clsInputValidate::readStringIncludeTab(3, "Enter the Choise Code Country To Find Currency : ")) ;

			while (!clsCurrency::IsCurrencyExistByCode(codeCountry)) {
				codeCountry = clsInputValidate::readStringIncludeTab(3, "Enter the Choise Code Country To Find Currency : ");
			};

			clsCurrency  kINFORMATION_CURRENCY_BY_CODE = clsCurrency::FindByCode(codeCountry);
			_PrintInformationCurrency(kINFORMATION_CURRENCY_BY_CODE);


			cout << clsUtility::createNewLine(2);
	
			double const kNEW_RATE = clsInputValidate::readNumberDoubleIncludeTab(3, "Enter the New Rate to be Update Rate : ", "Please , Enter of the Valid Rate : ");

			char answer{ ' ' };
			cout << clsUtility::createNewLine(1) << clsUtility::createTabs(3) << "Are you Sure you want to Update Rate of theis Currency [Y/N] ? ";
			cin >> answer;

			if (clsString::convertionUpperCharToLower(answer) == 'y') {
				kINFORMATION_CURRENCY_BY_CODE.updateRate(kNEW_RATE);
				cout << clsUtility::createNewLine(1) << clsUtility::createTabs(3) << "Successfully updated Rate" << clsUtility::createNewLine(1);

			}
			else {
				cout << clsUtility::createNewLine(1) << clsUtility::createTabs(3) << "Rejected updated Rate" << clsUtility::createNewLine(1);

			};

		}
		else if (kCHOISE_FIND_BY == enChoiseTypeFindCurrency::ekFIND_BY_NAME_COUNTRY) {
			string  nameCountry =clsString::trimString( clsInputValidate::readStringIncludeTab(3, "Enter the Choise Name Country To Find Currency : "));

			while (!clsCurrency::IsCurrencyExistByName(nameCountry)) {
				nameCountry = clsInputValidate::readStringIncludeTab(3, "Enter the Choise Name Country To Find Currency : ");
			};

			clsCurrency  kINFORMATION_CURRENCY_BY_NAME = clsCurrency::FindByCountry(nameCountry);
			_PrintInformationCurrency(kINFORMATION_CURRENCY_BY_NAME);

			cout << clsUtility::createNewLine(2);
			double const kNEW_RATE = clsInputValidate::readNumberDoubleIncludeTab(3, "Enter the New Rate to be Update Rate : ", "Please , Enter of the Valid Rate : ");

			char answer{ ' ' };
			cout << clsUtility::createNewLine(1) << clsUtility::createTabs(3) << "Are you Sure you want to Update Rate of theis Currency [Y/N] ? ";
			cin >> answer;

			if (clsString::convertionUpperCharToLower(answer) == 'y') {
				kINFORMATION_CURRENCY_BY_NAME.updateRate(kNEW_RATE);
				cout << clsUtility::createNewLine(1) << clsUtility::createTabs(3) << "Successfully updated Rate" << clsUtility::createNewLine(1);

			}
			else {
				cout << clsUtility::createNewLine(1) << clsUtility::createTabs(3) << "Rejected updated Rate" << clsUtility::createNewLine(1);

			};
		};

	
	}

public : 

	static inline void updateRateCurrency(void) {

		_DrawMainHeaderSecreen("Update Rate Currency Section");
		_HeaderSectionUpdateCurrency();

		enChoiseTypeFindCurrency const kCHOISE_FIND_BY = (enChoiseTypeFindCurrency)_ReadChoiseFindSection();
		_UpdateRate(kCHOISE_FIND_BY);
		clsUtility::pauseIncludeTab(3, "Enter of the any key in the Keyboard ti back Main Menu Currency Exchange..");
	};

};

