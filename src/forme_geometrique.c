/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forme_geometrique.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <kscordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 13:14:02 by kscordel          #+#    #+#             */
/*   Updated: 2023/12/28 13:38:37 by kscordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

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

void	draw_filled_circle(t_img *data, int centre[2], int radius, int color)
{
	int	point[2];
	int	d;

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

void	draw_line_bis(t_img *data, t_geo geo, int steps, int color)
{
	int	i;

	i = -1;
	while (++i <= steps)
	{
		if (check_color_pix(data, round(geo.point[X]), round(geo.point[Y]), MINI_FLOOR_COLOR))
			break ;
		my_mlx_pixel_put(data, round(geo.point[X]), round(geo.point[Y]), color);
		geo.point[X] += geo.incremente[X];
		geo.point[Y] += geo.incremente[Y];
	}
}

void	draw_line_dda(t_img *data, int p1[2], int p2[2], int color)
{
	int		d[2];
	int		steps;
	t_geo	geo;

	d[X] = p2[X] - p1[X];
	d[Y] = p2[Y] - p1[Y];
	if (abs(d[X]) > abs(d[Y]))
		steps = abs(d[X]);
	else
		steps = abs(d[Y]);
	geo.incremente[X] = (float)d[X] / (float)steps;
	geo.incremente[Y] = (float)d[Y] / (float)steps;
	geo.point[X] = p1[X];
	geo.point[Y] = p1[Y];
	draw_line_bis(data, geo, steps, color);
}
