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

void    error_message(void);
int		int_dup_check(int *num, const char *str, int len);
void	free_alloc(t_list *stk1, int *num);
int		unsorted_stack(t_list *stk1, t_list *stk2);

#endif