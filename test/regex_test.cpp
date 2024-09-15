#include <gtest/gtest.h>
#include "Regex.hpp"

TEST(RegexTest, TrueTest)
{
	EXPECT_EQ(my::Regex::isDatePattern("1998-07-17"), true);
	EXPECT_EQ(my::Regex::isDatePattern("0001-01-01"), true);
	EXPECT_EQ(my::Regex::isDatePattern("9999-12-31"), true);
	EXPECT_EQ(my::Regex::isDatePattern("2024-09-15"), true);
	EXPECT_EQ(my::Regex::isDatePattern("1192-05-05"), true);

	EXPECT_EQ(my::Regex::isPositiveIntegerPattern("1"), true);
	EXPECT_EQ(my::Regex::isPositiveIntegerPattern("10000000000000"), true);
	EXPECT_EQ(my::Regex::isPositiveIntegerPattern("2147483647"), true);
	EXPECT_EQ(my::Regex::isPositiveIntegerPattern("2147483648"), true);

	EXPECT_EQ(my::Regex::isPositivePointNumberPattern("1"), true);
	EXPECT_EQ(my::Regex::isPositivePointNumberPattern("1.0"), true);
	EXPECT_EQ(my::Regex::isPositivePointNumberPattern("1.012345"), true);
	EXPECT_EQ(my::Regex::isPositivePointNumberPattern("2147483647.9"), true);
	EXPECT_EQ(my::Regex::isPositivePointNumberPattern("2147483648.1"), true);
}

TEST(RegexTest, FalseTest)
{
	EXPECT_EQ(my::Regex::isDatePattern("0001-00-17"), false);
	EXPECT_EQ(my::Regex::isDatePattern("0001-07-00"), false);
	EXPECT_EQ(my::Regex::isDatePattern("0001-13-01"), false);
	EXPECT_EQ(my::Regex::isDatePattern("0001-01-32"), false);
	EXPECT_EQ(my::Regex::isDatePattern("10000-07-17"), false);
	EXPECT_EQ(my::Regex::isDatePattern("1998-007-17"), false);
	EXPECT_EQ(my::Regex::isDatePattern("1998-07-017"), false);
	EXPECT_EQ(my::Regex::isDatePattern("1998--07-17"), false);
	EXPECT_EQ(my::Regex::isDatePattern("1998-07--17"), false);
	EXPECT_EQ(my::Regex::isDatePattern(" 1998-07-17"), false);
	EXPECT_EQ(my::Regex::isDatePattern("1998-07-17 "), false);
	EXPECT_EQ(my::Regex::isDatePattern("1998--07-17"), false);
	EXPECT_EQ(my::Regex::isDatePattern("1998-07--17"), false);
	EXPECT_EQ(my::Regex::isDatePattern("1998-0 7-17"), false);
	EXPECT_EQ(my::Regex::isDatePattern("a998-07-17"), false);
	EXPECT_EQ(my::Regex::isDatePattern("1998=07-17"), false);
	EXPECT_EQ(my::Regex::isDatePattern("1998-07=17"), false);
	EXPECT_EQ(my::Regex::isDatePattern(""), false);

	EXPECT_EQ(my::Regex::isPositiveIntegerPattern("a"), false);
	EXPECT_EQ(my::Regex::isPositiveIntegerPattern("+1"), false);
	EXPECT_EQ(my::Regex::isPositiveIntegerPattern("-1"), false);

	EXPECT_EQ(my::Regex::isPositivePointNumberPattern(".0"), false);
	EXPECT_EQ(my::Regex::isPositivePointNumberPattern("-1"), false);
	EXPECT_EQ(my::Regex::isPositivePointNumberPattern("1.0.0"), false);
	EXPECT_EQ(my::Regex::isPositivePointNumberPattern("1."), false);
	EXPECT_EQ(my::Regex::isPositivePointNumberPattern("a.1"), false);
	EXPECT_EQ(my::Regex::isPositivePointNumberPattern("1.a"), false);
}
