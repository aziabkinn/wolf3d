/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freesher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziabkin <aziabkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/29 15:04:16 by aziabkin          #+#    #+#             */
/*   Updated: 2018/07/29 16:02:36 by aziabkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	free_arr(char **splitted_arr)
{
	int	i;

	i = 0;
	while (splitted_arr[i])
		ft_strdel(&(splitted_arr[i++]));
	free(splitted_arr);
}
