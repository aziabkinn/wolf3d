/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziabkin <aziabkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/14 14:20:31 by aziabkin          #+#    #+#             */
/*   Updated: 2018/07/14 14:23:41 by aziabkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		put_image(t_structs *s, int x, int y, unsigned int color)
{
	if (x >= 0 && y >= 0 && x < S_W && y < S_H)
		s->wind->adress[(y * S_W + x)] = color;
}

void		error_exit(int a)
{
	if (a == 1)
		ft_putendl("Invalid map :)");
	else if (a == 2)
		ft_putendl("Can't open file :)");
	else if (a == 3)
	{
		ft_putendl("usage: ./wolf3d maps/[name of maps]\n");
		ft_putendl("The numbers in the row of maps should be written in space");
	}
	else if (a == 4)
		ft_putendl("Invalid map! You should write numbers from 0 to 11 :)");
	else if (a == 5)
		ft_putendl("Invalid map! You can't set 0 on the edges of the map :)");
	else if (a == 6)
		ft_putendl("Invalid map! You can't set texture on the start position!");
	else if (a == 7)
		ft_putendl("Invalid map! Wrong size of map :)");
	else if (a == 8)
		ft_putendl("Error texture!");
	exit(0);
}

int			exit_x(int key, t_structs *strs)
{
	(void)strs;
	(void)key;
	system("killall -9 afplay");
	exit(0);
	return (0);
}

t_window	*new_window(void)
{
	t_window	*new;

	new = (t_window *)malloc(sizeof(t_window));
	new->image = NULL;
	new->window = NULL;
	new->adress = NULL;
	new->endian = 0;
	new->size_line = 0;
	new->bpp = 0;
	return (new);
}

void		create_window(t_window **wind)
{
	(*wind)->mlx = mlx_init();
	(*wind)->window = mlx_new_window((*wind)->mlx, S_W, S_H,
								"Project Wolf3d aziabkin");
}
