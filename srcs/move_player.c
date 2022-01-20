/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 18:16:56 by llethuil          #+#    #+#             */
/*   Updated: 2022/01/19 11:58:31 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	move_player(int key_code, t_data *data)
{
	if (data->player.win_event == 1)
		kill(data);
	if (key_code == 13)
		move_up(data);
	if (key_code == 0)
		move_left(data);
	if (key_code == 2)
		move_right(data);
	if (key_code == 1)
		move_down(data);
	if (key_code == 49 && data->player.available > 0)
		catch_pokemon(data);
	else if (key_code == 49 && data->player.available <= 0)
		printf("You don't have enough Pokeball !\n");
	if (key_code == 53)
		kill(data);
	check_event(data);
	if (data->player.win_event != 1)
		add_textures(data);
	return (0);
}

void	move_up(t_data *data)
{
	static int	turn = 0;

	if (data->map.bidim[(data->player.y) - 1][(data->player.x)] != '1'
		&& data->map.bidim[(data->player.y) - 1][(data->player.x)] != 'B'
		&& data->map.bidim[(data->player.y) - 1][(data->player.x)] != 'p'
		&& data->map.bidim[(data->player.y) - 1][(data->player.x)] != 'S')
	{
		data->player.y --;
		data->player.step ++;
		printf("Player is going up. %d steps done.\n", data->player.step);
	}
	check_catch(data);
	if (turn == 0 || turn == 1)
	{
		if (turn == 0)
			data->player.sprite = data->sprt.oak_i_u;
		if (turn == 1)
			data->player.sprite = data->sprt.oak_w_u;
		turn ++;
	}
	else if (turn == 2)
	{
		data->player.sprite = data->sprt.oak_w_u_2;
		turn --;
	}
}

void	move_left(t_data *data)
{
	static int	turn = 0;

	if (data->map.bidim[(data->player.y)][(data->player.x) - 1] != '1'
		&& data->map.bidim[(data->player.y)][(data->player.x) - 1] != 'B'
		&& data->map.bidim[(data->player.y)][(data->player.x) - 1] != 'p'
		&& data->map.bidim[(data->player.y)][(data->player.x) - 1] != 'S')
	{
		data->player.x --;
		data->player.step ++;
		printf("Player is going left. %d steps done.\n", data->player.step);
	}
	if (turn == 0)
	{
		data->player.sprite = data->sprt.oak_w_l;
		turn ++;
	}
	else if (turn == 1)
	{
		data->player.sprite = data->sprt.oak_i_l;
		turn --;
	}
}

void	move_right(t_data *data)
{
	static int	turn = 0;

	if (data->map.bidim[(data->player.y)][(data->player.x) + 1] != '1'
		&& data->map.bidim[(data->player.y)][(data->player.x) + 1] != 'B'
		&& data->map.bidim[(data->player.y)][(data->player.x) + 1] != 'p'
		&& data->map.bidim[(data->player.y)][(data->player.x) + 1] != 'S')
	{
		data->player.x ++;
		data->player.step ++;
		printf("Player is going right. %d steps done.\n", data->player.step);
	}
	if (turn == 0)
	{
		data->player.sprite = data->sprt.oak_w_r;
		turn ++;
	}
	else if (turn == 1)
	{
		data->player.sprite = data->sprt.oak_i_r;
		turn --;
	}
}

void	move_down(t_data *data)
{
	static int	turn = 0;

	if (data->map.bidim[(data->player.y) + 1][(data->player.x)] != '1'
		&& data->map.bidim[(data->player.y) + 1][(data->player.x)] != 'B'
		&& data->map.bidim[(data->player.y) + 1][(data->player.x)] != 'p'
		&& data->map.bidim[(data->player.y) + 1][(data->player.x)] != 'S')
	{
		data->player.y ++;
		data->player.step ++;
		printf("Player is going down. %d steps done.\n", data->player.step);
	}
	if (turn == 0 || turn == 1)
	{
		if (turn == 0)
			data->player.sprite = data->sprt.oak_i_d;
		if (turn == 1)
			data->player.sprite = data->sprt.oak_w_d;
		turn ++;
	}
	else if (turn == 2)
	{
		data->player.sprite = data->sprt.oak_w_d_2;
		turn --;
	}
}
