/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sigutier <sigutier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 10:28:07 by sigutier          #+#    #+#             */
/*   Updated: 2022/06/14 10:28:12 by sigutier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	tmp = lst[0];
	if (!del || !tmp)
		return ;
	while (tmp)
	{
		tmp = lst[0]->next;
		ft_lstdelone(lst[0], del);
		lst[0] = tmp;
	}
}
