/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <kscordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 13:57:13 by kscordel          #+#    #+#             */
/*   Updated: 2024/01/12 13:21:52 by kscordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	init_raycasting(t_game *game, int x)
{
	game->ray.mapx = (int)game->ray.posx;
	game->ray.mapy = (int)game->ray.posy;
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
}

void	calculate_step(t_game *game)
{
	if (game->ray.raydirx < 0)
	{
		game->ray.xstep = -1;
		game->ray.sidedistx = (game->ray.posx - game->ray.mapx) \
			* game->ray.deltadistx;
	}
	else
	{
		game->ray.xstep = 1;
		game->ray.sidedistx = (game->ray.mapx + 1.0 - game->ray.posx) \
			* game->ray.deltadistx;
	}
	if (game->ray.raydiry < 0)
	{
		game->ray.ystep = -1;
		game->ray.sidedisty = (game->ray.posy - game->ray.mapy) \
			* game->ray.deltadisty;
	}
	else
	{
		game->ray.ystep = 1;
		game->ray.sidedisty = (game->ray.mapy + 1.0 - game->ray.posy) \
			* game->ray.deltadisty;
	}
}

void	dda_algorithme(t_game *game)
{
	while (true)
	{
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
		if (game->map.map[game->ray.mapy][game->ray.mapx] == '1')
			break ;
	}
	if (game->ray.side == 0)
		game->ray.perpwalldist = game->ray.sidedistx - game->ray.deltadistx;
	else
		game->ray.perpwalldist = game->ray.sidedisty - game->ray.deltadisty;
}

void	raycasting(t_game *game)
{
	int	x;

	x = 0;
	while (x < game->image.width)
	{
		init_raycasting(game, x);
		calculate_step(game);
		dda_algorithme(game);
		randering(game, x);
		x++;
	}
}
