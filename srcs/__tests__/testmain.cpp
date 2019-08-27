#include "math/vec4.test.cpp"
#include "math/camera.test.cpp"
#include "ray/ray_grid_props.test.cpp"
#include "object/object.test.cpp"
#include "object/sphere.test.cpp"
#include "trace/trace_record.test.cpp"
#include "trace/tracer.test.cpp"

int main(void)
{
	TestVec4 test_vec4;
	TestCamera test_cam;
	TestRayGridProps test_ray_grid_props;
	TestObject test_object;
	TestSphere test_sphere;
	TestTraceRecord test_trace_record;
	TestTracer test_tracer(true);

	test_vec4.all();
	test_cam.all();
	test_ray_grid_props.all();
	test_object.all();
	test_sphere.all();
	test_trace_record.all();
	test_tracer.all();
}
