/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalyana <gmalyana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 19:59:19 by gmalyana          #+#    #+#             */
/*   Updated: 2024/05/15 21:49:20 by gmalyana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int		is_above_or_under(t_list *stack, int target)
{
	int	size;

	size = ft_lstsize(stack) / 2;
	while (size > 0)
	{
		if (target == stack->index)
			return 1;
		stack = stack->next;
		size--;
	}
	return 2;
}

int		is_sorted(t_list  *stack)
{
	while (stack->next  != NULL)
	{ 
		if (stack->next->index - stack->index != 1)
			return (0);
		stack = stack->next;
	}
	return (1);
}
static char	**ft_free(char **arr, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
		free(arr[i++]);
	free (arr);
	return (NULL);
}