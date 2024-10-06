/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moleksan <moleksan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:10:13 by moleksan          #+#    #+#             */
/*   Updated: 2024/07/23 12:58:10 by moleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H
# include <stdio.h>
# include <stdlib.h>
# include "../mlx/mlx.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdarg.h>
# include <stdbool.h>
# include <string.h>
# include "../gnl/get_next_line.h"
# include <time.h>

# define ERR_MAP_REC "MAP NOT RECTANGULAR\n"
# define ERR_CLOSE "MAP NOT CLOSE\n"
# define ERR_EXIT "MAP HAVE 0 OR MORE 1 EXIT\n"
# define ERR_PLAYER "MAP DONT HAVE PLAYER OR MORE 1 ON MAP\n"
# define ERR_MAP "PROBLEM WITH MAP OR MAP EMPTY\n"
# define ERROR_WMAP "WRONG WAY TO MAP OR MAP DOESNT EXISTS\n"
# define ERR_COIN "0 COIN ON MAP OR COIN CLOSE BY WALLS\n"
# define ERR_EXIT2 "CLOSE EXIT\n"

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	void	*wall;
	void	*floor;
	void	*exit;
	void	*player;
	void	*item;
	void	*enemy;
	void	*bl;

	char	**map;

	int		x;
	int		y;
	int		fd;
	int		colecteble;
	int		height;
	int		width;
	int		score;
	int		countscore;
	int		steps;

}			t_gamedata;

void	map_read(t_gamedata *game, char **av);
void	map_checker(t_gamedata *game);
void	image_in_window(t_gamedata *game);
void	graphics_map(t_gamedata *game);
int		key_cross(t_gamedata *data);
int		key_hook(int keycode, t_gamedata *data);
void	player_position(t_gamedata *game, int w, int h);
int		ft_printf(const char *s, ...);
int		keyboard_horisontal(t_gamedata *game, int keycode);
int		keyboard_vertical(t_gamedata *game, int keycode);
int		map_len(t_gamedata *game);
int		close_map(t_gamedata *game);
int		exit_point(t_gamedata *game);
int		check_player(t_gamedata *game);
int		check_coin(t_gamedata *game);
int		msg(char *err);
int		move_a(t_gamedata *game);
int		move_d(t_gamedata *game);
int		move_s(t_gamedata *game);
int		move_w(t_gamedata *game);
int		check_event(t_gamedata *game, int i, int j);
int		close_coin(t_gamedata *game, int h, int w);
char	*ft_itoa(int n);
void	game_counter(t_gamedata *game);
int		player_move(t_gamedata *game, int h, int w);

#endif