/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalyana <gmalyana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 17:41:31 by gmalyana          #+#    #+#             */
/*   Updated: 2024/05/04 23:05:29 by gmalyana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static int	swap(t_list **stack)
{
	t_list	*first;
	t_list	*second;
	t_list	*third;

	if (ft_lstsize(*stack) <= 1)
		return (0);
	first = *stack;
	second = first->next;
	third = second->next;
	first->next = third;
	second->next = first;
	*stack = second;
	return (1);
}

void	sa(t_list **stack)
{
	if (swap(stack) == 1)
		printf("sa\n");
}

void	sb(t_list **stack)
{
	if (swap(stack) == 1)
		printf("sb\n");
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	if (swap(stack_a) + swap(stack_b))
		printf("ss\n");
}
