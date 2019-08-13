#include "__test_utils__.hpp"
#include "vec4.hpp"

class TestVec4
{
private:
	UnitTest test;

public:
	TestVec4(void);
	void test_assign_case1(void);
	void test_cout_case1(void);
	void test_equal_case1(void);
	void test_equal_case2(void);
	void all(void);
};

TestVec4::TestVec4(void)
: test(UnitTest("Vec4"))
{}

void TestVec4::test_assign_case1(void)
{
	test.set_subject() ="[] operator has to work";
	Vec4 v;
	float arr[3] = {3.2f, 32.0f, -1.0f};

	v[0] = arr[0];
	v[1] = arr[1];
	v[2] = arr[2];

	test.eq(v[0], arr[0]);
	test.eq(v[1], arr[1]);
	test.eq(v[2], arr[2]);
}

void TestVec4::test_cout_case1(void)
{
	test.set_subject() = "<< operator has to work";
	Vec4 v;
	ostringstream str_stream;
	string expected_output = "Vec4[0, 3.14, 0, 1]";
	string res;

	v[1] = 3.14f;
	str_stream << v;
	res = str_stream.str();
	test.eq(res, expected_output);
}

void TestVec4::test_equal_case1(void)
{
	test.set_subject() = "== operator has to work with returning true";
	Vec4 v1;
	Vec4 v2;
	bool res = v1 == v2;
	bool expected_res = true;

	test.eq(res, expected_res);
}

void TestVec4::test_equal_case2(void)
{
	test.set_subject() = "== operator has to work with returning false";
	Vec4 v1;
	Vec4 v2;
	
	v2[3] = 2.1f;
	bool res = v1 == v2;
	bool expected_res = false;

	test.eq(res, expected_res);
}

void TestVec4::all(void)
{
	test_assign_case1();
	test_cout_case1();
	test_equal_case1();
	test_equal_case2();
}
