#include "__test_utils__.hpp"
#include "camera.hpp"

class TestCamera
{
private:
	UnitTest test;

public:
	TestCamera(void);
	void test_set_z_axis_case1(void);
}

TestCamera::TestCamera(void)
: test(UnitTest("Camera"))
{}

void TestCamera::test_set_z_axis_case1(void)
{
	Camera cam;

	
}

void TestVec4::all(void)
{
	test_set_z_axis_case1();
}
