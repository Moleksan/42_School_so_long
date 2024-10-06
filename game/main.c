/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moleksan <moleksan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 14:42:08 by moleksan          #+#    #+#             */
/*   Updated: 2024/07/19 14:37:02 by moleksan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../slnglib/solong.h"
#include <stdio.h>

static int	ft_len(int n)
{
	size_t	size;

	size = 0;
	if (n <= 0)
		size++;
	while (n)
	{
		size++;
		n = n / 10;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*num;

	len = ft_len(n);
	num = malloc(len + 1);
	if (!num)
		return (NULL);
	num[len] = '\0';
	if (n == 0)
		num[0] = '0';
	if (n < 0)
		num[0] = '-';
	if (n == -2147483648)
	{
		num[1] = '2';
		n += 2000000000;
	}
	if (n < 0)
		n *= -1;
	while (n)
	{
		num[--len] = n % 10 + '0';
		n /= 10;
	}
	return (num);
}

static void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)b;
	while (i < len)
	{
		ptr[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

int	main(int ac, char **av)
{
	t_gamedata	game;

	if (ac != 2)
	{
		msg(ERROR_WMAP);
		return (1);
	}
	ft_printf("Initializing game data\n");
	ft_memset(&game, 0, sizeof(t_gamedata));
	map_read(&game, av);
	map_checker(&game);
	game.mlx = mlx_init();
	if (!game.mlx)
		ft_printf("Failed to initialize mlx\n");
	game.mlx_win = mlx_new_window(game.mlx, game.width * 64,
			(game.height + 1) * 64, "so_long");
	if (!game.mlx_win)
		ft_printf("Failed to create window\n");
	image_in_window(&game);
	graphics_map(&game);
	mlx_hook(game.mlx_win, 2, 1L << 0, key_hook, &game);
	mlx_hook(game.mlx_win, 17, 0, key_cross, &game);
	mlx_loop(game.mlx);
	return (0);
}
