/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:03:14 by llethuil          #+#    #+#             */
/*   Updated: 2022/01/19 13:50:57 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	get_map(t_map *map, int argc, char **argv)
{
	int		fd;

	fd = open_map_file(argc, argv);
	if (fd == -1)
		return ;
	if (map_init(map, fd) == 0)
	{
		printf("Error !\nMap initialisation failed !\n");
		exit(0);
	}
	close_map_file(fd);
	if (parse_map(map) == 0)
	{
		printf("Error !\nInvalid map !\n");
		exit(0);
	}
}

int	open_map_file(int argc, char **argv)
{
	int	fd;
	int	i_extension;

	fd = open(argv[1], O_DIRECTORY);
	if (fd != -1)
	{
		printf("Error !\nPlease enter a '.ber' map file as first argument !\n");
		exit(0);
	}
	i_extension = ft_strlen(argv[1]) - 4;
	if (argc < 2 || ft_strnstr(argv[1] + i_extension, ".ber", 4) == NULL)
	{
		printf("Error !\nPlease enter a '.ber' map file as first argument !\n");
		exit(0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("Error !\nMap opening failed!\n");
		exit(0);
	}
	return (fd);
}

int	map_init(t_map *map, int fd)
{
	map->unidim = ft_calloc(1, 1);
	if (!map->unidim)
		return (0);
	while (1)
	{
		map->line = ft_get_next_line(fd);
		if (!map->line)
			break ;
		map->unidim = ft_strjoin(map->unidim, map->line);
		if (!map->unidim || ft_strlen(map->line) == 1)
			return (0);
		free(map->line);
	}
	if (!ft_strlen(map->unidim))
		return (0);
	map->bidim = ft_split(map->unidim, '\n');
	map->wdth = 0;
	while (map->bidim[0][map->wdth])
		map->wdth ++;
	map->hgt = 0;
	while (map->bidim[map->hgt])
		map->hgt ++;
	free(map->unidim);
	return (1);
}

void	close_map_file(int fd)
{
	if (close(fd) == -1)
	{
		printf ("Error !\nMap closing failed!\n");
		exit (0);
	}
}
