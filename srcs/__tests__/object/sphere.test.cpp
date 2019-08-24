#include "__test_utils__.hpp"
#include "sphere.hpp"

class TestSphere
{
private:
	UnitTest test;

public:
	TestSphere(bool print_success=false);
	void test_construct_case1(void);
	void all(void);
};

TestSphere::TestSphere(bool print_success)
: test(UnitTest("Sphere", print_success))
{}

void TestSphere::test_construct_case1(void)
{

}

void TestSphere::all(void)
{

}
