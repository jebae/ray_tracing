#ifndef CONE_HPP
# define CONE_HPP

# include "object.hpp"

class Cone : public Object
{
public:
	Vec4 vertex;
	Vec4 perp_vec;
	float height;
	float theta;
	float cos_2_theta;

	Cone(
		int specular_alpha,
		float reflectivity,
		float transparency,
		float ior,
		Vec4 color,
		Vec4 vertex,
		Vec4 perp_vec,
		float height,
		float theta
	);
	//bool intersect(Ray &ray, float &t);
};

#endif
