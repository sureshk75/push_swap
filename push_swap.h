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
	int	s1s;
	int	s2s;
	int	s1l;
	int	s1r;
	int	s1t;
	int	s2r;
	int	s2t;
	int	t1r;
	int	t1t;
	int	t2r;
	int	t2t;
	int	mxv;
	int	mxp;
	int	mxt;
	int	mnv;
	int	mnp;
}	t_flag;

char	**common_check_merge_split(char **argv, int *len);
int		*common_check_valid(char **str, int len);
int		common_check_is_unsorted(t_list *s1, t_list *s2, int *num);
void	common_move_execute(t_list **s1, t_list **s2, char *ins, int prn);
void	common_solve_run(t_list **s1, t_list **s2, int *num);
int		common_utils_count_moves(int pos, int size);
int		common_utils_gnl(char **str);
void	common_utils_init_flags(t_list *s1, t_list *s2, t_flag *flg, int pos);
void	common_utils_init_stack2(t_list **s1, t_list **s2);
void	common_utils_output(int errno);

#endif