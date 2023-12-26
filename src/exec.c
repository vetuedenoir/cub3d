/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <kscordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:15:38 by kscordel          #+#    #+#             */
/*   Updated: 2023/12/05 13:19:28 by kscordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	update_move_perso(t_game *game)
{
	double	tmp;

	if (game->mouv.rotate_left)
		game->ray.rotation_angle += -2 * ROTATION_SPEED;
	if (game->mouv.rotate_right)
		game->ray.rotation_angle += 2 * ROTATION_SPEED;
	if (game->mouv.go_straigth)
	{
		tmp = cos(game->ray.rotation_angle) * MOUV_SPEED;
		if (game->map.map[(int)game->ray.posy][(int)(game->ray.posx + tmp)] != '1')
			game->ray.posx += tmp;
		tmp = sin(game->ray.rotation_angle) * MOUV_SPEED;
		if (game->map.map[(int)(game->ray.posy + tmp)][(int)game->ray.posx] != '1')
			game->ray.posy += tmp;
	}
	if (game->mouv.go_backward)
	{
		tmp = cos(game->ray.rotation_angle) * -MOUV_SPEED;
		if (game->map.map[(int)game->ray.posy][(int)(game->ray.posx + tmp)] != '1')
			game->ray.posx += tmp;
		tmp = sin(game->ray.rotation_angle) * -MOUV_SPEED;
		if (game->map.map[(int)(game->ray.posy + tmp)][(int)game->ray.posx] != '1')
			game->ray.posy += tmp;
	}
	if (game->mouv.go_left)
	{
		tmp = cos(game->ray.rotation_angle - (PI / 2)) * MOUV_SPEED ;
		if (game->map.map[(int)game->ray.posy][(int)(game->ray.posx + tmp)] != '1')
			game->ray.posx += tmp;
		tmp = sin(game->ray.rotation_angle - (PI / 2)) * MOUV_SPEED;
		if (game->map.map[(int)(game->ray.posy + tmp)][(int)game->ray.posx] != '1')
			game->ray.posy += tmp;
	}
	if (game->mouv.go_right)
	{
		tmp = cos(game->ray.rotation_angle + (PI / 2)) * MOUV_SPEED ;
		if (game->map.map[(int)game->ray.posy][(int)(game->ray.posx + tmp)] != '1')
			game->ray.posx += tmp;
		tmp = sin(game->ray.rotation_angle + (PI / 2)) * MOUV_SPEED;
		if (game->map.map[(int)(game->ray.posy + tmp)][(int)game->ray.posx] != '1')
			game->ray.posy += tmp;
	}
}

void	back_ground(t_game *game)
{
	int	i;
	int	max;
	int	middle;
	int	floor;
	int	ceil;

	i = 0;
	max = game->win.h  * game->win.w;
	middle = max / 2;
	ceil = makecolor(255, game->ceil.r, game->ceil.g, game->ceil.b);
	floor = makecolor(255, game->floor.r, game->floor.g, game->floor.b);
	while (i < middle)
		*(unsigned int *)(game->image.addr + i++ * game->image.bits_per_pixel / 8) = ceil;
	while (i < max)
		*(unsigned int *)(game->image.addr + i++ * game->image.bits_per_pixel / 8) = floor;
}

void two_dim(t_game *game)
{	
	draw_map(game);
	draw_perso(game);
	raycasting_2d(game);
}

int the_game(t_game *game)
{
	update_move_perso(game);
	back_ground(game);
	two_dim(game);
	
	mlx_put_image_to_window(game->mlx, game->win.mlx_w, game->image.img, 0, 0);
	//printf("w = %d et h = %d\n",game->image.width, game->image.height);
	return (0);
}