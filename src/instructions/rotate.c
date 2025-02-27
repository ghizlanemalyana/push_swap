/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalyana <gmalyana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 15:07:57 by gmalyana          #+#    #+#             */
/*   Updated: 2024/05/24 17:15:53 by gmalyana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static int	rotate(t_list **stack)
{
	t_list	*first;
	t_list	*last;
	t_list	*second;

	if (ft_lstsize(*stack) <= 1)
		return (0);
	first = *stack;
	last = ft_lstlast(*stack);
	second = first->next;
	last->next = first;
	first->next = NULL;
	*stack = second;
	return (1);
}

void	ra(t_list **stack)
{
	if (rotate(stack) == 1)
		write(1, "ra\n", 3);
}

void	rb(t_list **stack)
{
	if (rotate(stack) == 1)
		write(1, "rb\n", 3);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	if (rotate(stack_a) + rotate(stack_b))
		write(1, "rr\n", 3);
}
