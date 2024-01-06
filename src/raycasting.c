/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <kscordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 13:57:13 by kscordel          #+#    #+#             */
/*   Updated: 2024/01/06 17:22:09 by kscordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

double	init_Angle(t_game *game, double distProjPlane, int num)
{
	double angle;
	
	angle = game->ray.rotation_angle + atan((num - game->image.width / 2) / distProjPlane);
    angle = remainder(angle, PI * 2);
    if (angle < 0)
    {angle = PI * 2 + angle;}
	game->ray.facing_up = !(angle > 0 && angle < PI);
	game->ray.facing_right = angle < 0.5 * PI || angle > 1.5 * PI;
    return (angle);
}

void	incremente_horiz_step(t_game *game)
{
	double	nextx;
	double	nexty;
	double	xtocheck;
	double	ytocheck;

	game->ray.found_horiz_wall = false;
	nextx = game->ray.xintercept;
	nexty = game->ray.yintercept;
	while (nextx >= 0 && nextx < game->map.map_width && nexty >= 0 && nexty < game->map.map_height)
	{
		xtocheck = nextx;
		ytocheck = nexty;
		if (game->ray.facing_up)
			ytocheck += -1;
		if (game->map.map[(int)ytocheck][(int)xtocheck] == '1')
		{
			game->ray.horiz_wallx = nextx;
			game->ray.horiz_wally = nexty;
			game->ray.found_horiz_wall = true;
			break ;
		}
		if (game->map.map[(int)ytocheck][(int)xtocheck] != '0')
		{
			//printf("chelou\n");
			//printf("X tocheck = %lf et Y tocheck = %lf\n", xtocheck, ytocheck);
			break ;
		}
		nextx += game->ray.xstep;
		nexty += game->ray.ystep;		
	}
}

//inversion de posx et de posy

void	find_horiz_step(t_game *game, double ray_angle)
{
	game->ray.yintercept = floor(game->ray.posx);
	if (!game->ray.facing_up)
		game->ray.yintercept += 1; //game->map.map_height;
	game->ray.xintercept = game->ray.posy + (game->ray.yintercept - game->ray.posx) / tan(ray_angle);
//	printf("y intercepte = %lf et pos = %lf\n", game->ray.yintercept, game->ray.posy);
//	printf("x intercepte = %lf et pos = %lf\n", game->ray.xintercept, game->ray.posx);
	game->ray.ystep = 1;
	if (game->ray.facing_up)
		game->ray.ystep *= -1;
	game->ray.xstep = tan(ray_angle);
	if (!game->ray.facing_right && game->ray.xstep > 0)
		game->ray.xstep *= -1;
	if (game->ray.facing_right && game->ray.xstep < 0)
		game->ray.xstep *= -1;
	
	incremente_horiz_step(game);
}




void	incremente_vert_step(t_game *game)
{
	double	nextx;
	double	nexty;
	double	xtocheck;
	double	ytocheck;

	game->ray.found_vert_wall = false;
	nextx = game->ray.xintercept;
	nexty = game->ray.yintercept;
	while (nextx >= 0 && nextx < game->map.map_width && nexty >= 0 && nexty < game->map.map_height)
	{
		xtocheck = nextx;
		ytocheck = nexty;
		if (!game->ray.facing_right)
			xtocheck += -1;
		if (game->map.map[(int)ytocheck][(int)xtocheck] == '1')
		{
			game->ray.horiz_wallx = nextx;
			game->ray.horiz_wally = nexty;
			game->ray.found_vert_wall = true;
			break ;
		}
		if (game->map.map[(int)ytocheck][(int)xtocheck] != '0')
		{
			//printf("chelou\n");
			//printf("X tocheck = %lf et Y tocheck = %lf et char = %c\n", xtocheck, ytocheck, game->map.map[(int)ytocheck][(int)xtocheck]);
			//printf("x intercepte = %lf et pos = %lf\n", game->ray.xintercept, game->ray.posx);
		}
		nextx += game->ray.xstep;
		nexty += game->ray.ystep;		
	}
}

void	find_vert_step(t_game *game, double ray_angle)
{
	game->ray.xintercept = floor(game->ray.posy);
	if (game->ray.facing_right)
		game->ray.yintercept += 1; //game->map.map_height;
	game->ray.yintercept = game->ray.posx + (game->ray.xintercept - game->ray.posy) / tan(ray_angle);
//	printf("y intercepte = %lf et pos = %lf\n", game->ray.yintercept, game->ray.posy);
//	printf("x intercepte = %lf et pos = %lf\n", game->ray.xintercept, game->ray.posx);
	game->ray.xstep = 1;
	if (!game->ray.facing_right)
		game->ray.ystep *= -1;
	game->ray.ystep = tan(ray_angle);
	if (game->ray.facing_up && game->ray.ystep > 0)
		game->ray.ystep *= -1;
	if (!game->ray.facing_up && game->ray.xstep < 0)
		game->ray.ystep *= -1;
	
	incremente_vert_step(game);
}

double	distanceBetweenPoints(double x1, double y1, double x2, double y2)
{
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

void	wall_hit_dist(t_game *game)
{
		double	horiz_dist;
		double	vert_dist;

		if (game->ray.found_horiz_wall)
			horiz_dist = distanceBetweenPoints(game->ray.posx, game->ray.posy, game->ray.horiz_wallx, game->ray.horiz_wally);
		else
			horiz_dist = INT_MAX;
		if (game->ray.found_vert_wall)
			vert_dist = distanceBetweenPoints(game->ray.posx, game->ray.posy, game->ray.vert_wallx, game->ray.vert_wally);
		else
			vert_dist = INT_MAX;
		if (vert_dist < horiz_dist)
		{
			game->ray.ray_dist = vert_dist;
			game->ray.wallhitx = game->ray.vert_wallx;
			game->ray.wallhity = game->ray.vert_wally;
			if (game->ray.facing_right)
				game->ray.texture = 0xFFFFFF33;
			else
				game->ray.texture = 0xFFFF33FF;
		}
		else
		{
			game->ray.ray_dist = horiz_dist;
			game->ray.wallhitx = game->ray.horiz_wallx;
			game->ray.wallhity = game->ray.horiz_wally;
			if (game->ray.facing_up)
				game->ray.texture = 0xFF33FF33;
			else
				game->ray.texture = 0xFF3333FF;
		}
}

void	projection(t_game *game, double distprojplane, int x)
{
	double	wallheight;
	int		wall_top_pix;
	int		wall_bottom_pix;
	int		y;
	
	wallheight = game->ray.ray_dist * distprojplane / 100;
	wall_top_pix = (game->image.height / 2) - ((int)wallheight / 2);
	if (wall_top_pix < 0)
		wall_top_pix = 0;
	wall_bottom_pix = (game->image.height / 2) + ((int)wallheight / 2);
	if (wall_bottom_pix < 0)
		wall_bottom_pix = 0;
	y = wall_top_pix;
	//printf("dist =  %lf\t wall height = %lf\n", game->ray.ray_dist, wallheight);
	while (y < wall_bottom_pix)
	{
		my_mlx_pixel_put(&game->image, x, y, 0xFF33FF33);
		y++;
	}
	
}

void	raycasting(t_game *game)
{
	double	ray_angle;
	double	distProjPlane;
	int		i;

	distProjPlane = (game->image.width / 2) / tan(FOV / 2);
	i = 0;
	while (i < game->image.width)
	{
		ray_angle = init_Angle(game, distProjPlane, i);
		find_horiz_step(game, ray_angle);
		find_vert_step(game, ray_angle);
		wall_hit_dist(game);
		projection(game, distProjPlane, i);
		
		i++;
	}
}