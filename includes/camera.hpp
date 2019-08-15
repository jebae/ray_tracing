#ifndef CAMERA_HPP
# define CAMERA_HPP

# include "vec4.hpp"

class Camera
{
public:
	Vec4 pos;
	Vec4 x_axis;
	Vec4 y_axis;
	Vec4 z_axis;
	float zoom;

	Camera(Vec4 pos, Vec4 focus);
	void set_z_axis(Vec4 focus);
	void set_x_axis(void);
}

#endif
