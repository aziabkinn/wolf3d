/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziabkin <aziabkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 14:15:10 by aziabkin          #+#    #+#             */
/*   Updated: 2018/08/08 19:12:43 by aziabkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	rebuild(t_structs *strs)
{
	ft_memset(strs->wind->adress, 0, S_W * S_H * 4);
	raycasting(strs);
	mlx_put_image_to_window(strs->wind->mlx, strs->wind->window,
							strs->wind->image, 0, 0);
	hints(strs, 2);
	hints(strs, 0);
}

void	on_keys(int key, t_structs *strs)
{
	if (key == UP1 || key == UP2)
		strs->up = 1;
	if (key == DOWN1 || key == DOWN2)
		strs->down = 1;
	if (key == ROT_R1 || key == ROT_R2)
		strs->rot_r = 1;
	if (key == ROT_L1 || key == ROT_L2)
		strs->rot_l = 1;
	if (key == LEFT1 || key == LEFT2)
		strs->left = 1;
	if (key == RIGHT1 || key == RIGHT2)
		strs->right = 1;
	if (key == SPACE)
		strs->speed = 1;
}

int		on(int key, t_structs *strs)
{
	if (key == ESC)
	{
		system("killall -9 afplay");
		exit(0);
	}
	if (key == ENTER)
	{
		if (strs->w->chng == 1)
			strs->w->chng = 0;
		else
			strs->w->chng = 1;
		rebuild(strs);
	}
	on_keys(key, strs);
	return (0);
}

int		off(int key, t_structs *strs)
{
	if (key == UP1 || key == UP2)
		strs->up = 0;
	if (key == DOWN1 || key == DOWN2)
		strs->down = 0;
	if (key == ROT_R1 || key == ROT_R2)
		strs->rot_r = 0;
	if (key == ROT_L1 || key == ROT_L2)
		strs->rot_l = 0;
	if (key == LEFT1 || key == LEFT2)
		strs->left = 0;
	if (key == RIGHT1 || key == RIGHT2)
		strs->right = 0;
	if (key == SPACE)
		strs->speed = 0;
	return (0);
}
