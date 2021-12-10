/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_solve.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schetty <schetty@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 22:04:29 by schetty           #+#    #+#             */
/*   Updated: 2021/12/11 02:21:54 by schetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	common_solve_get_closest(t_list *s, int n, t_flag *f, int i)
{
	int	mv;
	int	n1;
	int	n2;

	mv = 0;
	while (++i < (f->s1s - 1) && !mv)
	{
		n1 = *(int *)ft_lstget(s, i);
		n2 = *(int *)ft_lstget(s, i + 1);
		if ((n1 < n2 && n > n1 && n < n2) || (n1 > n2 && (n > n1 || n < n2)))
			mv = i + 1;
	}
	if (mv < (f->s1s / 2))
	{
		f->t1r = mv;
		f->t1t = 0;
	}
	else
	{
		f->t1r = f->s1s - mv;
		f->t1t = 1;
	}
}

static void	common_solve_rotations(t_list *s1, t_list *s2, t_flag *f, int p)
{
	while (++p < f->s2s)
	{
		common_solve_get_closest(s1, *(int *)ft_lstget(s2, p), f, -1);
		if (p < (f->s2s / 2) || f->s2s == 1)
		{
			f->t2r = p;
			f->t2t = 0;
		}
		else
		{
			f->t2r = f->s2s - p;
			f->t2t = 1;
		}
		if ((f->t1r + f->t2r) < (f->s1r + f->s2r))
		{
			f->s1r = f->t1r;
			f->s1t = f->t1t;
			f->s2r = f->t2r;
			f->s2t = f->t2t;
		}
	}
}

static void	common_solve_stacks(t_list **s1, t_list **s2, t_flag *f, char *ins)
{
	if (f->s2s && !f->s1r && !f->s2r)
		common_move_execute(s1, s2, "pa", 1);
	else if (f->s2s && ((f->s1t && f->s2t) || (!f->s1t && !f->s2t))
		&& f->s1r && f->s2r)
	{
		ins = "rr";
		if (f->s1t && f->s2t)
			ins = "rrr";
		while (--f->s1r >= 0 && --f->s2r >= 0)
			common_move_execute(s1, s2, ins, 1);
	}
	while (f->s2s && f->s1t && --f->s1r >= 0)
		common_move_execute(s1, s2, "rra", 1);
	while (f->s2s && !f->s1t && --f->s1r >= 0)
		common_move_execute(s1, s2, "ra", 1);
	while (f->s2s && f->s2t && --f->s2r >= 0)
		common_move_execute(s1, s2, "rrb", 1);
	while (f->s2s && !f->s2t && --f->s2r >= 0)
		common_move_execute(s1, s2, "rb", 1);
	if (!f->s2s && f->mxt)
		common_move_execute(s1, s2, "ra", 1);
	if (!f->s2s && !f->mxt)
		common_move_execute(s1, s2, "rra", 1);
}

void	common_solve_run(t_list **s1, t_list **s2, int *num)
{
	t_flag	*flg;

	if (ft_lstsize(*s1) == 2)
		common_move_execute(s1, s2, "sa", 1);
	else
	{
		flg = malloc(sizeof(t_flag));
		if (flg)
		{
			common_utils_init_stack2(s1, s2);
			while (common_check_is_unsorted(*s1, *s2, num))
			{
				common_utils_init_flags(*s1, *s2, flg, -1);
				common_solve_rotations(*s1, *s2, flg, -1);
				common_solve_stacks(s1, s2, flg, "");
			}
			free(flg);
		}
	}
}
