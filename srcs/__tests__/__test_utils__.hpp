#ifndef __TEST_UTILS__HPP
# define __TEST_UTILS__HPP

# include <iostream>

# define KRED "\x1B[31m"
# define KGRN "\x1B[32m"
# define KYEL "\x1B[33m"
# define KNRM "\x1B[0m"

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

	void show_success_msg();
	void show_fail_msg();

public:
	UnitTest(string arg_name)
	: name(arg_name)
	{}

	void set_subject(string arg_subject);
	template <typename T> int eq(T &a, T &b);
	template <typename T> int neq(T &a, T &b);
};

template <typename T> int UnitTest::eq(T &a, T &b)
{
	if (a == b)
	{
		show_success_msg();
		return (TEST_SUCCESS);
	}
	else
	{
		show_fail_msg();
		cout << KRED << "\t-> " << a << " != " << b << KNRM << endl;
		return (TEST_FAIL);
	}
}

template <typename T> int UnitTest::neq(T &a, T &b)
{
	if (a != b)
	{
		show_success_msg();
		return (TEST_SUCCESS);
	}
	else
	{
		show_fail_msg();
		cout << KRED << "\t-> " << a << " == " << b << KNRM << endl;
		return (TEST_FAIL);
	}
}

#endif
