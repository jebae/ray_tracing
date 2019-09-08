#include "color.hpp"

int rgb_vec_to_color(Vec4 &rgb)
{
	int color = 0;

	color += (rgb[0] >= 1.0f) ? 0xFF : 0xFF * rgb[0];
	color <<= 8;
	color += (rgb[1] >= 1.0f) ? 0xFF : 0xFF * rgb[1];
	color <<= 8;
	color += (rgb[2] >= 1.0f) ? 0xFF : 0xFF * rgb[2];
	return (color);
}
