/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalyana <gmalyana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 17:28:02 by gmalyana          #+#    #+#             */
/*   Updated: 2024/05/04 23:04:45 by gmalyana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static int	reverse_rorate(t_list **stack)
{
	t_list	*first;
	t_list	*last;
	t_list	*a;

	if (ft_lstsize(*stack) <= 1)
		return (0);
	first = *stack;
	last = ft_lstlast(*stack);
	last->next = first;
	*stack = last;
	a = first;
	while (a->next != last)
		a = a->next;
	a->next = NULL;
	return (1);
}

void	rra(t_list **stack)
{
	if (reverse_rorate(stack) == 1)
		printf("rra\n");
}

void	rrb(t_list **stack)
{
	if (reverse_rorate(stack) == 1)
		printf("rrb\n");
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	if (reverse_rorate(stack_a) + reverse_rorate(stack_b))
		printf("rrr\n");
}
