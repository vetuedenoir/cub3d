/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <kscordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:25:18 by kscordel          #+#    #+#             */
/*   Updated: 2024/01/12 13:25:47 by kscordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	makecolor(int t, int red, int green, int blue)
{
	return (t << 24 | red << 16 | green << 8 | blue);
}

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	*(unsigned int *)(data->addr + \
		( y * data->line_length + x * (data->bits_per_pixel / 8))) = color;
}

int	check_color_pix(t_img *data, int x, int y, int color)
{
	int	pix;

	pix = y * data->line_length + x * (data->bits_per_pixel / 8);
	if (pix >= 0 && pix <= data->height * data->width * \
		(data->bits_per_pixel / 8))
	{
		if (*(int *)(data->addr + pix) != (int)color \
			&& *(int *)(data->addr + pix) != (int)MINI_PERSO_COLOR)
			return (1);
		return (0);
	}
	else
		return (-1);
}

int	get_color_pix(t_img *img, int x, int y)
{
	return (*(int *)(img->addr + \
		(y * img->line_length + x * (img->bits_per_pixel / 8))));
}
