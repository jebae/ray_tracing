#include "__test_utils__.hpp"
#include "ray.hpp"

class TestRay : public UnitTest
{
public:
	TestRay(bool print_success=false);
	void test_get_intersect_point_case1(void);
	void test_get_ray_by_grid_props_case1(void);
	void all(void);
};

TestRay::TestRay(bool print_success)
: UnitTest("Ray", print_success)
{}

void TestRay::test_get_intersect_point_case1(void)
{
	set_subject("ray has to get intersect point");
	Vec4 e(vector<float>{3.14f, 2.0f, -0.45f});
	Vec4 d(vector<float>{0.5f, 0.01f, -0.45f});
	d.normalize();
	Ray ray = Ray(e, d);
	float t = 0.34f;
	Vec4 intersect = ray.get_intersect_point(t);

	eq(intersect, e + t * d);
}

void TestRay::test_get_ray_by_grid_props_case1(void)
{
	Camera cam(
		Vec4(vector<float>{0.0, 0.0, 0.0}),
		Vec4(vector<float>{0.0, 1.0, 0.0})
	);
	RayGridProps props(cam, 1000, 800);
	int i = 2;
	int j = 3;
	Ray ray = Ray::get_ray_by_grid_props(props, i, j);
	Vec4 d = props.offset + i * props.dx + j * props.dy;
	d.normalize();

	eq(ray.e, props.e);
	eq(ray.d, d);
}

void TestRay::all(void)
{
	test_get_intersect_point_case1();
	test_get_ray_by_grid_props_case1();
}
