#include "__test_utils__.hpp"
#include "tracer.hpp"
#include "sphere.hpp"
#include "light.hpp"
#include "distant_light.hpp"
#include "spherical_light.hpp"
#include "shade.hpp"
#include "color.hpp"

extern Vec4 AMBIENT_INTENSITY;

class TestTracer : public UnitTest
{
public:
	TestTracer(bool print_success=false);
	Sphere *create_test_sphere(float radius, Vec4 center);
	void test_check_intersect_case1(void);
	void test_shade_case1(void);
	void test_trace_case1(void); // using mlx
	void test_get_reflection_ray_case1(void);
	void test_get_refraction_ray_case1(void);
	void all(void);
};

TestTracer::TestTracer(bool print_success)
: UnitTest("TestTracer", print_success)
{}

Sphere* TestTracer::create_test_sphere(
	float radius,
	Vec4 center
)
{
	int specular_alpha = 50;
	float reflectivity = 0.3f;
	float transparency = 0.2f;
	float ior = 1.5f;
	Vec4 color(vector<float>{0.4f, 0.4f, 0.8f});

	return (new Sphere(
		specular_alpha,
		reflectivity,
		transparency,
		ior,
		color,
		radius,
		center
	));
}

void TestTracer::test_check_intersect_case1(void)
{
	set_subject("trace has to return proper record");
	Object *objs[3];
	/*
	** expected scenario
	** objs[1] is front of objs[2]
	** trace record has to be objs[1]
	*/
	objs[0] = create_test_sphere(
		1.0f, Vec4(vector<float>{2.0f, 3.0f, 1.0f})
	);
	objs[1] = create_test_sphere(
		2.0f, Vec4(vector<float>{-0.5f, 3.0f, 1.0f})
	);
	objs[2] = create_test_sphere(
		1.5f, Vec4(vector<float>{0.0f, 4.0f, 0.0f})
	);
	Ray ray(
		Vec4(vector<float>{0.0f, 0.0f, 0.0f}),
		Vec4(vector<float>{0.0f, 1.0f, 0.0f})
	);
	Tracer tracer(objs, 3, nullptr, 0);
	TraceRecord rec(ray, nullptr);

	bool res = tracer.check_intersect(rec);
	eq(res, true);
	eq(rec.obj, objs[1]);
	eq(rec.normal, objs[1]->get_normal(rec.point));

	float precision = 1000000;
	rec.point.for_each(
		[&precision] (float *f) -> void
		{
			*f = round(*f * precision) / precision;
		}
	);
	eq(
		rec.point,
		Vec4(vector<float>{0.0f, 1.341688f, 0.0f})
	);
	for (int i=0; i < 3; i++)
		delete objs[i];
}

void TestTracer::test_shade_case1(void)
{
	set_subject("tracer.shade has to return ambient + diffuse + specular for all light");
	// set ray, objects, lights
	Ray ray(
		Vec4(vector<float>{0.0f, 0.0f, 0.0f}),
		Vec4(vector<float>{0.0f, 1.0f, 0.0f})
	);
	Object *obj = create_test_sphere(
		2.0f,
		Vec4(vector<float>{-0.5f, 3.0f, -0.5f})
	);
	DistantLight distant_light(
		Vec4(vector<float>{0.9f, 0.9f, 0.9f}),
		Vec4(vector<float>{0.5f, 1.0f, -1.0f})
	);
	SphericalLight spherical_light(
		Vec4(vector<float>{0.8f, 0.8f, 0.8f}),
		Vec4(vector<float>{0.0f, 0.0f, 0.0f})
	);
	Light *lights[2] = {
		static_cast<Light *>(&distant_light),
		static_cast<Light *>(&spherical_light)
	};

	// set tracer
	Tracer tracer(&obj, 1, lights, 2);
	TraceRecord rec(ray, nullptr);
	bool intersect = tracer.check_intersect(rec);

	if (eq(intersect, true) == TEST_FAIL)
		return ;
	Vec4 res = tracer.shade(rec);

	// expected shade result
	Vec4 expected = Shade::ambient(obj->color, AMBIENT_INTENSITY);
	for (int i=0; i < 2; i++)
	{
		Shade shade(rec, lights[i]);

		expected += shade.diffuse();
		expected += shade.specular();
		// skip shadow
	}
	eq(res, expected);
}

void TestTracer::test_trace_case1(void)
{
	set_subject("tracer.trace has to show shaded image");
	// set ray grid
	float width = 1200;
	float height = 800;
	Camera cam(
		Vec4(vector<float>{0.0f, -4.0f, 0.0f}),
		Vec4(vector<float>{0.0f, 1.0f, 0.0f})
	);
	RayGridProps props(cam, width, height);

	// set objects
	Plane plane(
		50,
		0.7f,
		0.0f,
		1.5,
		Vec4(vector<float>{0.2f, 0.6f, 0.2f}),
		Vec4(vector<float>{0.0f, 0.0f, -1.0f}),
		Vec4(vector<float>{0.0f, 0.0f, -1.0f})
	);
	Sphere sphere(
		50,
		0.0f,
		0.8f,
		1.5,
		Vec4(vector<float>{0.7f, 0.1f, 0.2f}),
		1.0f,
		Vec4(vector<float>{0.0f, 3.0f, 0.5f})
	);
	Cone cone(
		50,
		0.0f,
		0.0f,
		1.5,
		Vec4(vector<float>{0.2f, 0.5f, 0.3f}),
		Vec4(vector<float>{-1.0f, 2.0f, 0.5f}), // vertex
		Vec4(vector<float>{-1.0f, 0.5f, 0.5f}), // prep_vec
		2.0f, // height
		M_PI / 6.0f // theta
	);
	Cylinder cylinder(
		50,
		0.3f,
		0.0f,
		1.5,
		Vec4(vector<float>{0.2f, 0.3f, 0.8f}),
		0.8f, // radius
		2.0f, // height
		Vec4(vector<float>{2.0f, 4.0f, 2.0f}), // center
		Vec4(vector<float>{1.0f, -0.5f, -1.5f}) // prep_vec
	);
	Object *objs[4] = {
		static_cast<Object *>(&plane),
		static_cast<Object *>(&sphere),
		static_cast<Object *>(&cone),
		static_cast<Object *>(&cylinder)
	};

	// set lights
	DistantLight distant_light(
		Vec4(vector<float>{0.8f, 0.8f, 0.8f}),
		Vec4(vector<float>{0.3f, 0.4f, -0.8f})
	);
	SphericalLight spherical_light(
		Vec4(vector<float>{50.0f, 50.0f, 50.0f}),
		Vec4(vector<float>{0.5f, 1.0f, 3.0f})
	);
	int num_lights = 2;
	Light *lights[2] = {
		static_cast<Light *>(&distant_light),
		static_cast<Light *>(&spherical_light)
	};

	MLXKit mlx((int)width, (int)height);
	int *img_buf = mlx.get_img_buffer();
	for (int i=0; i < height; i++)
	{
		for (int j=0; j < width; j++)
		{
			Ray ray = Ray::get_ray_by_grid_props(props, j, i);
			Tracer tracer(objs, 4, lights, num_lights);

			Vec4 rgb = tracer.trace(ray, 1.0f, 0, nullptr);
			img_buf[j + (int)width * i] = rgb_vec_to_color(rgb);
		}
	}
	mlx.put_img_to_window();
	mlx.loop();
}

void TestTracer::test_get_reflection_ray_case1(void)
{
	set_subject("tracer.get_reflection_ray should return correct reflection ray");

	// set object
	Sphere *sphere = create_test_sphere(
		0.5f, Vec4(vector<float>{0.0f, 0.0f, 0.0f})
	);

	// set ray
	Ray ray(
		Vec4(vector<float>{-0.9f, 1.0f, -2.1f}),
		Vec4(vector<float>{0.8f, -0.9f, 2.0f})
	);

	// set record
	TraceRecord rec(ray, nullptr, sphere);
	float t;
	bool intersect = sphere->intersect(ray, t);
	if (eq(intersect, true) == TEST_FAIL)
		return ;
	rec.update_intersect_info(t);

	// set tracer
	Object *sphere_ptr = static_cast<Object *>(sphere);
	Tracer tracer(&sphere_ptr, 1, nullptr, 0);

	Ray res = tracer.get_reflection_ray(rec);

	// get expected reflection ray
	float d_dot_n = -1.0f * ray.d.dot(rec.normal);
	Ray expected(
		rec.point + BIAS * rec.normal,
		ray.d + 2.0f * d_dot_n * rec.normal,
		RAY_TYPE_REFLECTION,
		rec.ray.ior
	);

	eq(res.d, expected.d);
	eq(res.e, expected.e);
	eq(res.type, expected.type);
	eq(res.ior, expected.ior);
	delete sphere;
}

void TestTracer::test_get_refraction_ray_case1(void)
{
	set_subject("tracer.get_refraction_ray should return correct refraction ray");

	// set object
	Sphere *sphere = create_test_sphere(
		0.5f, Vec4(vector<float>{0.0f, 0.0f, 0.0f})
	);

	// set ray
	Ray ray(
		Vec4(vector<float>{-0.9f, 1.0f, -2.1f}),
		Vec4(vector<float>{0.8f, -0.9f, 2.0f})
	);

	// set record
	TraceRecord rec(ray, nullptr, sphere);
	float t;
	bool intersect = sphere->intersect(ray, t);
	if (eq(intersect, true) == TEST_FAIL)
		return ;
	rec.update_intersect_info(t);

	// set tracer
	Object *sphere_ptr = static_cast<Object *>(sphere);
	Tracer tracer(&sphere_ptr, 1, nullptr, 0);

	Ray res = tracer.get_refraction_ray(rec);

	// get expected reflection ray
	float d_dot_n = -1.0f * ray.d.dot(rec.normal);
	float snell_ratio = ray.ior / rec.obj->ior;
	float det = 1.0f - snell_ratio * snell_ratio * (1.0f - d_dot_n * d_dot_n);
	Vec4 a = snell_ratio * (ray.d + d_dot_n * rec.normal);

	Ray expected(
		rec.point + (-1.0f) * BIAS * rec.normal,
		a - sqrtf(det) * rec.normal,
		RAY_TYPE_REFRACTION,
		rec.obj->ior
	);

	eq(res.d, expected.d);
	eq(res.e, expected.e);
	eq(res.type, expected.type);
	eq(res.ior, expected.ior);
	delete sphere;
}

void TestTracer::all(void)
{
	test_check_intersect_case1();
	test_shade_case1();
	test_get_reflection_ray_case1();
	test_get_refraction_ray_case1();
}
