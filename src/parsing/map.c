/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvisouth <kvisouth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:28:55 by kvisouth          #+#    #+#             */
/*   Updated: 2023/11/16 15:52:15 by kvisouth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

// Sets the last line of the file.
// So we dont have to loop until we have a NULL but until we reach this value.
void	set_last_line(t_game *game)
{
	int	i;

	i = game->parse.last_elem;
	while (game->parse.file_cont[i] != NULL)
		i++;
	game->parse.last_line = i;
}

// It sets the first line of the map.
// It must be a line with only 1 and 0
int	set_map_start(t_game *game, int i)
{
	int	j;

	j = 0;
	while (game->parse.file_cont[i][j] == ' ')
		j++;
	if (game->parse.file_cont[i][j] == '1'
		|| game->parse.file_cont[i][j] == '0')
	{
		game->map.map_start = i;
		return (1);
	}
	ft_putstr_fd("Error\nInvalid map\n", 2);
	return (0);
}

// Checks if there is garbage characters in the map.
// There must be only \n between the map and the end of the file
int	check_garbage(t_game *game, int a, int b)
{
	a++;
	while (a < b)
	{
		if (is_empty_line2(game, a) == 0)
		{
			ft_putstr_fd("Error\nGarbage characters after map\n", 2);
			return (0);
		}
		a++;
	}
	return (1);
}

// Stores the map in a char ** (game->map.map)
// Copies all the lines of the files from line 'start' to line 'end'
// start being the line where the map starts
// end being the line where the map ends
int	get_map(t_game *game, int start, int end)
{
	int	i;
	int	j;

	i = start;
	j = 0;
	game->map.map = ft_calloc(sizeof(char *), (game->map.map_height + 1));
	if (game->map.map == NULL)
		return (0);
	while (i <= end)
	{
		game->map.map[j] = ft_strdup(game->parse.file_cont[i]);
		if (game->map.map[j] == NULL)
		{
			free_array(game->map.map);
			return (0);
		}
		i++;
		j++;
	}
	return (1);
}

int	parse_map(t_game *game)

{
	int	i;

	set_last_line(game);
	i = game->parse.last_elem + 1;
	skip_newlines(game, &i);
	if (set_map_start(game, i) == 0)
		return (1);
	if (get_map_size(game, i) < 3)
		return (ft_putstr_fd("Error\nInvalid size or junk characters\n", 2), 1);
	game->map.map_end = (game->map.map_start + game->map.map_height) - 1;
	if (check_garbage(game, game->map.map_end, game->parse.last_line) == 0)
		return (1);
	if (get_map(game, game->map.map_start, game->map.map_end) == 0)
		return (ft_putstr_fd("Error\nMalloc error\n", 2), 1);
	game->map.map_width = get_width_of_map(game);
	if (check_map(game) == 0)
		return (1);
	return (0);
}
