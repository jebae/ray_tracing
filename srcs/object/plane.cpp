#include "plane.hpp"
#include "macro.hpp"

Plane::Plane(
	int specular_alpha,
	float reflectivity,
	float transparency,
	float ior,
	Vec4 color,
	Vec4 point,
	Vec4 n
): Object(
	specular_alpha,
	reflectivity,
	transparency,
	ior,
	color
), point(point),
n(n)
{
	this->n.normalize();
}

bool Plane::intersect(Ray &ray, float &t)
{
	float d_dot_n = ray.d.dot(n);
	Vec4 ep = point - ray.e;

	if (ABS(d_dot_n) < FLOAT_APPROX_0)
		return (false);
	t = ep.dot(n) / d_dot_n;
	if (t < 0.0f)
		return (false);
	return (true);
}
