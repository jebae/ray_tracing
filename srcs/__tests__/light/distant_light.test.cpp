#include "__test_utils__.hpp"
#include "distant_light.hpp"

class TestDistantLight : public UnitTest
{
public:
	TestDistantLight(bool print_success=false);
	void test_get_distance_case1(void);
	void test_get_direction_case1(void);
	void test_get_intensity_case1(void);
	void all(void);
};

TestDistantLight::TestDistantLight(bool print_success)
: UnitTest("Distant light", print_success)
{}

void TestDistantLight::test_get_distance_case1(void)
{
	set_subject("Distant light distance has to be INFINITY");
	DistantLight light(
		Vec4(vector<float>(3, 0.9f)),
		Vec4(vector<float>{0.1f, 0.2f, 0.3f})
	);
	Vec4 point;
	float distance;

	distance = light.get_distance(point);
	eq(distance, INFINITY);
}

void TestDistantLight::test_get_direction_case1(void)
{
	set_subject("Distant light direction has to be own direction");
	Vec4 direction(vector<float>{0.1f, 0.2f, 0.3f});
	DistantLight light(
		Vec4(vector<float>(3, 0.9f)),
		direction
	);
	Vec4 point;
	Vec4 res;

	direction.normalize();
	res = light.get_direction(point);
	eq(res, direction);
}

void TestDistantLight::test_get_intensity_case1(void)
{
	set_subject("Distant light intensity has to be same for all point");
	Vec4 intensity(vector<float>(3, 0.9f));
	DistantLight light(
		intensity,
		Vec4(vector<float>{0.1f, 0.2f, 0.3f})
	);
	Vec4 point;
	Vec4 res = light.get_intensity(INFINITY);

	eq(res, intensity);
}

void TestDistantLight::all(void)
{
	test_get_distance_case1();
	test_get_direction_case1();
	test_get_intensity_case1();
}
