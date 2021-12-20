/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schetty <schetty@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 23:17:40 by schetty           #+#    #+#             */
/*   Updated: 2021/12/20 23:43:18 by schetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	common_utils_init_stack2(t_list **s1, t_list **s2)
{
	const int	n1 = *(int *)(ft_lstget(*s1, ft_lstsize(*s1) - 3));
	const int	n2 = *(int *)(ft_lstget(*s1, ft_lstsize(*s1) - 2));
	const int	n3 = *(int *)(ft_lstget(*s1, ft_lstsize(*s1) - 1));

	while (ft_lstsize(*s1) > 3)
		common_move_execute(s1, s2, "pb", 1);
	if ((n2 > n3 && n3 > n1) || (n1 > n2 && n3 > n1))
		common_move_execute(s1, s2, "sa", 1);
	else if (n1 > n2 && n2 > n3)
	{
		common_move_execute(s1, s2, "ra", 1);
		common_move_execute(s1, s2, "sa", 1);
	}
}

void	common_utils_init_flags(t_list *s1, t_list *s2, t_flag *flg, int pos)
{
	int	cur;

	flg->s1s = ft_lstsize(s1);
	flg->s2s = ft_lstsize(s2);
	flg->s1l = *(int *)ft_lstlast(s1)->content;
	flg->s1r = flg->s1s;
	flg->s2r = flg->s2s;
	flg->mnv = INT_MAX;
	flg->mxv = INT_MIN;
	while (++pos < flg->s1s)
	{
		cur = *(int *)ft_lstget(s1, pos);
		if (cur <= flg->mnv)
			flg->mnp = pos;
		if (cur <= flg->mnv)
			flg->mnv = cur;
		if (cur >= flg->mxv)
			flg->mxp = pos;
		if (cur >= flg->mxv)
			flg->mxv = cur;
	}
	flg->mxt = 0;
	if (flg->mxp < (flg->s1s / 2))
		flg->mxt = 1;
}

void	common_utils_output(int errno)
{
	if (errno != 0)
	{
		if (errno == 1)
			ft_putendl_fd("Error", 2);
		else if (errno == 2)
			ft_putendl_fd("KO", 1);
		else
			ft_putendl_fd("OK", 1);
	}
	exit(0);
}

int	common_utils_gnl(char **str)
{
	int	i;

	*str = ft_calloc(6, sizeof(char));
	if (*str)
	{
		i = -1;
		while (++i < 6 && read(0, &((*str)[i]), 1))
		{
			if ((*str)[i] == '\n')
			{
				(*str)[i] = 0;
				return (1);
			}
		}
		return (0);
	}
	return (-1);
}

int	common_utils_count_moves(int pos, int size)
{
	if (pos < ((size / 2) + 0.5) || size == 1)
		return (pos);
	return (size - pos);
}
