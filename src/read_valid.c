/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_valid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziabkin <aziabkin@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/09 21:17:00 by aziabkin          #+#    #+#             */
/*   Updated: 2018/08/09 21:17:02 by aziabkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		valid_walls(t_wolf *w)
{
	int i;

	i = 0;
	while (i < w->map_w)
	{
		if (w->map[0][i] == 0 || w->map[w->map_h - 1][i] == 0)
			return (0);
		i++;
	}
	i = 0;
	while (i < w->map_h)
	{
		if (w->map[i][0] == 0 || w->map[i][w->map_w - 1] == 0)
			return (0);
		i++;
	}
	return (1);
}

int		check_input1(int len, char **splitted_arr, char *str)
{
	while (len--)
		if (check_dig(splitted_arr[len]) != 1)
		{
			free_arr(splitted_arr);
			free(str);
			return (0);
		}
	free_arr(splitted_arr);
	free(str);
	return (1);
}

int		check_input(int fd, int len_first, t_wolf *wolf)
{
	int		i;
	char	*str;
	int		len;
	char	**splitted_arr;

	i = 1;
	splitted_arr = NULL;
	while (get_next_line(fd, &str) > 0 && i++)
	{
		len = 0;
		splitted_arr = ft_strsplit(str, ' ');
		while (splitted_arr[len])
			len++;
		if (len != len_first)
		{
			free_arr(splitted_arr);
			free(str);
			return (0);
		}
		wolf->map_w = len;
		if (!(check_input1(len, splitted_arr, str)))
			return (0);
	}
	wolf->map_h = i;
	return (1);
}

int		validator_file(int fd, t_wolf *wolf)
{
	char	*str;
	char	**splitted_arr;
	int		len_first;

	str = NULL;
	len_first = 0;
	get_next_line(fd, &str);
	if (!str)
		error_exit(4);
	splitted_arr = ft_strsplit(str, ' ');
	while (splitted_arr[len_first] != NULL)
		len_first++;
	free(str);
	if (!(check_dig(str)) || !(check_input(fd, len_first, wolf)))
		return (0);
	free_arr(splitted_arr);
	check_size(wolf);
	return (1);
}

void	read_map(t_wolf *wolf, int fd)
{
	int		x;
	int		y;
	char	*str;
	char	**splitted_arr;

	wolf->map = (int **)malloc(sizeof(int *) * (wolf->map_h));
	x = 0;
	str = NULL;
	while (get_next_line(fd, &str) == 1 && x < wolf->map_h)
	{
		splitted_arr = ft_strsplit(str, ' ');
		wolf->map[x] = (int *)malloc(sizeof(int) * (wolf->map_w));
		y = -1;
		while (++y < wolf->map_w)
			wolf->map[x][y] = ft_atoi(splitted_arr[y]);
		x++;
		free_arr(splitted_arr);
		free(str);
	}
}
