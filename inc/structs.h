/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <kscordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:30:41 by kvisouth          #+#    #+#             */
/*   Updated: 2023/12/05 20:59:48 by kscordel         ###   ########.fr       */
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



// structure a utiliser si on veut utiliser les fonctions check_correct_paths et load_element 
/*typedef struct s_parse
{
	char		*no;
	char		*so;
	char		*we;
	char		*ea;
	char		**file_cont;
}				t_parse;
*/
// t_map contains all the informations about the map.
// (The map is all the 1, 0 and N S E or W)
typedef struct s_map
{
	char		**map;
	int			map_width;
	int			map_height;
}				t_map;

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

// t_win contains all the informations about the window./
// mlx_w is the mlx window.
// w is the width of the window.
// h is the height of the window.
// (Line too long norm issues)

typedef struct s_win
{
	void	*mlx_w;
	int		w;
	int		h;
}				t_win;

typedef struct	s_mouv
{
	bool	go_straigth;
	bool	go_backward;
	bool	go_left;
	bool	go_right;
	int		rotate_dir;
	bool	rotate_left;
	bool	rotate_right;
}			t_mouv;

typedef struct s_ray
{
	double	rotation_angle;
	double	posx;
	double	posy;
	double	ystep;
	double	xstep;
	double	xintercept; //le premier point
	double	yintercept;	
	double	wallx;
	double	wally;
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
	char		orient;
}				t_game;

#endif