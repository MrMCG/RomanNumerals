#include <regex>
#include <locale>
#include <iostream>
#include <unordered_map>

#include "RomanNumeralConverter.hpp"

namespace
{
	const std::unordered_map< unsigned char, int > NumeralLookupTable =
	{
		{'I', 1 },
		{'V', 5 },
		{'X', 10 },
		{'L', 50 },
		{'C', 100 },
		{'D', 500 },
		{'M', 1000 }
	};
}

RomanNumeralConverter::RomanNumeralConverter(std::string toConvert) :
	numeral(toConvert),
	validNumeral(false),
	standardNumeral(false)
{
}


bool RomanNumeralConverter::init()
{
	try
	{
		// match only the letters used in roman numerals
		static const std::regex IsValidRegex{ "^[iIvVxXlLcCdDmM]+$" };
		// match only standard rules
		static const std::regex IsStandardRegex{ "^M{0,4}(CM|CD|D?C{0,3})(XC|XL|L?X{0,3})(IX|IV|V?I{0,3})$" };

		// test if the string to convert can be converted
		if (std::regex_match(numeral, IsValidRegex))
		{
			validNumeral = true;
			// Only use uppercase
			std::transform(numeral.begin(), numeral.end(), numeral.begin(), ::toupper);

			if (std::regex_match(numeral, IsStandardRegex))
			{
				standardNumeral = true;
			}
		}
	}
	catch (const std::regex_error& e)
	{
		std::cerr << "regex_error caught: " << e.what() << std::endl;
		validNumeral = false;
		standardNumeral = false;
		return false;
	}

	return true;
}

bool RomanNumeralConverter::isValid() const
{
	return validNumeral;
}

bool RomanNumeralConverter::isStandard() const
{
	return standardNumeral;
}

int RomanNumeralConverter::toDecimal() const
{
	if (!validNumeral)
		return -1;

	int previous = 0, result = 0;
	for (auto iter = numeral.rbegin(); iter != numeral.rend(); ++iter)
	{
		auto value = NumeralLookupTable.at(*iter);
		if (value < previous)
		{
			result -= value;
		}
		else
		{
			result += value;
		}

		previous = value;
	}

	return result;
}