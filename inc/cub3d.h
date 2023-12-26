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

# include "../libft/inc/libft.h"
# include "../libft/inc/get_next_line.h"
# include "../libft/inc/ft_printf.h"
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
int		parse_map_info(t_game *game);
void	skip_lines(int fd);
void	skip_lines_end(int fd);
void	skip_spaces(char *line, int *i);
int		parse_rgb(char *str, t_game *game, char *elem);
void	set_line(char *elem, t_game *game, int i);

// void	init_t_parse(t_game *game);

int		check_empty_lines(t_game *game);
int		check_correct_paths(t_game *game);
void	parse_error_msg(void);
int		parse_map(t_game *game);
int		check_map(t_game *game);
int		check_player(t_game *game);
void	skip_newlines(t_game *game, int *i);
int		is_empty_line2(t_game *game, int i);
int		is_empty_line(t_game *game, int i);
int		get_map_size(t_game *game, int i);
int		get_width_of_map(t_game *game);
int		only_empty_lines_left(t_game *game, int i);

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
//void draw_filled_circle(t_img *data, int xc, int yc, int radius, int color);
//void draw_line_dda(t_img *data, int x1, int y1, int x2, int y2, int color);

void draw_filled_circle(t_img *data, int centre[2], int radius, int color);
void draw_line_dda(t_img *data, int p1[2], int p2[2], int color);

//minimap
void draw_map(t_game *game);
void draw_perso(t_game *game);



#endif