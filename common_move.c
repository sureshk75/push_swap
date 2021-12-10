/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schetty <schetty@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 16:53:50 by schetty           #+#    #+#             */
/*   Updated: 2021/12/11 02:20:00 by schetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	common_move_swap(t_list **s1, t_list **s2, char *ins)
{
	t_list	*tmp;

	if (ft_strncmp(ins, "ss", 2) == 0 || ft_strncmp(ins, "sa", 2) == 0)
	{
		tmp = (*s1)->next;
		(*s1)->next = (*s1)->next->next;
		ft_lstadd_front(s1, tmp);
	}
	if (ft_strncmp(ins, "ss", 2) == 0 || ft_strncmp(ins, "sb", 2) == 0)
	{
		tmp = (*s2)->next;
		(*s2)->next = (*s2)->next->next;
		ft_lstadd_front(s2, tmp);
	}
}

static void	common_move_push(t_list **s1, t_list **s2, char *ins)
{
	t_list	*tmp;

	if (ft_strncmp(ins, "pa", 2) == 0)
	{
		tmp = *s2;
		*s2 = (*s2)->next;
		ft_lstadd_front(s1, tmp);
	}
	if (ft_strncmp(ins, "pb", 2) == 0)
	{
		tmp = *s1;
		*s1 = (*s1)->next;
		ft_lstadd_front(s2, tmp);
	}
}

static void	common_move_rotate(t_list **s1, t_list **s2, char *ins)
{
	t_list	*tmp;

	if (ft_strncmp(ins, "rr", 2) == 0 || ft_strncmp(ins, "ra", 2) == 0)
	{
		tmp = *s1;
		*s1 = (*s1)->next;
		tmp->next = NULL;
		ft_lstadd_back(s1, tmp);
	}
	if (ft_strncmp(ins, "rr", 2) == 0 || ft_strncmp(ins, "rb", 2) == 0)
	{
		tmp = *s2;
		*s2 = (*s2)->next;
		tmp->next = NULL;
		ft_lstadd_back(s2, tmp);
	}
}

static void	common_move_rrotate(t_list **s1, t_list **s2, char *ins)
{
	t_list	*tmp;
	t_list	*end;

	if (ft_strncmp(ins, "rrr", 3) == 0 || ft_strncmp(ins, "rra", 3) == 0)
	{
		end = ft_lstlast(*s1);
		tmp = *s1;
		while (tmp->next != end)
			tmp = tmp->next;
		tmp->next = 0;
		ft_lstadd_front(s1, end);
	}
	if (ft_strncmp(ins, "rrr", 3) == 0 || ft_strncmp(ins, "rrb", 3) == 0)
	{
		end = ft_lstlast(*s2);
		tmp = *s2;
		while (tmp->next != end)
			tmp = tmp->next;
		tmp->next = 0;
		ft_lstadd_front(s2, end);
	}
}

void	common_move_execute(t_list **s1, t_list **s2, char *ins, int prn)
{
	if (ft_strncmp(ins, "s", 1) == 0)
		common_move_swap(s1, s2, ins);
	else if (ft_strncmp(ins, "p", 1) == 0)
		common_move_push(s1, s2, ins);
	else if (ft_strlen(ins) == 2)
		common_move_rotate(s1, s2, ins);
	else
		common_move_rrotate(s1, s2, ins);
	if (prn)
		ft_putendl_fd(ins, 1);
}
