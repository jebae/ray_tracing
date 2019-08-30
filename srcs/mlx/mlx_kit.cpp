#include "mlx_kit.hpp"
#include "macro.hpp"
#include <iostream>

using namespace std;

MLXKit::MLXKit(int width, int height)
: width(width), height(height)
{
	cout << "MLX kit is initializing";
	p_mlx = mlx_init();
	p_win = mlx_new_window(
		p_mlx, width, height,
		(char *)"window"
	);
	p_img = mlx_new_image(p_mlx, width, height);
	mlx_key_hook(p_win, &key_press, nullptr);
	cout << KGRN << " ... DONE" << KNRM << endl;
}

MLXKit::~MLXKit(void)
{
	cout << "MLX kit is destructing";
	mlx_destroy_image(p_mlx, p_img);
	mlx_destroy_window(p_mlx, p_win);
	cout << KGRN << " ... DONE" << KNRM << endl;
}

int* MLXKit::get_img_buffer(void)
{
	static int		bpp = MLX_BPP;
	static int		endian = MLX_ENDIAN;

	return ((int *)mlx_get_data_addr(p_img, &bpp, &width, &endian));
}

void MLXKit::put_img_to_window(void)
{
	mlx_put_image_to_window(p_mlx, p_win, p_img, 0, 0);
}

void MLXKit::loop(void)
{
	mlx_loop(p_mlx);
}

int key_press(void)
{
	exit(0);
}
