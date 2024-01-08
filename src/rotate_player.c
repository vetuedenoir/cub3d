/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <kscordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:42:18 by kscordel          #+#    #+#             */
/*   Updated: 2024/01/08 19:51:51 by kscordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	rotate_left(t_game *game)
{
	double	old_dirx;
	double	old_planex;

	old_dirx = game->ray.dirx;
	old_planex = game->ray.planex;
	game->ray.dirx = game->ray.dirx * cos(-ROTATION_SPEED)
		- game->ray.diry * sin(-ROTATION_SPEED);
	game->ray.diry = old_dirx * sin(-ROTATION_SPEED)
		+ game->ray.diry * cos(-ROTATION_SPEED);
	game->ray.planex = game->ray.planex * cos(-ROTATION_SPEED)
		- game->ray.planey * sin(-ROTATION_SPEED);
	game->ray.planey = old_planex * sin(-ROTATION_SPEED)
		+ game->ray.planey * cos(-ROTATION_SPEED);
}

void	rotate_right(t_game *game)
{
	double	old_dirx;
	double	old_planex;

	old_dirx = game->ray.dirx;
	old_planex = game->ray.planex;
	game->ray.dirx = game->ray.dirx * cos(ROTATION_SPEED)
		- game->ray.diry * sin(ROTATION_SPEED);
	game->ray.diry = old_dirx * sin(ROTATION_SPEED)
		+ game->ray.diry * cos(ROTATION_SPEED);
	game->ray.planex = game->ray.planex * cos(ROTATION_SPEED)
		- game->ray.planey * sin(ROTATION_SPEED);
	game->ray.planey = old_planex * sin(ROTATION_SPEED)
		+ game->ray.planey * cos(ROTATION_SPEED);
}

int	move_front(t_game *game)
{
	if (game->map.map[(int)(game->ray.posy + game->ray.diry \
			* MOUV_SPEED)][(int)game->ray.posx] != '1')
		game->ray.posy += game->ray.diry * MOUV_SPEED;
	if (game->map.map[(int)game->ray.posy][(int)(game->ray.posx + game->ray.dirx \
		* MOUV_SPEED)] != '1')
		game->ray.posx += game->ray.dirx * MOUV_SPEED;
	return (0);
}

int	move_back(t_game *game)
{
	if (game->map.map[(int)(game->ray.posy - game->ray.diry
			* MOUV_SPEED)][(int)game->ray.posx] != '1')
		game->ray.posy -= game->ray.diry * MOUV_SPEED;
	if (game->map.map[(int)game->ray.posy][(int)(game->ray.posx - game->ray.dirx
		* MOUV_SPEED)] != '1')
		game->ray.posx -= game->ray.dirx * MOUV_SPEED;
	//printf("move_back raydirx = %lf et raydiy = %lf\n", game->ray.dirx, game->ray.diry);
	return (0);
}

int	move_left(t_game *game)
{
	if (game->map.map[(int)(game->ray.posy - game->ray.planey
			* MOUV_SPEED)][(int)game->ray.posx] != '1')
		game->ray.posy -= game->ray.planey * MOUV_SPEED;
	if (game->map.map[(int)game->ray.posy][(int)(game->ray.posx - game->ray.planex
		* MOUV_SPEED)] != '1')
		game->ray.posx -= game->ray.planex * MOUV_SPEED;
	return (0);
}

int	move_right(t_game *game)
{
	if (game->map.map[(int)(game->ray.posy + game->ray.planey
			* MOUV_SPEED)][(int)game->ray.posx] != '1')
		game->ray.posy += game->ray.planey * MOUV_SPEED;
	if (game->map.map[(int)game->ray.posy][(int)(game->ray.posx + game->ray.planex
		* MOUV_SPEED)] != '1')
		game->ray.posx += game->ray.planex * MOUV_SPEED;
	return (0);
}