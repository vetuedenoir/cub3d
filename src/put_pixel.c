#include "../inc/cub3d.h"

int	makecolor(int t, int red, int green, int blue)
{
	return (t << 24 | red << 16 | green << 8 | blue);
}

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	int	pix;

	pix = y * data->line_length + x * (data->bits_per_pixel / 8);
	if (pix >= 0 && pix <= data->height * data->width * (data->bits_per_pixel / 8))
		*(unsigned int *)(data->addr + pix) = color;
}

int	check_color_pix(t_img *data, int x, int y, int color)
{
	int	pix;

	pix = y * data->line_length + x * (data->bits_per_pixel / 8);
	if (pix >= 0 && pix <= data->height * data->width * (data->bits_per_pixel / 8))
	{
		if (*(int *)(data->addr + pix) != (int)color \
			&& *(int *)(data->addr + pix) != (int)MINI_PERSO_COLOR)
				return (1);
		return (0);	
	}		
	else
		return (-1);
}