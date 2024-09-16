#include <gtest/gtest.h>
#include "Regex.hpp"

TEST(RegexTest, TrueTest)
{
	EXPECT_TRUE(my::Regex::isDatePattern("1998-07-17"));
	EXPECT_TRUE(my::Regex::isDatePattern("0001-01-01"));
	EXPECT_TRUE(my::Regex::isDatePattern("9999-12-31"));
	EXPECT_TRUE(my::Regex::isDatePattern("2024-09-15"));
	EXPECT_TRUE(my::Regex::isDatePattern("1192-05-05"));

	EXPECT_TRUE(my::Regex::isPositiveIntegerPattern("1"));
	EXPECT_TRUE(my::Regex::isPositiveIntegerPattern("10000000000000"));
	EXPECT_TRUE(my::Regex::isPositiveIntegerPattern("2147483647"));
	EXPECT_TRUE(my::Regex::isPositiveIntegerPattern("2147483648"));

	EXPECT_TRUE(my::Regex::isPositivePointNumberPattern("1"));
	EXPECT_TRUE(my::Regex::isPositivePointNumberPattern("1.0"));
	EXPECT_TRUE(my::Regex::isPositivePointNumberPattern("1.012345"));
	EXPECT_TRUE(my::Regex::isPositivePointNumberPattern("2147483647.9"));
	EXPECT_TRUE(my::Regex::isPositivePointNumberPattern("2147483648.1"));
}

TEST(RegexTest, FalseTest)
{
	EXPECT_FALSE(my::Regex::isDatePattern("0001-00-17"));
	EXPECT_FALSE(my::Regex::isDatePattern("0001-07-00"));
	EXPECT_FALSE(my::Regex::isDatePattern("0001-13-01"));
	EXPECT_FALSE(my::Regex::isDatePattern("0001-01-32"));
	EXPECT_FALSE(my::Regex::isDatePattern("10000-07-17"));
	EXPECT_FALSE(my::Regex::isDatePattern("1998-007-17"));
	EXPECT_FALSE(my::Regex::isDatePattern("1998-07-017"));
	EXPECT_FALSE(my::Regex::isDatePattern("1998--07-17"));
	EXPECT_FALSE(my::Regex::isDatePattern("1998-07--17"));
	EXPECT_FALSE(my::Regex::isDatePattern(" 1998-07-17"));
	EXPECT_FALSE(my::Regex::isDatePattern("1998-07-17 "));
	EXPECT_FALSE(my::Regex::isDatePattern("1998--07-17"));
	EXPECT_FALSE(my::Regex::isDatePattern("1998-07--17"));
	EXPECT_FALSE(my::Regex::isDatePattern("1998-0 7-17"));
	EXPECT_FALSE(my::Regex::isDatePattern("a998-07-17"));
	EXPECT_FALSE(my::Regex::isDatePattern("1998=07-17"));
	EXPECT_FALSE(my::Regex::isDatePattern("1998-07=17"));
	EXPECT_FALSE(my::Regex::isDatePattern(""));

	EXPECT_FALSE(my::Regex::isPositiveIntegerPattern("a"));
	EXPECT_FALSE(my::Regex::isPositiveIntegerPattern("+1"));
	EXPECT_FALSE(my::Regex::isPositiveIntegerPattern("-1"));
	EXPECT_FALSE(my::Regex::isPositiveIntegerPattern(""));

	EXPECT_FALSE(my::Regex::isPositivePointNumberPattern(".0"));
	EXPECT_FALSE(my::Regex::isPositivePointNumberPattern("-1"));
	EXPECT_FALSE(my::Regex::isPositivePointNumberPattern("1.0.0"));
	EXPECT_FALSE(my::Regex::isPositivePointNumberPattern("1."));
	EXPECT_FALSE(my::Regex::isPositivePointNumberPattern("a.1"));
	EXPECT_FALSE(my::Regex::isPositivePointNumberPattern("1.a"));
	EXPECT_FALSE(my::Regex::isPositivePointNumberPattern(""));
}
