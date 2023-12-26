/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_check_map.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvisouth <kvisouth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:13:19 by kvisouth          #+#    #+#             */
/*   Updated: 2023/11/16 15:51:55 by kvisouth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

// Checks if the map only contains authorized characters : '0', '1', '2', 'N'
// 'S', 'E', 'W' and ' '
int	check_characters(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.map[i] != NULL)
	{
		j = 0;
		while (game->map.map[i][j] != '\n' && game->map.map[i][j] != '\0')
		{
			if (game->map.map[i][j] != '1' && game->map.map[i][j] != '0'
				&& game->map.map[i][j] != 'N' && game->map.map[i][j] != 'S'
				&& game->map.map[i][j] != 'E' && game->map.map[i][j] != 'W'
				&& game->map.map[i][j] != ' ')
			{
				ft_putstr_fd("Error\nInvalid character in map\n", 2);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

// If we enter this function, it means map[i][j] is a '0'
// So we only have to check around map[i][j].
// It checks if the 0 is at the first line, last line, first column or last
// Then it checks on the right if there is a \n, on the left if there is a ' '
// Then it checks for ' ' on the top and the bottom of the 0.
// Then it checks on the top and bottom of the 0 for \0 and \n
int	check_around_index(t_map map, int i, int j)
{
	if (i == 0 || i == map.map_height - 1 || j == 0 || j == map.map_width - 1)
		return (1);
	if (map.map[i][j + 1] == '\n' || map.map[i][j - 1] == ' ')
		return (1);
	if (map.map[i + 1][j] == ' ' || map.map[i - 1][j] == ' ')
		return (1);
	if (map.map[i + 1][j] == '\0' || map.map[i - 1][j] == '\0')
		return (1);
	if (map.map[i + 1][j] == '\n' || map.map[i - 1][j] == '\n')
		return (1);
	return (0);
}

// This function checks if the map is closed.
// What really checks is the function above.
int	check_map_closed(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.map_height)
	{
		j = 0;
		while (game->map.map[i][j] != '\n' && game->map.map[i][j] != '\0')
		{
			if (game->map.map[i][j] == '0')
			{
				if (check_around_index(game->map, i, j))
				{
					ft_putstr_fd("Error\nMap is not closed\n", 2);
					return (1);
				}
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_map(t_game *game)
{
	if (check_characters(game))
		return (0);
	if (check_player(game))
		return (0);
	if (check_map_closed(game))
		return (0);
	return (1);
}
