#include "trace_record.hpp"
#include "ray.hpp"
#include <iostream>

using namespace std;

TraceRecord::TraceRecord(Object *obj, Ray &ray)
: obj(obj), ray(ray)
{}

void TraceRecord::set_intersect_point(float t)
{
	point = (t * ray.d + ray.e);
}

ostream& operator << (ostream &os, TraceRecord &rec)
{
	(void)(rec);
	os << "TraceRecord{obj, ray, point}";
	return (os);
}
