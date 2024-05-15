 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalyana <gmalyana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 13:15:41 by gmalyana          #+#    #+#             */
/*   Updated: 2024/05/10 18:36:02 by gmalyana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	indexing(t_list *list, t_list *node)
{
	while (list != NULL)
	{
		if (list->num == node->num)
			return (0);
		if (list->num > node->num)
			list->index += 1;
		else 
			node->index += 1;
		list = list->next;
	}
	return (1);
}



t_list	*list_init(char *nums[])
{
	t_list	*ls;
	t_list	*node;
	char	**arr;
	int		i;
	int		j;

	i = 0;
	ls = NULL;
	while (nums[i] != NULL)
	{
		arr = ft_split(nums[i], ' ');
		j = 0;
		while(arr[j] != NULL)
		{
			node = ft_lstnew(ft_atoi(arr[j]));
			if (node == NULL)
				return (NULL); //FIXME: Clear the list
			if (indexing(ls, node) == 0)
				return (NULL); //FIXME: Clear the list
			ft_lstadd_back(&ls, node);
			j++;
		}
		i++;
	}
	return (ls);
}

