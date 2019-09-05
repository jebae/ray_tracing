#ifndef DISTANT_LIGHT_HPP
# define DISTANT_LIGHT_HPP

# include "light.hpp"

class DistantLight : public Light
{
private:
	Vec4 direction;

public:
	DistantLight(Vec4 intensity, Vec4 direction);
	float get_distance(Vec4 &point);
	Vec4 get_direction(Vec4 &point);
	Vec4 get_intensity(float distance);
};

#endif
