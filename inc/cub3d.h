/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <kscordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:21:53 by kvisouth          #+#    #+#             */
/*   Updated: 2023/12/05 13:22:34 by kscordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// Allowed functions :
// open, close, read, write, printf, malloc
// free, perror, strerror, exit
// all the lib math (-lm man man 3 math)
// all the mlx functions

# include "../libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include "defines.h"
# include "structs.h"

# include <math.h>      // libmath
# include <stdio.h>     // printf
# include <stdlib.h>    // malloc, free, exit
# include <unistd.h>    // open, read, write, close
# include <sys/stat.h>
# include <fcntl.h>
# include <string.h>    // strerror
# include <errno.h>     // perror


// PARSING FUNCTIONS
int		ft_parse(int ac, char **av, t_game *game);
int		argument_check(int ac, char **av);
void	skip_lines(int fd);
void	skip_lines_end(int fd);

// void	init_t_parse(t_game *game);



// hook
int	key_hook(int key, t_game *game);
int	quit(t_game *game);
int	key_down_hook(int key, t_game *game);
int	key_up_hook(int key, t_game *game);

// clean the structure
void	free_array(char	**array);
void	free_elem(t_game *game);
void	free_mlx(t_game *game);
void	free_all(t_game *game);

// exec
int the_game(t_game *game);
void	define_mid(t_game *game, double *x, double *y);

// raycasting
void	raycasting_2d(t_game *game);

// put_pixel
int	makecolor(int t, int red, int green, int blue);
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);
int	check_color_pix(t_img *data, int x, int y, int color);

//forme_geometric
void draw_filled_circle(t_img *data, int centre[2], int radius, int color);
void draw_line_dda(t_img *data, int p1[2], int p2[2], int color);

//minimap
void draw_map(t_game *game);
void draw_perso(t_game *game);



#endif