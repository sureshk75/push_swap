/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schetty <schetty@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 09:19:48 by schetty           #+#    #+#             */
/*   Updated: 2021/11/16 09:20:11 by schetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stk1;
	t_list	*stk2;
	char	**str;
	int		*num;
	int		len;

	if (argc == 1)
		error_message();
	str = common_merge_split_args(argv + 1);
	if (!str)
		error_message();
	len = 0;
	while (str[len])
		len++;
	num = common_check_valid(str, len);
	if (!num)
		error_message();
	stk1 = NULL;
	while (len--)
		ft_lstadd_front(&stk1, ft_lstnew(&num[len]));
	stk2 = NULL;
	while (unsorted_stack(stk1, stk2))
		common_solve(&stk1, &stk2, len);
	free_alloc(stk1, num);
	return (0);
}
