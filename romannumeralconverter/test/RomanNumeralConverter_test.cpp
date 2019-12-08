#include <gtest/gtest.h>
#include <tuple>

#include "RomanNumeralConverter.hpp"

// numeral, isValid, isStandard, decimalValue
using KnownValue = std::tuple< std::string, bool, bool, int >;

class KnownValuesTest : public testing::TestWithParam < KnownValue >
{};

INSTANTIATE_TEST_SUITE_P(Parameterised, KnownValuesTest,
	::testing::Values
	(
		KnownValue{ "", false, false, -1 },
		// case sensitivity
		KnownValue{ "iI", true, true, 2 },
		KnownValue{ "vV", true, false, 10 },
		KnownValue{ "xX", true, true, 20 },
		KnownValue{ "lL", true, false, 100 },
		KnownValue{ "cC", true, true, 200 },
		KnownValue{ "dD", true, false, 1000 },
		KnownValue{ "mM", true, true, 2000 },
		// repeating/non standard
		KnownValue{ "iiiii", true, false, 5 },
		KnownValue{ "vvvvv", true, false, 25 },
		KnownValue{ "xxxxx", true, false, 50 },
		KnownValue{ "lllll", true, false, 250 },
		KnownValue{ "ccccc", true, false, 500 },
		KnownValue{ "ddddd", true, false, 2500 },
		KnownValue{ "mmmmm", true, false, 5000 },
		// known values
		KnownValue{ "i", true, true, 1 },
		KnownValue{ "iii", true, true, 3 },
		KnownValue{ "iv", true, true, 4 },
		KnownValue{ "v", true, true, 5 },
		KnownValue{ "vi", true, true, 6 },
		KnownValue{ "vii", true, true, 7 },
		KnownValue{ "viii", true, true, 8 },
		KnownValue{ "ix", true, true, 9 },
		KnownValue{ "x", true, true, 10 },
		KnownValue{ "xi", true, true, 11 },
		KnownValue{ "xii", true, true, 12 },
		KnownValue{ "xiii", true, true, 13 },
		KnownValue{ "xiv", true, true, 14 },
		KnownValue{ "xv", true, true, 15 },
		KnownValue{ "xvi", true, true, 16 },
		KnownValue{ "xvii", true, true, 17 },
		KnownValue{ "xviii", true, true, 18 },
		KnownValue{ "xix", true, true, 19 },
		KnownValue{ "xx", true, true, 20 },
		KnownValue{ "XXXVIII", true, true, 38 },
		KnownValue{ "XLVII", true, true, 47 },
		KnownValue{ "LXXXVIII", true, true, 88 },
		KnownValue{ "DCCC", true, true, 800 },
		KnownValue{ "LXXXIX", true, true, 89 }
	));

TEST_P(KnownValuesTest, value)
{
	auto param = GetParam();

	RomanNumeralConverter converter( std::get<0>(param) );
	EXPECT_EQ( converter.isValid(), std::get<1>(param) );
	EXPECT_EQ( converter.isStandard(), std::get<2>(param) );
	EXPECT_EQ( converter.toDecimal(), std::get<3>(param) );
}

TEST(RomanNumeralConverter, badInput)
{
	std::string characters{ " !\"#$%&\'()*+,-./0123456789:;<=>?@ABEFGHJKNOPQRSTUWYZ[\\]^_`abefghjknopqrstuwyz{|}~" };
	for (char const c : characters)
	{
		RomanNumeralConverter converter( std::string(1,c) );
		EXPECT_FALSE(converter.isValid());
		EXPECT_FALSE(converter.isStandard());
		EXPECT_EQ(converter.toDecimal(), -1);
	}
}