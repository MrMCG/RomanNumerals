#include <iostream>
#include <string>
#include <sstream>

#include "RomanNumeralConverter.hpp"

std::string summary()
{
	std::stringstream stream;
	stream << "Roman numerals are made up of letters representing numbers: " << '\n'
		<< " I = 1" << '\n'
		<< " V = 5" << '\n'
		<< " X = 10" << '\n'
		<< " L = 50" << '\n'
		<< " C = 100" << '\n'
		<< " D = 500" << '\n'
		<< " M = 1000 " << '\n'
		<< "Other numbers are built by combining these letters" << '\n'
		<< "e.g." << '\n'
		<< " III = 3 " << '\n'
		<< " XIV = 14" << '\n'
		<< " XL  = 40" << '\n'
		<< "The 'Standard' set of rules should be followed when creating roman numerals" << '\n'
		<< "If these rules are not followed, the conversion may be incorrect" << '\n';

	return stream.str();
}

int main()
{
	std::cout << "Roman Numeral Converter" << '\n';
	std::cout << "Type 'exit' to quit the application" << '\n';
	std::cout << "Type 'help' to see a brief summary" << '\n';
	std::string userInput = "";

	while (true)
	{
		std::cout << "Enter a Roman Numeral: " << std::flush;
		std::getline(std::cin, userInput);

		if (userInput == "exit")
		{
			break;
		}
		else if (userInput == "help")
		{
			std::cout << summary() << std::endl;
			continue;
		}

		RomanNumeralConverter converter( userInput );

		// this will provide basic input validation
		if (!converter.isValid())
		{
			std::cerr << "Input is not a valid roman numeral, cant convert " << std::endl;
			continue;
		}

		if (!converter.isStandard())
		{
			std::cout << "Input is not standard, conversion could be incorrect" << std::endl;
		}

		auto result = converter.toDecimal();

		if (result < 0)
		{
			std::cerr << "There was an error while converting!" << std::endl;
			continue;
		}
		else 
		{
			std::cout << "Converted number: " << result << std::endl;
		}
		
	}
	return 0;
}