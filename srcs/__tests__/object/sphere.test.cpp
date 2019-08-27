#include "__test_utils__.hpp"
#include "sphere.hpp"
#include "ray.hpp"

class TestSphere : public UnitTest
{
public:
	TestSphere(bool print_success=false);
	Sphere create_test_sphere(void);
	void test_intersect_case1(void);
	void test_intersect_case2(void);
	void all(void);
};

TestSphere::TestSphere(bool print_success)
: UnitTest("Sphere", print_success)
{}

Sphere TestSphere::create_test_sphere(void)
{
	int specular_alpha = 50;
	float reflectivity = 0.3f;
	float transparency = 0.2f;
	float ior = 1.5f;
	Vec4 color(vector<float>{0.4f, 0.4f, 0.4f});
	float radius = 1.0f;
	Vec4 center(vector<float>{0.0f, 3.0f, 2.0f});

	return (Sphere(
		specular_alpha,
		reflectivity,
		transparency,
		ior,
		color,
		radius,
		center
	));
}

void TestSphere::test_intersect_case1(void)
{
	set_subject("sphere intersect has to return true");
	Sphere s = create_test_sphere();
	Vec4 d(vector<float>{0.0f, 3.0, 2.1f});
	d.normalize();
	Ray r(
		Vec4(vector<float>{0.0f, 0.0f, 0.0f}), d
	);
	float t;
	bool res;
	float precision = 1000000;

	res = s.intersect(r, t);
	eq(res, true);
	// rounding t to compare
	t = round(t * precision) / precision;
	eq(t, 2.607982f);
}

void TestSphere::test_intersect_case2(void)
{
	set_subject("sphere intersect has to return false");
	Sphere s = create_test_sphere();
	Vec4 d(vector<float>{0.0f, 3.0, 2.1f});
	d.normalize();
	Ray r(
		Vec4(vector<float>{0.0f, 0.0f, 0.0f}),
		-1.0f * d
	);
	float t;
	bool res;

	res = s.intersect(r, t);
	eq(res, false);
}

void TestSphere::all(void)
{
	test_intersect_case1();
	test_intersect_case2();
}
