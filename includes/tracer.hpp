#ifndef TRACER_HPP
# define TRACER_HPP

# include "vec4.hpp"

class Object;
class Light;
class TraceRecord;
class Ray;

class Tracer
{
private:
	int num_objs;
	int num_lights;
	Object **objs;
	Light **lights;

	float get_refract_medium_ior(TraceRecord *rec);

public:
	Tracer(
		Object **objs,
		int num_objs,
		Light **lights,
		int num_lights
	);
	bool check_intersect(TraceRecord &rec);
	Vec4 shade(TraceRecord &rec);
	Vec4 trace(Ray &ray, float coeff, int depth, TraceRecord *prev);
	Ray get_reflection_ray(TraceRecord &rec);
	Ray get_refraction_ray(TraceRecord &rec);
};

#endif
