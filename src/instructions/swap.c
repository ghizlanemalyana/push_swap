/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalyana <gmalyana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 17:41:31 by gmalyana          #+#    #+#             */
/*   Updated: 2024/05/24 17:16:43 by gmalyana         ###   ########.fr       */
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
		write(1, "sa\n", 3);
}

void	sb(t_list **stack)
{
	if (swap(stack) == 1)
		write(1, "sb\n", 3);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	if (swap(stack_a) + swap(stack_b))
		write(1, "ss\n", 3);
}
