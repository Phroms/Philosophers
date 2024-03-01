/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrimald <agrimald@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:42:37 by agrimald          #+#    #+#             */
/*   Updated: 2024/03/01 18:56:28 by agrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_msg(char *color, t_philo *philo, char *s, int dead)
{
	uint64_t	saved_time;
	int			fin;

	pthread_mutex_lock(&philo->reglas->m_impresion);
	pthread_mutex_lock(&philo->reglas->m_muerte);
	fin = philo->reglas->count_deads;
	pthread_mutex_unlock(&philo->reglas->m_muerte);
	saved_time = total_miliseg() - philo->reglas->init_time;
	if (!fin || dead != 0)
		printf("%s%llu Philo[%d] %s\n%s", color, saved_time, philo->id, s, FINAL);
	pthread_mutex_unlock(&philo->reglas->m_impresion);
}

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

	gettimeofday(&pass_time, NULL);
	return ((uint64_t)pass_time.tv_sec + (uint64_t)pass_time.tv_usec);
}

void	ft_usleep(uint64_t waiting)
{
	waiting += total_miliseg();
	while (total_miliseg() <= waiting)
		usleep(100);
}
