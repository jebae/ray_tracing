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
