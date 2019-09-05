#ifndef TRACE_RECORD_HPP
# define TRACE_RECORD_HPP

#include "vec4.hpp"
#include "ray.hpp"

class Object;

class TraceRecord
{
public:
	Object *obj;
	Ray ray;
	Vec4 point;
	Vec4 normal;

	TraceRecord(Object *obj, Ray &ray);
	void update_intersect_info(float t);
	friend std::ostream & operator << (std::ostream &os, TraceRecord &rec);
};

#endif
