/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziabkin <aziabkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 13:48:54 by aziabkin          #+#    #+#             */
/*   Updated: 2018/08/08 19:12:27 by aziabkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_WOLF3D_H
# define FT_WOLF3D_H

# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <signal.h>

# define S_W 1000
# define S_H 800
# define T_W 64
# define T_H 64

# define R 0.1
# define M 1.5708
# define C 0.05

# define ESC 53
# define SPACE 49
# define ENTER 36

# define UP1 126
# define DOWN1 125
# define LEFT1 123
# define RIGHT1 124
# define ROT_R1 84
# define ROT_L1 83

# define UP2 13
# define DOWN2 1
# define ROT_R2 14
# define ROT_L2 12
# define LEFT2 0
# define RIGHT2 2

# define MAP_X_Y strs->w->map[strs->w->map_x][strs->w->map_y]
# define SPEED ((s->speed == 1) ? 0.2 : 0.1)

typedef struct		s_wolf
{
	int				**map;
	int				map_w;
	int				map_h;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			camera_x;
	double			ray_dir_x;
	double			ray_dir_y;
	int				map_x;
	int				map_y;
	double			side_d_x;
	double			side_d_y;
	double			del_d_x;
	double			del_d_y;
	double			perp_w_d;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	int				line_h;
	int				draw_start;
	int				draw_end;
	double			old_dir_x;
	double			old_plane_x;
	unsigned int	color;
	int				d;
	double			wall;
	int				tex_x;
	int				tex_y;
	int				chng;
	double			fl_wall_x;
	double			fl_wall_y;
	double			dist_wall;
	double			dist_player;
	double			curr_dist;
	double			weight;
	double			curr_fl_x;
	double			curr_fl_y;
	int				fl_tex_x;
	int				fl_tex_y;
}					t_wolf;

typedef struct		s_window
{
	void			*mlx;
	void			*image;
	void			*window;
	int				*adress;
	int				endian;
	int				size_line;
	int				bpp;
}					t_window;

typedef struct		s_structs
{
	t_wolf			*w;
	t_window		*wind;
	int				n;
	void			*img[11];
	char			*data[11];
	int				end[11];
	int				sl[11];
	int				bpp[11];
	int				r;
	int				g;
	int				b;
	int				up;
	int				down;
	int				left;
	double			speed;
	int				right;
	int				rot_r;
	int				rot_l;
	int				chng;
}					t_structs;

void				error_exit(int a);
int					exit_x(int key, t_structs *strs);
void				create_window(t_window **wind);
t_window			*new_window(void);
void				put_image(t_structs *s, int x, int y, unsigned int color);
void				free_arr(char **splitted_arr);
void				read_map(t_wolf *wolf, int fd);
int					validator_file(int fd, t_wolf *wolf);
int					check_input(int fd, int len_first, t_wolf *wolf);
int					check_input1(int len, char **splitted_arr, char *str);
int					check_dig(char *str);
void				raycasting(t_structs *strs);
void				draw(t_structs *strs, int x);
void				dda(t_structs *strs);
void				count_step_side(t_structs *strs);
void				realization(t_structs *strs);
void				count_step_side(t_structs *strs);
void				rebuild(t_structs *strs);
void				load_textures(t_structs *s);
void				get_data_addr(t_structs *s);
void				walls_from_map(t_structs *strs, int x);
void				walls_compass(t_structs *strs, int x);
int					texture(t_structs *s, int y, int t);
void				calc_fc(t_structs *s);
void				floor_ceiling(t_structs *s, int x);
void				put_rgb_floor1(t_structs *s);
void				put_rgb_ceil1(t_structs *s);
int					on(int key, t_structs *strs);
int					off(int key, t_structs *strs);
int					hadle_input_key(t_structs *s);
int					mouse(int key, int x, int y, t_structs *s);
int					valid_walls(t_wolf *w);
void				check_pos(t_wolf *w);
void				move_lr(t_structs *s);
void				rotate(t_structs *s);
void				check_size(t_wolf *w);
void				read_and_window(t_structs *strs, int fd);
void				program(t_structs *strs);
void				put_rgb_floor2(t_structs *s);
void				put_rgb_ceil2(t_structs *s);
void				hints(t_structs *s, int c);
void				stop_music(int sign);
void				choice_fc(t_structs *s, int x, int y);
void				on_keys(int key, t_structs *strs);

#endif
