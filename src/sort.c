/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalyana <gmalyana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 18:47:34 by gmalyana          #+#    #+#             */
/*   Updated: 2024/05/10 01:04:32 by gmalyana         ###     ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static void	push_to_b(t_list **stack_a, t_list **stack_b)
{
	int	len = ft_lstsize(*stack_a); //TODO: Norminette
	int pushed = 0;

	while (len > 5)
	{
		int i = 1 + pushed;
		while(i <= (len / 3 + pushed))
		{
			if((*stack_a)->index <= len / 3 + pushed)
			{
				pb(stack_a, stack_b);
				if ((*stack_b)->index <= len / 3 / 2 + pushed)
					rb(stack_b);
				i++;
			}
			else
				ra(stack_a);
		}
		pushed += len / 3;
		len -= len / 3;
	}
}

void	sort_three(t_list **stack)
{
	if (is_sorted(*stack) == 1)
		return ;
	if ((*stack)->index < (*stack)->next->index)
		rra(stack);
	else if ((*stack)->index > (*stack)->next->next->index)
		ra(stack);
	if ((*stack)->index > (*stack)->next->index)
		sa(stack);
}

void	sorter_le_reste(t_list **stack_a, t_list **stack_b)
{
	int big;
	int ilyasse;

	ilyasse = ft_lstsize(*stack_b);
	while (ft_lstsize(*stack_a) != 3)
	{
		if (is_sorted(*stack_a) == 1)
			return ;
		if((*stack_a)->index == ilyasse + 1 || (*stack_a)->index == ilyasse + 2)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
	sort_three(stack_a);
}

void	push_to_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*last_b;
	t_list	*last_a;
	int		target;
	int		max;

	max = (*stack_a)->next->next->index;	// Does the order of conditions matter?
	while(*stack_b != NULL)
	{
		last_b = ft_lstlast(*stack_b);
		last_a = ft_lstlast(*stack_a);
		target = (*stack_a)->index - 1;
		if (target == (*stack_b)->index)
			pa(stack_a, stack_b);		
		else if (target == last_b->index)
			(rrb(stack_b), pa(stack_a, stack_b));
		else if (target == last_a->index)
			rra(stack_a);
		else if (last_a->index == max)
			(pa(stack_a, stack_b), ra(stack_a));
		else if ((*stack_b)->index > last_a->index)
			(pa(stack_a, stack_b), ra(stack_a));
		else if (is_above_or_under(*stack_b, target) == 1)
			rb(stack_b);
		else
			rrb(stack_b);
	}
	while ((*stack_a)->index != 1)
		rra(stack_a);
}

void	sort(t_list **stack_a, t_list **stack_b)
{                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                             
	push_to_b(stack_a, stack_b);
	sorter_le_reste(stack_a, stack_b);
	push_to_a(stack_a, stack_b);
}
