/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaidu <lnaidu@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 11:30:49 by lnaidu            #+#    #+#             */
/*   Updated: 2022/11/21 10:17:42 by lnaidu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*tmp;

	tmp = malloc(sizeof(t_list));
	if (!tmp)
		return (NULL);
	tmp->content = content;
	tmp->next = NULL;
	return (tmp);
}
/*
int main(void)
{
	t_list	*list;
	 list = ft_lstnew("bonjour");
	printf("%s\n", list->content);
	 list = ft_lstnew("NULL");
	printf("%s\n", list->content);
	write(1, "\n", 1);
	return (0);
}*/
