#include "tracer.hpp"
#include "object.hpp"
#include <cmath>

Tracer::Tracer(Object **objs, int num_objs)
: objs(objs), num_objs(num_objs)
{}

TraceRecord Tracer::trace(Ray &ray)
{
	TraceRecord rec(nullptr, ray);
	int i = num_objs;
	float t[2];

	t[1] = INFINITY;
	while (i--)
	{
		if (!(objs[i]->intersect(ray, t[0])))
			continue ;
		if (t[0] < t[1])
		{
			t[1] = t[0];
			rec.obj = objs[i];
		}
	}
	if (t[1] != INFINITY)
		rec.set_intersect_point(t[1]);
	return (rec);
}
