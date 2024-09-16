#include <gtest/gtest.h>
#include "btc.hpp"

TEST(LoadFileTest, CsvTest)
{
	{
		std::map<string, float>	map;
		Csv2map("../../data.csv", map);
		EXPECT_FLOAT_EQ(map["2009-01-02"], atof("0"));
		EXPECT_FLOAT_EQ(map["2010-08-17"], atof("0"));
		EXPECT_FLOAT_EQ(map["2010-08-20"], atof("0.07"));
		EXPECT_FLOAT_EQ(map["2015-03-08"], atof("275"));
		EXPECT_FLOAT_EQ(map["2022-03-29"], atof("47115.93"));
	}

	try
	{
		std::map<string, float>	map;
		Csv2map("../data/csv/empty.csv", map);
	}
	catch (std::string& err_msg)
	{
		EXPECT_EQ(err_msg, "Error: could not open file.");
	}
	try
	{
		std::map<string, float>	map;
		Csv2map("../data/csv/no_access_right.csv", map);
	}
	catch (std::string& err_msg)
	{
		EXPECT_EQ(err_msg, "Error: could not open file.");
	}

	{
		std::map<string, float>	map;
		Csv2map("../data/csv/nodata.csv", map);
		EXPECT_EQ(map.size(), 0);
	}

	try
	{
		std::map<string, float>	map;
		Csv2map("../data/csv/nodata_with_newline.csv", map);
	}
	catch (std::string& err_msg)
	{
		EXPECT_EQ(err_msg, "Error: invalid csv format.");
	}

	try
	{
		std::map<string, float>	map;
		Csv2map("../data/csv/invalid_date.csv", map);
	}
	catch (std::string& err_msg)
	{
		EXPECT_EQ(err_msg, "Error: invalid date format in csv.");
	}

	try
	{
		std::map<string, float>	map;
		Csv2map("../data/csv/empty_date.csv", map);
	}
	catch (std::string& err_msg)
	{
		EXPECT_EQ(err_msg, "Error: invalid date format in csv.");
	}

	try
	{
		std::map<string, float>	map;
		Csv2map("../data/csv/invalid_rate.csv", map);
	}
	catch (std::string& err_msg)
	{
		EXPECT_EQ(err_msg, "Error: invalid positive point number format in csv.");
	}

	try
	{
		std::map<string, float>	map;
		Csv2map("../data/csv/empty_rate.csv", map);
	}
	catch (std::string& err_msg)
	{
		EXPECT_EQ(err_msg, "Error: invalid positive point number format in csv.");
	}
}
