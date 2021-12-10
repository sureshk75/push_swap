/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schetty <schetty@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 10:07:49 by schetty           #+#    #+#             */
/*   Updated: 2021/12/09 20:29:49 by schetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	common_check_is_unsorted(t_list *s1, t_list *s2, int *num)
{
	t_list	*tmp;

	if (s2)
		return (1);
	tmp = s1;
	while (tmp)
	{
		if (tmp->next && *(int *)tmp->content > *(int *)tmp->next->content)
			return (1);
		tmp = tmp->next;
	}
	while (s1)
	{
		tmp = s1->next;
		free(s1);
		s1 = tmp;
	}
	free(num);
	return (0);
}

char	**common_check_merge_split(char **argv, int *len)
{
	char	*tmp1;
	char	*tmp2;
	char	**str;

	tmp1 = ft_calloc(1, sizeof(char));
	while (tmp1 && *argv)
	{
		tmp2 = ft_strjoin(tmp1, " ");
		free(tmp1);
		tmp1 = ft_strjoin(tmp2, *argv++);
		free(tmp2);
	}
	if (!tmp1)
		return (NULL);
	str = ft_split(tmp1, ' ');
	free(tmp1);
	while (str[*len])
		*len += 1;
	return (str);
}

static void	common_check_num(char *str, int *noerr, int *num, int len)
{
	int	nb;
	int	i;

	i = -1;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[++i] && *noerr)
	{
		if (str[i] < '0' || str[i] > '9')
			*noerr = 0;
	}
	if (!*noerr)
		return ;
	nb = ft_atoi(str);
	if ((nb == -1 && ft_strncmp(str, "-1", 3) != 0)
		|| (nb == 0 && ft_strncmp(str, "0", 2) != 0))
		*noerr = 0;
	num[len] = nb;
	while (*noerr && len--)
	{
		if (num[len] == nb)
			*noerr = 0;
	}
	free(str);
}

static int	*common_check_presort(int *n1, int *n2, int len, int cur)
{
	int	i;
	int	j;
	int	k;

	while (++cur < len)
	{
		i = -1;
		j = INT_MAX;
		k = 0;
		while (++i < len)
		{
			if (n2[i] == cur)
			{
				if (n1[i] <= j)
				{
					j = n1[i];
					k = i;
				}
				n2[i] += 1;
			}
		}
		n2[k] -= 1;
	}
	free(n1);
	return (n2);
}

int	*common_check_valid(char **str, int len)
{
	int		*n1;
	int		*n2;
	int		noerr;
	int		i;

	n1 = ft_calloc(len, sizeof(int));
	if (!n1)
		return (0);
	noerr = 1;
	i = -1;
	while (++i < len)
		common_check_num(str[i], &noerr, n1, i);
	free(str);
	if (noerr)
	{
		n2 = ft_calloc(len, sizeof(int));
		if (n2)
			return (common_check_presort(n1, n2, len, -1));
	}
	free(n1);
	return (0);
}
