/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziabkin <aziabkin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 21:07:51 by aziabkin          #+#    #+#             */
/*   Updated: 2018/08/09 21:07:52 by aziabkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		mouse(int key, int x, int y, t_structs *s)
{
	(void)y;
	(void)key;
	if (x < 500)
	{
		s->w->old_dir_x = s->w->dir_x;
		s->w->dir_x = s->w->dir_x * cos(-R) - s->w->dir_y * sin(-R);
		s->w->dir_y = s->w->old_dir_x * sin(-R) + s->w->dir_y * cos(-R);
		s->w->old_plane_x = s->w->plane_x;
		s->w->plane_x = s->w->plane_x * cos(-R) - s->w->plane_y * sin(-R);
		s->w->plane_y = s->w->old_plane_x * sin(-R) + s->w->plane_y * cos(-R);
	}
	if (x > 500)
	{
		s->w->old_dir_x = s->w->dir_x;
		s->w->dir_x = s->w->dir_x * cos(R) - s->w->dir_y * sin(R);
		s->w->dir_y = s->w->old_dir_x * sin(R) + s->w->dir_y * cos(R);
		s->w->old_plane_x = s->w->plane_x;
		s->w->plane_x = s->w->plane_x * cos(R) - s->w->plane_y * sin(R);
		s->w->plane_y = s->w->old_plane_x * sin(R) + s->w->plane_y * cos(R);
	}
	rebuild(s);
	return (0);
}

void	rotate(t_structs *s)
{
	if (s->rot_l == 1)
	{
		s->w->old_dir_x = s->w->dir_x;
		s->w->dir_x = s->w->dir_x * cos(-R) - s->w->dir_y * sin(-R);
		s->w->dir_y = s->w->old_dir_x * sin(-R) + s->w->dir_y * cos(-R);
		s->w->old_plane_x = s->w->plane_x;
		s->w->plane_x = s->w->plane_x * cos(-R) - s->w->plane_y * sin(-R);
		s->w->plane_y = s->w->old_plane_x * sin(-R) + s->w->plane_y * cos(-R);
	}
	if (s->rot_r == 1)
	{
		s->w->old_dir_x = s->w->dir_x;
		s->w->dir_x = s->w->dir_x * cos(R) - s->w->dir_y * sin(R);
		s->w->dir_y = s->w->old_dir_x * sin(R) + s->w->dir_y * cos(R);
		s->w->old_plane_x = s->w->plane_x;
		s->w->plane_x = s->w->plane_x * cos(R) - s->w->plane_y * sin(R);
		s->w->plane_y = s->w->old_plane_x * sin(R) + s->w->plane_y * cos(R);
	}
}

void	move_lr(t_structs *s)
{
	if (s->left == 1)
	{
		if (s->w->map[(int)(s->w->pos_x + s->w->dir_x * cos(-M) -
						s->w->dir_y * sin(-M) * 0.4)][(int)s->w->pos_y] == 0)
			s->w->pos_x += (s->w->dir_x * cos(-M) - s->w->dir_y * sin(-M)) * C;
		if (s->w->map[(int)s->w->pos_x][(int)(s->w->pos_y +
				s->w->dir_x * sin(-M) * 0.4 + s->w->dir_y * cos(-M))] == 0)
			s->w->pos_y += (s->w->dir_x * sin(-M) + s->w->dir_y * cos(-M)) * C;
	}
	if (s->right == 1)
	{
		if (s->w->map[(int)(s->w->pos_x + s->w->dir_x * cos(M) -
						s->w->dir_y * sin(M) * 0.4)][(int)s->w->pos_y] == 0)
			s->w->pos_x += (s->w->dir_x * cos(M) - s->w->dir_y * sin(M)) * C;
		if (s->w->map[(int)s->w->pos_x][(int)(s->w->pos_y +
				s->w->dir_x * sin(M) * 0.4 + s->w->dir_y * cos(M))] == 0)
			s->w->pos_y += (s->w->dir_x * sin(M) + s->w->dir_y * cos(M)) * C;
	}
}

int		hadle_input_key(t_structs *s)
{
	if (s->up == 1)
	{
		if (s->w->map[(int)(s->w->pos_x + s->w->dir_x *\
											0.4)][(int)(s->w->pos_y)] == 0)
			s->w->pos_x += s->w->dir_x * SPEED;
		if (s->w->map[(int)(s->w->pos_x)][(int)(s->w->pos_y +\
											s->w->dir_y * 0.4)] == 0)
			s->w->pos_y += s->w->dir_y * SPEED;
	}
	if (s->down == 1)
	{
		if (s->w->map[(int)(s->w->pos_x - s->w->dir_x *\
											0.4)][(int)(s->w->pos_y)] == 0)
			s->w->pos_x -= s->w->dir_x * 0.1;
		if (s->w->map[(int)(s->w->pos_x)][(int)(s->w->pos_y -\
												s->w->dir_y * 0.4)] == 0)
			s->w->pos_y -= s->w->dir_y * 0.1;
	}
	rotate(s);
	move_lr(s);
	rebuild(s);
	return (0);
}
