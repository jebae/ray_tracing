#include "global.hpp"
#include "math/vec4.test.cpp"
#include "math/camera.test.cpp"
#include "ray/ray_grid_props.test.cpp"
#include "ray/ray.test.cpp"
#include "object/sphere.test.cpp"
#include "object/cylinder.test.cpp"
#include "object/cone.test.cpp"
#include "object/plane.test.cpp"
#include "trace/trace_record.test.cpp"
#include "trace/tracer.test.cpp"
#include "shade/shade.test.cpp"
#include "light/distant_light.test.cpp"
#include "light/spherical_light.test.cpp"

int main(void)
{
	// math
	TestVec4 test_vec4;
	TestCamera test_cam;

	test_vec4.all();
	test_cam.all();

	// ray
	TestRayGridProps test_ray_grid_props;
	TestRay test_ray;

	test_ray_grid_props.all();
	test_ray.all();

	// trace
	TestTracer test_tracer(true);
	TestTraceRecord test_trace_record;

	test_tracer.all();
	test_trace_record.all();

	// shade
	TestShade test_shade;

	test_shade.all();

	// light
	TestDistantLight test_distant_light;
	TestSphericalLight test_spherical_light;

	test_distant_light.all();
	test_spherical_light.all();

	// object
	TestSphere test_sphere;
	TestCone test_cone;
	TestCylinder test_cylinder;
	TestPlane test_plane;

	test_cone.all();
	test_cylinder.all();
	test_plane.all();

	//test_sphere.test_intersect_case1();
	//test_cone.test_intersect_case1();
	//test_cylinder.test_intersect_case1();
	//test_plane.test_intersect_case1();

	//test_sphere.test_get_normal_case1();
	//test_cone.test_get_normal_case1();
	//test_cylinder.test_get_normal_case1();
	//test_plane.test_get_normal_case1();
}
