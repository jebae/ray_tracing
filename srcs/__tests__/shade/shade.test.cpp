#include "__test_utils__.hpp"
#include "shade.hpp"
#include "trace_record.hpp"
#include "distant_light.hpp"
#include "global.hpp"

class TestShade : public UnitTest
{
public:
	TestShade(bool print_success=false);
	Sphere create_test_object(void);
	void test_ambient_case1(void);
	void test_diffuse_case1(void);
	void all(void);
};

TestShade::TestShade(bool print_success)
: UnitTest("Shade", print_success)
{}

Sphere TestShade::create_test_object(void)
{
	int specular_alpha = 50;
	float reflectivity = 0.3f;
	float transparency = 0.2f;
	float ior = 1.5f;
	Vec4 color(vector<float>{0.7f, 0.4f, 0.2f});

	return (Sphere(
		specular_alpha,
		reflectivity,
		transparency,
		ior,
		color,
		1.0f,
		Vec4(vector<float>{0.0f, 2.0f, 0.5f})
	));
}

void TestShade::test_ambient_case1(void)
{
	set_subject("Shade ambient has to be returned");
	Sphere obj = create_test_object();

	// create record (value below is dummy)
	Ray ray(
		Vec4(vector<float>{0.0f, 0.0f, 0.0f}),
		Vec4(vector<float>{0.0f, 1.0f, 0.0f})
	);
	TraceRecord rec(&obj, ray);

	Vec4 res = Shade::ambient(obj.color, AMBIENT_INTENSITY);
	Vec4 expected(vector<float>{
		AMBIENT_INTENSITY[0] * obj.color[0],
		AMBIENT_INTENSITY[1] * obj.color[1],
		AMBIENT_INTENSITY[2] * obj.color[2],
	});
	eq(res, expected);
}

void TestShade::test_diffuse_case1(void)
{
	set_subject("Shade diffuse has to be returned");
	// create test object and light
	Sphere obj = create_test_object();
	DistantLight light(
		Vec4(vector<float>{0.8f, 0.8f, 0.8f}),
		Vec4(vector<float>{0.5f, 0.8f, -0.8f})
	);

	// set ray
	Ray ray(
		Vec4(vector<float>{0.0f, 0.0f, 0.0f}),
		Vec4(vector<float>{0.1f, 0.9f, 0.1f})
	);

	TraceRecord rec(&obj, ray);
	float t;

	// test if intersect exist
	bool intersect = obj.intersect(ray, t);
	if (eq(intersect, true) == TEST_FAIL)
		return ;
	rec.update_intersect_info(t);

	Shade shade(&rec, light);
	float n_dot_l = rec.normal.dot(
		-1.0f * light.get_direction(rec.point)
	);
	Vec4 expected(vector<float>{
		MAX(n_dot_l, 0.0f) * obj.color[0] * light.intensity[0],
		MAX(n_dot_l, 0.0f) * obj.color[1] * light.intensity[1],
		MAX(n_dot_l, 0.0f) * obj.color[2] * light.intensity[2]
	});
	eq(expected, shade.diffuse());
}

void TestShade::all(void)
{
	test_ambient_case1();
	test_diffuse_case1();
}
