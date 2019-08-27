#include "__test_utils__.hpp"
#include "trace_record.hpp"

class TestTraceRecord : public UnitTest
{
public:
	TestTraceRecord(bool print_success=false);
	void test_set_intersect_point_case1(void);
	void all(void);
};

TestTraceRecord::TestTraceRecord(bool print_success): UnitTest("TraceRecord", print_success)
{}

void TestTraceRecord::test_set_intersect_point_case1(void)
{
	set_subject("intersect point has to be set");
	Vec4 e(vector<float>{2.0f, 3.14f, -0.9f});
	Vec4 d(vector<float>{8.0f, -3.24f, 0.12f});
	Ray r(e, d);
	TraceRecord rec(nullptr, r);
	float t = 2.2f;
	rec.set_intersect_point(t);

	eq(rec.point, t * r.d + r.e);
}

void TestTraceRecord::all(void)
{
	test_set_intersect_point_case1();
}
