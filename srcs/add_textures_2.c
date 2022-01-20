/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_textures_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 14:29:29 by llethuil          #+#    #+#             */
/*   Updated: 2022/01/13 17:24:16 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	set_animation(t_data *data)
{
	static int	animation_state_switch = 0;

	if (animation_state_switch == 8000)
	{
		if (data->sprt.state == 0)
			data->sprt.state = 1;
		else if (data->sprt.state == 1)
			data->sprt.state = 0;
		animation_state_switch = 0;
		if (data->player.win_event != 1)
			add_textures(data);
	}
	animation_state_switch ++;
	return (0);
}

void	display_player(t_data *data)
{
	if (data->map.x == data->player.x && data->map.y == data->player.y)
	{
		if (data->player.step == 0)
			mlx_put_image_to_window(data->win.mlx, data->win.frame,
				data->sprt.oak_i_d, data->win.x, data->win.y);
		else
			mlx_put_image_to_window(data->win.mlx, data->win.frame,
				data->player.sprite, data->win.x, data->win.y);
	}
	return ;
}

void	display_hud(t_data *data)
{
	char	*collected;
	char	*collected_hud;
	char	*total;
	char	*total_hud;
	char	*steps;

	collected = ft_itoa(data->player.collected);
	total = ft_itoa(data->map.n_c);
	steps = ft_itoa(data->player.step);
	collected_hud = ft_strjoin(collected, "/");
	if (!collected_hud)
	{
		printf("Error !\nHUD display failed !\n");
		exit(1);
	}
	total_hud = ft_strjoin(collected_hud, total);
	if (!total_hud)
	{
		printf("Error !\nHUD display failed !\n");
		exit(1);
	}
	put_hud_str(data, steps, total_hud);
	free(steps);
	free(total);
	free(total_hud);
}

void	put_hud_str(t_data *data, char *steps, char *total_hud)
{
	mlx_string_put(data->win.mlx, data->win.frame,
		120, 50, 0x00FF0000, "steps");
	mlx_string_put(data->win.mlx, data->win.frame,
		120, 75, 0x00FF0000, steps);
	mlx_string_put(data->win.mlx, data->win.frame,
		220, 50, 0x00FF0000, "pokeball");
	mlx_string_put(data->win.mlx, data->win.frame,
		220, 75, 0x00FF0000, total_hud);
}
