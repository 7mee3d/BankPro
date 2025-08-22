#pragma once
#include <iostream> 
#include <string>
#include "clsDate.h"
#include"clsString.h"
#include "clsUillity.h"


using namespace std;

class clsInputValidate
{


public:

	static inline bool isNumberBetween(int const kNUMBER_TO_CHEAK_BETWEEN, int const kNUMBER_ONE, int const kNUMBER_TWO) {

		return ((kNUMBER_TO_CHEAK_BETWEEN >= kNUMBER_ONE)
			&& (kNUMBER_TO_CHEAK_BETWEEN <= kNUMBER_TWO));

	};

	static inline bool isNumberBetween(double const kNUMBER_TO_CHEAK_BETWEEN, double const kNUMBER_ONE, double const kNUMBER_TWO) {

		return ((kNUMBER_TO_CHEAK_BETWEEN >= kNUMBER_ONE)
			&& (kNUMBER_TO_CHEAK_BETWEEN <= kNUMBER_TWO));

	};

	static inline bool isDateBetween(clsDate kDATE_TO_NEED_CHEAK, clsDate kDATE_ONE, clsDate kDATE_TWO) {
		return (
			(clsDate::compareTwoDates(kDATE_TO_NEED_CHEAK, kDATE_ONE) == clsDate::enCompareTwoDate::kAFTER &&
				clsDate::compareTwoDates(kDATE_TO_NEED_CHEAK, kDATE_TWO) == clsDate::enCompareTwoDate::kBEFORE)

			||

			(clsDate::compareTwoDates(kDATE_TO_NEED_CHEAK, kDATE_ONE) == clsDate::enCompareTwoDate::kBEFORE &&
				clsDate::compareTwoDates(kDATE_TO_NEED_CHEAK, kDATE_TWO) == clsDate::enCompareTwoDate::kAFTER)
			);
	}

	static inline int readNumberInteger(const string kMESSAGE_ORGINAL, const string kMESSAGE_WARNING) {

		int numberInteger{};

		cout << kMESSAGE_ORGINAL;
		cin >> numberInteger;

		cout << endl;
		while (cin.fail()) {

			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << kMESSAGE_WARNING;
			cin >> numberInteger;
		};

		return numberInteger;
	};

	static inline int readNumberIntegerIncludeTab(const unsigned short int kNUMBER_OF_TAB , const string kMESSAGE_ORGINAL, const string kMESSAGE_WARNING) {

		int numberInteger{};

		cout <<clsUtility::createTabs(kNUMBER_OF_TAB) <<  kMESSAGE_ORGINAL;
		cin >> numberInteger;

		cout << endl;
		while (cin.fail()) {

			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << clsUtility::createTabs(kNUMBER_OF_TAB) << kMESSAGE_WARNING;
			cin >> numberInteger;
		};

		return numberInteger;
	};
	static inline int readNumberIntegerBetween(int const kFRAM_NUMBER, const int kTO_NUMBER, const string kMESSAGE_ORGINAL, const string kMESSAGE_WARNING = "Number is not within range, Enter again:\n") {

		int numberInteger{ readNumberInteger(kMESSAGE_ORGINAL , kMESSAGE_WARNING) };
		cout << endl;
		while (!isNumberBetween(numberInteger, kFRAM_NUMBER, kTO_NUMBER)) {

			cout << kMESSAGE_WARNING;
			int numberInteger{ readNumberInteger(kMESSAGE_ORGINAL , kMESSAGE_WARNING) };

		}

		return numberInteger;
	};


	static inline int readNumberIntegerBetweenIncludeTabs (const unsigned short int kNUMBER_TAB , int const kFRAM_NUMBER, const int kTO_NUMBER, const string kMESSAGE_ORGINAL, const string kMESSAGE_WARNING = "Number is not within range, Enter again:\n") {

		int numberInteger{ readNumberIntegerIncludeTab(kNUMBER_TAB , kMESSAGE_ORGINAL , kMESSAGE_WARNING) };
		cout << endl;
		while (!isNumberBetween(numberInteger, kFRAM_NUMBER, kTO_NUMBER)) {

		 numberInteger = { readNumberIntegerIncludeTab(kNUMBER_TAB , kMESSAGE_ORGINAL , kMESSAGE_WARNING) };

		}

		return numberInteger;
	};

	//Double Number 


	static inline double readNumberDouble(const string kMESSAGE_ORGINAL, const string kMESSAGE_WARNING) {

		double numberDouble{};

		cout << kMESSAGE_ORGINAL;
		cin >> numberDouble;

		cout << endl;
		while ((cin.fail())/* || (floor(numberDouble) == numberDouble) */ ) {

			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << kMESSAGE_WARNING;
			cin >> numberDouble;
		};

		return numberDouble;
	};

	static inline double readNumberDoubleIncludeTab (const unsigned short int kNUMBER_OF_TAB , const string kMESSAGE_ORGINAL, const string kMESSAGE_WARNING) {

		double numberDouble{};

		cout << clsUtility::createTabs (kNUMBER_OF_TAB) <<  kMESSAGE_ORGINAL;
		cin >> numberDouble;

		cout << endl;
		while ((cin.fail()) /* || (floor(numberDouble) == numberDouble) */) {

			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << clsUtility::createTabs(kNUMBER_OF_TAB) << kMESSAGE_WARNING;
			cin >> numberDouble;
		};

		return numberDouble;
	};


	static inline double readNumberDoubleBetween(double const kFRAM_NUMBER, const double kTO_NUMBER, const string kMESSAGE_ORGINAL, const string kMESSAGE_WARNING = "Number is not within range, Enter again:\n") {

		double numberDouble{ readNumberDouble(kMESSAGE_ORGINAL , kMESSAGE_WARNING) };
		cout << endl;

		while (!isNumberBetween(numberDouble, kFRAM_NUMBER, kTO_NUMBER)) {

			 numberDouble = { readNumberDouble(kMESSAGE_ORGINAL , kMESSAGE_WARNING) };

		}

		return numberDouble;
	};

	static inline double readNumberDoubleBetweenIncludeTab (const unsigned short int kNUMBER_TAB, double const kFRAM_NUMBER, const double kTO_NUMBER, const string kMESSAGE_ORGINAL, const string kMESSAGE_WARNING = "Number is not within range, Enter again:\n") {

		double numberDouble{ readNumberDoubleIncludeTab(kNUMBER_TAB, kMESSAGE_ORGINAL , kMESSAGE_WARNING) };
		cout << endl;

		while (!isNumberBetween(numberDouble, kFRAM_NUMBER, kTO_NUMBER)) {

			 numberDouble = { readNumberDoubleIncludeTab(kNUMBER_TAB , kMESSAGE_ORGINAL , kMESSAGE_WARNING) };

		}

		return numberDouble;
	};


	static inline bool validationDate(clsDate date) {

		return (clsDate::validationDate(date));
	};


	static inline string readString(string const kMESSAGE) {

		string text{ "" }; 

		cout << kMESSAGE; 
		getline(cin >> ws, text); 
		cout << endl;
		return text; 

		
	}

	static inline string readStringIncludeTab(const unsigned short int kNUMBER_OF_TAB, string const kMESSAGE) {

		string text{ "" };

		cout << clsUtility::createTabs(kNUMBER_OF_TAB) << kMESSAGE;
		getline(cin >> ws, text);
		cout << endl;
		return text;


	};
	

	static inline char readCharacter(string const& kMESSAGE) {

		char character{  };

		cout << kMESSAGE;

		cin >> character;


		return character;

	};

	static inline char readCharacterIncludeTab(unsigned short int const kNUMBER_OF_TAB , string const& kMESSAGE) {

		char character{  };
		cout<< clsUtility::createNewLine(1) << clsUtility::createTabs(kNUMBER_OF_TAB) << kMESSAGE;
		cin >> character; 

		return character; 
	}
};

