/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realization.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziabkin <aziabkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/21 13:15:54 by aziabkin          #+#    #+#             */
/*   Updated: 2018/08/08 19:10:09 by aziabkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	draw(t_structs *strs, int x)
{
	if (strs->w->draw_start < 0)
		strs->w->draw_start = 0;
	strs->w->draw_end = strs->w->line_h / 2 + S_H / 2;
	if (strs->w->draw_end >= S_H)
		strs->w->draw_end = S_H - 1;
	if (strs->w->side == 0)
		strs->w->wall = strs->w->pos_y + strs->w->perp_w_d *\
							strs->w->ray_dir_y;
	else
		strs->w->wall = strs->w->pos_x + strs->w->perp_w_d *\
							strs->w->ray_dir_x;
	strs->w->wall -= floor((strs->w->wall));
	strs->w->tex_x = (int)(strs->w->wall * (double)T_W);
	if (strs->w->side == 0 && strs->w->ray_dir_x > 0)
		strs->w->tex_x = T_W - strs->w->tex_x - 1;
	if (strs->w->side == 1 && strs->w->ray_dir_y < 0)
		strs->w->tex_x = T_W - strs->w->tex_x - 1;
	if (strs->w->chng == 0)
		walls_from_map(strs, x);
	else if (strs->w->chng == 1)
		walls_compass(strs, x);
	calc_fc(strs);
	floor_ceiling(strs, x);
}

void	dda(t_structs *strs)
{
	while (strs->w->hit == 0)
	{
		if (strs->w->side_d_x < strs->w->side_d_y)
		{
			strs->w->side_d_x += strs->w->del_d_x;
			strs->w->map_x += strs->w->step_x;
			strs->w->side = 0;
		}
		else
		{
			strs->w->side_d_y += strs->w->del_d_y;
			strs->w->map_y += strs->w->step_y;
			strs->w->side = 1;
		}
		if (MAP_X_Y > 0)
			strs->w->hit = 1;
	}
	if (strs->w->side == 0)
		strs->w->perp_w_d = (strs->w->map_x - strs->w->pos_x +\
						(1 - strs->w->step_x) / 2) / strs->w->ray_dir_x;
	else
		strs->w->perp_w_d = (strs->w->map_y - strs->w->pos_y +\
						(1 - strs->w->step_y) / 2) / strs->w->ray_dir_y;
	strs->w->line_h = (int)(S_H / strs->w->perp_w_d);
	strs->w->draw_start = -strs->w->line_h / 2 + S_H / 2;
}

void	count_step_side(t_structs *strs)
{
	if (strs->w->ray_dir_x < 0)
	{
		strs->w->step_x = -1;
		strs->w->side_d_x = (strs->w->pos_x - strs->w->map_x) *\
								strs->w->del_d_x;
	}
	else
	{
		strs->w->step_x = 1;
		strs->w->side_d_x = (strs->w->map_x + 1.0 -\
								strs->w->pos_x) * strs->w->del_d_x;
	}
	if (strs->w->ray_dir_y < 0)
	{
		strs->w->step_y = -1;
		strs->w->side_d_y = (strs->w->pos_y - strs->w->map_y) *\
								strs->w->del_d_y;
	}
	else
	{
		strs->w->step_y = 1;
		strs->w->side_d_y = (strs->w->map_y + 1.0 -\
								strs->w->pos_y) * strs->w->del_d_y;
	}
}

void	raycasting(t_structs *strs)
{
	int x;

	x = -1;
	while (++x < S_W)
	{
		strs->w->camera_x = 2 * x / (double)S_W - 1;
		strs->w->ray_dir_x = strs->w->dir_x +\
								strs->w->plane_x * strs->w->camera_x;
		strs->w->ray_dir_y = strs->w->dir_y +\
								strs->w->plane_y * strs->w->camera_x;
		strs->w->map_x = (int)strs->w->pos_x;
		strs->w->map_y = (int)strs->w->pos_y;
		strs->w->del_d_x = fabs(1 / strs->w->ray_dir_x);
		strs->w->del_d_y = fabs(1 / strs->w->ray_dir_y);
		strs->w->hit = 0;
		count_step_side(strs);
		dda(strs);
		draw(strs, x);
	}
}

void	realization(t_structs *strs)
{
	strs->w->pos_x = 1.5;
	strs->w->pos_y = 1.5;
	strs->w->dir_x = 1;
	strs->w->dir_y = 0;
	strs->w->plane_x = 0;
	strs->w->plane_y = 0.66;
	strs->w->chng = 1;
}
