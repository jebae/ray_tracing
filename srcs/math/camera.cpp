#include "camera.hpp"
#include <cmath>

Camera::Camera(Vec4 pos, Vec4 focus)
: pos(pos)
{
	zoom = 1.0f;
	set_z_axis(focus);
	set_x_axis();
	set_y_axis();
}

void Camera::set_z_axis(Vec4 &focus)
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

void Camera::set_y_axis(void)
{
	y_axis = z_axis.cross(x_axis);
	y_axis.normalize();
}
