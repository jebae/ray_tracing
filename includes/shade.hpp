#ifndef SHADE_HPP
# define SHADE_HPP

# include "vec4.hpp"

class TraceRecord;

class Shade
{
private:
	TraceRecord *rec;
	Vec4 ambient_intensity;

public:
	Shade(
		TraceRecord *rec,
		Vec4 ambient_intensity=Vec4(
			std::vector<float>(3, 0.05f)
		)
	);
	Vec4 ambient(void);
};

#endif
