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

typedef struct s_flag
{
	int	len;
	int	max_val;
	int	max_pos;
	int	min_val;
	int	min_pos;
	int	mean;
}	t_flag;

void	common_message_output(int errno);
char	**common_check_merge_split(char **argv, int *len);
int		*common_check_valid(char **str, int len);
int		common_check_is_unsorted(t_list *s1, t_list *s2, int *num);

void	common_init(t_flag *flg, t_list *stk, int isstk1);
void	common_mover(t_list **stk1, t_list **stk2, char *ins);
void	common_solve(t_list	**stk1, t_list **stk2, int len);

#endif