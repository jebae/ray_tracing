#include "trace_record.hpp"
#include "ray.hpp"
#include "object.hpp"
#include <iostream>

using namespace std;

TraceRecord::TraceRecord(Object *obj, Ray &ray)
: obj(obj), ray(ray)
{}

ostream& operator << (ostream &os, TraceRecord &rec)
{
	(void)(rec);
	os << "TraceRecord{obj, ray, point}";
	return (os);
}

void TraceRecord::update_intersect_info(float t)
{
	point = ray.get_intersect_point(t);
	normal = obj->get_normal(point);
	if (ray.d.dot(normal) > 0.0f)
		normal *= -1.0f;
}
