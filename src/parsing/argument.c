/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_argument.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kvisouth <kvisouth@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:29:12 by kvisouth          #+#    #+#             */
/*   Updated: 2023/11/14 18:07:41 by kvisouth         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/cub3d.h"

// Argument check will check if the argument seems valid.
// Meaning it has to be :
// - only 1 argument which is the map file.
// - this map file has to end with '.cub'
// - the map file has to have a character before the '.'
// - the character before the '.' has to be alphanumeric
// - this file has to exist.

int	argument_check(int ac, char **av)
{
	int	fd;

	if (ac != 2)
		return (ft_putstr_fd("Wrong number of arguments\n", 2), 1);
	if (ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".cub", 4) != 0)
		return (ft_putstr_fd("wrong format of file\n", 2), 1);
	if (ft_strlen(av[1]) <= 4 || ft_isalnum(av[1][ft_strlen(av[1]) - 5]) == 0)
		return (ft_putstr_fd("wrong format of file\n", 2), 1);
	fd = open(av[1], O_RDONLY | O_DIRECTORY);
	if (fd >= 0)
	{
		close(fd);
		return (ft_putstr_fd(av[1], 2), ft_putstr_fd(" is a directory", 2), 1);
	}
	return (0);
}
