/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziabkin <aziabkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 17:50:21 by aziabkin          #+#    #+#             */
/*   Updated: 2018/08/08 18:31:37 by aziabkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		texture(t_structs *s, int y, int t)
{
	s->w->d = y * s->sl[t] - S_H * 128 + s->w->line_h * 128;
	s->w->tex_y = ((s->w->d * T_H) / s->w->line_h) / s->sl[t];
	s->r = s->data[t][(s->sl[t] *
							s->w->tex_y + s->w->tex_x * 4) + 2];
	s->g = s->data[t][(s->sl[t] *
							s->w->tex_y + s->w->tex_x * 4) + 1];
	s->b = s->data[t][s->sl[t] * s->w->tex_y + s->w->tex_x * 4];
	s->w->color = ((s->r & 0xff) << 16) + ((s->g & 0xff) << 8) +\
					(s->b & 0xff);
	s->w->color = (s->w->color >> 1) & 8355711;
	return (s->w->color);
}

void	get_data_addr(t_structs *s)
{
	s->data[0] = mlx_get_data_addr(s->img[0], &s->bpp[0],\
										&s->sl[0], &s->end[0]);
	s->data[1] = mlx_get_data_addr(s->img[1], &s->bpp[1],\
										&s->sl[1], &s->end[1]);
	s->data[2] = mlx_get_data_addr(s->img[2], &s->bpp[2],\
										&s->sl[2], &s->end[2]);
	s->data[3] = mlx_get_data_addr(s->img[3], &s->bpp[3],\
										&s->sl[3], &s->end[3]);
	s->data[4] = mlx_get_data_addr(s->img[4], &s->bpp[4],\
										&s->sl[4], &s->end[4]);
	s->data[5] = mlx_get_data_addr(s->img[5], &s->bpp[5],\
										&s->sl[5], &s->end[5]);
	s->data[6] = mlx_get_data_addr(s->img[6], &s->bpp[6],\
										&s->sl[6], &s->end[6]);
	s->data[7] = mlx_get_data_addr(s->img[7], &s->bpp[7],\
										&s->sl[7], &s->end[7]);
	s->data[8] = mlx_get_data_addr(s->img[8], &s->bpp[8],\
										&s->sl[8], &s->end[8]);
	s->data[9] = mlx_get_data_addr(s->img[9], &s->bpp[9],\
										&s->sl[9], &s->end[9]);
	s->data[10] = mlx_get_data_addr(s->img[10], &s->bpp[10],\
										&s->sl[10], &s->end[10]);
}

void	load_textures(t_structs *s)
{
	int i;
	int w;
	int h;

	i = -1;
	w = 64;
	h = 64;
	s->img[0] = mlx_xpm_file_to_image(s->wind->mlx, "tex/clrstone.xpm", &w, &h);
	s->img[1] = mlx_xpm_file_to_image(s->wind->mlx, "tex/blbrick.xpm", &w, &h);
	s->img[2] = mlx_xpm_file_to_image(s->wind->mlx, "tex/sky.xpm", &w, &h);
	s->img[3] = mlx_xpm_file_to_image(s->wind->mlx, "tex/drtfence.xpm", &w, &h);
	s->img[4] = mlx_xpm_file_to_image(s->wind->mlx, "tex/grstone.xpm", &w, &h);
	s->img[5] = mlx_xpm_file_to_image(s->wind->mlx, "tex/wood.xpm", &w, &h);
	s->img[6] = mlx_xpm_file_to_image(s->wind->mlx, "tex/blstone.xpm", &w, &h);
	s->img[7] = mlx_xpm_file_to_image(s->wind->mlx, "tex/eagle.xpm", &w, &h);
	s->img[8] = mlx_xpm_file_to_image(s->wind->mlx, "tex/roof.xpm", &w, &h);
	s->img[9] = mlx_xpm_file_to_image(s->wind->mlx, "tex/redbrick.xpm", &w, &h);
	s->img[10] = mlx_xpm_file_to_image(s->wind->mlx, "tex/metalfl.xpm", &w, &h);
	while (++i < 11)
		if (s->img[i] == NULL)
			error_exit(8);
	get_data_addr(s);
}
