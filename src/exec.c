/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <kscordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:15:38 by kscordel          #+#    #+#             */
/*   Updated: 2024/01/08 18:12:21 by kscordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	back_ground(t_game *game)
{
	int	i;
	int	max;
	int	middle;
	int	floor;
	int	ceil;

	i = 0;
	max = game->win.h * game->win.w;
	middle = max / 2;
	ceil = makecolor(255, game->ceil.r, game->ceil.g, game->ceil.b);
	floor = makecolor(255, game->floor.r, game->floor.g, game->floor.b);
	while (i < middle)
		*(unsigned int *)(game->image.addr + i++ *\
			game->image.bits_per_pixel / 8) = ceil;
	while (i < max)
		*(unsigned int *)(game->image.addr + i++ *\
			game->image.bits_per_pixel / 8) = floor;
}

void	mini_map(t_game *game)
{	
	draw_map(game);
	draw_perso(game);
	raycasting_2d(game);
}

/*long	gettime(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000000) + (time.tv_usec));
}

int	the_game(t_game *game)
{
	static long time = 0;
	long tt;
	long dif;

	tt  = gettime();
	dif = tt - time;
	printf("dif = %ld\n", dif);
	if (dif < TICS)
		usleep((TICS - dif));
	time = tt;
	update_move_perso(game);
	back_ground(game);
	raycasting(game);
	if (game->is_a_map)
		mini_map(game);
	mlx_put_image_to_window(game->mlx, game->win.mlx_w, game->image.img, 0, 0);
	return (0);
}*/

int	the_game(t_game *game)
{
	update_move_perso(game);
	back_ground(game);
	raycasting(game);
	if (game->is_a_map)
		mini_map(game);
	mlx_put_image_to_window(game->mlx, game->win.mlx_w, game->image.img, 0, 0);
	return (0);
}

