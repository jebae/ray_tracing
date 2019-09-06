#include "tracer.hpp"
#include "object.hpp"
#include "shade.hpp"
#include "trace_record.hpp"
#include "macro.hpp"
#include <cmath>

extern Vec4 AMBIENT_INTENSITY;

using namespace std;

Tracer::Tracer(
	Object **objs,
	int num_objs,
	Light **lights,
	int num_lights
)
: num_objs(num_objs),
num_lights(num_lights),
objs(objs),
lights(lights)
{}

bool Tracer::check_intersect(TraceRecord &rec)
{
	int i = num_objs;
	float t[2];

	t[1] = INFINITY;
	while (i--)
	{
		if (!(objs[i]->intersect(rec.ray, t[0])))
			continue ;
		if (t[0] < t[1])
		{
			t[1] = t[0];
			rec.obj = objs[i];
		}
	}
	if (t[1] == INFINITY)
		return (false);
	rec.update_intersect_info(t[1]);
	return (true);
}

Vec4 Tracer::shade(TraceRecord &rec)
{
	Vec4 res;
	Vec4 shade_per_light;

	for (int i=0; i < num_lights; i++)
	{
		Shade shade(rec, lights[i]);

		shade_per_light = shade.diffuse();
		shade_per_light += shade.specular();
		shade_per_light *= shade.shadow(objs, num_objs);
		res += shade_per_light;
	}
	res += Shade::ambient(rec.obj->color, AMBIENT_INTENSITY);
	return (res);
}

Vec4 Tracer::trace(Ray &ray, float coeff, int depth)
{
	TraceRecord rec(ray);
	Vec4 rgb;

	if (!check_intersect(rec))
		return (rgb);
	rgb = shade(rec);
	if (depth > MAX_TRACE_DEPTH)
		return (coeff * rgb);
	Ray reflection_ray = get_reflection_ray(rec);
	rgb += trace(reflection_ray, coeff * rec.obj->reflectivity, depth + 1);
	// get refraction ray
	// recursion -> trace(refraction_ray, coeff * (1 - rec.obj->reflectivity) * transparency);
	// sum shade + reflect + refract
	return (coeff * rgb);
}

Ray Tracer::get_reflection_ray(TraceRecord &rec)
{
	float d_dot_n = -1.0f * rec.ray.d.dot(rec.normal);

	return Ray(
		rec.point + BIAS * rec.normal,
		rec.ray.d + 2.0f * d_dot_n * rec.normal
	);
}
