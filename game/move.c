/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moleksan <moleksan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:01:19 by moleksan          #+#    #+#             */
/*   Updated: 2024/07/15 13:16:42 by moleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../slnglib/solong.h"

static void	check_event_help(t_gamedata *game, int i, int j)
{
	if (game->map[i][j] == '0' || game->map[i][j] == 'C')
	{
		game->map[i][j] = 'P';
		game->x = i;
		game->y = j;
	}
	if (game->map[i][j] == 'C')
	{
		game->map[i][j] = 'P';
		game->x = i;
		game->y = j;
		game->colecteble--;
	}
}

static void	died_player(t_gamedata *game, int i, int j)
{
	if (game->map[i][j] == 'X')
	{
		ft_printf("\n\t\033[0;31m\033[1m   YOU DIED\n");
		key_cross(game);
	}
}

int	check_event(t_gamedata *game, int i, int j)
{
	if (game->map[i][j] == 'E')
	{
		if (game->colecteble != 0)
			return (0);
		game->map[i][j] = 'P';
		game->x = i;
		game->y = j;
		ft_printf("\n\t\033[0;32m\033[1mYOU WIN\n\n");
		key_cross(game);
	}
	if (game->map[i][j] == '0')
		check_event_help(game, i, j);
	if (game->map[i][j] == 'C')
		check_event_help(game, i, j);
	if (game->map[i][j] == 'X')
		died_player(game, i, j);
	game->steps++;
	return (1);
}

int	keyboard_vertical(t_gamedata *game, int keycode)
{
	int	i;

	i = 0;
	if (keycode == 115)
		i = move_w(game);
	else if (keycode == 119)
		i = move_s(game);
	return (i);
}

int	keyboard_horisontal(t_gamedata *game, int keycode)
{
	int	i;

	i = 0;
	if (keycode == 97)
		i = move_a(game);
	else if (keycode == 100)
		i = move_d(game);
	return (i);
}
