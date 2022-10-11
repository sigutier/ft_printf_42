/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sigutier <sigutier@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 16:24:30 by sigutier          #+#    #+#             */
/*   Updated: 2022/06/14 11:35:49 by sigutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_null_str(void)
{
	char	*subs;

	subs = (char *)malloc(sizeof(char) * 1);
	if (!subs)
		return (0);
	subs[0] = '\0';
	return (subs);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	len_s;
	char	*subs;

	if (!s)
		return (0);
	len_s = ft_strlen(s);
	if (len_s < start)
		return (ft_null_str());
	if (len_s <= len)
		len = len_s - start;
	subs = (char *)malloc(sizeof(char) * (len + 1));
	if (!subs)
		return (0);
	i = 0;
	while (s[i] && start < len_s && i < len)
	{
		subs[i] = s[start];
		start++;
		i++;
	}
	subs[i] = '\0';
	return (subs);
}
