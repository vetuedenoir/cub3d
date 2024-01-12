/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_move_perso.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <kscordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:15:31 by kscordel          #+#    #+#             */
/*   Updated: 2024/01/12 13:58:16 by kscordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	straight_or_backward(t_game *game)
{
	if (game->mouv.go_straigth)
	{
		if (game->map.map[(int)(game->ray.posy + game->ray.diry \
			* MOUV_SPEED)][(int)game->ray.posx] != '1')
			game->ray.posy += game->ray.diry * MOUV_SPEED;
		if (game->map.map[(int)game->ray.posy][(int)(game->ray.posx + \
			game->ray.dirx * MOUV_SPEED)] != '1')
			game->ray.posx += game->ray.dirx * MOUV_SPEED;
	}
	if (game->mouv.go_backward)
	{
		if (game->map.map[(int)(game->ray.posy - game->ray.diry \
			* MOUV_SPEED)][(int)game->ray.posx] != '1')
			game->ray.posy -= game->ray.diry * MOUV_SPEED;
		if (game->map.map[(int)game->ray.posy][(int)(game->ray.posx - \
			game->ray.dirx * MOUV_SPEED)] != '1')
			game->ray.posx -= game->ray.dirx * MOUV_SPEED;
	}
}

void	right_or_left(t_game *game)
{
	if (game->mouv.go_left)
	{
		if (game->map.map[(int)(game->ray.posy - game->ray.planey \
			* MOUV_SPEED)][(int)game->ray.posx] != '1')
			game->ray.posy -= game->ray.planey * MOUV_SPEED;
		if (game->map.map[(int)game->ray.posy][(int)(game->ray.posx - \
			game->ray.planex * MOUV_SPEED)] != '1')
			game->ray.posx -= game->ray.planex * MOUV_SPEED;
	}
	if (game->mouv.go_right)
	{
		if (game->map.map[(int)(game->ray.posy + game->ray.planey \
			* MOUV_SPEED)][(int)game->ray.posx] != '1')
			game->ray.posy += game->ray.planey * MOUV_SPEED;
		if (game->map.map[(int)game->ray.posy][(int)(game->ray.posx + \
			game->ray.planex * MOUV_SPEED)] != '1')
			game->ray.posx += game->ray.planex * MOUV_SPEED;
	}
}

void	update_move_perso(t_game *game)
{
	if (game->mouv.rotate_left)
	{
		game->ray.rotation_angle += -1 * ROTATION_SPEED;
		rotate_left(game);
	}
	if (game->mouv.rotate_right)
	{
		game->ray.rotation_angle += 1 * ROTATION_SPEED;
		rotate_right(game);
	}
	straight_or_backward(game);
	right_or_left(game);
}

int	key_down_hook(int key, t_game *game)
{
	if (key == ECHAP)
		quit(game);
	if (key == K_LEFT)
		game->mouv.rotate_left = true;
	if (key == K_RIGHT)
		game->mouv.rotate_right = true;
	if (key == K_UP || key == K_W)
		game->mouv.go_straigth = true;
	if (key == K_DOWN || key == K_S)
		game->mouv.go_backward = true;
	if (key == K_A)
		game->mouv.go_left = true;
	if (key == K_D)
		game->mouv.go_right = true;
	return (0);
}

int	key_up_hook(int key, t_game *game)
{
	if (key == K_LEFT)
		game->mouv.rotate_left = false;
	if (key == K_RIGHT)
		game->mouv.rotate_right = false;
	if (key == K_UP || key == K_W)
		game->mouv.go_straigth = false;
	if (key == K_DOWN || key == K_S)
		game->mouv.go_backward = false;
	if (key == K_A)
		game->mouv.go_left = false;
	if (key == K_D)
		game->mouv.go_right = false;
	return (0);
}
