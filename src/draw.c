/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziabkin <aziabkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 16:10:28 by aziabkin          #+#    #+#             */
/*   Updated: 2018/08/08 18:46:03 by aziabkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	choice_fc(t_structs *s, int x, int y)
{
	if (s->w->chng == 1)
	{
		put_rgb_floor1(s);
		put_image(s, x, y, s->w->color);
		put_rgb_ceil1(s);
		put_image(s, x, S_H - y, s->w->color);
	}
	else if (s->w->chng == 0)
	{
		put_rgb_floor2(s);
		put_image(s, x, y, s->w->color);
		put_rgb_ceil2(s);
		put_image(s, x, S_H - y, s->w->color);
	}
}

void	floor_ceiling(t_structs *s, int x)
{
	int y;

	y = s->w->draw_end + 1;
	s->w->dist_player = 0.0;
	s->w->dist_wall = s->w->perp_w_d;
	while (y++ < S_H)
	{
		s->w->curr_dist = S_H / (2.0 * y - S_H);
		s->w->weight = (s->w->curr_dist - s->w->dist_player) /\
									(s->w->dist_wall - s->w->dist_player);
		s->w->curr_fl_x = s->w->weight * s->w->fl_wall_x +\
									(1.0 - s->w->weight) * s->w->pos_x;
		s->w->curr_fl_y = s->w->weight * s->w->fl_wall_y +\
									(1.0 - s->w->weight) * s->w->pos_y;
		s->w->fl_tex_x = (int)(s->w->curr_fl_x * T_W) % T_W;
		s->w->fl_tex_y = (int)(s->w->curr_fl_y * T_H) % T_H;
		choice_fc(s, x, y);
	}
}

void	calc_fc(t_structs *s)
{
	if (s->w->side == 0 && s->w->ray_dir_x > 0)
	{
		s->w->fl_wall_x = s->w->map_x;
		s->w->fl_wall_y = s->w->map_y + s->w->wall;
	}
	else if (s->w->side == 0 && s->w->ray_dir_x < 0)
	{
		s->w->fl_wall_x = s->w->map_x + 1.0;
		s->w->fl_wall_y = s->w->map_y + s->w->wall;
	}
	else if (s->w->side == 1 && s->w->ray_dir_y > 0)
	{
		s->w->fl_wall_x = s->w->map_x + s->w->wall;
		s->w->fl_wall_y = s->w->map_y;
	}
	else
	{
		s->w->fl_wall_x = s->w->map_x + s->w->wall;
		s->w->fl_wall_y = s->w->map_y + 1.0;
	}
	if (s->w->draw_end < 0)
		s->w->draw_end = S_H;
}
