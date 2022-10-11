/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sigutier <sigutier@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 16:09:30 by sigutier          #+#    #+#             */
/*   Updated: 2022/05/25 16:09:30 by sigutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

void	increment(unsigned int i, char *s)
{
	i = 0;
	s[i] = s[i] + 1;
	i++;
}

/*int main()
{
    char s[] = "toto";
    ft_striteri(s, increment);

    printf("%s\n", s);
    return (0);
}*/