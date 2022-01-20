/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 18:21:05 by llethuil          #+#    #+#             */
/*   Updated: 2022/01/07 14:32:35 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	get_player(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (data->map.bidim[y])
	{
		x = 0;
		while (data->map.bidim[y][x])
		{
			if (data->map.bidim[y][x] == 'P')
			{
				data->player.x = x;
				data->player.y = y;
				break ;
			}
			x ++;
		}
		y ++;
	}
}
