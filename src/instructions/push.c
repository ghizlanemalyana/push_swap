/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalyana <gmalyana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 15:05:51 by gmalyana          #+#    #+#             */
/*   Updated: 2024/05/24 17:15:38 by gmalyana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*first_a;
	t_list	*first_b;
	t_list	*second_b;

	if (ft_lstsize(*stack_b) == 0)
		return ;
	first_b = *stack_b;
	first_a = first_b;
	second_b = first_a->next;
	*stack_b = second_b;
	first_a->next = *stack_a;
	*stack_a = first_a;
	write(1, "pa\n", 3);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*first_a;
	t_list	*first_b;
	t_list	*second_a;

	if (ft_lstsize(*stack_a) == 0)
		return ;
	first_a = *stack_a;
	first_b = first_a;
	second_a = first_a->next;
	*stack_a = second_a;
	first_b->next = *stack_b;
	*stack_b = first_b;
	write(1, "pb\n", 3);
}
