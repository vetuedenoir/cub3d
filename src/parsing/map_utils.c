/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvisouth <kvisouth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:10:43 by kvisouth          #+#    #+#             */
/*   Updated: 2023/11/16 15:35:36 by kvisouth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

// Will increase i until it reaches a line with only \n
void	skip_newlines(t_game *game, int *i)
{
	while (game->parse.file_cont[*i] && game->parse.file_cont[*i][0] == '\n')
		(*i)++;
}

// Will check if line (i) is completely empty (only \n at [0])
int	is_empty_line2(t_game *game, int i)
{
	if (game->parse.file_cont[i][0] == '\n')
		return (1);
	return (0);
}

// Will check if line (i) is empty but can contain spaces.
int	is_empty_line(t_game *game, int i)
{
	int	j;

	j = 0;
	while (game->parse.file_cont[i][j] == ' ')
		j++;
	if (game->parse.file_cont[i][j] == '\n')
		return (1);
	return (0);
}

// Will get the size of the map (map_height)
int	get_map_size(t_game *game, int i)
{
	int	j;
	int	size;

	j = 0;
	size = 0;
	while (i < game->parse.last_line)
	{
		j = 0;
		skip_spaces(game->parse.file_cont[i], &j);
		if (game->parse.file_cont[i][j] != '1'
			&& game->parse.file_cont[i][j] != '0'
			&& game->parse.file_cont[i][j] != '\n'
			&& game->parse.file_cont[i][j] != ' ')
		{
			return (0);
		}
		if (only_empty_lines_left(game, i) == 1)
			break ;
		size++;
		i++;
	}
	game->map.map_height = size;
	return (size);
}

// Will get the width of the map (map_width) (max line length)
int	get_width_of_map(t_game *game)
{
	int	i;
	int	j;
	int	max;
	int	tmp;

	i = 0;
	max = 0;
	while (i < game->map.map_height - 1)
	{
		j = 0;
		tmp = 0;
		while (game->map.map[i][j] != '\n')
		{
			j++;
			tmp++;
		}
		if (tmp > max)
			max = tmp;
		i++;
	}
	return (max);
}
