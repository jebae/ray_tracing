#include "shade.hpp"

Shade::Shade(
	TraceRecord *rec,
	Vec4 ambient_intensity
): rec(rec),
ambient_intensity(ambient_intensity)
{}
