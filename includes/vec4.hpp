#ifndef VEC4_HPP
# define VEC4_HPP

# include <vector>

class Vec4
{
private:
	vector<float> vec;

public:
	Vec4(void);
	Vec4 operator + (Vec4 &factor);
	float& operator [] (int i);
	friend ostream & operator << (ostream &os, Vec4 &vec4);
};

#endif
