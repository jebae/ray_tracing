#include "__test_utils__.hpp"
#include "spherical_light.hpp"

class TestSphericalLight : public UnitTest
{
public:
	TestSphericalLight(bool print_success=false);
	void test_get_distance_case1(void);
	void test_get_direction_case1(void);
	void all(void);
};

TestSphericalLight::TestSphericalLight(bool print_success)
: UnitTest("Spherical light", print_success)
{}

void TestSphericalLight::test_get_distance_case1(void)
{
	set_subject("Spherical light has to return proper distance");
	Vec4 origin(vector<float>{0.1f, 0.2f, 0.3f});
	SphericalLight light(
		Vec4(vector<float>(3, 0.9f)),
		origin
	);
	Vec4 point(vector<float>{1.0f, 2.0f, -31.2f});
	Vec4 op = point - origin;
	float expected;
	float res;

	expected = op.norm();
	res = light.get_distance(point);
	eq(res, expected);
}

void TestSphericalLight::test_get_direction_case1(void)
{
	set_subject("Spherical light has to return proper direction");
	Vec4 origin(vector<float>{0.1f, 0.2f, 0.3f});
	SphericalLight light(
		Vec4(vector<float>(3, 0.9f)),
		origin
	);
	Vec4 point(vector<float>{1.0f, 2.0f, -31.2f});
	Vec4 expected = point - origin;
	expected.normalize();
	Vec4 res;

	res = light.get_direction(point);
	eq(res, expected);
}

void TestSphericalLight::all(void)
{
	test_get_distance_case1();
	test_get_direction_case1();
}
