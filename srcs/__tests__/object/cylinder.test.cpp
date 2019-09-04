#include "__test_utils__.hpp"
#include "cylinder.hpp"
#include "ray.hpp"

class TestCylinder : public UnitTest
{
public:
	TestCylinder(bool print_success=false);
	Cylinder create_test_cylinder(void);
	void test_construct_case1(void);
	void test_intersect_case1(void);
	void test_get_normal_case1(void);
	void all(void);
};

TestCylinder::TestCylinder(bool print_success)
: UnitTest("Cylinder", print_success)
{}

Cylinder TestCylinder::create_test_cylinder(void)
{
	int specular_alpha = 50;
	float reflectivity = 0.3f;
	float transparency = 0.2f;
	float ior = 1.5f;
	Vec4 color(vector<float>{0.4f, 0.4f, 0.4f});
	float radius = 1.0f;
	float height = 2.0f;
	Vec4 center(vector<float>{0.0f, 5.0f, 2.0f});
	Vec4 perp_vec(vector<float>{1.0f, 1.0f, -2.0f});

	return (Cylinder(
		specular_alpha,
		reflectivity,
		transparency,
		ior,
		color,
		radius,
		height,
		center,
		perp_vec
	));
}

void TestCylinder::test_construct_case1(void)
{
	set_subject("Cylinder perpe vector has to be normalized");
	Cylinder cylinder = create_test_cylinder();
	float precision = 1000000;
	float norm;

	norm = round(cylinder.perp_vec.norm() * precision) / precision;
	eq(norm, 1.0f);
}

void TestCylinder::test_intersect_case1(void)
{
	set_subject("cylinder intersect has to be shown");
	float width = 1000;
	float height = 800;
	Camera cam(
		Vec4(vector<float>{0.0f, 0.0f, 0.0f}),
		Vec4(vector<float>{0.0f, 1.0f, 0.0f})
	);
	RayGridProps props(cam, width, height);
	Cylinder cylinder = create_test_cylinder();
	MLXKit mlx((int)width, (int)height);
	int *img_buf = mlx.get_img_buffer();
	float t;

	for (int i=0; i < height; i++)
	{
		for (int j=0; j < width; j++)
		{
			Ray ray = Ray::get_ray_by_grid_props(props, j, i);

			if (cylinder.intersect(ray, t))
				img_buf[j + (int)width * i] = 0xFFFFFF;
		}
	}
	mlx.put_img_to_window();
	mlx.loop();
}

void TestCylinder::test_get_normal_case1(void)
{
	set_subject("cylinder get_normal has to return normal vector");
	float width = 1000;
	float height = 800;
	Camera cam(
		Vec4(vector<float>{0.0f, 0.0f, 0.0f}),
		Vec4(vector<float>{0.0f, 1.0f, 0.0f})
	);
	RayGridProps props(cam, width, height);
	Cylinder cylinder = create_test_cylinder();
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

			if (!cylinder.intersect(ray, t))
				continue ;
			Vec4 point = ray.get_intersect_point(t);
			Vec4 n = cylinder.get_normal(point);
			float n_dot_l = MAX(0.0f, n.dot(light_direction));
			img_buf[j + (int)width * i] = 0x0000FF * n_dot_l;
		}
	}
	mlx.put_img_to_window();
	mlx.loop();
}

void TestCylinder::all(void)
{
	test_construct_case1();
}
