/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <kscordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:15:31 by kscordel          #+#    #+#             */
/*   Updated: 2023/12/05 13:15:32 by kscordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

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
