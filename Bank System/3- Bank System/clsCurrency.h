#pragma once
#include <iostream> 
#include <vector> 
#include "clsString.h"

using namespace std; 


class clsCurrency
{

private : 

	enum enTypeMode {

		kEMPTY_MODE = 0 , 
		kUPDATE_MODE = 1 
		
	};

	enTypeMode _ModeType{}; 
	string _NameCountry{ "" };
	string _CountryCode{ "" }; 
	string _NameCoinCountry{ "" }; 
	double _RateCurrencyOfDollar{}; 

	static clsCurrency _ConvertLinetoCurrencyObject(string Line, string Seperator = "#//#")
	{
		vector<string> vCurrencyData;
		vCurrencyData = clsString::splitWordInText(Line, Seperator);

		return clsCurrency(enTypeMode::kUPDATE_MODE, vCurrencyData[0], vCurrencyData[1], vCurrencyData[2],
			stod(vCurrencyData[3]));

	}

	static string _ConverCurrencyObjectToLine(clsCurrency Currency, string Seperator = "#//#")
	{

		string stCurrencyRecord = "";
		stCurrencyRecord += Currency.getNameCountry() + Seperator;
		stCurrencyRecord += Currency.getCountryCode() + Seperator;
		stCurrencyRecord += Currency.getNameCountryCoin() + Seperator;
		stCurrencyRecord += to_string(Currency.getRateCurrency());

		return stCurrencyRecord;

	}

	static  vector <clsCurrency> _LoadCurrencysDataFromFile()
	{

		vector <clsCurrency> vCurrencys;

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);

		if (MyFile.is_open())
		{

			string Line;

			while (getline(MyFile, Line))
			{

				clsCurrency Currency = _ConvertLinetoCurrencyObject(Line);

				vCurrencys.push_back(Currency);
			}

			MyFile.close();

		}

		return vCurrencys;

	}

	static void _SaveCurrencyDataToFile(vector <clsCurrency> vCurrencys)
	{

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::out);

		string DataLine;

		if (MyFile.is_open())
		{

			for (clsCurrency C : vCurrencys)
			{
				DataLine = _ConverCurrencyObjectToLine(C);
				MyFile << DataLine << endl;



			}

			MyFile.close();

		}

	}

	void _Update()
	{
		vector <clsCurrency> _vCurrencys;
		_vCurrencys = _LoadCurrencysDataFromFile();

		for (clsCurrency& C : _vCurrencys)
		{
			if (C.getCountryCode() == getCountryCode())
			{
				C = *this;
				break;
			}

		}

		_SaveCurrencyDataToFile(_vCurrencys);

	}

	static clsCurrency _GetEmptyCurrencyObject()
	{
		return clsCurrency(enTypeMode::kEMPTY_MODE, "", "", "", 0);
	}

	
public : 

	clsCurrency(enTypeMode const kTYPE_MODE, string const kNAME_COUNTRY, string const kCOUNTRY_CODE, string const kNAME_COUNTRY_CODE, double const kRATE_COIN_OF_DOLLAR) {
		_ModeType = kTYPE_MODE;
		_NameCountry = kNAME_COUNTRY;
		_CountryCode = kCOUNTRY_CODE;
		_NameCoinCountry = kNAME_COUNTRY_CODE;
		_RateCurrencyOfDollar = kRATE_COIN_OF_DOLLAR;

	}



	string getNameCountry() {
		return _NameCountry; 
	}

	string getCountryCode() {
		return _CountryCode;
	}

	string getNameCountryCoin() {
		return _NameCoinCountry; 
	}

	double getRateCurrency() {
		return _RateCurrencyOfDollar;
	}
	
	bool isEmpty() {
		return (enTypeMode::kEMPTY_MODE == _ModeType);
	};


	void updateRate(double const kNEW_RATE) {
		_RateCurrencyOfDollar = kNEW_RATE;
		_Update();
	};


	static   clsCurrency FindByCode(string CurrencyCode)
	{

		CurrencyCode = clsString::ConvertLetter(CurrencyCode , clsString::enChoiseLetter::kCAPITAL_LETTERS );

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLinetoCurrencyObject(Line);
				if (Currency.getCountryCode() == CurrencyCode)
				{
					MyFile.close();
					return Currency;
				}
			}

			MyFile.close();

		}

		return _GetEmptyCurrencyObject();

	}

	static   clsCurrency FindByCountry(string Country)
	{
		Country = clsString::ConvertLetter(Country , clsString::enChoiseLetter::kCAPITAL_LETTERS);

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::in);//read Mode

		if (MyFile.is_open())
		{
			string Line;
			while (getline(MyFile, Line))
			{
				clsCurrency Currency = _ConvertLinetoCurrencyObject(Line);
				if (clsString::ConvertLetter(Currency.getNameCountry(), clsString::enChoiseLetter::kCAPITAL_LETTERS) == Country)
				{
					MyFile.close();
					return Currency;
				}

			}

			MyFile.close();

		}

		return _GetEmptyCurrencyObject();

	}

	static bool IsCurrencyExistByCode(string CurrencyCode)
	{
		clsCurrency C1 = clsCurrency::FindByCode(CurrencyCode);
		return (!C1.isEmpty());

	};
	static bool IsCurrencyExistByName(string CountryName)
	{
		clsCurrency C1 = clsCurrency::FindByCountry(CountryName);
		return (!C1.isEmpty());

	};
	static vector <clsCurrency> GetCurrenciesList()
	{
		return _LoadCurrencysDataFromFile();
	};


	 double CalculateCurrencyToConvertDollar_Loacally(double const kAMOUNT_ONE) {

		return (kAMOUNT_ONE / this->getRateCurrency());
	};

	 double CalculateCurrencyToConvertDollarToAntherCurrency(double const kAMOUNT,  clsCurrency CurrencyTwo  ) {
		
		 double AmountUSD = CalculateCurrencyToConvertDollar_Loacally(kAMOUNT);

		 if (clsString::ConvertLetter(CurrencyTwo.getCountryCode(), clsString::enChoiseLetter::kCAPITAL_LETTERS) == "USD") {
			 return AmountUSD;
		 }

		 return AmountUSD * CurrencyTwo.getRateCurrency(); 
	};
};

