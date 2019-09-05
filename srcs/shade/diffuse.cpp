#include "shade.hpp"
#include "trace_record.hpp"
#include "object.hpp"
#include "macro.hpp"

using namespace std;

Vec4 Shade::diffuse(void)
{
	float n_dot_l = rec->normal.dot(-1.0f * light_direction);
	n_dot_l = MAX(n_dot_l, 0.0f);

	return Vec4(vector<float>{
		n_dot_l * rec->obj->color[0] * light_intensity[0],
		n_dot_l * rec->obj->color[1] * light_intensity[1],
		n_dot_l * rec->obj->color[2] * light_intensity[2]
	});
}
