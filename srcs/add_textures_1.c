/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_textures_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 09:53:11 by llethuil          #+#    #+#             */
/*   Updated: 2022/01/19 11:58:33 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	add_textures(t_data *data)
{
	data->sprt.size = 100;
	cam_init(data);
	mlx_clear_window(data->win.mlx, data->win.frame);
	data->map.y = data->cam.y;
	data->map.x = data->cam.x;
	data->win.y = 0;
	while (data->map.y < (data->win.hgt / data->sprt.size) + data->cam.y
		&& data->map.bidim[data->map.y])
	{
		data->map.x = data->cam.x;
		data->win.x = 0;
		while (data->map.x < (data->win.wdth / data->sprt.size) + data->cam.x
			&& data->map.bidim[data->map.y][data->map.x])
		{
			select_field_sprite(data);
			select_pokemon_sprite(data);
			display_player(data);
			data->map.x ++;
			data->win.x += data->sprt.size;
		}
		data->map.y ++;
		data->win.y += data->sprt.size;
	}
	display_hud(data);
}

void	select_field_sprite(t_data *data)
{
	mlx_put_image_to_window(data->win.mlx, data->win.frame,
		data->sprt.grass_1, data->win.x, data->win.y);
	if (data->map.bidim[data->map.y][data->map.x] == '1')
		put_field_sprite(data, '1');
	else if (data->map.bidim[data->map.y][data->map.x] == '2')
		put_field_sprite(data, '2');
	else if (data->map.bidim[data->map.y][data->map.x] == '3')
		put_field_sprite(data, '3');
	else if (data->map.bidim[data->map.y][data->map.x] == 'C')
		put_field_sprite(data, 'C');
	else if (data->map.bidim[data->map.y][data->map.x] == 'E')
		put_field_sprite(data, 'E');
}

void	put_field_sprite(t_data *data, char c)
{
	void	*img_ptr;

	img_ptr = NULL;
	if (c == '1')
		img_ptr = data->sprt.tree;
	else if (c == '2' && data->sprt.state == 0)
		img_ptr = data->sprt.grass_2_1;
	else if (c == '2' && data->sprt.state != 0)
		img_ptr = data->sprt.grass_2_2;
	else if (c == '3')
		img_ptr = data->sprt.grass_3;
	else if (c == 'C')
		img_ptr = data->sprt.pokeball;
	else if (c == 'E')
		img_ptr = data->sprt.ladder;
	mlx_put_image_to_window(data->win.mlx, data->win.frame,
		img_ptr, data->win.x, data->win.y);
}

void	select_pokemon_sprite(t_data *data)
{
	if (data->map.bidim[data->map.y][data->map.x] == 'B')
		put_pokemon_sprite(data, 'B');
	else if (data->map.bidim[data->map.y][data->map.x] == 'p')
		put_pokemon_sprite(data, 'p');
	else if (data->map.bidim[data->map.y][data->map.x] == 'S')
		put_pokemon_sprite(data, 'S');
}

void	put_pokemon_sprite(t_data *data, char c)
{
	void	*img_ptr;

	img_ptr = NULL;
	if (c == 'B' && data->sprt.state == 0)
		img_ptr = data->sprt.bulbi_1;
	else if (c == 'B' && data->sprt.state != 0)
		img_ptr = data->sprt.bulbi_2;
	else if (c == 'p' && data->sprt.state == 0)
		img_ptr = data->sprt.pika_1;
	else if (c == 'p' && data->sprt.state != 0)
		img_ptr = data->sprt.pika_2;
	else if (c == 'S' && data->sprt.state == 0)
		img_ptr = data->sprt.spectrum_1;
	else if (c == 'S' && data->sprt.state != 0)
		img_ptr = data->sprt.spectrum_2;
	mlx_put_image_to_window(data->win.mlx, data->win.frame,
		img_ptr, data->win.x, data->win.y);
}
