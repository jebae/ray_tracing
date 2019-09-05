#ifndef SPHERICAL_LIGHT_HPP
# define SPHERICAL_LIGHT_HPP

#include "light.hpp"

class SphericalLight : public Light
{
private:
	Vec4 origin;

public:
	SphericalLight(Vec4 intensity, Vec4 origin);
	float get_distance(Vec4 &point);
	Vec4 get_direction(Vec4 &point);
	Vec4 get_intensity(float distance);
};

#endif
