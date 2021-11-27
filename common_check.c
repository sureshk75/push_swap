/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schetty <schetty@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 10:07:49 by schetty           #+#    #+#             */
/*   Updated: 2021/11/26 12:02:01 by schetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**common_merge_split_args(char **argv)
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
	return (str);
}

static void	common_check_num(const char *str, int *noerr, int *num, int len)
{
	int	i;
	int	nb;

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
	if (!*noerr)
		return ;
	nb = ft_atoi(str);
	if ((nb == -1 && ft_strncmp(str, "-1", 3) != 0)
		|| (nb == 0 && ft_strncmp(str, "0", 2) != 0))
		*noerr = 0;
	while (*noerr && len--)
	{
		if (num[len] == nb)
			*noerr = 0;
	}
}

static void	common_num2pos(int *dst, int *src, int len)
{
	int	i;
	int	j;
	int	k;
	int	l;

	i = -1;
	while (++i < len)
	{
		j = -1;
		k = 0;
		l = INT_MAX;
		while (++j < len)
		{
			if (dst[j] == i)
			{
				if (src[j] <= l)
				{
					l = src[j];
					k = j;
				}
				dst[j] += 1;
			}
		}
		dst[k] -= 1;
	}
}

static int	*common_presort(int *num, int len)
{
	int	*tmp;

	tmp = ft_calloc(len, sizeof(int));
	if (tmp)
	{
		common_num2pos(tmp, num, len);
		free(num);
	}
	return (tmp);
}

int	*common_check_valid(char **str, int len)
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
		common_check_num(str[i], &noerr, num, i);
		if (noerr)
			num[i] = ft_atoi(str[i]);
		free(str[i]);
	}
	free(str);
	if (!noerr)
	{
		free(num);
		return (0);
	}
	return (common_presort(num, len));
}
