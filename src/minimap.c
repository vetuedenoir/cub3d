/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <kscordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:15:16 by kscordel          #+#    #+#             */
/*   Updated: 2024/01/12 13:34:58 by kscordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
#include "limits.h"

void	define_midl(t_game *game, long double *x, long double *y)
{
	*x = 0;
	*y = 0;
	if (game->ray.posy > (MINI_T / 2))
		*y = game->ray.posy - (MINI_T / 2);
	else
		*y = 0;
	if (game->ray.posx > (MINI_T / 2))
		*x = game->ray.posx - (MINI_T / 2);
	else
		*x = 0;
	if (MINI_T < game->map.map_height)
	{
		if (MINI_T + *y > game->map.map_height)
		*y = game->map.map_height - MINI_T;
	}
	if (MINI_T < game->map.map_width)
	{
		if (MINI_T + *x > game->map.map_width)
		*x = game->map.map_width - MINI_T;
	}
}

void	define_mid(t_game *game, double *x, double *y)
{
	*x = 0;
	*y = 0;
	if (game->ray.posy > (MINI_T / 2))
		*y = game->ray.posy - (MINI_T / 2);
	else
		*y = 0;
	if (game->ray.posx > (MINI_T / 2))
		*x = game->ray.posx - (MINI_T / 2);
	else
		*x = 0;
	if (MINI_T < game->map.map_height)
	{
		if (MINI_T + *y > game->map.map_height)
		*y = game->map.map_height - MINI_T;
	}
	if (MINI_T < game->map.map_width)
	{
		if (MINI_T + *x > game->map.map_width)
		*x = game->map.map_width - MINI_T;
	}
}

void	draw_perso(t_game *game)
{
	double	point[2];
	int		p[2];
	double	xs;
	double	ys;

	xs = 0;
	ys = 0;
	define_mid(game, &xs, &ys);
	point[X] = (game->ray.posx - xs) * MINI_BLOCK;
	point[Y] = (game->ray.posy - ys) * MINI_BLOCK;
	p[X] = (int)point[X];
	p[Y] = (int)point[Y];
	draw_filled_circle(&game->image, p, 5, MINI_PERSO_COLOR);
}

void	draw_map(t_game *game)
{
	long double	x;
	long double	y;
	long double	xs;
	long double	ys;
	double		ratio;

	ratio = 1.0 / (double)MINI_BLOCK;
	define_midl(game, &xs, &ys);
	x = xs;
	y = ys;
	while (game->map.map[(int)y] && y - ys < MINI_T)
	{
		x = xs;
		while (game->map.map[(int)y][(int)floor(x)] && x - xs < MINI_T)
		{			
			if (game->map.map[(int)y][(int)x] == '1')
				my_mlx_pixel_put(&game->image, (x - xs) * MINI_BLOCK, \
					(y - ys) * MINI_BLOCK, MINI_WALL_COLOR);
			else if (game->map.map[(int)y][(int)x] == '0')
				my_mlx_pixel_put(&game->image, (x - xs) * MINI_BLOCK, \
					(y - ys) * MINI_BLOCK, MINI_FLOOR_COLOR);
			x += ratio;
		}
		y += ratio;
	}
}
