/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_fc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziabkin <aziabkin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/10 20:04:24 by aziabkin          #+#    #+#             */
/*   Updated: 2018/08/10 20:04:25 by aziabkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	put_rgb_floor1(t_structs *s)
{
	s->r = s->data[1][s->sl[1] * s->w->fl_tex_y + s->w->fl_tex_x * 4 + 2];
	s->g = s->data[1][s->sl[1] * s->w->fl_tex_y + s->w->fl_tex_x * 4 + 1];
	s->b = s->data[1][s->sl[1] * s->w->fl_tex_y + s->w->fl_tex_x * 4];
	s->w->color = ((s->r & 0xff) << 16) + ((s->g & 0xff) << 8) + (s->b & 0xff);
	s->w->color = (s->w->color >> 1) & 8355711;
}

void	put_rgb_ceil1(t_structs *s)
{
	s->r = s->data[2][s->sl[2] * s->w->fl_tex_y + s->w->fl_tex_x * 4 + 2];
	s->g = s->data[2][s->sl[2] * s->w->fl_tex_y + s->w->fl_tex_x * 4 + 1];
	s->b = s->data[2][s->sl[2] * s->w->fl_tex_y + s->w->fl_tex_x * 4];
	s->w->color = ((s->r & 0xff) << 16) + ((s->g & 0xff) << 8) + (s->b & 0xff);
	s->w->color = (s->w->color >> 1) & 8355711;
}

void	put_rgb_floor2(t_structs *s)
{
	s->r = s->data[10][s->sl[10] * s->w->fl_tex_y + s->w->fl_tex_x * 4 + 2];
	s->g = s->data[10][s->sl[10] * s->w->fl_tex_y + s->w->fl_tex_x * 4 + 1];
	s->b = s->data[10][s->sl[10] * s->w->fl_tex_y + s->w->fl_tex_x * 4];
	s->w->color = ((s->r & 0xff) << 16) + ((s->g & 0xff) << 8) + (s->b & 0xff);
	s->w->color = (s->w->color >> 1) & 8355711;
}

void	put_rgb_ceil2(t_structs *s)
{
	s->r = s->data[8][s->sl[8] * s->w->fl_tex_y + s->w->fl_tex_x * 4 + 2];
	s->g = s->data[8][s->sl[8] * s->w->fl_tex_y + s->w->fl_tex_x * 4 + 1];
	s->b = s->data[8][s->sl[8] * s->w->fl_tex_y + s->w->fl_tex_x * 4];
	s->w->color = ((s->r & 0xff) << 16) + ((s->g & 0xff) << 8) + (s->b & 0xff);
	s->w->color = (s->w->color >> 1) & 8355711;
}
