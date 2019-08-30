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

	TraceRecord(Object *obj, Ray &ray);
	friend std::ostream & operator << (std::ostream &os, TraceRecord &rec);
};

#endif
