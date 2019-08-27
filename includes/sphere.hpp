#ifndef SPHERE_HPP
# define SPHERE_HPP

# include "object.hpp"

class Sphere : public Object
{
private:
	float get_t(float d_dot_ce, float root_det);

public:
	float radius;
	Vec4 center;

	Sphere(
		int specular_alpha,
		float reflectivity,
		float transparency,
		float ior,
		Vec4 color,
		float radius,
		Vec4 center
	);
	bool intersect(Ray &ray, float &t);
};

#endif
