/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sigutier <sigutier@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 16:30:48 by sigutier          #+#    #+#             */
/*   Updated: 2022/05/25 16:09:45 by sigutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*s2 == '\0')
		return ((char *)s1);
	while (s1[i] != '\0' && i < n)
	{
		j = 0;
		while (s1[i + j] == s2[j] && i + j < n)
		{
			j++;
			if (s2[j] == '\0')
				return ((char *)(s1 + i));
		}
		i++;
	}
	return (0);
}

/*int	main (void)
{
	char	s1[] = "hola que tal";
	char	s2[] = "tal";

	printf("%s\n", ft_strnstr(s1, s2, 12));
	printf("%s\n", strnstr(s1, s2, 12));
	return (0);
}*/
