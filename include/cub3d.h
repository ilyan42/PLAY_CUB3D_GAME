/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elanson <elanson@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 11:35:00 by elanson           #+#    #+#             */
/*   Updated: 2024/06/14 11:35:03 by elanson          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include "../LIBFT/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <math.h>
# include <string.h>
# include "struct.h"
# include "define.h"

/********************************************************/
/*					GET_FILE							*/
/********************************************************/

void		count_map_height(t_cub *cub, int fd);
char		**allocate_and_fill_map(t_cub *cub, int fd);
void		is_cub_file(char *map, t_cub *cub);
void		get_map_and_tex(char *file, t_cub *cub);

/********************************************************/
/*					PARSE_MAP_UTILS						*/
/********************************************************/

bool		valide_position(t_cub *cub, int x, int y);
bool		ft_check_around_floor(t_cub *cub, int x, int y);
bool		ft_check_around_wall(t_cub *cub, int x, int y);

/********************************************************/
/*					PARSE_MAP							*/
/********************************************************/

void		get_size_map(t_cub *cub);
void		init_player(t_cub *cub, int x, int y);
void		get_player_position(t_cub *cub);
void		check_first_colone(t_cub *cub);
void		map_is_valid(t_cub *cub);

/********************************************************/
/*					TEXTURE_FILE						*/
/********************************************************/

int			check_nb_texture(t_cub *cub, int y);
void		count_texture_height(t_cub *cub, int fd);
char		**parse_texture_file(t_cub *cub, int fd);
int			is_in_space(char *line, int y);

/********************************************************/
/*					PARSE_AND_OPEN_TEXTURE				*/
/********************************************************/

void		parsing_texture(t_cub *cub);
int			open_texture(t_cub *cub);
void		check_extention_texture(char *path, t_cub *cub);
void		texture_processing(t_cub *cub);

/********************************************************/
/*					PUT_TEXTURE							*/
/********************************************************/

int			put_texture_no_so(char *line, int *check, int x, t_cub *cub);
int			put_texture_we_ea(char *line, int *check, int x, t_cub *cub);
int			put_texture_c_f_d(char *line, int *check, int x, t_cub *cub);
int			put_texture(char *line, int *check, int x, t_cub *cub);
int			put_texture_door(char *line, int *check, int x, t_cub *cub);

/********************************************************/
/*					GET_TEXTURE							*/
/********************************************************/

int			parse_north_texture(t_cub *cub, char *line, int x);
int			parse_south_texture(t_cub *cub, char *line, int x);
int			parse_west_texture(t_cub *cub, char *line, int x);
int			parse_east_texture(t_cub *cub, char *line, int x);

/********************************************************/
/*					COLOR								*/
/********************************************************/

void		convert_color_hex(t_cub *cub);
int			parse_floor_color(t_cub *cub, char *line);
int			parse_ceiling_color(t_cub *cub, char *line);

/********************************************************/
/*					GET_DISTANCE_WALL					*/
/********************************************************/

void		init_raycast(t_cub *cub, t_raycast *raycast, int x);
void		get_step_and_side_dist(t_cub *cub, t_raycast *raycast);
void		perform_dda(t_cub *cub, t_raycast *raycast);
void		get_distance(t_cub *cub, t_raycast *raycast);

/********************************************************/
/*					GET_MINI_MAP						*/
/********************************************************/

void		init_struct_mini_map(t_cub *cub);
void		draw_mini_map_wall(t_cub *cub, t_mini_map *mini_map,
				int x, int y);
void		draw_mini_map_floor(t_cub *cub, t_mini_map *mini_map,
				int x, int y);
void		draw_mini_map_player(t_cub *cub, t_mini_map *mini_map);
void		display_map_pixel_color(t_cub *cub);

/********************************************************/
/*					PLAYER_MOUVEMENT					*/
/********************************************************/

int			key_press(int key, t_cub *data);
int			key_release(int key, t_cub *data);
int			key_press(int key, t_cub *data);
int			key_release(int key, t_cub *data);
int			ft_handle_key_press(t_cub *cub);
int			is_position_valid(t_cub *cub, double new_x, double new_y);
void		maj_plane_player(t_cub *cub);
void		move_forward(t_cub *cub);
void		move_backward(t_cub *cub);
void		move_left(t_cub *cub);
void		move_right(t_cub *cub);
void		cam_rotate_left(t_cub *cub, double angle_delta);
void		cam_rotate_right(t_cub *cub, double angle_delta);
int			mouse_move(int x, int y, t_cub *cub);

/********************************************************/
/*					RENDER_RAYCAST						*/
/********************************************************/

void		draw_wall(t_cub *cub, int x, t_raycast *ray);
int			get_pixel_color(t_texture *texture, int x, int y);
t_texture	get_player_direction(t_cub *cub, t_raycast *ray,
				t_texture texture);
void		ray_wall_x_init(t_cub *cub, t_raycast *ray);

/********************************************************/
/*					INIT_STRUCT							*/
/********************************************************/

void		init_struct_cub(t_cub *cub);

/********************************************************/
/*					RENDER_UTILS						*/
/********************************************************/

void		my_pixel_put(t_image *image, int x, int y, int color);
void		draw_floor_ceilling(t_cub *cub, int x, int draw_start,
				t_raycast *ray);
void		init_draw_start_end(t_cub *cub);

/********************************************************/
/*					ERROR								*/
/********************************************************/

void		print_and_exit(char *msg, t_cub *cub, int err);
int			close_game(t_cub *cub);

/********************************************************/
/*					RAYCASTING							*/
/********************************************************/

void		raycasting(void *param);

/********************************************************/
/*					INIT_STRUCT							*/
/********************************************************/

void		init_struct_mlx(t_cub *cub);
void		init_struct_map(t_cub *cub);
void		init_struct_image(t_cub *cub);
void		init_struct_player(t_cub *cub);
void		init_struct_color(t_cub *cub);
void		init_struct_key(t_cub *cub);
void		init_struct_key_good(t_cub *cub);
void		init_struct_raycast(t_cub *cub);
void		init_struct_cub(t_cub *cub);
void		init_struct_raycast_utils(t_cub *cub);

/********************************************************/
/*					INIT_SPRITE_WINDOW					*/
/********************************************************/

void		init_window(t_minilibx *window, t_cub *cub);
t_texture	new_sprite(t_cub *cub, int i);
void		init_sprite(t_cub *cub);
void		initialize_textures(t_cub *cub);
void		init_image(t_cub *cub);

/********************************************************/
/*					DOOR								*/
/********************************************************/

int			parse_door_texture(t_cub *cub, char *line, int x);
void		open_close_door(t_cub *cub);
void		draw_mini_map_door(t_cub *cub, t_mini_map *mini_map, int x, int y);

/********************************************************/
/*					CHECK_MAP							*/
/********************************************************/

void		check_to_many_player(t_cub *cub);
void		check_character_in_map(t_cub *cub);
void		check_first_colone(t_cub *cub);
void		check_map(t_cub *cub);

/********************************************************/
/*						FREE							*/
/********************************************************/

void		free_image(t_image *image, void *mlx_ptr);
void		free_mlx(t_minilibx *mlx);
void		free_player(t_player *player);
void		free_raycast(t_raycast *raycast);
void		free_keys(t_key *keys);
void		ft_destroy_utils(t_cub *cub);
void		ft_destroy(t_cub *cub);
void		free_map(t_map *map);
void		free_texture_file(t_texture_file *texture_file);
void		clear_before_exit_3(t_cub *cub);
void		clear_before_exit_2(t_cub *cub);
void		clear_before_exit(t_cub *cub, int err);
void		free_split(char **tmp_line);

/********************************************************/
/*						WEAPON							*/
/********************************************************/

void		draw(t_cub *cub, t_image *img);
int			mousepress(int keycode, int x, int y, t_cub *cub);
void		init_gun(t_cub *cub);
void		init_weapon_utils(t_cub *cub);

/********************************************************/
/*						UTILS							*/
/********************************************************/

bool		has_only_spaces(const char *start, const char *end);
int			is_valid_floor_color_char(char c);
void		validate_floor_color_values(const char *color_values, t_cub *cub);
void		check_first_line(t_cub *cub);
void		check_last_line(t_cub *cub);
void		free_textures(t_cub *cub);
void		free_gun(t_cub *cub);
void		init_order_tex(t_cub *cub);
int			check_cmp(char *line);
int			check_line(char *line, int check, t_cub *cub, int texture_found);
int			isspace(int c);
bool		has_only_spaces_before(const char *line, int pos);
void		validate_ceilling_color_values(const char
				*color_values, t_cub *cub);

#endif