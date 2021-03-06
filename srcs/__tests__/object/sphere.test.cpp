#include "__test_utils__.hpp"
#include "sphere.hpp"
#include "ray.hpp"
#include "mlx_kit.hpp"

class TestSphere : public UnitTest
{
public:
	TestSphere(bool print_success=false);
	Sphere create_test_sphere(void);
	void test_intersect_case1(void);
	void test_get_normal_case1(void);
	void all(void);
};

TestSphere::TestSphere(bool print_success)
: UnitTest("Sphere", print_success)
{}

Sphere TestSphere::create_test_sphere(void)
{
	int specular_alpha = 50;
	float reflectivity = 0.3f;
	float transparency = 0.2f;
	float ior = 1.5f;
	Vec4 color(vector<float>{0.4f, 0.4f, 0.4f});
	float radius = 1.0f;
	Vec4 center(vector<float>{0.0f, 3.0f, 0.5f});

	return (Sphere(
		specular_alpha,
		reflectivity,
		transparency,
		ior,
		color,
		radius,
		center
	));
}

void TestSphere::test_intersect_case1(void)
{
	set_subject("sphere intersect has to be shown");
	float width = 1000;
	float height = 800;
	Camera cam(
		Vec4(vector<float>{0.0f, 0.0f, 0.0f}),
		Vec4(vector<float>{0.0f, 1.0f, 0.0f})
	);
	RayGridProps props(cam, width, height);
	Sphere sphere = create_test_sphere();
	MLXKit mlx((int)width, (int)height);
	int *img_buf = mlx.get_img_buffer();
	float t;

	for (int i=0; i < height; i++)
	{
		for (int j=0; j < width; j++)
		{
			Ray ray = Ray::get_ray_by_grid_props(props, j, i);

			if (sphere.intersect(ray, t))
				img_buf[j + (int)width * i] = 0xFFFFFF;
		}
	}
	mlx.put_img_to_window();
	mlx.loop();
}

void TestSphere::test_get_normal_case1(void)
{
	set_subject("sphere get_normal has to return normal vector");
	float width = 1000;
	float height = 800;
	Camera cam(
		Vec4(vector<float>{0.0f, 0.0f, 0.0f}),
		Vec4(vector<float>{0.0f, 1.0f, 0.0f})
	);
	RayGridProps props(cam, width, height);
	Sphere sphere = create_test_sphere();
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

			if (!sphere.intersect(ray, t))
				continue ;
			Vec4 point = ray.get_intersect_point(t);
			Vec4 n = sphere.get_normal(point);
			float n_dot_l = MAX(0.0f, n.dot(light_direction));
			img_buf[j + (int)width * i] = 0x0000FF * n_dot_l;
		}
	}
	mlx.put_img_to_window();
	mlx.loop();
}

void TestSphere::all(void)
{

}
