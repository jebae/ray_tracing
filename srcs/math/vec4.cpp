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

ostream & operator << (ostream &os, Vec4 &vec4)
{
	cout << "Vec4[";
	for (int i=0; i < 4; i++)
		cout << vec4.vec[i] << ", ";
	cout << "]" << endl;
	return (os);
}
