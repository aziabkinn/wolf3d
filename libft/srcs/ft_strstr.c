/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aziabkin <aziabkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 19:02:00 by aziabkin          #+#    #+#             */
/*   Updated: 2018/07/23 12:55:05 by aziabkin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s, const char *f)
{
	int i;
	int j;

	i = 0;
	if (*f == '\0')
		return ((char*)s);
	while (s[i] != '\0')
	{
		j = 0;
		while (s[i + j] == f[j] &&
				f[j] != '\0' && s[i + j] != '\0')
			j++;
		if (f[j] == '\0')
			return ((char*)s + i);
		i++;
	}
	return (NULL);
}
