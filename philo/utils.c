/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrimald <agrimald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 12:42:37 by agrimald          #+#    #+#             */
/*   Updated: 2024/03/08 15:51:44 by agrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_msg(char *color, t_philo *philo, char *s, int dead)
{
	uint64_t	s_time;
	int			fin;

	pthread_mutex_lock(&philo->rules->m_print);
	pthread_mutex_lock(&philo->rules->m_dead);
	fin = philo->rules->count_deads;
	pthread_mutex_unlock(&philo->rules->m_dead);
	s_time = total_miliseg() - philo->rules->init_time;
	if (!fin || dead != 0)
		printf("%s%llu Philo[%d] %s\n%s", color, s_time, philo->id, s, FINAL);
	pthread_mutex_unlock(&philo->rules->m_print);
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

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}

uint64_t	total_miliseg(void)
{
	struct timeval	pass_time;

	gettimeofday(&pass_time, NULL);
	return (pass_time.tv_sec * 1000 + (pass_time.tv_usec / 1000));
}

void	ft_usleep(uint64_t waiting)
{
	waiting += total_miliseg();
	while (total_miliseg() <= waiting)
		usleep(100);
}
