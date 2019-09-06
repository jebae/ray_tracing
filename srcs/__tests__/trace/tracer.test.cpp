#include "__test_utils__.hpp"
#include "tracer.hpp"
#include "sphere.hpp"
#include "light.hpp"
#include "distant_light.hpp"
#include "spherical_light.hpp"
#include "shade.hpp"

extern Vec4 AMBIENT_INTENSITY;

class TestTracer : public UnitTest
{
public:
	TestTracer(bool print_success=false);
	Sphere *create_test_sphere(float radius, Vec4 center);
	void test_check_intersect_case1(void);
	void test_shade_case1(void);
	void all(void);
};

TestTracer::TestTracer(bool print_success)
: UnitTest("TestTracer", print_success)
{}

Sphere* TestTracer::create_test_sphere(
	float radius,
	Vec4 center
)
{
	int specular_alpha = 50;
	float reflectivity = 0.3f;
	float transparency = 0.2f;
	float ior = 1.5f;
	Vec4 color(vector<float>{0.4f, 0.4f, 0.4f});

	return (new Sphere(
		specular_alpha,
		reflectivity,
		transparency,
		ior,
		color,
		radius,
		center
	));
}

void TestTracer::test_check_intersect_case1(void)
{
	set_subject("trace has to return proper record");
	Object *objs[3];
	/*
	** expected scenario
	** objs[1] is front of objs[2]
	** trace record has to be objs[1]
	*/
	objs[0] = create_test_sphere(
		1.0f, Vec4(vector<float>{2.0f, 3.0f, 1.0f})
	);
	objs[1] = create_test_sphere(
		2.0f, Vec4(vector<float>{-0.5f, 3.0f, 1.0f})
	);
	objs[2] = create_test_sphere(
		1.5f, Vec4(vector<float>{0.0f, 4.0f, 0.0f})
	);
	Ray ray(
		Vec4(vector<float>{0.0f, 0.0f, 0.0f}),
		Vec4(vector<float>{0.0f, 1.0f, 0.0f})
	);
	Tracer tracer(objs, 3, nullptr, 0);
	TraceRecord rec(ray);

	bool res = tracer.check_intersect(rec);
	eq(res, true);
	eq(rec.obj, objs[1]);
	eq(rec.normal, objs[1]->get_normal(rec.point));

	float precision = 1000000;
	rec.point.for_each(
		[&precision] (float *f) -> void
		{
			*f = round(*f * precision) / precision;
		}
	);
	eq(
		rec.point,
		Vec4(vector<float>{0.0f, 1.341688f, 0.0f})
	);
	for (int i=0; i < 3; i++)
		delete objs[i];
}

void TestTracer::test_shade_case1(void)
{
	set_subject("tracer.shade has to return ambient + diffuse + specular for all light");
	// set ray, objects, lights
	Ray ray(
		Vec4(vector<float>{0.0f, 0.0f, 0.0f}),
		Vec4(vector<float>{0.0f, 1.0f, 0.0f})
	);
	Object *obj = create_test_sphere(
		2.0f,
		Vec4(vector<float>{-0.5f, 3.0f, -0.5f})
	);
	DistantLight distant_light(
		Vec4(vector<float>{0.9f, 0.9f, 0.9f}),
		Vec4(vector<float>{0.5f, 1.0f, -1.0f})
	);
	SphericalLight spherical_light(
		Vec4(vector<float>{100, 100, 100}),
		Vec4(vector<float>{0.0f, 0.0f, 0.0f})
	);
	Light *lights[2] = {
		static_cast<Light *>(&distant_light),
		static_cast<Light *>(&spherical_light)
	};

	// set tracer
	Tracer tracer(&obj, 1, lights, 2);
	TraceRecord rec(ray);
	bool intersect = tracer.check_intersect(rec);

	if (eq(intersect, true) == TEST_FAIL)
		return ;
	Vec4 res = tracer.shade(rec);

	// expected shade result
	Vec4 expected = Shade::ambient(obj->color, AMBIENT_INTENSITY);
	for (int i=0; i < 2; i++)
	{
		Shade shade(rec, lights[i]);

		expected += shade.diffuse();
		expected += shade.specular();
	}
	eq(res, expected);
}

void TestTracer::all(void)
{
	test_check_intersect_case1();
	test_shade_case1();
}
