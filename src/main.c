/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <kscordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:09:34 by kvisouth          #+#    #+#             */
/*   Updated: 2024/01/12 18:51:58 by kscordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

t_img	load_texture(t_game *game, char *file)
{
	t_img	img;

	img.img = mlx_xpm_file_to_image(game->mlx, file,
			&img.width, &img.height);
	if (!img.img)
		return (img);
	img.addr = mlx_get_data_addr(img.img, \
	&img.bits_per_pixel, &img.line_length, &img.endian);
	return (img);
}

int	load_element(t_game *game)
{
	game->no = load_texture(game, game->parse.no);
	game->so = load_texture(game, game->parse.so);
	game->we = load_texture(game, game->parse.we);
	game->ea = load_texture(game, game->parse.ea);
	if (!game->ea.img || !game->we.img || !game->so.img || !game->no.img)
		return (perror("Error\nmlx_xpm_file_to_image"), 1);
	if (game->so.height != game->no.height || game->we.height != \
		game->ea.height || game->so.height != game->ea.height)
		return (ft_putstr_fd("Error\ndimensions des textures non egales\n", 2), 1);
	game->image.img = mlx_new_image(game->mlx, game->win.w, game->win.h);
	if (!game->image.img)
		return (perror("Error\nmlx_new_image"), 1);
	game->image.addr = mlx_get_data_addr(game->image.img, \
	&game->image.bits_per_pixel, &game->image.line_length, &game->image.endian);
	game->image.width = game->win.w;
	game->image.height = game->win.h;
	return (0);
}

int	init_struct(t_game *game)
{
	ft_bzero(game, sizeof(t_game));
	game->mlx = mlx_init();
	if (!game->mlx)
		return (free_elem(game), 1);
	mlx_get_screen_size(game->mlx, &game->win.w, &game->win.h);
	game->win.w /= 2;
	game->win.h -= 90;
	return (0);
}

int	main(int ac, char **av)
{
	t_game	game;

	if (init_struct(&game))
		return (1);
	if (ft_parse(ac, av, &game))
		return (free_all(&game), 1);
	if (load_element(&game))
		return (free_all(&game), 1);
	game.win.mlx_w = mlx_new_window(game.mlx, game.win.w, game.win.h, "cub3d");
	if (!game.win.mlx_w)
		return (free_all(&game), 1);
	init_dir(&game);
	mlx_loop_hook(game.mlx, the_game, &game);
	mlx_hook(game.win.mlx_w, 2, 1L << 0, key_down_hook, &game);
	mlx_hook(game.win.mlx_w, 3, 1L << 1, key_up_hook, &game);
	mlx_hook(game.win.mlx_w, 17, 1L << 0, quit, &game);
	mlx_loop(game.mlx);
	return (free_all(&game), 0);
}
