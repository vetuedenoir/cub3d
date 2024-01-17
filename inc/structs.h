/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <kscordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:30:41 by kvisouth          #+#    #+#             */
/*   Updated: 2024/01/12 15:08:19 by kscordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <stdbool.h>
// t_rgb contains the 3 colors of the rgb format.
// It is for the ceiling and the floor arguments.
typedef struct s_rgb
{
	int		r;
	int		g;
	int		b;
}				t_rgb;

typedef struct s_geo
{
	double	point[2];
	double	incremente[2];
}	t_geo;

// t_map contains all the informations about the map.
// (The map is all the 1, 0 and N S E or W)
typedef struct s_map
{
	char		**map;
	int			map_start;
	int			map_end;
	int			map_width;
	int			map_height;
}				t_map;

// t_parse contains all the informations about the parsing.
// elem_lines is an array of int.
// elem_lines[0] is the line in the file where the NO argument is.
// elem_lines[1] is the same for SO.
// all the way with this order: NO (0), SO (1), WE (2), EA (3), F (4), C (5).
// last_elem is the last element parsed. (the line it's located in)
// it's the lower (in lines) of the arguments.
// it's the closest element to the map.
typedef struct s_parse
{
	int			elem_lines[6];
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	int			last_elem;
	int			last_line;
	char		**file_cont;
}				t_parse;

// t_win contains all the informations about the window./
// mlx_w is the mlx window.
// w is the width of the window.
// h is the height of the window.
// (Line too long norm issues)

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		height;
	int		width;
}		t_img;

typedef struct s_win
{
	void	*mlx_w;
	int		w;
	int		h;
}				t_win;

typedef struct s_mouv
{
	bool	go_straigth;
	bool	go_backward;
	bool	go_left;
	bool	go_right;
	bool	rotate_left;
	bool	rotate_right;
}			t_mouv;

typedef struct s_ray
{
	double	rotation_angle;
	double	posx;
	double	posy;
	int		mapx;
	int		mapy;
	double	ystep;
	double	xstep;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
	double	raydirx;
	double	raydiry;
	double	camerax;
	double	sidedistx;
	double	sidedisty;
	double	deltadistx;
	double	deltadisty;
	double	wallx;
	double	wally;
	int		textx;
	int		texty;
	float	step;
	float	textpos;
	int		side;
	int		draw_start;
	int		draw_end;
	int		line_height;
	double	perpwalldist;
}			t_ray;

// t_game is the main strucure.
// it includes all the others structures.
typedef struct s_game
{
	void		*mlx;
	t_win		win;
	t_img		no;
	t_img		so;
	t_img		we;
	t_img		ea;
	t_img		image;
	t_rgb		floor;
	t_rgb		ceil;
	t_ray		ray;
	t_mouv		mouv;
	t_map		map;
	t_parse		parse;
	char		orient;
	bool		is_a_map;
}				t_game;

#endif
