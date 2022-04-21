/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapaulo <joapaulo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 00:07:01 by joapaulo          #+#    #+#             */
/*   Updated: 2022/04/20 03:49:27 by joapaulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hays, const char *ndl, size_t len)
{
	size_t	i;
	size_t	j;

	if (*ndl == 0)
	{
		return ((char *)(hays));
	}
	if (len == 0)
	{
		return (NULL);
	}
	i = 0;
	while (hays[i] && i < len && len > 0)
	{
		j = 0;
		while (ndl[j] && (ndl[j] == hays[i + j] && i + j < len))
			j++;
		if (ndl[j] == 0)
			return (&((char *)hays)[i]);
		i++;
	}
	return (NULL);
}
