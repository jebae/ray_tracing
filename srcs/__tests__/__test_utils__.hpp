#ifndef __TEST_UTILS__HPP
# define __TEST_UTILS__HPP

# include <iostream>
# include <sstream>
# include <string>
# include "macro.hpp"

# define TEST_TRUE 1
# define TEST_FALSE 0
# define TEST_SUCCESS 1
# define TEST_FAIL 0

using namespace std;

class UnitTest
{
private:
	string name;
	string subject;
	bool print_success;

	void print_success_msg(string func_name);
	void print_fail_msg(string func_name);

public:
	UnitTest(string name, bool print_success=false)
	: name(name), print_success(print_success)
	{}

	void set_subject(string str);
	template <typename T> int eq(T &a, T b);
	template <typename T> int neq(T &a, T b);
};

template <typename T> int UnitTest::eq(T &a, T b)
{
	if (a == b)
	{
		print_success_msg("eq");
		return (TEST_SUCCESS);
	}
	else
	{
		print_fail_msg("eq");
		cout << KRED << "\t: " << a << " != " << b << KNRM << endl;
		return (TEST_FAIL);
	}
}

template <typename T> int UnitTest::neq(T &a, T b)
{
	if (a != b)
	{
		print_success_msg("neq");
		return (TEST_SUCCESS);
	} else
	{
		print_fail_msg("neq");
		cout << KRED << "\t: " << a << " == " << b << KNRM << endl;
		return (TEST_FAIL);
	}
}

#endif
