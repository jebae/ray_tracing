#include "tracer.hpp"
#include "object.hpp"
#include "shade.hpp"
#include "trace_record.hpp"
#include <cmath>

extern Vec4 AMBIENT_INTENSITY;

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
	Vec4 res = Shade::ambient(rec.obj->color, AMBIENT_INTENSITY);

	for (int i=0; i < num_lights; i++)
	{
		Shade shade(rec, lights[i]);

		res += shade.diffuse();
		res += shade.specular();
	}
	return (res);
}
