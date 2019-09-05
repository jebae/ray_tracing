#include "shade.hpp"
#include "trace_record.hpp"

Shade::Shade(TraceRecord *rec, Light &light)
: rec(rec)
{
	light_distance = light.get_distance(rec->point);
	light_direction = light.get_direction(rec->point);
	light_intensity = light.get_intensity(light_distance);
}
