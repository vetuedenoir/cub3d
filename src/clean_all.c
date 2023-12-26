#include "../inc/cub3d.h"

// This function will free a char ** AND free the array itself
void	free_array(char	**array)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_elem(t_game *game)
{
	if (game->parse.no != NULL)
		free(game->parse.no);
	if (game->parse.so != NULL)
		free(game->parse.so);
	if (game->parse.we != NULL)
		free(game->parse.we);
	if (game->parse.ea != NULL)
		free(game->parse.ea);
	if (game->map.map != NULL)
		free_array(game->map.map);
}

void	free_mlx(t_game *game)
{
	if (game->no.img)
		mlx_destroy_image(game->mlx, game->no.img);
	if (game->so.img)
		mlx_destroy_image(game->mlx, game->so.img);
	if (game->we.img)
		mlx_destroy_image(game->mlx, game->we.img);
	if (game->ea.img)
		mlx_destroy_image(game->mlx, game->ea.img);
	if (game->image.img)
		mlx_destroy_image(game->mlx, game->image.img);
	if (game->win.mlx_w)
		mlx_destroy_window(game->mlx, game->win.mlx_w);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}

void	free_all(t_game *game)
{
	free_elem(game);
	free_mlx(game);
}

int	quit(t_game *game)
{
	free_all(game);
	exit(0);
}