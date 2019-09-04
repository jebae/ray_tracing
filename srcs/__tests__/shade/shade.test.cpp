#include "__test_utils__.hpp"
#include "shade.hpp"
#include "trace_record.hpp"

class TestShade : public UnitTest
{
public:
	TestShade(bool print_success=false);
	void test_ambient_case1(void);
	void all(void);
};

TestShade::TestShade(bool print_success)
: UnitTest("Shade", print_success)
{}

void TestShade::test_ambient_case1(void)
{
	set_subject("Shade ambient has to be returned");
	// create object
	int specular_alpha = 50;
	float reflectivity = 0.3f;
	float transparency = 0.2f;
	float ior = 1.5f;
	Vec4 color(vector<float>{0.4f, 0.4f, 0.4f});
	Sphere obj(
		specular_alpha,
		reflectivity,
		transparency,
		ior,
		color,
		1.0f,
		Vec4(vector<float>(3, 0.0f))
	);

	// create record (value below is dummy)
	Ray ray(
		Vec4(vector<float>{0.0f, 0.0f, 0.0f}),
		Vec4(vector<float>{0.0f, 1.0f, 0.0f})
	);
	TraceRecord rec(&obj, ray);
	rec.point = ray.get_intersect_point(2.0f);

	// create shade
	Shade shade(&rec);
	Vec4 expected(vector<float>{
		0.05f * obj.color[0],
		0.05f * obj.color[1],
		0.05f * obj.color[2]
	});
	eq(expected, shade.ambient());
}

void TestShade::all(void)
{
	test_ambient_case1();
}
