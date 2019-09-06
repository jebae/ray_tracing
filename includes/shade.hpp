#ifndef SHADE_HPP
# define SHADE_HPP

# include "vec4.hpp"
# include "light.hpp"

class TraceRecord;
class Object;

class Shade
{
private:
	TraceRecord &rec;
	float n_dot_l;
	float light_distance;
	Vec4 light_direction;
	Vec4 light_intensity;

public:
	Shade(TraceRecord &rec, Light *light);
	static Vec4 ambient(
		Vec4 &color,
		Vec4 &ambient_intensity
	);
	Vec4 diffuse(void);
	Vec4 specular(void);
	float shadow(Object **objs, int num_objs);
};

#endif
