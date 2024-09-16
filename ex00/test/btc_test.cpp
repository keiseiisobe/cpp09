#include <gtest/gtest.h>
#include "BitcoinExchange.hpp"

TEST(BtcTest, MainTest)
{
	std::map<string, float>	map;
	csv2map("../../data.csv", map);
	{
		std::stringstream	ss;
		ss << "2009-01-02 => 1 = " << 1 * 0;
		EXPECT_EQ(getResult(map, "2009-01-02 | 1"), ss.str());
	}
	{
		std::stringstream	ss;
		ss << "2010-08-17 => 100 = " << 100 * 0;
		EXPECT_EQ(getResult(map, "2010-08-17 | 100"), ss.str());
	}
	{
		std::stringstream	ss;
		ss << "2010-08-20 => 4.2 = " << 4.2 * 0.07;
		EXPECT_EQ(getResult(map, "2010-08-20 | 4.2"), ss.str());
	}
	{
		std::stringstream	ss;
		ss << "2010-08-20 => 42 = " << 42 * 0.07;
		EXPECT_EQ(getResult(map, "2010-08-20 | 42"), ss.str());
	}
	{
		std::stringstream	ss;
		ss << "9999-12-31 => 1 = " << 1 * 47115.93;
		EXPECT_EQ(getResult(map, "9999-12-31 | 1"), ss.str());
	}
	try
	{
		getResult(map, "0000-01-01 | 1");
	}
	catch(string& err_msg)
	{
		EXPECT_EQ(err_msg, "Error: too old date.");
	}
	try
	{
		getResult(map, "2009-01-01 | 1");
	}
	catch(string& err_msg)
	{
		EXPECT_EQ(err_msg, "Error: too old date.");
	}
	{
		std::stringstream	ss;
		ss << "2011-10-29 => 1000.123 = " << 1000.123 * 3.39;
		EXPECT_EQ(getResult(map, "2011-10-29 | 1000.123"), ss.str());
	}
	{
		std::stringstream	ss;
		ss << "2011-10-30 => 1000.999 = " << 1000.999 * 3.39;
		EXPECT_EQ(getResult(map, "2011-10-30 | 1000.999"), ss.str());
	}
	{
		std::stringstream	ss;
		ss << "2011-10-31 => 999 = " << 999 * 3.38;
		EXPECT_EQ(getResult(map, "2011-10-31 | 999"), ss.str());
	}
}
