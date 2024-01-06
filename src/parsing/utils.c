/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kscordel <kscordel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 18:00:24 by kvisouth          #+#    #+#             */
/*   Updated: 2024/01/06 18:02:41 by kscordel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"


void	print_tab(char **tab)
{
	int	y = 0;
	int x = 0;
	
	while (tab[y])
	{
		x = 0;
		while (tab[y][x] != '\n' && tab[y][x])
		{
			ft_putchar_fd(tab[y][x], 1);
			x++;
		}
		write(1, "%\n", 2);
		y++;
	}
}

char	*dup_str_len(const char *s, int len)
{
	char	*dup;
	int		i;
	int		t;

	i = 0;
	t = ft_strlen(s);
	if (len > t)
		dup = calloc(sizeof(char), len);
	else
		dup = malloc(t + 1);
	if (!dup)
		return (NULL);
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

// This function will skip all the lines but will free the lines as well
void	skip_lines_end(int fd)
{
	char	*line;

	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
	}
}

// This function will skip all the lines but will not free the lines
void	skip_lines(int fd)
{
	while (get_next_line(fd) != NULL)
		;
}

// This function will skip all the spaces in a line
void	skip_spaces(char *line, int *i)
{
	if (line == NULL)
		return ;
	if (line[*i] == '\0')
		return ;
	if (line[*i] == '\n')
		return ;
	while (line[*i] == ' ')
	{
		if (line[*i] == '\0')
			return ;
		(*i)++;
	}
}
