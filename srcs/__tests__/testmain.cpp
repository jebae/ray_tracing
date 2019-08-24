#include "math/vec4.test.cpp"
#include "math/camera.test.cpp"
#include "ray/ray_grid_props.test.cpp"
#include "object/object.test.cpp"

int main(void)
{
	TestVec4 test_vec4;
	TestCamera test_cam;
	TestRayGridProps test_ray_grid_props;
	TestObject test_object;

	test_vec4.all();
	test_cam.all();
	test_ray_grid_props.all();
	test_object.all();
}
