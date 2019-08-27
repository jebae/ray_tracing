#ifndef TRACER_HPP
# define TRACER_HPP

# include "ray.hpp"
# include "trace_record.hpp"

class Object;

class Tracer
{
private:
	Object **objs;
	int num_objs;

public:
	Tracer(Object **objs, int num_objs);
	TraceRecord trace(Ray &ray);
};

#endif
