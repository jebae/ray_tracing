#ifndef VEC4_HPP
# define VEC4_HPP

# include <iostream>
# include <vector>
# include <functional>

class Vec4
{
private:
	std::vector<float> vec;

public:
	Vec4(std::vector<float> vec3=std::vector<float>(3, 0.0f));
	float& operator [] (int i);
	bool operator == (Vec4 factor);
	Vec4 operator + (Vec4 factor);
	Vec4& operator += (Vec4 factor);
	Vec4 operator - (Vec4 factor);
	Vec4& operator -= (Vec4 factor);
	Vec4 operator * (float scalar);
	Vec4& operator *= (float scalar);
	float dot(Vec4 factor);
	Vec4 cross(Vec4 factor);
	float norm(void);
	void normalize(void);
	friend std::ostream& operator << (std::ostream &os, Vec4 vec4);
	friend Vec4 operator * (float scalar, Vec4 vec);
	void for_each(std::function<void(float *)> fn);
};

#endif
