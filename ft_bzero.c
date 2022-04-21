/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapaulo <joapaulo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 20:06:04 by joapaulo          #+#    #+#             */
/*   Updated: 2022/04/19 20:28:08 by joapaulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t l)
{
	size_t	i;

	i = 0;
	while (i < l)
	{
		((char *)s)[i] = 0;
		i++;
	}
}
