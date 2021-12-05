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
	t_list	*s1;
	t_list	*s2;
	char	**str;
	int		*num;
	int		len;

	if (argc == 1)
		common_message_output(1);
	len = 0;
	str = common_check_merge_split(argv + 1, &len);
	if (!str || len < 2)
		common_message_output(1);
	num = common_check_valid(str, len);
	if (!num)
		common_message_output(1);
	s1 = NULL;
	while (len--)
		ft_lstadd_front(&s1, ft_lstnew(&num[len]));
	s2 = NULL;
	while (common_check_is_unsorted(s1, s2, num))
		common_solve(&s1, &s2, len);
	free_alloc(s1, num);
}
