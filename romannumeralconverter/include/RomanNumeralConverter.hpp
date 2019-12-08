#pragma once

#include <string>

class RomanNumeralConverter
{
public:
	RomanNumeralConverter( std::string toConvert );

	bool init();
	bool isValid() const;
	bool isStandard() const;
	int toDecimal() const;

private:
	std::string numeral;
	bool validNumeral;
	bool standardNumeral;
};