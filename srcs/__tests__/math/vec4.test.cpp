#include "__test_utils__.hpp"
#include "vec4.hpp"

class TestVec4
{
private:
	UnitTest test;

public:
	TestVec4(void);
	void test_add_case1(void);
	void all(void);
};

TestVec4::TestVec4(void)
: test(UnitTest("Vec4"))
{}

void TestVec4::test_add_case1(void)
{
	test.set_subject("+ operator has to be success");
	Vec4 v1;
	Vec4 v2;
	Vec4 expected;

	v1[0] = 3.0f;
	v1[1] = 32.0f;
	v1[2] = -1.0f;

	v2[0] = -4.0f;
	v2[1] = 56.0f;
	v2[2] = 0.0f;

	expected[0] = v1[0] + v2[0];
	expected[1] = v1[1] + v2[1];
	expected[2] = v1[2] + v2[2];
	test.eq(v1 + v2, expected);
}

void TestVec4::all(void)
{
	test_add_case1();
}
