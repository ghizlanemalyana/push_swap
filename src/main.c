/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalyana <gmalyana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 19:22:20 by gmalyana          #+#    #+#             */
/*   Updated: 2024/05/15 20:04:41 by gmalyana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	print_stack(t_list *stack, char c)
{
	if (stack == NULL)
		return ;
	printf("Stack : %c\n\n", c);
	while (stack != NULL)
	{
		printf("Num: %d\t\tIndex:%d\n", stack->num, stack->index);
		stack = stack->next;
	}
	printf("\n");
}

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	stack_a = list_init(argv + 1);
	if (stack_a == NULL)
		return (write(1, "Error\n", 6), 0);
	sort(&stack_a, &stack_b);
	return (0);
}
