/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_elem_info.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvisouth <kvisouth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:28:34 by kvisouth          #+#    #+#             */
/*   Updated: 2023/11/16 15:42:03 by kvisouth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

// This function will store the path in the right variable depending on the elem
void	store_path(char *path, t_game *game, char *elem)
{
	if (elem[0] == 'N' && elem[1] == 'O')
		game->parse.no = path;
	else if (elem[0] == 'S' && elem[1] == 'O')
		game->parse.so = path;
	else if (elem[0] == 'W' && elem[1] == 'E')
		game->parse.we = path;
	else if (elem[0] == 'E' && elem[1] == 'A')
		game->parse.ea = path;
}

// This function will parse the path to the textures for NO, SO, WE, EA
int	parse_path(char *str, t_game *game, char *elem)
{
	int		i;
	int		j;
	char	*path;

	i = 0;
	path = NULL;
	while (str[i] != '\n' && str[i] != '\0' && str[i] != ' ')
		i++;
	path = malloc(sizeof(char) * (i + 1));
	if (!path)
		return (0);
	j = 0;
	while (j < i)
	{
		path[j] = str[j];
		j++;
	}
	path[j] = '\0';
	store_path(path, game, elem);
	return (1);
}

// This function will redirect to the right function depending on the elem
int	rgb_or_path(t_game *game, char *elem, int i, int j)
{
	if (elem[0] != 'F' && elem[0] != 'C')
	{
		if (parse_path(game->parse.file_cont[i] + j, game, elem) == 0)
			return (0);
	}
	else
	{
		if (parse_rgb(game->parse.file_cont[i] + j, game, elem) == 0)
			return (0);
	}
	return (1);
}

// Will search in game->parse.file_cont (is a char**) for *elem.
// If it finds it, it will parse the path.
int	search_elem(char *elem, t_game *game)
{
	int	i;
	int	j;
	int	elem_len;

	i = 0;
	elem_len = ft_strlen(elem);
	while (game->parse.file_cont[i] != NULL)
	{
		j = 0;
		skip_spaces(game->parse.file_cont[i], &j);
		if ((ft_strncmp(game->parse.file_cont[i] + j, elem, elem_len) == 0)
			&& (game->parse.file_cont[i][j + ft_strlen(elem)] == ' '
			|| game->parse.file_cont[i][j + ft_strlen(elem)] == '\t'))
		{
			j += ft_strlen(elem);
			skip_spaces(game->parse.file_cont[i], &j);
			if (rgb_or_path(game, elem, i, j) == 0)
				return (0);
			set_line(elem, game, i);
			return (1);
		}
		i++;
	}
	ft_putstr_fd("Error\nIncorrect element\n", 2);
	return (0);
}

int	parse_map_info(t_game *game)
{
	if (search_elem("NO", game) == 0)
		return (1);
	if (search_elem("SO", game) == 0)
		return (1);
	if (search_elem("WE", game) == 0)
		return (1);
	if (search_elem("EA", game) == 0)
		return (1);
	if (search_elem("F", game) == 0)
		return (1);
	if (search_elem("C", game) == 0)
		return (1);
	if (check_empty_lines(game) == 0)
		return (1);
	if (check_correct_paths(game))
		return (1);
	return (0);
}
