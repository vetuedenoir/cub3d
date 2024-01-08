/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <kscordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 13:57:13 by kscordel          #+#    #+#             */
/*   Updated: 2024/01/08 19:51:01 by kscordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	init_raycasting(t_game *game, int x)
{
	game->ray.camerax = 2 * x / (double)game->image.width - 1;
	game->ray.raydirx = game->ray.dirx + game->ray.planex * game->ray.camerax;
	game->ray.raydiry = game->ray.diry + game->ray.planey * game->ray.camerax;
	if (game->ray.raydirx == 0)
		game->ray.deltadistx = INT_MAX;
	else
		game->ray.deltadistx = fabs(1 / game->ray.raydirx);
	if (game->ray.raydiry == 0)
		game->ray.deltadisty = INT_MAX;
	else
		game->ray.deltadisty = fabs(1 / game->ray.raydiry);

	printf("camerax = %lf\n", game->ray.camerax);
	printf("raydirx = %lf raydiy = %lf\n", game->ray.raydirx, game->ray.dirx);
	printf("deltadistx = %lf et deltadisty = %lf\n", game->ray.deltadistx, game->ray.deltadisty);
}

void	calculate_step(t_game *game)
{
	if (game->ray.raydirx < 0)
	{
		game->ray.xstep = -1;
		game->ray.sidedistx = (game->ray.posy - game->ray.mapx) \
			* game->ray.deltadistx;
	}
	else
	{
		game->ray.xstep = 1;
		game->ray.sidedistx = (game->ray.mapx + 1.0 - game->ray.posy) \
			* game->ray.deltadistx;
	}
	if (game->ray.raydiry < 0)
	{
		game->ray.ystep = -1;
		game->ray.sidedisty = (game->ray.posx - game->ray.mapy) \
			* game->ray.deltadisty;
	}
	else
	{
		game->ray.ystep = 1;
		game->ray.sidedisty = (game->ray.mapy + 1.0 - game->ray.posx) \
			* game->ray.deltadisty;
	}
}

void	dda_algorithme(t_game *game)
{
	printf("xstep = %lf et y step =%lf \n", game->ray.xstep, game->ray.ystep);
	while (true)
	{
		printf("sidedistance X = %lf , sidedistance Y = %lf\n", game->ray.sidedistx, game->ray.sidedisty);
		printf("map X = %d , map Y = %d\n", game->ray.mapx, game->ray.mapy);
		if (game->ray.sidedistx < game->ray.sidedisty)
		{
			game->ray.sidedistx += game->ray.deltadistx;
			game->ray.mapx += game->ray.xstep;
			game->ray.side = 0;
		}
		else
		{
			game->ray.sidedisty += game->ray.deltadisty;
			game->ray.mapy += game->ray.ystep;
			game->ray.side = 1;	
		}
		printf("map X = %d , map Y = %d\n", game->ray.mapx, game->ray.mapy);

		/*if (game->ray.mapx <= 0 || game->ray.mapx >= game->map.map_width || \
			game->ray.mapy <= 0 || game->ray.mapy >= game->map.map_height || \
			(game->map.map[game->ray.mapx][game->ray.mapy] != '0' && game->map.map[game->ray.mapx][game->ray.mapy] != 'N'))*/
		if (game->map.map[game->ray.mapx][game->ray.mapy] == '1')
			break ;
	}
	if (game->ray.side == 0)
		game->ray.perpwalldist = game->ray.sidedistx - game->ray.deltadistx;
	else
		game->ray.perpwalldist = game->ray.sidedisty - game->ray.deltadisty;
}

void	randering(t_game *game, int x)
{
	int	pitch;
	int	v;

	pitch = 100;
	(void)pitch;
	game->ray.line_height = (int)(game->image.height / game->ray.perpwalldist);
	game->ray.draw_start = -game->ray.line_height / 2 + game->image.height / 2;
	if (game->ray.draw_start < 0)
		game->ray.draw_start = 0;
	 game->ray.draw_end = game->ray.line_height / 2 + game->image.height / 2;
	if (game->ray.draw_end >= game->image.height)
		game->ray.draw_end = game->image.height -1;
	v = game->ray.draw_start;
	while (v <= game->ray.draw_end)
	{
		my_mlx_pixel_put(&game->image, x, v, 0xFF33FF);
		v++;
	}
}

void	raycasting(t_game *game)
{
	int	x;

	x = 0;
	while (x < game->image.width)
	{
		game->ray.mapx = (int)game->ray.posy;
		game->ray.mapy = (int)game->ray.posx;
		init_raycasting(game, x);
		calculate_step(game);
		dda_algorithme(game);
		randering(game, x);
		x++;
	}
}