/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_ckeck.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moleksan <moleksan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 16:46:30 by moleksan          #+#    #+#             */
/*   Updated: 2024/07/03 17:50:03 by moleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../slnglib/solong.h"

int	msg(char *err)
{
	write(2, err, ft_strlen(err));
	write(2, "\n", 1);
	exit(1);
}

static int	check_exit(t_gamedata *game, int w, int h)
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

static int	close_exit(t_gamedata *game)
{
	int	w;
	int	h;
	int	we;
	int	he;
	int	res;

	h = 0;
	while (h <= game->height)
	{
		w = 0;
		while (game->map[h][w])
		{
			if (game->map[h][w] == 'E')
			{
				we = w;
				he = h;
			}
			w++;
		}
		h++;
	}
	res = check_exit(game, we, he);
	return (res);
}

int	close_coin(t_gamedata *game, int h, int w)
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

void	map_checker(t_gamedata *game)
{
	if (map_len(game) != 1)
		msg(ERR_MAP_REC);
	if (close_map(game) != 1)
		msg(ERR_CLOSE);
	if (exit_point(game) != 1)
		msg(ERR_EXIT);
	if (check_player(game) != 1)
		msg(ERR_PLAYER);
	if (check_coin(game) < 1)
		msg(ERR_COIN);
	if (close_exit(game) != 1)
		msg(ERR_EXIT2);
}
