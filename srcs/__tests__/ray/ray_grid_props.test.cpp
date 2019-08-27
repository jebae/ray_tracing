#include "__test_utils__.hpp"
#include "ray.hpp"

class TestRayGridProps : public UnitTest
{
public:
	TestRayGridProps(bool print_success=false);
	void test_construct_case1(void);
	void all(void);
};

TestRayGridProps::TestRayGridProps(bool print_success)
: UnitTest("Ray Grid Props", print_success)
{}

void TestRayGridProps::test_construct_case1(void)
{
	set_subject("ray grid props has to be constructed");
	Camera cam(
		Vec4(vector<float>{0.0, 0.0, 0.0}),
		Vec4(vector<float>{0.0, 1.0, 0.0})
	);
	RayGridProps ray_grid_props(cam, 1000, 800);
	float precision = 1000000;
	auto rounding = [&precision] (float *f) -> void
	{
		*f = round(*f * precision) / precision;
	};

	eq(ray_grid_props.e, cam.pos);

	ray_grid_props.offset.for_each(rounding);
	ray_grid_props.dx.for_each(rounding);
	ray_grid_props.dy.for_each(rounding);
	eq(ray_grid_props.offset, Vec4(vector<float>{-1.0f, 1.0f, 0.8f}));
	eq(ray_grid_props.dx, Vec4(vector<float>{0.002002f, 0, 0}));
	eq(ray_grid_props.dy, Vec4(vector<float>{0, 0, -0.002003}));
}

void TestRayGridProps::all(void)
{
	test_construct_case1();
}
