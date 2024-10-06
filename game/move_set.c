/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moleksan <moleksan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:04:55 by moleksan          #+#    #+#             */
/*   Updated: 2024/07/03 17:50:53 by moleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../slnglib/solong.h"

int	move_s(t_gamedata *game)
{
	int	i;
	int	j;
	int	wall;

	i = game->y;
	j = game->x;
	i--;
	if (game->map[i][j] == '1')
		return (0);
	wall = check_event(game, i, j);
	if (!wall)
		return (0);
	game->map[i + 1][j] = '0';
	return (1);
}

int	move_w(t_gamedata *game)
{
	int	i;
	int	j;
	int	wall;

	i = game->y;
	j = game->x;
	i++;
	if (game->map[i][j] == '1')
		return (0);
	wall = check_event(game, i, j);
	if (!wall)
		return (0);
	game->map[i - 1][j] = '0';
	return (1);
}

int	move_a(t_gamedata *game)
{
	int	i;
	int	j;
	int	wall;

	i = game->y;
	j = game->x;
	j--;
	if (game->map[i][j] == '1')
		return (0);
	wall = check_event(game, i, j);
	if (!wall)
		return (0);
	game->map[i][j + 1] = '0';
	return (1);
}

int	move_d(t_gamedata *game)
{
	int	i;
	int	j;
	int	wall;

	i = game->y;
	j = game->x;
	j++;
	if (game->map[i][j] == '1')
		return (0);
	wall = check_event(game, i, j);
	if (!wall)
		return (0);
	game->map[i][j - 1] = '0';
	return (1);
}
