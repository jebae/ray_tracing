#include "ray_tracing.hpp"

Vec4::Vec4(void)
: vec(vector<float>(4, 0.0f))
{
	vec[3] = 1.0f;
}

Vec4 Vec4::operator + (Vec4 &factor)
{
	Vec4 res;

	for (int i=0; i < 3; i++)
		res.vec[i] = vec[i] + factor.vec[i];
	return (res);
}

float& Vec4::operator [] (int i)
{
	return (vec[i]);
}

bool Vec4::operator == (Vec4 &factor)
{
	for (int i=0; i < 4; i++)
	{
		if (vec[i] != factor[i])
			return (false);
	}
	return (true);
}

ostream& operator << (ostream &os, Vec4 &vec4)
{
	int i;

	os << "Vec4[";
	for (i=0; i < 3; i++)
		os << vec4[i] << ", ";
	os << vec4[i];
	os << "]";
	return (os);
}
