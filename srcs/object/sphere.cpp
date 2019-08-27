#include "sphere.hpp"
#include "ray.hpp"

Sphere::Sphere(
	int specular_alpha,
	float reflectivity,
	float transparency,
	float ior,
	Vec4 color,
	float radius,
	Vec4 center
): Object(
	specular_alpha,
	reflectivity,
	transparency,
	ior,
	color
), radius(radius),
center(center)
{}

bool Sphere::intersect(Ray &ray, float &t)
{
	Vec4 ce;
	float d_dot_ce;
	float det;

	ce = ray.e - center;
	d_dot_ce = ray.d.dot(ce);
	det = d_dot_ce * d_dot_ce - (ce.dot(ce) - radius * radius);
	if (det < 0.0f)
		return (false);
	t = get_t(d_dot_ce, sqrtf(det));
	if (t < 0.0f)
		return (false);
	return (true);
}

float Sphere::get_t(float d_dot_ce, float root_det)
{
	float t1 = -1.0f * d_dot_ce + root_det;
	float t2 = -1.0f * d_dot_ce - root_det;

	if (t1 < 0.0f)
	// sphere is back from eye
		return (-1.0f);
	else if (t2 < 0.0f)
	// t1 is solution
		return (t1);
	else
		return (t2);
}
