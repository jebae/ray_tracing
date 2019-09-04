#include "__test_utils__.hpp"
#include "plane.hpp"
#include "ray.hpp"
#include "mlx_kit.hpp"

class TestPlane : public UnitTest
{
public:
	TestPlane(bool print_success=false);
	Plane create_test_plane(void);
	void test_construct_case1(void);
	void test_intersect_case1(void);
	void test_get_normal_case1(void);
	void all(void);
};

TestPlane::TestPlane(bool print_success)
: UnitTest("Plane", print_success)
{}

Plane TestPlane::create_test_plane(void)
{
	int specular_alpha = 50;
	float reflectivity = 0.3f;
	float transparency = 0.2f;
	float ior = 1.5f;
	Vec4 color(vector<float>{0.4f, 0.4f, 0.4f});
	Vec4 point(vector<float>{0.0f, 0.0f, -1.0f});
	Vec4 n(vector<float>{0.0f, 0.0f, 2.0f});

	return (Plane(
		specular_alpha,
		reflectivity,
		transparency,
		ior,
		color,
		point,
		n
	));
}

void TestPlane::test_construct_case1(void)
{
	set_subject("Plane n has to be normalized when construct");
	Plane plane = create_test_plane();
	float precision = 1000000;
	float norm;

	norm = round(plane.n.norm() * precision) / precision;
	eq(norm, 1.0f);
}

void TestPlane::test_intersect_case1(void)
{
	set_subject("Plane intersect has to be shown");
	float width = 1000;
	float height = 800;
	Camera cam(
		Vec4(vector<float>{0.0f, 0.0f, 0.0f}),
		Vec4(vector<float>{0.0f, 1.0f, 0.0f})
	);
	RayGridProps props(cam, width, height);
	Plane plane = create_test_plane();
	MLXKit mlx((int)width, (int)height);
	int *img_buf = mlx.get_img_buffer();
	float t;

	for (int i=0; i < height; i++)
	{
		for (int j=0; j < width; j++)
		{
			Ray ray = Ray::get_ray_by_grid_props(props, j, i);

			if (plane.intersect(ray, t))
				img_buf[j + (int)width * i] = 0xFFFFFF;
		}
	}
	mlx.put_img_to_window();
	mlx.loop();
}

void TestPlane::test_get_normal_case1(void)
{
	set_subject("plane get_normal has to return normal vector");
	float width = 1000;
	float height = 800;
	Camera cam(
		Vec4(vector<float>{0.0f, 0.0f, 0.0f}),
		Vec4(vector<float>{0.0f, 1.0f, 0.0f})
	);
	RayGridProps props(cam, width, height);
	Plane plane = create_test_plane();
	Vec4 light_direction(vector<float>{1.0f, 2.0f, -1.5f});
	light_direction.normalize();
	light_direction *= -1.0f;

	MLXKit mlx((int)width, (int)height);
	int *img_buf = mlx.get_img_buffer();
	float t;

	for (int i=0; i < height; i++)
	{
		for (int j=0; j < width; j++)
		{
			Ray ray = Ray::get_ray_by_grid_props(props, j, i);

			if (!plane.intersect(ray, t))
				continue ;
			Vec4 point = ray.get_intersect_point(t);
			Vec4 n = plane.get_normal(point);
			float n_dot_l = MAX(0.0f, n.dot(light_direction));
			img_buf[j + (int)width * i] = 0x0000FF * n_dot_l;
		}
	}
	mlx.put_img_to_window();
	mlx.loop();
}

void TestPlane::all(void)
{
	test_construct_case1();
}
