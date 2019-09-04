#ifndef PLANE_HPP
# define PLANE_HPP

#include "object.hpp"

class Plane : public Object
{
public:
	Vec4 point;
	Vec4 n;

	Plane(
		int specular_alpha,
		float reflectivity,
		float transparency,
		float ior,
		Vec4 color,
		Vec4 point,
		Vec4 n
	);
	bool intersect(Ray &ray, float &t);
	Vec4 get_normal(Vec4 &point);
};

#endif
