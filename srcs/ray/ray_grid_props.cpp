#include "ray.hpp"
#include "camera.hpp"

RayGridProps::RayGridProps(
	Camera &cam,
	float width,
	float height,
	float aov
): e(cam.pos)
{
	float gx;
	float gy;

	gx = tan(aov / 2.0f);
	gy = gx * height / width;
	dx = gx * cam.x_axis;
	dy = gy * cam.y_axis;
	offset = cam.z_axis - dx;
	offset -= dy;
	dx *= 2 / (width - 1);
	dy *= 2 / (height - 1);
}
