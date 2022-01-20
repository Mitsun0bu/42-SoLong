/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 09:40:02 by llethuil          #+#    #+#             */
/*   Updated: 2022/01/19 11:25:58 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	parse_map(t_map *map)
{
	if (check_map_edges(map) == 0)
		return (0);
	if (check_map_rectangular(map) == 0)
		return (0);
	if (check_map_composition(map) == 0)
		return (0);
	return (1);
}

int	check_map_edges(t_map *map)
{
	map->y = -1;
	while (map->bidim[++map->y])
	{
		map->x = -1;
		while (map->bidim[map->y][++map->x])
		{
			if (map->y == 0 || map->y == map->hgt - 1)
				if (map->bidim[map->y][map->x] != '1')
					return (0);
			if (map->y != 0 && map->y != map->hgt - 1)
				if (map->bidim[map->y][0] != '1'
					|| map->bidim[map->y][map->wdth - 1] != '1')
					return (0);
		}
	}
	return (1);
}

int	check_map_rectangular(t_map *map)
{
	map->y = -1;
	while (map->bidim[++map->y])
	{
		if (ft_strlen(map->bidim[map->y]) != ft_strlen(map->bidim[0]))
			return (0);
	}
	return (1);
}

int	check_map_composition(t_map *map)
{
	map->y = -1;
	while (++map->y < map->hgt - 1)
	{
		map->x = -1;
		while (++map->x < map->wdth -1)
		{
			if (map->bidim[map->y][map->x] == 'C')
				map->n_c++;
			else if (map->bidim[map->y][map->x] == 'E')
				map->n_e++;
			else if (map->bidim[map->y][map->x] == 'P')
				map->n_p++;
			else if (map->bidim[map->y][map->x] != '1'
				&& map->bidim[map->y][map->x] != '0')
				return (0);
		}
	}
	if (map->n_c == 0 || map->n_e == 0 || map->n_p != 1)
		return (0);
	return (1);
}
