#include "__test_utils__.hpp"
#include "object.hpp"

class TestObject
{
private:
	UnitTest test;

public:
	TestObject(bool print_success=false);
	Object *create_test_object(void *shape=nullptr);
	void test_destruct_case1(void);
	void all(void);
};

TestObject::TestObject(bool print_success)
: test(UnitTest("Object", print_success))
{}

Object* TestObject::create_test_object(void *shape)
{
	int specular_alpha = 50;
	float reflectivity = 0.3f;
	float transparency = 0.2f;
	float ior = 1.5f;
	Vec4 color(vector<float>{0.4f, 0.4f, 0.4f});
	Object *obj = new Object(
		shape,
		specular_alpha,
		reflectivity,
		transparency,
		ior,
		color
	);

	return (obj);
}

void TestObject::test_destruct_case1(void)
{
	test.set_subject("set_del_shape has to destructed properly");
	Object *obj = create_test_object();
	ostringstream str_stream;
	string res;

	obj->set_del_shape(
		[&str_stream] (void *shape) -> void {
			(void)(shape);
			str_stream << "done";
		}
	);
	delete obj;
	res = str_stream.str();
	test.eq(res, string("done"));
}

void TestObject::all(void)
{
	test_destruct_case1();
}
