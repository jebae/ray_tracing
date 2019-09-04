#include "shade.hpp"
#include "trace_record.hpp"
#include "object.hpp"

using namespace std;

Vec4 Shade::ambient(void)
{
	return Vec4(vector<float>{
		ambient_intensity[0] * rec->obj->color[0],
		ambient_intensity[1] * rec->obj->color[1],
		ambient_intensity[2] * rec->obj->color[2]
	});
}
