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
	cos_2_theta = powf(cosf(theta), 2.0f);
	this->perp_vec.normalize();
}

bool Cone::intersect(Ray &ray, float &t)
{
	Vec4 ve = ray.e - vertex;
	float a;
	float b;
	float c;
	float det;
	float d_dot_perp = ray.d.dot(perp_vec);
	float ve_dot_perp = ve.dot(perp_vec);

	a = d_dot_perp * d_dot_perp - cos_2_theta;
	b = d_dot_perp * ve_dot_perp - ray.d.dot(ve) * cos_2_theta;
	c = ve_dot_perp * ve_dot_perp - ve.dot(ve) * cos_2_theta;
	det = b * b - a * c;
	if (det < 0.0f)
		return (false);
	t = get_t(ray, a, b, sqrtf(det));
	if (t < 0.0f)
		return (false);
	return (true);
}

float Cone::get_t(
	Ray &ray,
	float a,
	float b,
	float root_det
)
{
	float t[2];
	float det;
	float temp;
	Vec4 vp;

	t[0] = (-1.0f * b + root_det) / a;
	t[1] = (-1.0f * b - root_det) / a;
	if (a > 0.0f)
	{
		temp = t[0];
		t[0] = t[1];
		t[1] = temp;
	}
	for (int i=0; i < 2; i++)
	{
		if (t[i] < 0.0f)
			continue ;
		vp = ray.get_intersect_point(t[i]) - vertex;
		det = vp.dot(perp_vec);
		if (det >= 0.0f && det <= height)
			return (t[i]);
	}
	return (-1.0f);
}

Vec4 Cone::get_normal(Vec4 &point)
{
	Vec4 vp = point - vertex;
	Vec4 va = perp_vec * (vp.norm() / cosf(theta));
	Vec4 n = vp - va;

	n.normalize();
	return (n);
}
