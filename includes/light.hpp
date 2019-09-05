#ifndef LIGHT_HPP
# define LIGHT_HPP

# include "vec4.hpp"

class Light
{
public:
	Vec4 intensity;

	Light(Vec4 intensity);
	~Light() {};
	virtual float get_distance(Vec4 &point) = 0;
	virtual Vec4 get_direction(Vec4 &point) = 0;
	virtual Vec4 get_intensity(float distance) = 0;
};

#endif
