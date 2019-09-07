#include "__test_utils__.hpp"
#include "shade.hpp"
#include "trace_record.hpp"
#include "distant_light.hpp"

extern Vec4 AMBIENT_INTENSITY;

class TestShade : public UnitTest
{
public:
	TestShade(bool print_success=false);
	Sphere create_test_object(void);
	void test_ambient_case1(void);
	void test_diffuse_case1(void);
	void test_specular_case1(void);
	void test_shadow_case1(void);
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

	TraceRecord rec(ray, nullptr, &obj);
	float t;

	// test if intersect exist
	bool intersect = obj.intersect(ray, t);
	if (eq(intersect, true) == TEST_FAIL)
		return ;
	rec.update_intersect_info(t);

	Shade shade(rec, &light);
	float n_dot_l = rec.normal.dot(
		-1.0f * light.get_direction(rec.point)
	);
	n_dot_l = MAX(n_dot_l, 0.0f);
	Vec4 expected(vector<float>{
		n_dot_l * obj.color[0] * light.intensity[0],
		n_dot_l * obj.color[1] * light.intensity[1],
		n_dot_l * obj.color[2] * light.intensity[2]
	});
	eq(expected, shade.diffuse());
}

void TestShade::test_specular_case1(void)
{
	set_subject("Shade specular has to be returned");
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

	TraceRecord rec(ray, nullptr, &obj);
	float t;

	// test if intersect exist
	bool intersect = obj.intersect(ray, t);
	if (eq(intersect, true) == TEST_FAIL)
		return ;
	rec.update_intersect_info(t);

	Shade shade(rec, &light);

	// calculate expected value
	Vec4 l = light.get_direction(rec.point);
	float n_dot_l = rec.normal.dot(-1.0f * l);
	n_dot_l = MAX(n_dot_l, 0.0f);
	Vec4 r = l + 2 * n_dot_l * rec.normal;
	float r_dot_d = -1.0f * r.dot(ray.d);

	r_dot_d = MAX(r_dot_d, 0.0f);
	r_dot_d = powf(r_dot_d, obj.specular_alpha);

	Vec4 expected(vector<float>{
		light.intensity[0] * obj.color[0] * r_dot_d,
		light.intensity[1] * obj.color[1] * r_dot_d,
		light.intensity[2] * obj.color[2] * r_dot_d
	});
	eq(expected, shade.specular());
}

void TestShade::test_shadow_case1(void)
{
	set_subject("shadow has to be returned");
	// set intersecting object
	// center : { 0.0f, 2.0f, 0.5f }
	// radius : 1.0f
	Sphere hit_obj = create_test_object();

	// set ray
	Ray ray(
		Vec4(vector<float>{0.0f, 0.0f, 0.0f}),
		Vec4(vector<float>{0.1f, 0.9f, 0.5f})
	);

	// set light
	SphericalLight light(
		Vec4(vector<float>{0.8f, 0.8f, 0.8f}),
		Vec4(vector<float>{0.2f, 0.2f, 7.0f}) // between two planes below
	);

	// set objects in scene
	Plane obj1(
		50,
		0.0f,
		0.1f, // transparency
		1.5f,
		Vec4(vector<float>{0.1f, 0.3f, 0.6f}), // color
		Vec4(vector<float>{0.0f, 0.0f, 6.0f}), // point
		Vec4(vector<float>{0.0f, 0.0f, -1.0f}) // n
	);
	Plane obj2(
		50,
		0.0f,
		0.8f, // transparency
		1.5f,
		Vec4(vector<float>{0.1f, 0.3f, 0.6f}), // color
		Vec4(vector<float>{0.0f, 0.0f, 8.0f}), // point
		Vec4(vector<float>{0.0f, 0.0f, -1.0f}) // n
	);
	Object *objs[2] = {
		static_cast<Object *>(&obj1),
		static_cast<Object *>(&obj2)
	};
	int num_objs = 2;

	TraceRecord rec(ray, nullptr, &hit_obj);
	float t;

	// test if intersect exist
	bool intersect = hit_obj.intersect(ray, t);
	if (eq(intersect, true) == TEST_FAIL)
		return ;
	rec.update_intersect_info(t);

	Shade shade(rec, &light);
	float res = shade.shadow(objs, num_objs);

	// get expected shadow
	float expected = obj1.transparency;

	eq(res, expected);
}

void TestShade::all(void)
{
	test_ambient_case1();
	test_diffuse_case1();
	test_specular_case1();
	test_shadow_case1();
}
