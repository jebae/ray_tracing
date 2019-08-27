#include "__test_utils__.hpp"
#include "object.hpp"

class TestObject : public UnitTest
{
public:
	TestObject(bool print_success=false);
	Object create_test_object(void);
	void all(void);
};

TestObject::TestObject(bool print_success)
: UnitTest("Object", print_success)
{}

Object TestObject::create_test_object(void)
{
	int specular_alpha = 50;
	float reflectivity = 0.3f;
	float transparency = 0.2f;
	float ior = 1.5f;
	Vec4 color(vector<float>{0.4f, 0.4f, 0.4f});

	return Object(
		specular_alpha,
		reflectivity,
		transparency,
		ior,
		color
	);
}

void TestObject::all(void)
{

}
