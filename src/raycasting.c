/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <kscordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:15:24 by kscordel          #+#    #+#             */
/*   Updated: 2023/12/05 21:02:13 by kscordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

//tout ce raycasting est fait pour la minimap

/*void	init(t_game *game, double ray_angle)
{
	ray_angle = 2 * PI;
	if (ray_angle < 0)
		ray_angle = (2 * PI) + ray_angle;
	
}*/

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
	while (i < game->image.width)
	{
		fin[X] = point[X] + cos(ray_angle) * MINI_SIZE * 2;
		fin[Y] = point[Y] + sin(ray_angle) * MINI_SIZE * 2;
		draw_line_dda(&game->image, point, fin, MINI_PERSO_COLOR);
		
		ray_angle += FOV / game->image.width;
		i++;
	}
}
