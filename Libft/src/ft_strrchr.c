/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sigutier <sigutier@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 14:02:58 by sigutier          #+#    #+#             */
/*   Updated: 2022/05/25 16:09:47 by sigutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i--;
	}
	return (NULL);
}

/*int   main()
{
	const char  *s = "hola que tal";
    const char  ch = 'a';
    char    *ret;

    ret = ft_strrchr(s, ch);
    printf("String after |%c| is - |%s|\n", ch, ret);
    return (0);
}*/
