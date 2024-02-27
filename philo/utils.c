/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrimald <agrimald@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:42:37 by agrimald          #+#    #+#             */
/*   Updated: 2024/02/27 15:42:12 by agrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str[i])
	{
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res);
}

uint64_t	total_miliseg(void)
{
	struct timeval	pass_time;

	gettimeofdat(&pass_time, NULL);
	return ((uint64_t)pass_time.tv_sec + (uint64_t)pass_time.tv_usec);
}
