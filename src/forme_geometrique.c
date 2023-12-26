#include "../inc/cub3d.h"
/*
void draw_filled_circle(t_img *data, int xc, int yc, int radius, int color)
{
	int x = 0, y = radius;
	int d = 3 - 2 * radius;

	while (x <= y)
	{
		// Dessine la ligne horizontale entre les points symétriques
		for (int i = xc - x; i <= xc + x; i++)
		{
			my_mlx_pixel_put(data, i, yc + y, color / 2);
			my_mlx_pixel_put(data, i, yc - y, color / 2);
		}

		// Dessine la ligne horizontale entre les points symétriques
		for (int i = xc - y; i <= xc + y; i++)
		{
			my_mlx_pixel_put(data, i, yc + x, color);
			my_mlx_pixel_put(data, i, yc - x, color);
		}

		x++;

		if (d > 0)
		{
			y--;
			d = d + 4 * (x - y) + 10;
		}
		else
		{
			d = d + 4 * x + 6;
		}
	}
}*/

void	circle_bis(t_img *data, int *centre, int *point, int color)
{
	int	i;

	i = centre[X] - point[X] - 1;
	while (++i <= centre[X] + point[X])
	{
		my_mlx_pixel_put(data, i, centre[Y] + point[Y], color);
		my_mlx_pixel_put(data, i, centre[Y] - point[Y], color);
	}
	i = centre[X] - point[Y] - 1;
	while (++i <= centre[X] + point[Y])
	{
		my_mlx_pixel_put(data, i, centre[Y] + point[X], color);
		my_mlx_pixel_put(data, i, centre[Y] - point[X], color);
	}
}

void draw_filled_circle(t_img *data, int centre[2], int radius, int color)
{
	int point[2];
	int d;

	point[X] = 0;
	point[Y] = radius;
	d = 3 - 2 * radius;
	while (point[X] <= point[Y])
	{
		circle_bis(data, centre, point, color);
		point[X]++;
		if (d > 0)
		{
			point[Y]--;
			d = d + 4 * (point[X] - point[Y]) + 10;
		}
		else
			d = d + 4 * point[X] + 6;
	}
}
/*
void draw_line_dda(t_img *data, int x1, int y1, int x2, int y2, int color)
{
	int dx = x2 - x1;
	int dy = y2 - y1;

	int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

	float xIncrement = (float)dx / (float)steps;
	float yIncrement = (float)dy / (float)steps;

	float x = x1, y = y1;

	for (int i = 0; i <= steps; i++)
	{
		if (check_color_pix(data, round(x), round(y), MINI_FLOOR_COLOR))
			break ;
		my_mlx_pixel_put(data, round(x), round(y), color);
		x += xIncrement;
		y += yIncrement;
	}
}*/


void draw_line_dda(t_img *data, int p1[2], int p2[2], int color)
{
	int		d[2];
	int		steps;
	float	Increment[2];
	float	point[2];
	int		i;

	d[X] = p2[X] - p1[X];
	d[Y] = p2[Y] - p1[Y];
	if (abs(d[X]) > abs(d[Y]))
		steps = abs(d[X]);
	else
		steps = abs(d[Y]);
	Increment[X] = (float)d[X] / (float)steps;
	Increment[Y] = (float)d[Y] / (float)steps;
	point[X] = p1[X];
	point[Y] = p1[Y];
	i = -1;
	while (++i <= steps)
	{
		if (check_color_pix(data, round(point[X]), round(point[Y]), MINI_FLOOR_COLOR))
			break ;
		my_mlx_pixel_put(data, round(point[X]), round(point[Y]), color);
		point[X] += Increment[X];
		point[Y] += Increment[Y];
	}
}