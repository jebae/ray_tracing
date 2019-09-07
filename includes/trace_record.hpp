#ifndef TRACE_RECORD_HPP
# define TRACE_RECORD_HPP

#include "vec4.hpp"
#include "ray.hpp"

/*
 * objects will be saved as pointer array
 * and passed around.
 * so save object as pointer is better than ref
*/
class Object;

class TraceRecord
{
public:
	Object *obj;
	Ray &ray;
	Vec4 point;
	Vec4 normal;
	TraceRecord *prev;

	TraceRecord(Ray &ray, TraceRecord *prev, Object *obj=nullptr);
	void update_intersect_info(float t);
	friend std::ostream & operator << (std::ostream &os, TraceRecord &rec);
};

#endif
