/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 14:53:14 by llethuil          #+#    #+#             */
/*   Updated: 2022/01/20 10:48:44 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_event(t_data *data)
{
	int	x_endscreen;
	int	y_endscreen;

	x_endscreen = (data->win.wdth / 2) - 500;
	y_endscreen = (data->win.hgt / 2) - 280;
	if (data->map.bidim[(data->player.y)][(data->player.x)] == 'C')
	{
		data->map.bidim[(data->player.y)][(data->player.x)] = '0';
		data->player.collected ++;
		data->player.available ++;
		printf("Player has collected a collectible !\n");
	}
	if (data->map.bidim[(data->player.y)][(data->player.x)] == 'E'
			&& data->player.collected == data->map.n_c)
	{
		printf("Congratulations! You win!\n");
		data->player.win_event = 1;
		mlx_clear_window(data->win.mlx, data->win.frame);
		mlx_put_image_to_window(data->win.mlx,
			data->win.frame, data->sprt.end_screen, x_endscreen, y_endscreen);
	}
}

void	check_catch(t_data *data)
{
	if (data->map.bidim[(data->player.y) - 1][(data->player.x)] == 'B'
		|| data->map.bidim[(data->player.y) - 1][(data->player.x)] == 'p'
		|| data->map.bidim[(data->player.y) - 1][(data->player.x)] == 'S')
		printf("Wow ! A wild Pokemon appears, press 'space' to catch it !\n");
}

void	catch_pokemon(t_data *data)
{
	if (data->map.bidim[(data->player.y) - 1][(data->player.x)] == 'B')
	{
		data->map.bidim[(data->player.y) - 1][(data->player.x)] = '0';
		data->player.available --;
		printf("You have caught a Bulbasaur!\n");
	}
	else if (data->map.bidim[(data->player.y) - 1][(data->player.x)] == 'p')
	{
		data->map.bidim[(data->player.y) - 1][(data->player.x)] = '0';
		data->player.available --;
		printf("You have caught a Pikachu!\n");
	}
	else if (data->map.bidim[(data->player.y) - 1][(data->player.x)] == 'S')
	{
		data->map.bidim[(data->player.y) - 1][(data->player.x)] = '0';
		data->player.available --;
		printf("You have caught a Haunter!\n");
	}
}
