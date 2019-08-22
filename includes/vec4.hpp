#ifndef VEC4_HPP
# define VEC4_HPP

# include <iostream>
# include <vector>
# include <cmath>

using namespace std;

class Vec4
{
private:
	vector<float> vec;

public:
	Vec4(vector<float> vec3=vector<float>(3, 0.0f));
	float& operator [] (int i);
	bool operator == (Vec4 &factor);
	Vec4 operator + (Vec4 &factor);
	Vec4 operator - (Vec4 &factor);
	float dot(Vec4 &factor);
	Vec4 cross(Vec4 &factor);
	float norm(void);
	void normalize(void);
	friend ostream& operator << (ostream &os, Vec4 &vec4);
	friend Vec4 operator * (float scalar, Vec4 &vec);
	friend Vec4 operator * (Vec4 &vec, float scalar);
};

#endif
