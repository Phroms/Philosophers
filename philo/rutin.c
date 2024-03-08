/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rutin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrimald <agrimald@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:57:43 by agrimald          #+#    #+#             */
/*   Updated: 2024/03/08 16:06:23 by agrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_dead(t_rules *rules, int i, uint64_t time)
{
	pthread_mutex_lock(&(rules->m_dead));
	if (total_miliseg() - rules->init_time > time)
	{
		rules->count_deads = 1;
		pthread_mutex_unlock(&(rules->m_dead));
		print_msg(RED, &(rules->philo[i]), DIED, 1);
	}
	else
		pthread_mutex_unlock(&rules->m_dead);
}

void	check_philo(t_rules *rules)
{
	uint64_t	tiempo;
	int			i;

	i = 0;
	while (rules->count_deads == 0)
	{
		pthread_mutex_lock(&(rules->philo[i].m_check_meals));
		tiempo = rules->philo[i].time_dead;
		pthread_mutex_unlock(&(rules->philo[i].m_check_meals));
		philo_dead(rules, i, tiempo);
		pthread_mutex_lock(&(rules->philo[i].m_check_meals));
		if (rules->philo[i].num_meals == rules->max_meals)
			rules->all_eat++;
		pthread_mutex_unlock(&(rules->philo[i].m_check_meals));
		if (rules->num_philo == rules->all_eat)
			break ;
		i++;
		if (i == rules->num_philo)
		{
			i = 0;
			rules->all_eat = 0;
		}
	}
}

void	life(t_philo *ph)
{
	t_rules	*rules;

	rules = ph->rules;
	pthread_mutex_lock(&(ph->l_fork));
	print_msg(GREEN, ph, FORK, 0);
	if (rules->num_philo == 1)
	{
		ft_usleep(rules->time_of_dead);
		pthread_mutex_unlock(&(ph->l_fork));
		return ;
	}
	pthread_mutex_lock(ph->r_fork);
	print_msg(CYAN, ph, FORK, 0);
	pthread_mutex_lock(&(ph->m_check_meals));
	ph->time_dead = rules->time_of_dead + (total_miliseg() - rules->init_time);
	ph->num_meals++;
	pthread_mutex_unlock(&(ph->m_check_meals));
	print_msg(BLUE, ph, EAT, 0);
	ft_usleep(rules->time_of_eat);
	pthread_mutex_unlock(&(ph->l_fork));
	pthread_mutex_unlock(ph->r_fork);
	print_msg(MAGENTA, ph, SLEEP, 0);
	ft_usleep(rules->time_of_sleep);
	print_msg(YELLOW, ph, THINK, 0);
}

void	*rutin(void *void_philo)
{
	int			finish;
	t_rules		*rules;
	t_philo		*philo;

	philo = (t_philo *)void_philo;
	rules = philo->rules;
	finish = 0;
	if (philo->id % 2 == 0)
		ft_usleep(rules->time_of_eat);
	while (finish == 0 && (philo->num_meals != rules->max_meals))
	{
		life(philo);
		pthread_mutex_lock(&(rules->m_dead));
		finish = rules->count_deads;
		pthread_mutex_unlock(&(rules->m_dead));
	}
	return (NULL);
}
