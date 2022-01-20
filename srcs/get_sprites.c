/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_sprites.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 10:51:23 by llethuil          #+#    #+#             */
/*   Updated: 2022/01/07 14:42:21 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	get_field_sprites(t_sprt *sprt, t_win *win)
{
	sprt->grass_1 = mlx_xpm_file_to_image(win->mlx,
			"./sprites/grass_1.xpm", &sprt->size, &sprt->size);
	sprt->grass_2_1 = mlx_xpm_file_to_image(win->mlx,
			"./sprites/grass_2_1.xpm", &sprt->size, &sprt->size);
	sprt->grass_2_2 = mlx_xpm_file_to_image(win->mlx,
			"./sprites/grass_2_2.xpm", &sprt->size, &sprt->size);
	sprt->grass_3 = mlx_xpm_file_to_image(win->mlx,
			"./sprites/grass_3.xpm", &sprt->size, &sprt->size);
	sprt->pokeball = mlx_xpm_file_to_image(win->mlx,
			"./sprites/pokeball.xpm", &sprt->size, &sprt->size);
	sprt->ladder = mlx_xpm_file_to_image(win->mlx,
			"./sprites/ladder.xpm", &sprt->size, &sprt->size);
	sprt->tree = mlx_xpm_file_to_image(win->mlx,
			"./sprites/tree.xpm", &sprt->size, &sprt->size);
	sprt->end_screen = mlx_xpm_file_to_image(win->mlx,
			"./sprites/end_screen.xpm", &sprt->size, &sprt->size);
}

void	get_pokemon_sprites(t_sprt *sprt, t_win *win)
{
	sprt->bulbi_1 = mlx_xpm_file_to_image(win->mlx,
			"./sprites/bulbi_1.xpm", &sprt->size, &sprt->size);
	sprt->bulbi_2 = mlx_xpm_file_to_image(win->mlx,
			"./sprites/bulbi_2.xpm", &sprt->size, &sprt->size);
	sprt->pika_1 = mlx_xpm_file_to_image(win->mlx,
			"./sprites/pika_1.xpm", &sprt->size, &sprt->size);
	sprt->pika_2 = mlx_xpm_file_to_image(win->mlx,
			"./sprites/pika_2.xpm", &sprt->size, &sprt->size);
	sprt->spectrum_1 = mlx_xpm_file_to_image(win->mlx,
			"./sprites/spectrum_1.xpm", &sprt->size, &sprt->size);
	sprt->spectrum_2 = mlx_xpm_file_to_image(win->mlx,
			"./sprites/spectrum_2.xpm", &sprt->size, &sprt->size);
}

void	get_oak_sprites(t_sprt *sprt, t_win *win)
{
	sprt->oak_i_d = mlx_xpm_file_to_image(win->mlx,
			"./sprites/oak_i_d.xpm", &sprt->size, &sprt->size);
	sprt->oak_i_u = mlx_xpm_file_to_image(win->mlx,
			"./sprites/oak_i_u.xpm", &sprt->size, &sprt->size);
	sprt->oak_i_l = mlx_xpm_file_to_image(win->mlx,
			"./sprites/oak_i_l.xpm", &sprt->size, &sprt->size);
	sprt->oak_i_r = mlx_xpm_file_to_image(win->mlx,
			"./sprites/oak_i_r.xpm", &sprt->size, &sprt->size);
	sprt->oak_w_d = mlx_xpm_file_to_image(win->mlx,
			"./sprites/oak_w_d.xpm", &sprt->size, &sprt->size);
	sprt->oak_w_d_2 = mlx_xpm_file_to_image(win->mlx,
			"./sprites/oak_w_d_2.xpm", &sprt->size, &sprt->size);
	sprt->oak_w_u = mlx_xpm_file_to_image(win->mlx,
			"./sprites/oak_w_u.xpm", &sprt->size, &sprt->size);
	sprt->oak_w_u_2 = mlx_xpm_file_to_image(win->mlx,
			"./sprites/oak_w_u_2.xpm", &sprt->size, &sprt->size);
	sprt->oak_w_l = mlx_xpm_file_to_image(win->mlx,
			"./sprites/oak_w_l.xpm", &sprt->size, &sprt->size);
	sprt->oak_w_r = mlx_xpm_file_to_image(win->mlx,
			"./sprites/oak_w_r.xpm", &sprt->size, &sprt->size);
}
