#include "cone.hpp"

Cone::Cone(
	int specular_alpha,
	float reflectivity,
	float transparency,
	float ior,
	Vec4 color,
	Vec4 vertex,
	Vec4 perp_vec,
	float height,
	float theta
): Object(
	specular_alpha,
	reflectivity,
	transparency,
	ior,
	color
), vertex(vertex),
perp_vec(perp_vec),
height(height),
theta(theta)
{
	cos_2_theta = powf(cos(theta), 2.0f);
}

bool Cone::intersect(Ray &ray, float &t)
{
	
}
