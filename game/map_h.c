/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_h.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moleksan <moleksan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:03:47 by moleksan          #+#    #+#             */
/*   Updated: 2024/07/03 17:50:10 by moleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../slnglib/solong.h"

int	map_len(t_gamedata *game)
{
	int	w;
	int	h;
	int	w1;

	h = 0;
	w = 0;
	while (h <= game->height - 1)
	{
		if (w == 0)
			w = ft_strlen(game->map[h]);
		h++;
		if (h == game->height)
			w1 = ft_strlen(game->map[h]) + 1;
		else
			w1 = ft_strlen(game->map[h]);
		if (w != w1)
			return (0);
	}
	return (1);
}

int	close_map(t_gamedata *game)
{
	int	w;
	int	h;

	h = 0;
	while (h <= game->height)
	{
		w = 0;
		while (game->map[h][w + 1] != '\0')
		{
			if (game->map[h][w] != '1')
				return (0);
			w++;
		}
		while (h++ < game->height)
			if (game->map[h][0] != '1' || game->map[h][w - 1] != '1')
				return (0);
		w = 0;
		while (h == game->height && game->map[h][w + 1] != '\0')
		{
			if (game->map[h][w] != '1')
				return (0);
			w++;
		}
	}
	return (1);
}

int	exit_point(t_gamedata *game)
{
	int	e;
	int	w;
	int	h;

	e = 0;
	h = 0;
	while (h <= game->height)
	{
		w = 0;
		while (game->map[h][w])
		{
			if (game->map[h][w] == 'E')
				e++;
			w++;
		}
		h++;
	}
	return (e);
}

int	check_player(t_gamedata *game)
{
	int	p;
	int	w;
	int	h;

	p = 0;
	h = 0;
	while (h <= game->height)
	{
		w = 0;
		while (game->map[h][w])
		{
			if (game->map[h][w] == 'P')
			{
				if (player_move(game, h, w) != 1)
					return (0);
				p++;
			}
			w++;
		}
		h++;
	}
	return (p);
}

int	check_coin(t_gamedata *game)
{
	int	c;
	int	w;
	int	h;

	c = 0;
	h = 0;
	while (h <= game->height)
	{
		w = 0;
		while (game->map[h][w])
		{
			if (game->map[h][w] == 'C')
			{
				if (close_coin(game, h, w) != 1)
					return (0);
				c++;
			}
			w++;
		}
		h++;
	}
	return (c);
}
