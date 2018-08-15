/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziabkin <aziabkin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 21:01:36 by aziabkin          #+#    #+#             */
/*   Updated: 2018/08/09 21:01:38 by aziabkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	walls_from_map(t_structs *strs, int x)
{
	int i;

	i = strs->w->draw_start;
	if (MAP_X_Y != 0)
		strs->n = MAP_X_Y - 1;
	while (i++ < strs->w->draw_end)
	{
		strs->w->color = texture(strs, i, strs->n);
		if (strs->w->side == 1)
			strs->w->color = (strs->w->color >> 1) & 8355711;
		put_image(strs, x, i, strs->w->color);
	}
}

void	walls_compass(t_structs *strs, int x)
{
	int i;

	i = strs->w->draw_start;
	while (i++ < strs->w->draw_end)
	{
		if (strs->w->side == 0)
		{
			if (strs->w->step_x < 0)
				strs->w->color = texture(strs, i, 6);
			else
				strs->w->color = texture(strs, i, 4);
		}
		else if (strs->w->side == 1)
		{
			if (strs->w->step_y < 0)
				strs->w->color = texture(strs, i, 3);
			else
				strs->w->color = texture(strs, i, 9);
			if (strs->w->side == 1)
				strs->w->color = (strs->w->color >> 1) & 8355711;
		}
		put_image(strs, x, i, strs->w->color);
	}
}
