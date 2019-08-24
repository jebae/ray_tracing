#include "__test_utils__.hpp"
#include "camera.hpp"

class TestCamera
{
private:
	UnitTest test;

public:
	TestCamera(bool print_success=false);
	void test_construct_case1(void);
	void all(void);
};

TestCamera::TestCamera(bool print_success)
: test(UnitTest("Camera", print_success))
{}

void TestCamera::test_construct_case1(void)
{
	test.set_subject("camera has to be constructed");
	Vec4 pos(vector<float>{1.0f, 2.54f, 3.0f});
	Vec4 focus(vector<float>{-2.0f, -3.13f, 2.0f});
	Camera cam(pos, focus);
	float precision = 1000000;
	auto rounding = [&precision] (float *f) -> void
	{
		*f = round(*f * precision) / precision;
	};

	test.eq(cam.pos, pos);
	// round axis to test eq
	cam.z_axis.for_each(rounding);
	cam.x_axis.for_each(rounding);
	cam.y_axis.for_each(rounding);
	test.eq(cam.z_axis, Vec4(vector<float>{-0.462092, -0.873353, -0.154031}));
	test.eq(cam.x_axis, Vec4(vector<float>{-0.883902, 0.467673, 0}));
	test.eq(cam.y_axis, Vec4(vector<float>{0.072036, 0.136148, -0.988066}));
}

void TestCamera::all(void)
{
	test_construct_case1();
}
