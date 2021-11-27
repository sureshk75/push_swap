/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_solve.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schetty <schetty@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 22:04:29 by schetty           #+#    #+#             */
/*   Updated: 2021/11/27 09:31:58 by schetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	common_init(t_flag *flg, t_list *stk, int len)
{
	int	i;

	flg->len = ft_lstsize(stk);
	if (flg->len)
	{
		i = -1;
		flg->min_val = len;
		flg->max_val = 0;
		while(++i && stk)
		{
			if (*(int *)stk > flg->max_val)
			{
				flg->max_val = *(int *)stk;
				flg->max_pos = i;
			}
			if (*(int *)stk < flg->min_val)
			{
				flg->min_val = *(int *)stk;
				flg->min_pos = i;
			}
		}
		flg->mean = flg->len / 2;
	}
}

static char	*common_ins(t_flag *flg1, t_flag *flg2)
{}
// static char	*common_ins(t_flag *flg1, t_flag *flg2, int len)
// {
// 	if (flg1->rrv && flg2->rrv)
// 		return ("rrr");
// 	else if (flg1->rev && flg2->rev)
// 		return ("rr");
// 	else if (flg1->swp && flg2->swp)
// 		return ("ss");
// 	else if (flg1->rrv)
// 		return ("rra");
// 	else if (flg2->rrv)
// 		return ("rrb");
// 	else if (flg1->rev)
// 		return ("ra");
// 	else if (flg2->rev)
// 		return ("rb");
// 	else if (flg1->swp)
// 		return ("sa");
// 	else if (flg2->swp)
// 		return ("sb");
// 	else if (flg1->psh)
// 		return ("pb");
// 	else
// 		return ("pa");
// }

static int	get_highest_unordered_value(t_list *stk, int len)
{
	int	stk_len;
	int	i;

	stk_len = ft_lstsize(stk);
	i = -1;
	while (--len > -1 && ++i)
	{
		
	}
		
}

void	common_solve(t_list	**stk1, t_list **stk2, int len)
{
	t_flag	*flg1;
	t_flag	*flg2;

	flg1 = malloc(sizeof(t_flag));
	flg2 = malloc(sizeof(t_flag));
	if (flg1 && flg2)
	{
		common_init(flg1, *stk1, len);
		common_init(flg2, *stk2, len);
		common_mover(stk1, stk2, common_ins(flg1, flg2));
	}
	if (flg1)
		free(flg1);
	if (flg2)
		free(flg2);
}
