#include "spherical_light.hpp"

SphericalLight::SphericalLight(Vec4 intensity, Vec4 origin)
: Light(intensity), origin(origin)
{}


float SphericalLight::get_distance(Vec4 &point)
{
	Vec4 op = point - origin;

	return (op.norm());
}

Vec4 SphericalLight::get_direction(Vec4 &point)
{
	Vec4 direction = point - origin;

	direction.normalize();
	return (direction);
}
