/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moleksan <moleksan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 16:59:15 by moleksan          #+#    #+#             */
/*   Updated: 2024/07/15 13:12:16 by moleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../slnglib/solong.h"

int	player_move(t_gamedata *game, int h, int w)
{
	w++;
	if (game->map[h][w] == '0' || game->map[h][w] == 'C')
		return (1);
	w--;
	h++;
	if (game->map[h][w] == '0' || game->map[h][w] == 'C')
		return (1);
	h--;
	w--;
	if (game->map[h][w] == '0' || game->map[h][w] == 'C')
		return (1);
	w++;
	h--;
	if (game->map[h][w] == '0' || game->map[h][w] == 'C')
		return (1);
	return (0);
}

int	key_cross(t_gamedata *data)
{
	int	i;

	i = 0;
	mlx_destroy_window(data->mlx, data->mlx_win);
	free(data->mlx);
	while (i <= data->height)
		free(data->map[i++]);
	exit(0);
}

int	key_hook(int keycode, t_gamedata *game)
{
	int	i;

	if (keycode == 65307)
	{
		i = 0;
		mlx_destroy_window(game->mlx, game->mlx_win);
		ft_printf("\n CLOSE GAME \n\n");
		free(game->mlx);
		while (i <= game->height)
			free(game->map[i++]);
		exit(0);
	}
	if (keycode == 119)
		keyboard_vertical(game, keycode);
	else if (keycode == 115)
		keyboard_vertical(game, keycode);
	else if (keycode == 97)
		keyboard_horisontal(game, keycode);
	else if (keycode == 100)
		keyboard_horisontal(game, keycode);
	graphics_map(game);
	return (1);
}
