/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_move_perso.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <kscordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:15:31 by kscordel          #+#    #+#             */
/*   Updated: 2024/01/02 16:42:35 by kscordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	straight_or_backward(t_game *game)
{
	double	tmp;

	if (game->mouv.go_straigth)
	{
		tmp = cos(game->ray.rotation_angle) * MOUV_SPEED;
		if (game->map.map[(int)game->ray.posy][(int)(game->ray.posx + tmp)] \
			!= '1')
			game->ray.posx += tmp;
		tmp = sin(game->ray.rotation_angle) * MOUV_SPEED;
		if (game->map.map[(int)(game->ray.posy + tmp)][(int)game->ray.posx] \
			!= '1')
			game->ray.posy += tmp;
	}
	if (game->mouv.go_backward)
	{
		tmp = cos(game->ray.rotation_angle) * -MOUV_SPEED;
		if (game->map.map[(int)game->ray.posy][(int)(game->ray.posx + tmp)] \
			!= '1')
			game->ray.posx += tmp;
		tmp = sin(game->ray.rotation_angle) * -MOUV_SPEED;
		if (game->map.map[(int)(game->ray.posy + tmp)][(int)game->ray.posx] \
			!= '1')
			game->ray.posy += tmp;
	}
}

void	right_or_left(t_game *game)
{
	double	tmp;

	if (game->mouv.go_left)
	{
		tmp = cos(game->ray.rotation_angle - (PI / 2)) * MOUV_SPEED ;
		if (game->map.map[(int)game->ray.posy][(int)(game->ray.posx + tmp)] \
			!= '1')
			game->ray.posx += tmp;
		tmp = sin(game->ray.rotation_angle - (PI / 2)) * MOUV_SPEED;
		if (game->map.map[(int)(game->ray.posy + tmp)][(int)game->ray.posx] \
			!= '1')
			game->ray.posy += tmp;
	}
	if (game->mouv.go_right)
	{
		tmp = cos(game->ray.rotation_angle + (PI / 2)) * MOUV_SPEED ;
		if (game->map.map[(int)game->ray.posy][(int)(game->ray.posx + tmp)] \
			!= '1')
			game->ray.posx += tmp;
		tmp = sin(game->ray.rotation_angle + (PI / 2)) * MOUV_SPEED;
		if (game->map.map[(int)(game->ray.posy + tmp)][(int)game->ray.posx] \
			!= '1')
			game->ray.posy += tmp;
	}
}

void	update_move_perso(t_game *game)
{
	if (game->mouv.rotate_left)
		game->ray.rotation_angle += -2 * ROTATION_SPEED;
	if (game->mouv.rotate_right)
		game->ray.rotation_angle += 2 * ROTATION_SPEED;
	straight_or_backward(game);
	right_or_left(game);
}

int	key_down_hook(int key, t_game *game)
{
	//printf("key = %d\n", key);
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
