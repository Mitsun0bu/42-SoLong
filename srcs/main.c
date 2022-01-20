/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 11:40:17 by llethuil          #+#    #+#             */
/*   Updated: 2022/01/20 10:48:46 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_data	data;

	ft_memset(&data, 0, sizeof(data));
	get_map(&data.map, argc, argv);
	if (!data.map.bidim)
		exit (0);
	get_window(&data);
	get_player(&data);
	randomize_field(&data.map);
	get_field_sprites(&data.sprt, &data.win);
	get_pokemon_sprites(&data.sprt, &data.win);
	get_oak_sprites(&data.sprt, &data.win);
	add_textures(&data);
	mlx_loop_hook(data.win.mlx, set_animation, &data);
	mlx_hook(data.win.frame, 2, 0, move_player, &data);
	mlx_loop(data.win.mlx);
	return (0);
}
