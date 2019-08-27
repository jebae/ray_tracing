#include "object.hpp"

Object::Object(
	int specular_alpha,
	float reflectivity,
	float transparency,
	float ior,
	Vec4 color
): specular_alpha(specular_alpha),
reflectivity(reflectivity),
transparency(transparency),
ior(ior),
color(color)
{}

bool Object::intersect(Ray &ray, float &t)
{
	(void)(ray);
	(void)(t);
	return (false);
}

Vec4 Object::get_normal(Vec4 &point)
{
	(void)(point);
	return (Vec4());
}
