#ifndef OBJECT_HPP
# define OBJECT_HPP

# include "vec4.hpp"
# include "ray.hpp"

class Object
{
public:
	int specular_alpha;
	float reflectivity;
	float transparency;
	float ior;
	Vec4 color;

	Object(
		int specular_alpha,
		float reflectivity,
		float transparency,
		float ior,
		Vec4 color
	);
	virtual ~Object() {};
	virtual bool intersect(Ray &ray, float &t);
	virtual Vec4 get_normal(Vec4 &point);
};

#endif
