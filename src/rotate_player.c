/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_player.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <kscordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 11:42:18 by kscordel          #+#    #+#             */
/*   Updated: 2024/01/12 13:59:27 by kscordel         ###   ########.fr       */
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

void	init_dir2(t_game *game)
{
	if (game->ray.diry == -1)
		game->ray.planex = 0.66;
	else if (game->ray.diry == 1)
		game->ray.planex = -0.66;
	else if (game->ray.dirx == -1)
		game->ray.planey = -0.66;
	else if (game->ray.dirx == 1)
		game->ray.planey = 0.66;
}

void	init_dir(t_game *game)
{
	if (game->orient == 'N')
	{
		game->ray.rotation_angle = PI * 1.5;
		game->ray.diry = -1;
	}
	else if (game->orient == 'S')
	{
		game->ray.rotation_angle = PI / 2;
		game->ray.diry = 1;
	}
	else if (game->orient == 'E')
	{
		game->ray.rotation_angle = 0;
		game->ray.dirx = 1;
	}
	else if (game->orient == 'W')
	{
		game->ray.rotation_angle = PI;
		game->ray.dirx = -1;
	}
	init_dir2(game);
}
