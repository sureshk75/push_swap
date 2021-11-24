/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schetty <schetty@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 09:19:42 by schetty           #+#    #+#             */
/*   Updated: 2021/11/16 09:21:23 by schetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>

typedef struct	s_flag
{
	int			len;
	int			n1;
	int			n2;
	int			n3;
	int			psh;
	int			swp;
	int			rev;
	int			rrv;
}				t_flag;

void	error_message(void);
void	free_alloc(t_list *stk1, int *num);
int		unsorted_stack(t_list *stk1, t_list *stk2);
void	common_init(t_flag *flg, t_list *stk, int isstk1);
void	common_mover(t_list **stk1, t_list **stk2, char *ins);
void	common_solve(t_list	**stk1, t_list **stk2, char *tmp);

#endif