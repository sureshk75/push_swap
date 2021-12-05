/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_message.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schetty <schetty@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 01:04:36 by schetty           #+#    #+#             */
/*   Updated: 2021/12/05 01:09:11 by schetty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	common_message_output(int errno)
{
	if (errno == 1)
		ft_putendl_fd("Error", 1);
	else if (errno == 2)
		ft_putendl_fd("KO", 1);
	else
		ft_putendl_fd("OK", 1);
	exit(0);
}
