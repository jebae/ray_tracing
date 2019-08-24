#ifndef OBJECT_HPP
# define OBJECT_HPP

# include <iostream>
# include "vec4.hpp"

using namespace std;

typedef function<void(void *)> del_shape_fn;

class Object
{
private:
	void *shape;
	del_shape_fn del_shape;

public:
	int specular_alpha;
	float reflectivity;
	float transparency;
	float ior;
	Vec4 color;

	Object(
		void *shape,
		int specular_alpha,
		float reflectivity,
		float transparency,
		float ior,
		Vec4 color
	);

	~Object(void);

	void set_del_shape(del_shape_fn fn);
};

#endif
