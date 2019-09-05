#include "__test_utils__.hpp"
#include "trace_record.hpp"
#include "sphere.hpp"

class TestTraceRecord : public UnitTest
{
public:
	TestTraceRecord(bool print_success=false);
	void test_update_intersect_info_case1(void);
	void all(void);
};

TestTraceRecord::TestTraceRecord(bool print_success): UnitTest("TraceRecord", print_success)
{}

void TestTraceRecord::test_update_intersect_info_case1(void)
{
	set_subject("trace record has to update intersect point and normal vector from object");

	// set obj
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
		Vec4(vector<float>{0.0f, 2.0f, 0.5f})
	);

	// set ray
	Ray ray(
		Vec4(vector<float>{0.0f, 0.0f, 0.0f}),
		Vec4(vector<float>{0.1f, 0.9f, 0.1f})
	);

	// set record
	TraceRecord rec(&obj, ray);

	// test if ray intersect obj
	float t;
	bool intersect = obj.intersect(ray, t);

	if (eq(intersect, true) == TEST_FAIL)
		return ;
	rec.update_intersect_info(t);
	eq(rec.point, ray.get_intersect_point(t));
	eq(rec.normal, obj.get_normal(rec.point));
}

void TestTraceRecord::all(void)
{
	test_update_intersect_info_case1();
}
