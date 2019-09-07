#include "trace_record.hpp"
#include "ray.hpp"
#include "object.hpp"
#include <iostream>

using namespace std;

TraceRecord::TraceRecord(Ray &ray, TraceRecord *prev, Object *obj)
: obj(obj), ray(ray), prev(prev)
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

	/*
	 * if normal vector is not towards camera
	 * reverse direction of normal vector
	*/
	if (ray.d.dot(normal) > 0.0f)
		normal *= -1.0f;
}
