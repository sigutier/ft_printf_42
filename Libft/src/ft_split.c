/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sigutier <sigutier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 16:09:24 by sigutier          #+#    #+#             */
/*   Updated: 2022/06/14 10:34:24 by sigutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	next_word(const char *s, int *first, int *last, char c)
{
	*first = *last;
	while (s[*first] == c)
		*first = *first + 1;
	*last = *first;
	while (s[*last] != c && s[*last] != '\0')
		*last = *last + 1;
}

static int	count_words(const char *s, char c)
{
	int		first;
	int		last;
	size_t	index;

	index = 0;
	first = 0;
	last = 0;
	while (s[last] != '\0')
	{
		next_word(s, &first, &last, c);
		if (first == last)
			break ;
		else
			index++;
	}
	return (index);
}

static void	*ft_free(char **ret, size_t total)
{
	if (total == 0)
	{
		free(ret);
		return (NULL);
	}
	while (total != 0)
	{
		free(ret[total]);
		total--;
	}
	free(ret[total]);
	free(ret);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	int		first;
	int		last;
	char	**ret;
	size_t	index;

	if (!s)
		return (NULL);
	ret = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!ret)
		return (NULL);
	index = 0;
	first = 0;
	last = 0;
	while (s[last] != '\0')
	{
		next_word(s, &first, &last, c);
		if (first == last)
			break ;
		ret[index] = ft_substr(s, first, last - first);
		if (!ret[index])
			return (ft_free(ret, index));
		index++;
	}
	ret[index] = NULL;
	return (ret);
}
