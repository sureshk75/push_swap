/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_solve.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schetty <schetty@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 22:04:29 by schetty           #+#    #+#             */
/*   Updated: 2021/11/24 17:08:29 by schetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	common_init(t_flag *flg, t_list *stk, int isstk1)
{
	flg->len = ft_lstsize(stk);
	flg->n1 = 0;
	if (flg->len > 0)
		flg->n1 = *(int *)stk->content;
	flg->n2 = 0;
	if (flg->len > 1)
		flg->n2 = *(int *)stk->next->content;
	flg->n3 = 0;
	if (flg->len > 1)
		flg->n3 = *(int *)ft_lstlast(stk)->content;
	flg->swp = 0;
	if ((isstk1 && flg->len > 1 && flg->n1 > flg->n2) || 
		(!isstk1 && flg->len > 1 && flg->n1 < flg->n2))
		flg->swp = 1;
	flg->rev = 0;
	if ((isstk1 && flg->len > 1 && flg->n1 > flg->n3 && flg->n3 >= flg->n2) ||
		(!isstk1 && flg->len > 1 && flg->n1 < flg->n3 && flg->n3 <= flg->n2))
		flg->rev = 1;
	flg->rrv = 0;
	if ((isstk1 && flg->len > 1 && flg->n1 < flg->n3 && flg->n3 >= flg->n2) || 
		(!isstk1 && flg->len > 1 && flg->n1 > flg->n3 && flg->n3 <= flg->n2))
		flg->rrv = 1;
	flg->psh = 0;
	if (flg->len > 0 && !flg->swp && !flg->rev && !flg->rrv)
		flg->psh = 1;
}

// static char	*common_ins(t_flag *flg1, t_flag *flg2)
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

void	common_solve(t_list	**stk1, t_list **stk2, char *tmp)
{
	t_flag	*flg1;
	t_flag	*flg2;

	flg1 = malloc(sizeof(t_flag));
	flg2 = malloc(sizeof(t_flag));
	if (flg1 && flg2)
	{
		common_init(flg1, *stk1, 1);
		common_init(flg2, *stk2, 0);
		// common_mover(stk1, stk2, common_ins(flg1, flg2));
	}
	common_mover(stk1, stk2, tmp);
	if (flg1)
	{
		// printf("\nSTACK #1 >> len: %d n1: %d n2: %d n3: %d\n", flg1->len, flg1->n1, flg1->n2, flg1->n3);
		// printf("STACK #1 >> swp: %d rev: %d rrv: %d psh: %d\n", flg1->swp, flg1->rev, flg1->rrv, flg1->psh);
		free(flg1);
	}
	if (flg2)
	{
		// printf("\nSTACK #2 >> len: %d n1: %d n2: %d n3: %d\n", flg2->len, flg2->n1, flg2->n2, flg2->n3);
		// printf("STACK #2 >> swp: %d rev: %d rrv: %d psh: %d\n", flg2->swp, flg2->rev, flg2->rrv, flg2->psh);
		free(flg2);
	}
}
