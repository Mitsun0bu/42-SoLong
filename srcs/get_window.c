/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 09:46:13 by llethuil          #+#    #+#             */
/*   Updated: 2022/01/20 10:21:40 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	get_window(t_data *data)
{
	data->win.hgt = 1000;
	data->win.wdth = 1700;
	if (data->map.wdth <= 17)
		data->win.wdth = data->map.wdth * 100;
	if (data->map.hgt <= 10)
		data->win.hgt = data->map.hgt * 100;
	data->win.mlx = mlx_init();
	data->win.frame = mlx_new_window(data->win.mlx,
			data->win.wdth, data->win.hgt, "POKELONG - CATCH 'EM ALL !");
	mlx_hook(data->win.frame, 17, 0, kill, data);
}

void	cam_init(t_data *data)
{
	int	y;
	int	x;

	y = data->player.y - ((data->win.hgt / data->sprt.size) / 2);
	x = data->player.x - ((data->win.wdth / data->sprt.size) / 2);
	if (y < 0)
		y = 0;
	if (x < 0)
		x = 0;
	if (y + (data->win.hgt / data->sprt.size) > data->map.hgt)
		y = data->map.hgt - (data->win.hgt / data->sprt.size);
	if (x + (data->win.wdth / data->sprt.size) > data->map.wdth)
		x = data->map.wdth - (data->win.wdth / data->sprt.size);
	data->cam.y = y;
	data->cam.x = x;
	return ;
}
