#pragma once
#include <iostream>
#include <string>
#include <time.h> 
#include <cstdlib> 
#include "clsDate.h" 
#include "clsString.h"


using namespace std;


class clsUtility
{
private:

	static unsigned short int const kZERO{ 0 };
	static unsigned short int const kONE{ 1 };

	static unsigned short int const kMAX_ASCII_CAPITAL_CHARACTER{ 90 };
	static unsigned short int const kMIN_ASCII_CAPITAL_CHARACTER{ 65 };

	static unsigned short int const kMAX_ASCII_SMALL_CHARACTER{ 122 };
	static unsigned short int const kMIN_ASCII_SMALL_CHARACTER{ 97 };

	static unsigned short int const kMAX_ASCII_SPECIAL_CHARACTER{ 47 };
	static unsigned short int const kMIN_ASCII_SPECIAL_CHARACTER{ 33 };

	static unsigned short int const kMAX_ASCII_DIGIT_CHARACTER{ 57 };
	static unsigned short int const kMIN_ASCII_DIGIT_CHARACTER{ 48 };

	static unsigned short int const kMAX_ASCII_MIX_CHARACTER{ 122 };
	static unsigned short int const kMIN_ASCII_MIX_CHARACTER{ 33 };



	static unsigned short int const kSIZE_ARRAY{ 200 };



public:

	static enum enCharacterType {

		kCAPITAL_CHARACTER = 1,
		kSMALL_CHARACTER = 2,
		kDIGIT_CHARACTER = 3,
		kSPECIAL_CHARACTER = 4,
		kMIX_CHARACTER_RANDOMLLY = 5

	};

	//----------------------------- Encryption and Decryption Methods ----------------------------

	static inline string Encryption(string text, unsigned short int  kENCRYPTION_KEY) {

		/*for (char& chracter : text) {

			chracter = static_cast <char>
				(static_cast <int> (chracter) + kENCRYPTION_KEY);

		};
		*/
		for (int counter{kZERO}; counter < text.size(); counter++) {

			text[counter] += kENCRYPTION_KEY;

		}
		
		return text;
	};

	// Decryption the string according the dey decreption 
	static inline string Decryption(string text, unsigned short int const& kDECRYPTION_KEY) {

		for (char& chracter : text) {
			chracter = static_cast <char>
				(static_cast <int> (chracter) - kDECRYPTION_KEY);
		};

		return text;
	};

	//-------------------------------- Genarates Methods --------------------------------------


	static inline void Srand(void) {
		srand((unsigned)time(NULL));
	}

	static inline int randomNumber(int const kFROM_NUMBER, int const kTO_NUMBER) {

		int randNumber = ((rand() % (kTO_NUMBER - kFROM_NUMBER + kONE)) + kFROM_NUMBER);
		return randNumber;
	};

	static inline char getCharacterRandomlly(enCharacterType const kTYPE_CHARACTER) {

		switch (kTYPE_CHARACTER) {


		case enCharacterType::kCAPITAL_CHARACTER:

			return randomNumber(kMIN_ASCII_CAPITAL_CHARACTER, kMAX_ASCII_CAPITAL_CHARACTER);

			break;
		case enCharacterType::kSMALL_CHARACTER:

			return randomNumber(kMIN_ASCII_SMALL_CHARACTER, kMAX_ASCII_SMALL_CHARACTER);

			break;
		case enCharacterType::kSPECIAL_CHARACTER:

			return randomNumber(kMIN_ASCII_SPECIAL_CHARACTER, kMAX_ASCII_SPECIAL_CHARACTER);

			break;
		case enCharacterType::kDIGIT_CHARACTER:

			return randomNumber(kMIN_ASCII_DIGIT_CHARACTER, kMAX_ASCII_DIGIT_CHARACTER);

			break;
		case enCharacterType::kMIX_CHARACTER_RANDOMLLY:
			return randomNumber(kMIN_ASCII_MIX_CHARACTER, kMAX_ASCII_MIX_CHARACTER);

		};

		return '\0';
	};

	static inline string genarateWord(enCharacterType const& kTYPE_CHARACTER_TO_GENARATE_WORD, unsigned short int const& kLENGTH_WORD) {

		string word{ "" };
		for (int counter{ kONE }; counter <= kLENGTH_WORD; counter++)
			word += getCharacterRandomlly(kTYPE_CHARACTER_TO_GENARATE_WORD);

		return word;
	};

	static inline string genarateKey(enCharacterType const& kTYPE_CHARACTER_TO_GENARATE_KEY) {

		string key{ "" };

		key += genarateWord(kTYPE_CHARACTER_TO_GENARATE_KEY, 4) + "-";
		key += genarateWord(kTYPE_CHARACTER_TO_GENARATE_KEY, 4) + "-";
		key += genarateWord(kTYPE_CHARACTER_TO_GENARATE_KEY, 4) + "-";
		key += genarateWord(kTYPE_CHARACTER_TO_GENARATE_KEY, 4);

		return key;

	};

	static inline void genarateKeys(enCharacterType const& kTYPE_CHARACTER, unsigned short int const kSIZE_OF_ARRAY_INSIDE_METHOD, unsigned short int const& kNUMBER_OF_KEY_TO_NEED_GENARATE) {

		for (int counter{ kONE }; counter <= kNUMBER_OF_KEY_TO_NEED_GENARATE; counter++)

		{
			cout << "Key [" << counter << "] : ";
			cout << genarateKey(kTYPE_CHARACTER) << endl;
		};
	};

	//--------------------------------- Fill Array Methods -------------------------------------------


	static inline void FillArrayInOfRandomNumbers(int array[kSIZE_ARRAY], unsigned short int const kSIZE_OF_ARRAY_INSIDE_METHOD, int const kFROM_NUMBER, int const kTO_NUMBER) {

		for (int counter{ kZERO }; counter < kSIZE_OF_ARRAY_INSIDE_METHOD; counter++)
			array[counter] = randomNumber(kFROM_NUMBER, kTO_NUMBER);

	};

	static inline void FillArrayInOfRandomCharacters(char array[kSIZE_ARRAY], unsigned short int const kSIZE_OF_ARRAY_INSIDE_METHOD, int const kFROM_NUMBER, int const kTO_NUMBER) {

		for (int counter{ kZERO }; counter < kSIZE_OF_ARRAY_INSIDE_METHOD; counter++)

			array[counter] = static_cast <char>(randomNumber(kFROM_NUMBER, kTO_NUMBER));

	};


	static inline void FillArrayInOfRandomString(string array[kSIZE_ARRAY], unsigned short int const kSIZE_OF_ARRAY_INSIDE_METHOD, enCharacterType const& kTYPE_CHARACTER_TO_GENARATE_WORD, unsigned short int const kLENGTH_OF_WORD_TO_BE_GENARATE) {

		for (int counter{ kZERO }; counter < kSIZE_OF_ARRAY_INSIDE_METHOD; counter++)

			array[counter] = genarateWord(kTYPE_CHARACTER_TO_GENARATE_WORD, kLENGTH_OF_WORD_TO_BE_GENARATE);

	};

	static inline void FillArrayInOfRandomKeys(string array[kSIZE_ARRAY], unsigned short int const kSIZE_OF_ARRAY_INSIDE_METHOD, enCharacterType const& kTYPE_CHARACTER_TO_GENARATE_WORD) {

		for (int counter{ kZERO }; counter < kSIZE_OF_ARRAY_INSIDE_METHOD; counter++)

			array[counter] = genarateKey(kTYPE_CHARACTER_TO_GENARATE_WORD);

	};


	//------------------------------- Swap Methods ----------------------------------


	static inline void swap(int& numberOne, int& numberTwo) {

		int tempNumber = numberOne;
		numberOne = numberTwo;
		numberTwo = tempNumber;

	};

	static inline void swap(double& numberOne, double& numberTwo) {

		double tempNumber = numberOne;
		numberOne = numberTwo;
		numberTwo = tempNumber;

	};

	static inline void swap(string& wordOne, string& wordTwo) {

		string tempWord = wordOne;
		wordOne = wordTwo;
		wordTwo = tempWord;

	};

	static inline void swap(char& characterOne, char& characterTwo) {

		char tempCharacter = characterOne;
		characterOne = characterTwo;
		characterTwo = tempCharacter;

	};

	static inline void swap(bool& flagOne, char& flagTwo) {

		bool tempFlag = flagOne;
		flagOne = flagTwo;
		flagTwo = tempFlag;

	};


	static inline void swap(clsDate& date1, clsDate& date2) {

		clsDate tempDate = date1;
		date1 = date2;
		date2 = tempDate;

	};


	//------------------------------------------  Shuffle Methods --------------------------------------------------


	static  void ShuffleArray(int array[100], int const kLENGTH_ARRAY)
	{

		for (int counter{ kZERO }; counter < kLENGTH_ARRAY; counter++)
		{
			swap(array[randomNumber(kONE, kLENGTH_ARRAY) - kONE], array[randomNumber(kONE, kLENGTH_ARRAY) - kONE]);
		}

	}

	static  void ShuffleArray(string array[100], int const kLENGTH_ARRAY)
	{

		for (int counter{ kZERO }; counter < kLENGTH_ARRAY; counter++)
		{
			swap(array[randomNumber(kONE, kLENGTH_ARRAY) - kONE], array[randomNumber(kONE, kLENGTH_ARRAY) - kONE]);
		}

	}

	//------------------------------------- Formating Methods ------------------------------------------------------

	static string  createTabs(unsigned short int const  kNUMBER_OF_TAB)
	{
		string tab = "";

		for (int counter{ kONE }; counter <= kNUMBER_OF_TAB; counter++)
		{
			tab = tab + "\t";
		}
		return tab;

	};

	static string  createNewLine(unsigned short int const  kNUMBER_OF_LINE)
	{
		string line = "";

		for (int counter{ kONE }; counter <= kNUMBER_OF_LINE; counter++)
		{
			line = line + "\n";
		}
		return line;

	};

	static inline void pause(string const kPROMT_PAUSE) {

		cout << clsUtility::createNewLine(2);
		cout << kPROMT_PAUSE << "\n";
		system("pause>0");

	};


	static inline void pauseIncludeTab (const unsigned short int kNUMBER_OF_TAB , string const kPROMT_PAUSE) {

		cout << clsUtility::createNewLine(2); 
		cout << clsUtility::createTabs(kNUMBER_OF_TAB) << kPROMT_PAUSE << clsUtility::createNewLine(1); 

		system("pause>0");

	};

	static inline void clearDetailesInSecren(void) {

		system("cls"); 
	}

};

