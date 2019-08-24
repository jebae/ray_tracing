#include "__test_utils__.hpp"
#include "vec4.hpp"

class TestVec4
{
private:
	UnitTest test;

public:
	TestVec4(bool print_success=false);
	void test_construct_case1(void);
	void test_construct_case2(void);
	void test_assign_case1(void);
	void test_cout_case1(void);
	void test_equal_case1(void);
	void test_equal_case2(void);
	void test_plus_case1(void);
	void test_plus_case2(void);
	void test_sub_case1(void);
	void test_sub_case2(void);
	void test_scalar_mul_case1(void);
	void test_scalar_mul_case2(void);
	void test_scalar_mul_case3(void);
	void test_dot_prod_case1(void);
	void test_cross_prod_case1(void);
	void test_norm_case1(void);
	void test_normalize_case1(void);
	void test_for_each_case1(void);
	void all(void);
};

TestVec4::TestVec4(bool print_success)
: test(UnitTest("Vec4", print_success))
{}

void TestVec4::test_construct_case1(void)
{
	test.set_subject("default value has to be assigned for constructor");
	Vec4 v;

	test.eq(v[0], 0.0f);
	test.eq(v[1], 0.0f);
	test.eq(v[2], 0.0f);
	test.eq(v[3], 1.0f);
}

void TestVec4::test_construct_case2(void)
{
	test.set_subject("passed value has to be assigned for constructor");
	Vec4 v(vector<float>{1.0f, 2.0f, 3.0f});

	test.eq(v[0], 1.0f);
	test.eq(v[1], 2.0f);
	test.eq(v[2], 3.0f);
	test.eq(v[3], 1.0f);
}

void TestVec4::test_assign_case1(void)
{
	test.set_subject("[] operator has to work");
	Vec4 v;
	float arr[3] = {3.2f, 32.0f, -1.0f};

	v[0] = arr[0];
	v[1] = arr[1];
	v[2] = arr[2];

	test.eq(v[0], arr[0]);
	test.eq(v[1], arr[1]);
	test.eq(v[2], arr[2]);
}

void TestVec4::test_cout_case1(void)
{
	test.set_subject("<< operator has to work");
	Vec4 v;
	ostringstream str_stream;
	string res;
	string expected = "Vec4[0, 3.14, 0, 1]";

	v[1] = 3.14f;
	str_stream << v;
	res = str_stream.str();
	test.eq(res, expected);
}

void TestVec4::test_equal_case1(void)
{
	test.set_subject("== operator has to work with returning true");
	Vec4 v1;
	Vec4 v2;
	bool res = v1 == v2;

	test.eq(res, true);
}

void TestVec4::test_equal_case2(void)
{
	test.set_subject("== operator has to work with returning false");
	Vec4 v1;
	Vec4 v2;
	
	v2[3] = 2.1f;
	bool res = v1 == v2;

	test.eq(res, false);
}

void TestVec4::test_plus_case1(void)
{
	test.set_subject("+ operator has to work");
	Vec4 v1;
	Vec4 v2;
	Vec4 res;

	v1[0] = 3.14f;
	v1[1] = -0.89f;
	v1[2] = 100.0f;
	v2[0] = -1.89f;
	v2[1] = 9.24;
	v2[2] = 11.234;
	res = v1 + v2;

	test.eq(res[0], v1[0] + v2[0]);
	test.eq(res[1], v1[1] + v2[1]);
	test.eq(res[2], v1[2] + v2[2]);
	test.eq(res[3], 1.0f);
}

void TestVec4::test_plus_case2(void)
{
	test.set_subject("+= operator has to work");
	Vec4 v1;
	Vec4 v2;
	Vec4 res;

	v1[0] = 3.14f;
	v1[1] = -0.89f;
	v1[2] = 100.0f;
	v2[0] = -1.89f;
	v2[1] = 9.24;
	v2[2] = 11.234;
	res = v1;
	res += v2;

	test.eq(res[0], v1[0] + v2[0]);
	test.eq(res[1], v1[1] + v2[1]);
	test.eq(res[2], v1[2] + v2[2]);
	test.eq(res[3], 1.0f);
}

void TestVec4::test_sub_case1(void)
{
	test.set_subject("- operator has to work");
	Vec4 v1;
	Vec4 v2;
	Vec4 res;

	v1[0] = 3.14f;
	v1[1] = -0.89f;
	v1[2] = 100.0f;
	v2[0] = -1.89f;
	v2[1] = 9.24;
	v2[2] = 11.234;
	res = v1 - v2;

	test.eq(res[0], v1[0] - v2[0]);
	test.eq(res[1], v1[1] - v2[1]);
	test.eq(res[2], v1[2] - v2[2]);
	test.eq(res[3], 1.0f);
}

void TestVec4::test_sub_case2(void)
{
	test.set_subject("-= operator has to work");
	Vec4 v1;
	Vec4 v2;
	Vec4 res;

	v1[0] = 3.14f;
	v1[1] = -0.89f;
	v1[2] = 100.0f;
	v2[0] = -1.89f;
	v2[1] = 9.24;
	v2[2] = 11.234;
	res = v1;
	res -= v2;

	test.eq(res[0], v1[0] - v2[0]);
	test.eq(res[1], v1[1] - v2[1]);
	test.eq(res[2], v1[2] - v2[2]);
	test.eq(res[3], 1.0f);
}

void TestVec4::test_scalar_mul_case1(void)
{
	test.set_subject("* operator has to scalar multiplication (s * v)");
	float scalar;
	Vec4 v1;
	Vec4 res;

	scalar = -1.34;
	v1[0] = 3.14f;
	v1[1] = -0.89f;
	v1[2] = 100.0f;
	res = scalar * v1;

	test.eq(res[0], v1[0] * scalar);
	test.eq(res[1], v1[1] * scalar);
	test.eq(res[2], v1[2] * scalar);
	test.eq(res[3], 1.0f);
}

void TestVec4::test_scalar_mul_case2(void)
{
	test.set_subject("* operator has to scalar multiplication (v * s)");
	float scalar;
	Vec4 v1;
	Vec4 res;

	scalar = -1.34;
	v1[0] = 3.14f;
	v1[1] = -0.89f;
	v1[2] = 100.0f;
	res = v1 * scalar;

	test.eq(res[0], v1[0] * scalar);
	test.eq(res[1], v1[1] * scalar);
	test.eq(res[2], v1[2] * scalar);
	test.eq(res[3], 1.0f);
}

void TestVec4::test_scalar_mul_case3(void)
{
	test.set_subject("*= operator has to scalar multiplication");
	float scalar;
	Vec4 v1;
	Vec4 res;

	scalar = -1.34;
	v1[0] = 3.14f;
	v1[1] = -0.89f;
	v1[2] = 100.0f;
	res = v1;
	res *= scalar;

	test.eq(res[0], v1[0] * scalar);
	test.eq(res[1], v1[1] * scalar);
	test.eq(res[2], v1[2] * scalar);
	test.eq(res[3], 1.0f);
}

void TestVec4::test_dot_prod_case1(void)
{
	test.set_subject("dot product has to work");
	Vec4 v1;
	Vec4 v2;
	float res;

	v1[0] = 3.14f;
	v1[1] = -0.89f;
	v1[2] = 100.0f;
	v2[0] = -1.89f;
	v2[1] = 9.24;
	v2[2] = 11.234;

	res = v1.dot(v2);
	test.eq(res, v1[0] * v2[0] + v1[1] * v2[1] + v1[2] * v2[2]);
	res = v2.dot(v1);
	test.eq(res, v1[0] * v2[0] + v1[1] * v2[1] + v1[2] * v2[2]);
}

void TestVec4::test_cross_prod_case1(void)
{
	test.set_subject("cross product has to work");
	Vec4 v1;
	Vec4 v2;
	Vec4 res;

	v1[0] = 3.14f;
	v1[1] = -0.89f;
	v1[2] = 100.0f;
	v2[0] = -1.89f;
	v2[1] = 9.24;
	v2[2] = 11.234;

	res = v1.cross(v2);
	test.eq(res[0], v1[1] * v2[2] - v1[2] * v2[1]);
	test.eq(res[1], v1[2] * v2[0] - v1[0] * v2[2]);
	test.eq(res[2], v1[0] * v2[1] - v1[1] * v2[0]);
}

void TestVec4::test_norm_case1(void)
{
	test.set_subject("norm of vector has to be returned");
	Vec4 vec;
	float res;

	vec[0] = 3.14f;
	vec[1] = -0.89f;
	vec[2] = 100.0f;
	res = vec.norm();
	test.eq(res, sqrtf(vec[0] * vec[0] + vec[1] * vec[1] + vec[2] * vec[2]));
}

void TestVec4::test_normalize_case1(void)
{
	test.set_subject("vector has to be normalized");
	Vec4 vec;
	float norm;
	float precision = 1000000;

	vec[0] = 3.141592234f;
	vec[1] = -0.89f;
	vec[2] = 100.0f;
	vec.normalize();
	norm = round(vec.norm() * precision) / precision;
	test.eq(norm, 1.0f);
}

void TestVec4::test_for_each_case1(void)
{
	test.set_subject("every element has to be affected by function");
	Vec4 vec;
	float arr[3] = {1.2456, -55.234, 0.2};

	vec[0] = arr[0];
	vec[1] = arr[1];
	vec[2] = arr[2];
	vec.for_each(
		[] (float *f)
		{
			*f += 1.0f;
		}
	);
	test.eq(vec[0], arr[0] + 1.0f);
	test.eq(vec[1], arr[1] + 1.0f);
	test.eq(vec[2], arr[2] + 1.0f);
}

void TestVec4::all(void)
{
	test_construct_case1();
	test_construct_case2();
	test_assign_case1();
	test_cout_case1();
	test_equal_case1();
	test_equal_case2();
	test_plus_case1();
	test_plus_case2();
	test_sub_case1();
	test_sub_case2();
	test_scalar_mul_case1();
	test_scalar_mul_case2();
	test_scalar_mul_case3();
	test_dot_prod_case1();
	test_cross_prod_case1();
	test_norm_case1();
	test_normalize_case1();
	test_for_each_case1();
}
