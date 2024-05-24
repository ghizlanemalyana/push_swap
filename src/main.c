/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalyana <gmalyana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 19:22:20 by gmalyana          #+#    #+#             */
/*   Updated: 2024/05/24 21:53:48 by gmalyana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
		return (0);
	stack_a = list_init(argv + 1);
	if (stack_a == NULL)
		return (write(1, "Error\n", 6), 0);
	sort(&stack_a, &stack_b);
	ft_lstclear(&stack_a);
	return (0);
}
