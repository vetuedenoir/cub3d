/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <kscordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 13:57:13 by kscordel          #+#    #+#             */
/*   Updated: 2024/01/09 18:53:07 by kscordel         ###   ########.fr       */
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

//	printf("camerax = %lf\n", game->ray.camerax);
//	printf("raydirx = %lf raydiy = %lf\n", game->ray.raydirx, game->ray.dirx);
//	printf("deltadistx = %lf et deltadisty = %lf\n", game->ray.deltadistx, game->ray.deltadisty);
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
	//printf("xstep = %lf et y step =%lf \n", game->ray.xstep, game->ray.ystep);
	//printf("avant map X = %d , map Y = %d\n", game->ray.mapx, game->ray.mapy);
	while (true)
	{
	//	printf("sidedistance X = %lf , sidedistance Y = %lf\n", game->ray.sidedistx, game->ray.sidedisty);
		
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
		//printf("map X = %d , map Y = %d\n", game->ray.mapx, game->ray.mapy);

		/*if (game->ray.mapx <= 0 || game->ray.mapx >= game->map.map_width || \
			game->ray.mapy <= 0 || game->ray.mapy >= game->map.map_height || \
			(game->map.map[game->ray.mapx][game->ray.mapy] != '0' && game->map.map[game->ray.mapx][game->ray.mapy] != 'N'))*/
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
	//printf(" position X = %lf , position Y = %lf    x = %d\n", game->ray.posx, game->ray.posy, x);
	while (x < game->image.width)
	{
		game->ray.mapx = (int)game->ray.posx;
		game->ray.mapy = (int)game->ray.posy;
		//printf(" in boucle map X = %d , map Y = %d    x = %d\n", game->ray.mapx, game->ray.mapy, x);
		init_raycasting(game, x);
		calculate_step(game);
		dda_algorithme(game);
		//randering(game, x);
		x++;
	}
}