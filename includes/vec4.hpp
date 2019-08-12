#ifndef VEC4_HPP
# define VEC4_HPP

# include <vector>
# include <iostream>

using namespace std;

class Vec4
{
private:
	vector<float> vec;

public:
	Vec4(void);
	Vec4 operator + (Vec4 &factor);
	friend ostream & operator << (ostream &os, Vec4 &vec4);
}

#endif
