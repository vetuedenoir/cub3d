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