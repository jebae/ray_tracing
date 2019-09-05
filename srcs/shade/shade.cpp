#include "shade.hpp"
#include "trace_record.hpp"
#include "object.hpp"
#include "macro.hpp"

using namespace std;

Shade::Shade(TraceRecord *rec, Light &light)
: rec(rec)
{
	light_distance = light.get_distance(rec->point);
	light_direction = light.get_direction(rec->point);
	light_intensity = light.get_intensity(light_distance);
	n_dot_l = rec->normal.dot(-1.0f * light_direction);
	n_dot_l = MAX(n_dot_l, 0.0f);
}

Vec4 Shade::ambient(
	Vec4 &color,
	Vec4 &ambient_intensity
)
{
	return Vec4(vector<float>{
		ambient_intensity[0] * color[0],
		ambient_intensity[1] * color[1],
		ambient_intensity[2] * color[2]
	});
}

Vec4 Shade::diffuse(void)
{
	return Vec4(vector<float>{
		n_dot_l * rec->obj->color[0] * light_intensity[0],
		n_dot_l * rec->obj->color[1] * light_intensity[1],
		n_dot_l * rec->obj->color[2] * light_intensity[2]
	});
}

Vec4 Shade::specular(void)
{
	Vec4 r = light_direction + 2 * n_dot_l * rec->normal;
	float r_dot_d = -1.0f * r.dot(rec->ray.d);

	r_dot_d = MAX(r_dot_d, 0.0f);
	r_dot_d = powf(r_dot_d, rec->obj->specular_alpha);
	return Vec4(vector<float>{
		light_intensity[0] * rec->obj->color[0] * r_dot_d,
		light_intensity[1] * rec->obj->color[1] * r_dot_d,
		light_intensity[2] * rec->obj->color[2] * r_dot_d
	});
}
