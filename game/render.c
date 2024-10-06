/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moleksan <moleksan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 16:50:33 by moleksan          #+#    #+#             */
/*   Updated: 2024/07/15 12:58:33 by moleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../slnglib/solong.h"
#include <time.h>

void	player_position(t_gamedata *game, int w, int h)
{
	ft_printf("Placing player at (%d, %d)\n", w, h);
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->player, w * 64, h * 64);
	game->x = w;
	game->y = h;
}

void	place_coin(t_gamedata *game, int w, int h)
{
	ft_printf("Placing coin at (%d, %d)\n", w, h);
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->item, w * 64, h * 64);
	game->colecteble++;
}

void	image_in_window(t_gamedata *game)
{
	int	i;
	int	j;

	ft_printf("Loading images\n");
	game->floor = mlx_xpm_file_to_image(game->mlx,
			"textures/floor.xpm", &i, &j);
	game->wall = mlx_xpm_file_to_image(game->mlx,
			"textures/wall.xpm", &i, &j);
	game->exit = mlx_xpm_file_to_image(game->mlx,
			"textures/port.xpm", &i, &j);
	game->player = mlx_xpm_file_to_image(game->mlx,
			"textures/player.xpm", &i, &j);
	game->enemy = mlx_xpm_file_to_image(game->mlx,
			"textures/enemy.xpm", &i, &j);
	game->bl = mlx_xpm_file_to_image(game->mlx,
			"textures/bl.xpm", &i, &j);
	game->item = mlx_xpm_file_to_image(game->mlx,
			"textures/oxygen.xpm", &i, &j);
}

static void	help_map(t_gamedata *game, int w, int h)
{
	if (game->map[h][w] == '1')
		mlx_put_image_to_window(game->mlx,
			game->mlx_win, game->wall, w * 64, h * 64);
	else if (game->map[h][w] == '0')
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->floor, w * 64, h * 64);
	else if (game->map[h][w] == 'X')
		mlx_put_image_to_window(game->mlx, game->mlx_win,
			game->enemy, w * 64, h * 64);
	else if (game->map[h][w] == 'E')
		mlx_put_image_to_window(game->mlx,
			game->mlx_win, game->exit, w * 64, h * 64);
}

void	graphics_map(t_gamedata *game)
{
	int	h;
	int	w;

	h = 0;
	game->colecteble = 0;
	ft_printf("Starting to render graphics\n");
	while (h <= game->height)
	{
		w = 0;
		while (game->map[h][w])
		{
			if (game->map[h][w] == '1'
				|| game->map[h][w] == '0'
				|| game->map[h][w] == 'X'
				|| game->map[h][w] == 'E')
				help_map(game, w, h);
			else if (game->map[h][w] == 'C')
				place_coin(game, w, h);
			else if (game->map[h][w] == 'P')
				player_position(game, w, h);
			w++;
		}
		h++;
	}
	game_counter(game);
}
