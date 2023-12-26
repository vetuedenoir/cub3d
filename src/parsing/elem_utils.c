/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvisouth <kvisouth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:57:04 by kvisouth          #+#    #+#             */
/*   Updated: 2023/11/16 15:31:57 by kvisouth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

void	set_larger(t_game *game)
{
	int	i;
	int	larger;

	i = 0;
	larger = 0;
	while (i < 6)
	{
		if (game->parse.elem_lines[i] > larger)
			larger = game->parse.elem_lines[i];
		i++;
	}
	game->parse.last_elem = larger;
}

void	set_line(char *elem, t_game *game, int i)
{
	if (elem[0] == 'N' && elem[1] == 'O')
		game->parse.elem_lines[0] = i;
	else if (elem[0] == 'S' && elem[1] == 'O')
		game->parse.elem_lines[1] = i;
	else if (elem[0] == 'W' && elem[1] == 'E')
		game->parse.elem_lines[2] = i;
	else if (elem[0] == 'E' && elem[1] == 'A')
		game->parse.elem_lines[3] = i;
	else if (elem[0] == 'F')
		game->parse.elem_lines[4] = i;
	else if (elem[0] == 'C')
		game->parse.elem_lines[5] = i;
	set_larger(game);
}

int	check_empty_lines(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i <= game->parse.last_elem)
	{
		j = 0;
		while (game->parse.file_cont[i][j] == '\n')
			i++;
		while (i == game->parse.elem_lines[0]
			|| i == game->parse.elem_lines[1]
			|| i == game->parse.elem_lines[2]
			|| i == game->parse.elem_lines[3]
			|| i == game->parse.elem_lines[4]
			|| i == game->parse.elem_lines[5])
			i++;
		if (game->parse.file_cont[i][j] != '\n')
			return (ft_putstr_fd("Error\nIncorrect elements\n", 1), 0);
	}
	if (i - 1 != game->parse.last_elem)
		return (ft_putstr_fd("Error\nIncorrect elements\n", 1), 0);
	return (1);
}
