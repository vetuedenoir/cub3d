/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvisouth <kvisouth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 16:05:10 by kvisouth          #+#    #+#             */
/*   Updated: 2023/11/16 15:31:57 by kvisouth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

// Checks if there is only empty lines after the map.
int	only_empty_lines_left(t_game *game, int i)
{
	while (game->parse.file_cont[i] != NULL)
	{
		if (is_empty_line(game, i) == 0)
			return (0);
		i++;
	}
	return (1);
}
