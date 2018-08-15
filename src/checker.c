/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziabkin <aziabkin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 21:18:27 by aziabkin          #+#    #+#             */
/*   Updated: 2018/08/09 21:18:30 by aziabkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	check_pos(t_wolf *w)
{
	if (w->map[(int)w->pos_x][(int)w->pos_y] != 0)
		error_exit(6);
}

void	check_size(t_wolf *w)
{
	if (w->map_h > 100 || w->map_h < 4)
		error_exit(7);
	if (w->map_w > 100 || w->map_w < 4)
		error_exit(7);
}

int		check_dig(char *str)
{
	int		val;
	int		i;
	char	**nums;

	nums = ft_strsplit(str, ' ');
	val = 1;
	i = 0;
	while (nums[i])
	{
		if ((ft_atoi(nums[i]) >= 0 && ft_atoi(nums[i]) <= 11))
			val *= 1;
		else
			error_exit(4);
		i++;
	}
	free_arr(nums);
	return (val);
}
