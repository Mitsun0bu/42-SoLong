/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomize_field.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 18:01:39 by llethuil          #+#    #+#             */
/*   Updated: 2022/01/07 15:14:23 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	randomize_field(t_map *map)
{
	int	rand;

	map->y = -1;
	while (map->bidim[++map->y])
	{
		map->x = -1;
		while (map->bidim[map->y][++map->x])
		{
			rand = get_random();
			if (map->bidim[map->y][map->x] == '0')
			{
				if (150 <= rand && rand < 155)
					map->bidim[(map->y)][(map->x)] = '2';
				else if (180 <= rand && rand < 210)
					map->bidim[(map->y)][(map->x)] = '3';
				else if (210 <= rand && rand < 220)
					randomize_pokemon(map, 'B');
				else if (220 <= rand && rand < 230)
					randomize_pokemon(map, 'p');
				else if (230 <= rand && rand < 240)
					randomize_pokemon(map, 'S');
			}
		}
	}
}

void	randomize_pokemon(t_map *map, char c)
{
	if (map->bidim[(map->y - 1)][(map->x)] != '1'
		&& map->bidim[(map->y + 1)][(map->x)] != '1'
		&& map->bidim[(map->y)][(map->x + 1)] != '1'
		&& map->bidim[(map->y)][(map->x -1)] != '1'
		&& map->bidim[(map->y - 1)][(map->x + 1)] != '1'
		&& map->bidim[(map->y + 1)][(map->x -1)] != '1'
		&& map->bidim[(map->y - 1)][(map->x)] != c
		&& map->bidim[(map->y + 1)][(map->x)] != c
		&& map->bidim[(map->y)][(map->x + 1)] != c
		&& map->bidim[(map->y)][(map->x -1)] != c
		&& map->bidim[(map->y - 1)][(map->x + 1)] != c
		&& map->bidim[(map->y + 1)][(map->x -1)] != c)
	{
		map->bidim[(map->y)][(map->x)] = c;
	}
}

int	get_random(void)
{
	int		fd;
	int		i;
	char	buffer[4];
	int		result;

	result = 0;
	fd = open("/dev/urandom", O_RDONLY);
	if (fd == -1)
	{
		printf("Error !\nGet random failed!\n");
		exit(0);
	}
	read(fd, buffer, 4);
	buffer[3] = '\0';
	i = -1;
	while (buffer[++i])
		result = result + buffer[i];
	if (result < 0)
		result = -result;
	if (close(fd) == -1)
	{
		printf("Error !\nGet random failed!\n");
		exit (0);
	}
	return (result);
}
