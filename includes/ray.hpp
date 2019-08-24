#ifndef RAY_HPP
# define RAY_HPP

# include "vec4.hpp"
# include "camera.hpp"

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
	Vec4 e;
	Vec4 d;
};

#endif
