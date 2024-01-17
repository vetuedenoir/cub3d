/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <kscordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 18:10:18 by kscordel          #+#    #+#             */
/*   Updated: 2024/01/12 13:28:43 by kscordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	define_size_of_line(t_game *game)
{
	game->ray.line_height = (int)(game->image.height / game->ray.perpwalldist);
	game->ray.draw_start = -game->ray.line_height / 2 + game->image.height / 2;
	if (game->ray.draw_start < 0)
		game->ray.draw_start = 0;
	game->ray.draw_end = game->ray.line_height / 2 + game->image.height / 2;
	if (game->ray.draw_end >= game->image.height)
		game->ray.draw_end = game->image.height -1;
}

void	get_line_texture(t_game *game)
{
	if (game->ray.side == 0)
		game->ray.wallx = game->ray.posy + game->ray.perpwalldist * \
			game->ray.raydiry;
	else
		game->ray.wallx = game->ray.posx + game->ray.perpwalldist * \
			game->ray.raydirx;
	game->ray.wallx -= floor(game->ray.wallx);
	game->ray.textx = (game->ray.wallx * game->so.width);
	if (game->ray.side == 0 && game->ray.dirx > 0)
		game->ray.textx = game->so.width - game->ray.textx - 1;
	if (game->ray.side == 1 && game->ray.diry < 0)
		game->ray.textx = game->so.width - game->ray.textx - 1;
	game->ray.step = 1.0 * game->so.width / game->ray.line_height;
	game->ray.textpos = (game->ray.draw_start - game->image.height / 2 + \
		game->ray.line_height / 2) * game->ray.step;
}

void	search_and_draw(t_game *game, t_img *texture, int x)
{
	int	height;

	x *= (game->image.bits_per_pixel / 8);
	game->ray.textx *= (texture->bits_per_pixel / 8);
	game->ray.draw_start *= game->image.line_length;
	game->ray.draw_end *= game->image.line_length;
	game->ray.textpos *= texture->line_length;
	height = (game->so.height - 1) * texture->line_length;
	game->ray.step *=  texture->line_length;
	while (game->ray.draw_start <= game->ray.draw_end)
	{
		game->ray.texty = ((int)game->ray.textpos & height);
		game->ray.textpos += game->ray.step;
		*(int *)(game->image.addr + game->ray.draw_start + x) = \
			*(int *)(texture->addr + game->ray.texty + game->ray.textx);
		game->ray.draw_start += game->image.line_length;
	}
}

void	randering(t_game *game, int x)
{
	define_size_of_line(game);
	get_line_texture(game);
	if (game->ray.side == 1 && game->ray.raydiry < 0)
		search_and_draw(game, &game->so, x);
	else if (game->ray.side == 1 && game->ray.raydiry > 0)
		search_and_draw(game, &game->no, x);
	else if (game->ray.side == 0 && game->ray.raydirx < 0)
		search_and_draw(game, &game->we, x);
	else if (game->ray.side == 0 && game->ray.raydirx > 0)
		search_and_draw(game, &game->ea, x);
}
