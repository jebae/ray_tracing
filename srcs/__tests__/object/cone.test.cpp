#include "__test_utils__.hpp"
#include "cone.hpp"
#include "ray.hpp"

class TestCone : public UnitTest
{
public:
	TestCone(bool print_success=false);
	Cone create_test_cone(void);
	void test_construct_case1(void);
	void test_intersect_case1(void);
	void test_get_normal_case1(void);
	void all(void);
};

TestCone::TestCone(bool print_success)
: UnitTest("Cone", print_success)
{}

Cone TestCone::create_test_cone(void)
{
	int specular_alpha = 50;
	float reflectivity = 0.3f;
	float transparency = 0.2f;
	float ior = 1.5f;
	Vec4 color(vector<float>{0.4f, 0.4f, 0.4f});
	Vec4 vertex(vector<float>{-1.0f, 10.0f, 1.5f});
	Vec4 perp_vec(vector<float>{0.5f, 2.0f, -3.0f});
	float height = 4.0f;
	float theta = M_PI / 6.0f;

	return (Cone(
		specular_alpha,
		reflectivity,
		transparency,
		ior,
		color,
		vertex,
		perp_vec,
		height,
		theta
	));
}

void TestCone::test_construct_case1(void)
{
	set_subject("Cone has to have cos_2_theta, and normalized perp_vec");
	Cone cone = create_test_cone();
	float precision = 1000000;
	float norm;

	eq(cone.cos_2_theta, powf(cosf(cone.theta), 2.0f));
	norm = round(cone.perp_vec.norm() * precision) / precision;
	eq(norm, 1.0f);
}

void TestCone::test_intersect_case1(void)
{
	set_subject("cone intersect has to be shown");
	float width = 1000;
	float height = 800;
	Camera cam(
		Vec4(vector<float>{0.0f, 0.0f, 0.0f}),
		Vec4(vector<float>{0.0f, 1.0f, 0.0f})
	);
	RayGridProps props(cam, width, height);
	Cone cone = create_test_cone();
	MLXKit mlx((int)width, (int)height);
	int *img_buf = mlx.get_img_buffer();
	float t;

	for (int i=0; i < height; i++)
	{
		for (int j=0; j < width; j++)
		{
			Ray ray = Ray::get_ray_by_grid_props(props, j, i);

			if (cone.intersect(ray, t))
				img_buf[j + (int)width * i] = 0xFFFFFF;
		}
	}
	mlx.put_img_to_window();
	mlx.loop();
}

void TestCone::test_get_normal_case1(void)
{
	set_subject("cone get_normal has to return normal vector");
	float width = 1000;
	float height = 800;
	Camera cam(
		Vec4(vector<float>{0.0f, 0.0f, 0.0f}),
		Vec4(vector<float>{0.0f, 1.0f, 0.0f})
	);
	RayGridProps props(cam, width, height);
	Cone cone = create_test_cone();
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

			if (!cone.intersect(ray, t))
				continue ;
			Vec4 point = ray.get_intersect_point(t);
			Vec4 n = cone.get_normal(point);
			float n_dot_l = MAX(0.0f, n.dot(light_direction));
			img_buf[j + (int)width * i] = 0x0000FF * n_dot_l;
		}
	}
	mlx.put_img_to_window();
	mlx.loop();
}

void TestCone::all(void)
{
	test_construct_case1();
}
