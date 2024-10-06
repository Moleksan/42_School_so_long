/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moleksan <moleksan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 15:19:50 by moleksan          #+#    #+#             */
/*   Updated: 2024/07/19 14:41:07 by moleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../slnglib/solong.h"

static int	check_ext(char *av)
{
	int		l;
	char	*ber;
	int		lb;

	ber = ".ber";
	lb = 4;
	l = ft_strlen(av);
	while (lb > 0)
	{
		if (ber[lb] == av[l])
		{
			lb--;
			l--;
		}
		else
			return (0);
	}
	return (1);
}

static void	count_arr(int fd, t_gamedata *game)
{
	int		l;
	int		s;
	char	*line;

	l = 0;
	s = 0;
	line = get_next_line(fd);
	if (line == NULL)
		msg(ERR_MAP);
	while (line[s] != '\0')
		s++;
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		l++;
	}
	game->width = s - 1;
	game->height = l - 1;
}

static void	alocc_map(t_gamedata *game, int fd)
{
	int		i;
	char	*line;

	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		game->map[i] = ft_strdup(line);
		free(line);
		line = get_next_line(fd);
		i++;
	}
}

static int	check_map_symbols(t_gamedata *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] != '1' && game->map[i][j] != '0' &&
				game->map[i][j] != 'P' && game->map[i][j] != 'X' &&
				game->map[i][j] != 'E' && game->map[i][j] != 'C')
			{
				ft_printf("Invalid symbol '%c' in map\n", game->map[i][j]);
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	map_read(t_gamedata *game, char **av)
{
	int	fd;
	int	i;

	fd = open(av[1], O_RDONLY);
	i = check_ext(av[1]);
	if (fd < 0 || i < 1)
	{
		msg(ERROR_WMAP);
	}
	count_arr(fd, game);
	close(fd);
	fd = open(av[1], O_RDONLY);
	game->map = malloc(sizeof(char *) * (size_t)(game->height + 1));
	alocc_map(game, fd);
	close(fd);
	if (check_map_symbols(game) != 0)
		msg("Invalid map symbols");
}
