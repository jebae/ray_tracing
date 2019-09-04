#include "math/vec4.test.cpp"
#include "math/camera.test.cpp"
#include "ray/ray_grid_props.test.cpp"
#include "ray/ray.test.cpp"
#include "object/object.test.cpp"
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
	TestVec4 test_vec4;
	TestCamera test_cam;
	TestRayGridProps test_ray_grid_props;
	TestObject test_object;
	TestTracer test_tracer;
	TestRay test_ray;
	TestShade test_shade;
	TestDistantLight test_distant_light;
	TestSphericalLight test_spherical_light(true);

	TestSphere test_sphere;
	TestCone test_cone;
	TestCylinder test_cylinder;
	TestPlane test_plane;

	test_vec4.all();
	test_cam.all();
	test_ray_grid_props.all();
	test_object.all();
	test_tracer.all();
	test_ray.all();
	test_shade.all();
	test_distant_light.all();
	test_spherical_light.all();

	//test_sphere.all();
	//test_cone.all();
	//test_cylinder.all();
	//test_plane.all();
}
