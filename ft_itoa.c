/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joapaulo <joapaulo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 00:05:54 by joapaulo          #+#    #+#             */
/*   Updated: 2022/04/20 04:20:31 by joapaulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	get_nbr_str(char *str, int n, size_t size)
{
	str[size] = '\0';
	if (n >= 0)
	{
		while (size--)
		{
			str[size] = (n % 10) + '0';
			n /= 10;
		}
	}
	else
	{
		while (--size)
		{
			str[size] = (n % 10) * -1 + '0';
			n /= 10;
		}
		str[size] = '-';
	}
}

char	*ft_itoa(int n)
{
	int		temp;
	char	*num;
	size_t	size;

	if (n >= 0)
		size = 1;
	else
		size = 2;
	temp = n / 10;
	while (temp)
	{
		size++;
		temp /= 10;
	}
	num = malloc(size + 1);
	if (num == NULL)
		return (NULL);
	get_nbr_str(num, n, size);
	return (num);
}
