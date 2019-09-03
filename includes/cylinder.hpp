#ifndef CYLINDER_HPP
# define CYLINDER_HPP

#include "object.hpp"

class Cylinder : public Object
{
private:
	float get_t(
		Ray &ray,
		float a,
		float b,
		float root_det
	);
public:
	float radius;
	float height;
	Vec4 center;
	Vec4 perp_vec;

	Cylinder(
		int specular_alpha,
		float reflectivity,
		float transparency,
		float ior,
		Vec4 color,
		float radius,
		float height,
		Vec4 center,
		Vec4 perp_vec
	);
	bool intersect(Ray &ray, float &t);
};

#endif
