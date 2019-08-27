#include "__test_utils__.hpp"
#include "cone.hpp"
#include "ray.hpp"

class TestCone : public UnitTest
{
public:
	TestCone(bool print_success=false);
	void all(void);
};

TestCone::TestCone(bool print_success)
: UnitTest("TestCone", print_success)
{}

Cone TestCone::create_test_cone(void)
{
	int specular_alpha = 50;
	float reflectivity = 0.3f;
	float transparency = 0.2f;
	float ior = 1.5f;
	Vec4 color(vector<float>{0.4f, 0.4f, 0.4f});
	Vec4 vertex(vector<float>{-1.0f, 3.0f, 2.0f});
	Vec4 perp_vec(vector<float>{0.5f, -0.5f, -2.0f});
	float height = 2.0f;
	float theta = M_PI / 6.0ff;
	// perp_vec, height, vertex, theta

	return (Cone(
		specular_alpha,
		reflectivity,
		transparency,
		ior,
		color,
		vertex,
		perp_vec,
		height,
		theta
	));
}

void TestCone::test_intersect_case1(void)
{
	set_subject("sphere intersect has to return true");
	Cone s = create_test_cone();
	Vec4 d(vector<float>{0.0f, 3.0, 2.1f});
	d.normalize();
	Ray r(
		Vec4(vector<float>{0.0f, 0.0f, 0.0f}), d
	);
	float t;
	bool res;
	float precision = 1000000;

	res = s.intersect(&r, t);
	eq(res, true);
	// rounding t to compare
	t = round(t * precision) / precision;
	eq(t, /* expected result */);
}

void TestCone::all(void)
{

}
