/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romoldov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 20:46:17 by romoldov          #+#    #+#             */
/*   Updated: 2017/12/18 20:53:40 by romoldov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ret;

	if (!lst || !f)
		return (NULL);
	if (lst->next)
	{
		ret = ft_lstmap(lst->next, f);
		ft_lstadd(&ret, f(lst));
	}
	else
		ret = f(lst);
	return (ret);
}
