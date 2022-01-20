/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 14:40:46 by llethuil          #+#    #+#             */
/*   Updated: 2022/01/13 14:31:23 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	kill(t_data *data)
{
	mlx_destroy_window(data->win.mlx, data->win.frame);
	exit(0);
}
