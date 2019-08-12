#include "vec4.hpp"

Vec4::Vec4(void)
: vec(vector<float> default_vec{0.0f, 0.0f, 0.0f, 1.0f})
{

}

Vec4 Vec4::operator + (Vec4 &factor)
{
	Vec4 res;

	for (int i=0; i < 3; i ++)
		res.vec[i] = vec[i] + factor.vec[i];
	return (res);
}

ostream & operator << (ostream &os, Vec4 &vec4)
{
	cout << vec4.vec << endl;
}
