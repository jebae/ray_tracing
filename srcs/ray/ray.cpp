#include "ray.hpp"

Ray::Ray(Vec4 e, Vec4 d)
: e(e), d(d)
{}

Vec4 Ray::get_intersect_point(float t)
{
	return (e + t * d);
}

Ray Ray::get_ray_by_grid_props(
	RayGridProps &props,
	int scalar_x,
	int scalar_y
)
{
	Vec4 d = props.offset + scalar_y * props.dy + scalar_x * props.dx;
	d.normalize();
	return (Ray(props.e, d));
}
