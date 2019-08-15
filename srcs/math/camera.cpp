#include "ray_tracing.hpp"

Camera::Camera(Vec4 arg_pos, Vec4 focus);
{
	pos = arg_pos;
	zoom = 1.0f;
	// here
}

void Camera::set_z_axis(Vec4 focus)
{
	z_axis = focus - pos;
	z_axis.normalize();
}

void Camera::set_x_axis(void)
{
	Vec4 z_w;

	z_w[2] = 1.0f;
	if (abs(z_w.dot(z_axis)) >= 1.0f)
		return ;
	x_axis = z_axis.cross(z_w);
	x_axis.normalize();
}
