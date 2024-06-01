/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmalyana <gmalyana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 21:54:35 by gmalyana          #+#    #+#             */
/*   Updated: 2024/06/01 17:15:27 by gmalyana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static int	indexing(t_list *list, t_list *node)
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

static long	get_number(const char *str)
{
	int		i;
	int		sign;
	long	res;

	i = 0;
	sign = 1;
	res = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * sign);
}

static int	is_number(char *number)
{
	int		i;

	i = 0;
	while (*number == '0')
		number++;
	while (number[i] != '\0')
	{
		if (!ft_isdigit(number[i]) && number[i + 1] == '\0')
			return (0);
		else if ((number[i] == '+' || number[i] == '-')
			&& !ft_isdigit(number[i + 1]) && number[i + 1] != '\0')
			return (0);
		else if (!ft_isdigit(number[i]) && !ft_isdigit(number[i + 1]))
			return (0);
		else if (ft_isdigit(number[i]) && !ft_isdigit(number[i + 1])
			&& number[i + 1] != '\0')
			return (0);
		else if (!ft_isdigit(number[i]) && number[i] != '-' && number[i] != '+')
			return (0);
		i++;
	}
	if (i > 11)
		return (0);
	return (1);
}

static t_list	*create_node(char *str, t_list *ls)
{
	long	num;
	t_list	*node;

	if (is_number(str) == 0)
		return (NULL);
	num = get_number(str);
	if (num > INT_MAX || num < INT_MIN)
		return (NULL);
	node = ft_lstnew(num);
	if (node == NULL)
		return (NULL);
	if (indexing(ls, node) == 0)
		return (free(node), NULL);
	return (node);
}

t_list	*list_init(char **nums)
{
	t_list	*ls;
	t_list	*node;
	char	**arr;
	int		i;
	int		j;

	i = -1;
	ls = NULL;
	while (nums[++i] != NULL)
	{
		arr = ft_split(nums[i], ' ');
		if (arr == NULL || arr[0] == NULL)
			return (ft_lstclear(&ls), free(arr), NULL);
		j = -1;
		while (arr[++j] != NULL)
		{
			node = create_node(arr[j], ls);
			if (node == NULL)
				return (ft_free(arr), ft_lstclear(&ls), NULL);
			ft_lstadd_back(&ls, node);
		}
		ft_free(arr);
	}
	return (ls);
}
