#pragma once
#include <iostream>
#include "clsSecreen.h"
#include "clsString.h" 
#include "clsUillity.h"
#include "clsShowListCurrency.h"
#include "clsFindCurrency.h"
#include "clsUpdateRate.h"
#include "clsCalculatorCurrency.h"

class clsMainMenuCurrencyExchange : protected clsSecreen 
{
private :
	enum enChoiseCurrencyExchange {

		ekSHOW_LIST_CURRENCY = 1 , 
		ekFIND_CURRENCY = 2 ,
		ekUPDATE_CURRENCY = 3 , 
		ekCURRENCY_CALCULATOR = 4 , 
		ekBACK_TO_MAIN_MENU = 5 

	};
	static inline unsigned short int _ReadChoiseSectionToBePerform() {

		unsigned short int  choiseSection = clsInputValidate::readNumberIntegerBetweenIncludeTabs(3, 1, 5, "Enter the Choise Between [ 1 - 6 ] : ", "Please Sir , Enter a valid Choise : ");

		return choiseSection;

	};

	static inline void _HeaderMainMenuCurrencyExchange(void) {

		cout << clsUtility::createNewLine(1);
		cout << clsUtility::createTabs(3) << "|+---------------------------------------------------------------+|" << clsUtility::createNewLine(1);
		cout << clsUtility::createTabs(3) << "|+                    Currency Exchange Main Menu                +|" << clsUtility::createNewLine(1);
		cout << clsUtility::createTabs(3) << "|+---------------------------------------------------------------+|" << clsUtility::createNewLine(2);

	};

	static inline void _BodyMainMenuCurrencyExchange(void) {


		cout << clsUtility::createNewLine(1);
		cout << clsUtility::createTabs(3) << "|+ [01]- Show List Currency                                      +|" << clsUtility::createNewLine(1);
		cout << clsUtility::createTabs(3) << "|+ [02]- Find Currency                                           +|" << clsUtility::createNewLine(1);
		cout << clsUtility::createTabs(3) << "|+ [03]- Update Currency                                         +|" << clsUtility::createNewLine(1);
		cout << clsUtility::createTabs(3) << "|+ [04]- Currency Calculator                                     +|" << clsUtility::createNewLine(1);
		cout << clsUtility::createTabs(3) << "|+ [05]- Back To Main Menu                                       +|" << clsUtility::createNewLine(2);
	
	};

	static inline void _FooterMainMenuCurrencyExchange(void) {
		cout << clsUtility::createTabs(3) << "|+---------------------------------------------------------------+|" << clsUtility::createNewLine(2);

	};

	static inline void _ShowListCurrency(void) {
		clsShowListCurrency::showListCrruncyInformation();
	};
	static inline void _FindCurrency(void) {
		clsFindCurrency::findCurrency(); 

	};
	static inline void _UpdateCurrency (void) {
		clsUpdateRate::updateRateCurrency(); 
	};

	static inline void _CurrencyCalculator(void) {

		clsCalculatorCurrency::calcalatorCurrency();
	};


	static inline void _PerformMainMenuCurrencyExchange(enChoiseCurrencyExchange const kCHOISE_CURRENCY_EXCHANGE) {

		clsUtility::clearDetailesInSecren();

		switch (kCHOISE_CURRENCY_EXCHANGE) {

		case enChoiseCurrencyExchange::ekSHOW_LIST_CURRENCY: {

			_ShowListCurrency();
			mainMenuCurrencyExchange();
			break;

		}
		case enChoiseCurrencyExchange::ekFIND_CURRENCY: {

			_FindCurrency();
			mainMenuCurrencyExchange();
			break;

		}
		case enChoiseCurrencyExchange::ekUPDATE_CURRENCY: {

			_UpdateCurrency();
			mainMenuCurrencyExchange();
			break;

		}

		case enChoiseCurrencyExchange::ekCURRENCY_CALCULATOR: {

			_CurrencyCalculator();
			mainMenuCurrencyExchange();
			break;

		}
		case enChoiseCurrencyExchange::ekBACK_TO_MAIN_MENU: {

		}

		};

	};

public : 

	static inline void mainMenuCurrencyExchange(void) {

		clsUtility::clearDetailesInSecren();


		_DrawMainHeaderSecreen("Currency Exchange Secren");
		_HeaderMainMenuCurrencyExchange();
		_BodyMainMenuCurrencyExchange(); 
		_FooterMainMenuCurrencyExchange();

		_PerformMainMenuCurrencyExchange((enChoiseCurrencyExchange)_ReadChoiseSectionToBePerform());
	}
};

