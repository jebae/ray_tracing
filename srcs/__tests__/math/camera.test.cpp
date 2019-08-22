#include "__test_utils__.hpp"
#include "camera.hpp"

class TestCamera
{
friend class Camera;

private:
	UnitTest test;

public:
	TestCamera(void);
	void test_construct_case1(void);
	void all(void);
};

TestCamera::TestCamera(void)
: test(UnitTest("Camera"))
{}

void TestCamera::test_construct_case1(void)
{
	test.set_subject() = "camera has to be constructed";
	Vec4 pos(vector<float>{1.0f, 2.54f, 3.0f});
	Vec4 focus(vector<float>{-2.0f, -3.13f, 2.0f});
	Camera cam(pos, focus);
	float precision = 1000000;

	cout << cam.z_axis << endl;
	// make for each function to vec4
	cout << cam.z_axis << endl;
}

void TestCamera::all(void)
{
	test_construct_case1();
}
