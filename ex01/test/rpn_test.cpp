#include <gtest/gtest.h>
#include "RPN.hpp"

TEST(RPNTest, ValidTest)
{
	EXPECT_EQ(rpn("0 2 /"), 0);
	EXPECT_EQ(rpn("1 2 +"), 3);
	EXPECT_EQ(rpn("6 2 /"), 3);
	EXPECT_EQ(rpn("\t\n\v\f\r 1 \t\n\v\f\r 2 \t\n\v\f\r + \t\n\v\f\r"), 3);
	EXPECT_EQ(rpn("3 4 +"), 7);
	EXPECT_EQ(rpn("2 7 + 5 2 - *" ), 27);
	EXPECT_EQ(rpn("7 2 - 3 4 - *"), -5);
	EXPECT_EQ(rpn("2 3 1 * + 9 -"), -4);
	EXPECT_EQ(rpn("5 1 2 + 4 * + 3 -"), 14);
	EXPECT_EQ(rpn("3 4 + 1 2 - *"), -7);
	EXPECT_EQ(rpn("4 8 + 1 3 + /"), 3);
	EXPECT_EQ(rpn("9 3 / 2 * 7 4 - +"), 9);
	EXPECT_EQ(rpn("4 6 + 2 / 2 * 7 +"), 17);
	EXPECT_EQ(rpn("3 5 8 * 7 + *"), 141);
	EXPECT_EQ(rpn("8 5 * 7 4 2 + * +"), 82);
	EXPECT_EQ(rpn("4  2  5  *  +  1  3  2  *  +  /"), 2);
}

TEST(RPNTest, InvalidTest)
{
	try
	{
		rpn("1 0 /");
	}
	catch(string& err_msg)
	{
		EXPECT_EQ(err_msg, "Error: floating point exception detected");
	}
	try
	{
		rpn("(1 + 1)");
	}
	catch(string& err_msg)
	{
		EXPECT_EQ(err_msg, "Error: invalid character at str[0] ('(')");
	}
	try
	{
		rpn("12+?");
	}
	catch(string& err_msg)
	{
		EXPECT_EQ(err_msg, "Error: invalid character at str[3] ('?')");
	}
	try
	{
		rpn("1 + 1");
	}
	catch(string& err_msg)
	{
		EXPECT_EQ(err_msg, "Error: cannot pop at str[2] ('+')");
	}
	try
	{
		rpn("12+-/*");
	}
	catch(string& err_msg)
	{
		EXPECT_EQ(err_msg, "Error: cannot pop at str[3] ('-')");
	}
	try
	{
		rpn("");
	}
	catch(string& err_msg)
	{
		EXPECT_EQ(err_msg, "Error: stack is empty");
	}
	try
	{
		rpn("       ");
	}
	catch(string& err_msg)
	{
		EXPECT_EQ(err_msg, "Error: stack is empty");
	}
}
