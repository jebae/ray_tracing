#ifndef MACRO_HPP
# define MACRO_HPP

# define KRED					"\x1B[31m"
# define KGRN					"\x1B[32m"
# define KYEL					"\x1B[33m"
# define KNRM					"\x1B[0m"

# define KEY_ESC				53
# define MLX_BPP				32
# define MLX_ENDIAN				0
# define FLOAT_APPROX_0			1e-6f
# define BIAS					1e-3f
# define MAX_TRACE_DEPTH		2

# define RAY_TYPE_NONE			0
# define RAY_TYPE_ORIGIN		1
# define RAY_TYPE_REFLECTION	2
# define RAY_TYPE_REFRACTION	3

# define ABS(X) ((X < 0) ? -(X) : (X))
# define MAX(X, Y) ((X > Y) ? (X) : (Y))

#endif
