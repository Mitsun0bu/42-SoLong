/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llethuil <llethuil@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 11:24:15 by llethuil          #+#    #+#             */
/*   Updated: 2022/01/19 11:39:37 by llethuil         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                               ~~~ DEFINES ~~~                              */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* ************************************************************************** */
/*                                                                            */
/*                               ~~~ INCLUDES ~~~                             */
/*                                                                            */
/* ************************************************************************** */

# include "../libft/libft.h"
# include "../mlx/mlx.h"

/* ************************************************************************** */
/*                                                                            */
/*                              ~~~ TYPEDEFS ~~~                              */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_map
{
	char	*line;
	char	*unidim;
	char	**bidim;
	int		n_c;
	int		n_e;
	int		n_p;
	int		wdth;
	int		x;
	int		hgt;
	int		y;
}	t_map;

typedef struct s_player
{
	int		x;
	int		y;
	void	*sprite;
	int		step;
	int		collected;
	int		available;
	int		win_event;
}	t_player;

typedef struct s_sprt
{
	void	*img;
	int		size;
	int		state;
	void	*bulbi_1;
	void	*bulbi_2;
	void	*grass_1;
	void	*grass_2_1;
	void	*grass_2_2;
	void	*grass_3;
	void	*oak_i_d;
	void	*oak_i_u;
	void	*oak_i_l;
	void	*oak_i_r;
	void	*oak_w_d;
	void	*oak_w_d_2;
	void	*oak_w_u;
	void	*oak_w_u_2;
	void	*oak_w_l;
	void	*oak_w_r;
	void	*pika_1;
	void	*pika_2;
	void	*pokeball;
	void	*ladder;
	void	*spectrum_1;
	void	*spectrum_2;
	void	*tree;
	void	*end_screen;
}	t_sprt;

typedef struct s_win
{
	void	*mlx;
	void	*frame;
	int		wdth;
	int		x;
	int		hgt;
	int		y;
}	t_win;

typedef struct s_cam
{
	int		x;
	int		y;
}	t_cam;

typedef struct s_data
{
	t_map		map;
	t_player	player;
	t_sprt		sprt;
	t_win		win;
	t_cam		cam;
}	t_data;

/* ************************************************************************** */
/*                                                                            */
/*                              ~~~ PROTOTYPES ~~~                            */
/*                                                                            */
/* ************************************************************************** */

/* add_textures_1.c */
void	add_textures(t_data *data);
void	select_field_sprite(t_data *data);
void	put_field_sprite(t_data *data, char c);
void	select_pokemon_sprite(t_data *data);
void	put_pokemon_sprite(t_data *data, char c);

/* add_textures_2.c */
int		set_animation(t_data *data);
void	display_player(t_data *data);
void	display_hud(t_data *data);
void	put_hud_str(t_data *data, char *steps, char *total_hud);

/* events.c */
void	check_event(t_data *data);
void	check_catch(t_data *data);
void	catch_pokemon(t_data *data);

/* move_player.c */
int		move_player(int key_code, t_data *data);
void	move_up(t_data *data);
void	move_left(t_data *data);
void	move_right(t_data *data);
void	move_down(t_data *data);

/* get_map.c */
void	get_map(t_map *map, int argc, char **argv);
int		open_map_file(int argc, char **argv);
int		map_init(t_map *map, int fd);
void	close_map_file(int fd);

/* get_sprites.c */
void	get_field_sprites(t_sprt *sprt, t_win *win);
void	get_pokemon_sprites(t_sprt *sprt, t_win *win);
void	get_oak_sprites(t_sprt *sprt, t_win *win);

/* get_window.c */
void	get_window(t_data *data);
void	cam_init(t_data *data);

/* main.c */
int		main(int argc, char **argv);

/* parse_map.c */
int		parse_map(t_map *map);
int		check_map_edges(t_map *map);
int		check_map_rectangular(t_map *map);
int		check_map_composition(t_map *map);

/* get_player.c */
void	get_player(t_data *data);

/* randomize_field */
void	randomize_field(t_map *map);
void	randomize_pokemon(t_map *map, char c);
int		get_random(void);

/* utils.c */
int		kill(t_data *data);

#endif