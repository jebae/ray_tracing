#include <cassert>
#include <iostream>
#include <cmath>
#include <functional>
#include "vec4.hpp"

using namespace std;

Vec4::Vec4(vector<float> vec3)
{
	assert(vec3.size() == 3);
	vec = vector<float>(4);
	for (int i=0; i < 3; i++)
		vec[i] = vec3[i];
	vec[3] = 1.0f;
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

Vec4 Vec4::operator + (Vec4 &factor)
{
	Vec4 res;

	for (int i=0; i < 3; i++)
		res[i] = vec[i] + factor[i];
	return (res);
}

Vec4& Vec4::operator += (Vec4 &factor)
{
	for (int i=0; i < 3; i++)
		vec[i] += factor[i];
	return (*this);
}

Vec4 Vec4::operator - (Vec4 &factor)
{
	Vec4 res;

	for (int i=0; i < 3; i++)
		res[i] = vec[i] - factor[i];
	return (res);
}

Vec4& Vec4::operator -= (Vec4 &factor)
{
	for (int i=0; i < 3; i++)
		vec[i] -= factor[i];
	return (*this);
}

float Vec4::dot(Vec4 &factor)
{
	float res;

	res = 0.0f;
	for (int i=0; i < 3; i++)
		res += vec[i] * factor[i];
	return (res);
}

Vec4 Vec4::cross(Vec4 &factor)
{
	Vec4 res;

	res[0] = vec[1] * factor[2] - vec[2] * factor[1];
	res[1] = vec[2] * factor[0] - vec[0] * factor[2];
	res[2] = vec[0] * factor[1] - vec[1] * factor[0];
	return (res);
}

float Vec4::norm(void)
{
	return (sqrtf(vec[0] * vec[0] + vec[1] * vec[1] + vec[2] * vec[2]));
}

void Vec4::normalize(void)
{
	float n;

	n = norm();
	for (int i=0; i < 3; i++)
		vec[i] /= n;
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

Vec4 operator * (float scalar, Vec4 &vec)
{
	Vec4 res;

	for (int i=0; i < 3; i++)
		res[i] = scalar * vec[i];
	return (res);
}

Vec4 Vec4::operator * (float scalar)
{
	Vec4 res;

	for (int i=0; i < 3; i++)
		res[i] = scalar * vec[i];
	return (res);
}

Vec4& Vec4::operator *= (float scalar)
{
	for (int i=0; i < 3; i++)
		vec[i] *= scalar;
	return (*this);
}

void Vec4::for_each(function<void(float *)> fn)
{
	for (int i=0; i < 3; i++)
		fn(&(vec[i]));
}
