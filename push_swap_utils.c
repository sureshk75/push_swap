/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schetty <schetty@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 09:41:45 by schetty           #+#    #+#             */
/*   Updated: 2021/11/23 11:37:02 by schetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    error_message(void)
{
	ft_putendl_fd("Error", 0);
	exit(0);
}

int		int_dup_check(int *num, const char *str, int len)
{
	int	nb;

	nb = ft_atoi(str);
	if (nb == -1 && (str[0] != '-' || str[1] != '0'))
		return (1);
	if (nb == 0 && str[0] != '0')
		return (1);
	while (len--)
	{
		if (num[len] == nb)
			return (1);
	}
	return (0);
}

void	free_alloc(t_list *stk1, int *num)
{
	t_list	*tmp;

	while (stk1)
	{
		tmp = stk1->next;
		free(stk1);
		stk1 = tmp;
	}
	free(num);
}

int	unsorted_stack(t_list *stk1, t_list *stk2)
{
	if (stk2)
		return (0);
	while (stk1)
	{
		if (stk1->next && *(int *)stk1->content > *(int *)stk1->next->content)
			return (1);
		stk1 = stk1->next;
	}
	return (0);
}