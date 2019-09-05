#include "distant_light.hpp"
#include <cmath>

DistantLight::DistantLight(Vec4 intensity, Vec4 direction)
: Light(intensity), direction(direction)
{
	this->direction.normalize();
}

float DistantLight::get_distance(Vec4 &point)
{
	(void)(point);
	return (INFINITY);
}

Vec4 DistantLight::get_direction(Vec4 &point)
{
	(void)(point);
	return (direction);
}

Vec4 DistantLight::get_intensity(float distance)
{
	(void)(distance);
	return (intensity);
}
