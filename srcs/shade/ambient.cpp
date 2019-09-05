#include "shade.hpp"
#include "trace_record.hpp"
#include "object.hpp"

using namespace std;

Vec4 Shade::ambient(
	Vec4 &color,
	Vec4 &ambient_intensity
)
{
	return Vec4(vector<float>{
		ambient_intensity[0] * color[0],
		ambient_intensity[1] * color[1],
		ambient_intensity[2] * color[2]
	});
}
