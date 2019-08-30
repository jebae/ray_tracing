#include "__test_utils__.hpp"
#include "cone.hpp"
#include "ray.hpp"

class TestCone : public UnitTest
{
public:
	TestCone(bool print_success=false);
	Cone create_test_cone(void);
	void test_construct_case1(void);
	void test_intersect_case1(void);
	void all(void);
};

TestCone::TestCone(bool print_success)
: UnitTest("Cone", print_success)
{}

Cone TestCone::create_test_cone(void)
{
	int specular_alpha = 50;
	float reflectivity = 0.3f;
	float transparency = 0.2f;
	float ior = 1.5f;
	Vec4 color(vector<float>{0.4f, 0.4f, 0.4f});
	Vec4 vertex(vector<float>{-1.0f, 1.0f, 1.5f});
	Vec4 perp_vec(vector<float>{0.5f, -0.5f, -2.0f});
	float height = 2.0f;
	float theta = M_PI / 6.0f;

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

void TestCone::test_construct_case1(void)
{
	set_subject("Cone has to have cos_2_theta, and normalized perp_vec");
	Cone cone = create_test_cone();
	float precision = 1000000;
	float norm;

	eq(cone.cos_2_theta, powf(cosf(cone.theta), 2.0f));
	norm = round(cone.perp_vec.norm() * precision) / precision;
	eq(norm, 1.0f);
}

void TestCone::test_intersect_case1(void)
{
	set_subject("cone intersect has to return true");
	Cone cone = create_test_cone();
	Ray r(
		Vec4(vector<float>{0.0f, 0.0f, 0.0f}),
		Vec4(vector<float>{0.0f, 1.0, 0.0f})
	);
	float t;
	bool res;
	float precision = 1000000;

	res = cone.intersect(r, t);
	eq(res, true);
	// rounding t to compare
	t = round(t * precision) / precision;
	eq(t, 1.290647f);
}

void TestCone::all(void)
{
	test_construct_case1();
	test_intersect_case1();
}
