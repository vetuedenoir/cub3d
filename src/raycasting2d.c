/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting2d.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <kscordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 13:57:04 by kscordel          #+#    #+#             */
/*   Updated: 2024/01/05 16:33:03 by kscordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

//tout ce raycasting est fait pour la minimap

void	raycasting_2d(t_game *game)
{
	double	ray_angle;
	int		i;
	int		point[2];
	int		fin[2];
	double	mid[2];

	define_mid(game, &mid[X], &mid[Y]);
	point[X] = (game->ray.posx - mid[X]) * MINI_BLOCK;
	point[Y] = (game->ray.posy - mid[Y]) * MINI_BLOCK;
	ray_angle = game->ray.rotation_angle - (FOV / 2);
	i = 0;
	while (i < game->image.width / 100)
	{
		fin[X] = point[X] + cos(ray_angle) * MINI_SIZE * 2;
		fin[Y] = point[Y] + sin(ray_angle) * MINI_SIZE * 2;
		draw_line_dda(&game->image, point, fin, MINI_PERSO_COLOR);
		ray_angle += FOV / game->image.width * 100;
		i++;
	}
}
