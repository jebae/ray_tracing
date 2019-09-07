#ifndef RAY_HPP
# define RAY_HPP

# include <cmath>
# include "vec4.hpp"
# include "macro.hpp"

class Camera;

class RayGridProps
{
public:
	Vec4 e;
	Vec4 offset;
	Vec4 dx;
	Vec4 dy;

	RayGridProps(
		Camera &cam,
		float width,
		float height,
		float aov=M_PI / 2.0f
	);
};

class Ray
{
public:
	int type;
	float ior; 
	Vec4 e;
	Vec4 d;

	Ray(Vec4 e, Vec4 d, int type=RAY_TYPE_ORIGIN, float ior=1.0f);
	Vec4 get_intersect_point(float t);
	static Ray get_ray_by_grid_props(
		RayGridProps &props,
		int scalar_x,
		int scalar_y
	);
};

#endif
