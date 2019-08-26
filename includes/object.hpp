#ifndef OBJECT_HPP
# define OBJECT_HPP

# include "vec4.hpp"

class Ray;

class Object
{
private:

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
	virtual bool intersect(Ray *ray) = 0;
};

#endif
