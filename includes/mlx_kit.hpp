#ifndef MLX_KIT_HPP
# define MLX_KIT_HPP

extern "C"
{
	#include "mlx.h"
}

class MLXKit
{
public:
	int width;
	int height;
	void *p_mlx;
	void *p_win;
	void *p_img;

	MLXKit(int width, int height);
	~MLXKit(void);
	int *get_img_buffer(void);
	void loop(void);
	void put_img_to_window(void);
};

int key_press(int keycode, void *param);

#endif
