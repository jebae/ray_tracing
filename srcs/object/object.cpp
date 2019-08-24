#include "object.hpp"

Object::Object(
	void *shape,
	int specular_alpha,
	float reflectivity,
	float transparency,
	float ior,
	Vec4 color
): shape(shape),
specular_alpha(specular_alpha),
reflectivity(reflectivity),
transparency(transparency),
ior(ior),
color(color)
{}

Object::~Object(void)
{
	del_shape(shape);
}

void Object::set_del_shape(del_shape_fn fn)
{
	del_shape = fn;
}
