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

char	**merge_split_args(char **argv)
{
	char	*tmp1;
	char	*tmp2;
	char	**str;

	tmp1 = ft_calloc(1, sizeof(char));
	if (tmp1)
	{
		while (*argv)
		{
			tmp2 = ft_strjoin(tmp1, " ");
			free(tmp1);
			tmp1 = ft_strjoin(tmp2, *argv++);
			free(tmp2);
		}
	}
	if (!tmp1)
		return (NULL);
	str = ft_split(tmp1, ' ');
	free(tmp1);
	return (str);
}

int	int_dup_check(int *num, const char *str, int len)
{
	int	nb;

	nb = ft_atoi(str);
	if (nb == -1 && (str[0] != '-' || str[1] != '0'))
		return (1);
	if (nb == 0 && str[0] != '0')
		return (1);
	while (len--)
	{
		if (num[len] == nb)
			return (1);
	}
	return (0);
}

void	check_num(const char *str, int *noerr, int *num, int len)
{
	int	i;

	if (!*noerr)
		return ;
	i = -1;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[++i] && *noerr)
	{
		if (str[i] < '0' || str[i] > '9')
			*noerr = 0;
	}
	if (*noerr && int_dup_check(num, str, len))
		*noerr = 0;
}

int	*check_valid(char **str, int len)
{
	int		*num;
	int		noerr;
	int		i;

	if (len < 2)
		return (0);
	num = ft_calloc(len, sizeof(int));
	if (!num)
		return (0);
	noerr = 1;
	i = -1;
	while (++i < len)
	{
		check_num(str[i], &noerr, num, i);
		if (noerr)
			num[i] = ft_atoi(str[i]);
		free(str[i]);
	}
	free(str);
	if (noerr)
		return (num);
	free(num);
	return (0);
}

int	main(int argc, char **argv)
{
	t_list	*stk1;
	t_list	*stk2;
	char	**str;
	int		*num;
	int		len;

	if (argc == 1)
		error_message();
	str = merge_split_args(argv + 1);
	if (!str)
		error_message();
	len = 0;
	while (str[len])
		len++;
	num = check_valid(str, len);
	if (!num)
		error_message();
	stk1 = NULL;
	while (len--)
		ft_lstadd_front(&stk1, ft_lstnew(&num[len]));
	stk2 = NULL;
	if (unsorted_stack(stk1, stk2))
	{
		common_solve(&stk1, &stk2);
		ft_putendl_fd("Stack Is Not Sorted..", 1);
	}
	ft_putendl_fd("Stack Is Sorted!", 1);
	free_alloc(stk1, num);
	return (0);
}
