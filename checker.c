/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schetty <schetty@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 19:49:14 by schetty           #+#    #+#             */
/*   Updated: 2021/12/11 02:38:43 by schetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	checker_exit(t_list *s1, t_list *s2, int *num)
{
	t_list	*tmp;

	while (s1)
	{
		tmp = s1->next;
		free(s1);
		s1 = tmp;
	}
	while (s2)
	{
		tmp = s2->next;
		free(s2);
		s2 = tmp;
	}
	free(num);
}

static void	checker_listen(t_list **s1, t_list **s2, int *num)
{
	char	*str;
	int		ret;

	str = NULL;
	ret = 1;
	while (ret != -1)
	{
		ret = common_utils_gnl(&str);
		if (ret != -1)
		{
			common_move_execute(s1, s2, str, 0);
			free(str);
			str = NULL;
			if (ret == 0)
				break ;
		}
	}
	if (ret == 0 && !common_check_is_unsorted(*s1, *s2, num))
		common_utils_output(3);
	if (s1 || s2 || num)
		checker_exit(*s1, *s2, num);
	if (ret == 0)
		common_utils_output(2);
	else
		common_utils_output(1);
}

int	main(int argc, char **argv)
{
	t_list	*s1;
	t_list	*s2;
	char	**str;
	int		*num;
	int		len;

	if (argc == 1)
		common_utils_output(0);
	len = 0;
	str = common_check_merge_split(argv + 1, &len);
	if (!str)
		common_utils_output(1);
	num = common_check_valid(str, len);
	if (!num)
		common_utils_output(1);
	s1 = NULL;
	while (len--)
		ft_lstadd_front(&s1, ft_lstnew(&num[len]));
	s2 = NULL;
	checker_listen(&s1, &s2, num);
}