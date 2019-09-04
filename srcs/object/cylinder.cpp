#include "cylinder.hpp"

Cylinder::Cylinder(
	int specular_alpha,
	float reflectivity,
	float transparency,
	float ior,
	Vec4 color,
	float radius,
	float height,
	Vec4 center,
	Vec4 perp_vec
): Object(
	specular_alpha,
	reflectivity,
	transparency,
	ior,
	color
), radius(radius),
height(height),
center(center),
perp_vec(perp_vec)
{
	this->perp_vec.normalize();
}

bool Cylinder::intersect(Ray &ray, float &t)
{
	Vec4 ce = ray.e - center;
	float a;
	float b;
	float c;
	float det;
	float d_dot_perp = ray.d.dot(perp_vec);
	float ce_dot_perp = ce.dot(perp_vec);

	a = d_dot_perp * d_dot_perp - 1.0f;
	b = d_dot_perp * ce_dot_perp - ce.dot(ray.d);
	c = radius * radius + ce_dot_perp * ce_dot_perp - ce.dot(ce);
	det = b * b - a * c;
	if (det < 0.0f)
		return (false);
	t = get_t(ray, a, b, sqrtf(det));
	if (t < 0.0f)
		return (false);
	return (true);
}

float Cylinder::get_t(
	Ray &ray,
	float a,
	float b,
	float root_det
)
{
	float t[2];
	float det;
	float temp;
	Vec4 cp;

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
		cp = ray.get_intersect_point(t[i]) - center;
		det = cp.dot(perp_vec);
		if (det >= 0.0f && det <= height)
			return (t[i]);
	}
	return (-1.0f);
}

Vec4 Cylinder::get_normal(Vec4 &point)
{
	Vec4 cp = point - center;
	Vec4 ca = perp_vec * (cp.dot(perp_vec));
	Vec4 n = cp - ca;

	n.normalize();
	return (n);
}
