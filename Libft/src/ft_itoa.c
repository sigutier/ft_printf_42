/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sigutier <sigutier@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 16:16:13 by sigutier          #+#    #+#             */
/*   Updated: 2022/06/14 11:05:52 by sigutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	isnegative_check(int *isnegative, long *number)
{
	*isnegative = 0;
	if (*number < 0)
	{
		*isnegative = 1;
		*number = *number * -1;
	}
}

static size_t	ft_intlen(const int n)
{
	size_t	size;
	long	temp;

	temp = n;
	size = 0;
	if (n < 0)
		temp *= -1;
	while (temp > 9)
	{
		temp = temp / 10;
		size++;
	}
	size++;
	return (size);
}

char	*ft_itoa(int n)
{
	size_t	size;
	char	*str;
	int		isnegative;
	long	number;

	number = n;
	isnegative_check(&isnegative, &number);
	size = ft_intlen(n) + isnegative;
	str = (char *)malloc(sizeof(char) * (size + 1));
	if (!str)
		return (NULL);
	if (isnegative == 1)
		*str = '-';
	str[size] = '\0';
	size--;
	while (number > 9)
	{
		str[size] = (number % 10) + '0';
		number = number / 10;
		size--;
	}
	str[size] = number + '0';
	return (str);
}
