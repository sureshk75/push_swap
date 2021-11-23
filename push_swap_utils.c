/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schetty <schetty@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 09:41:45 by schetty           #+#    #+#             */
/*   Updated: 2021/11/23 19:04:58 by schetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_message(void)
{
	ft_putendl_fd("Error", 1);
	exit(0);
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
		return (1);
	while (stk1)
	{
		if (stk1->next && *(int *)stk1->content > *(int *)stk1->next->content)
			return (1);
		stk1 = stk1->next;
	}
	return (0);
}
