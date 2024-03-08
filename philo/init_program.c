/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrimald <agrimald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:04:30 by agrimald          #+#    #+#             */
/*   Updated: 2024/03/08 20:28:39 by agrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	time_philo(t_rules	*rul)
{
	int		i;
	t_philo	*philos;

	i = 0;
	philos = rul->philo;
	rul->init_time = total_miliseg();
	while (i < rul->num_philo)
	{
		pthread_create(&(philos[i].id_philo), NULL, rutin, &(rul->philo[i]));
		i++;
	}
	return (0);
}

void	init_philo(t_rules *rules)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&rules->m_init);
	while (i < rules->num_philo)
	{
		rules->philo[i].id = i + 1;
		rules->philo[i].rules = rules;
		rules->philo[i].time_dead = rules->time_of_dead;
		rules->philo[i].num_meals = 0;
		if (i == 0)
			rules->philo[i].r_fork \
				= &(rules->philo[rules->num_philo - 1].l_fork);
		else
			rules->philo[i].r_fork = &(rules->philo[i - 1].l_fork);
		pthread_mutex_init(&(rules->philo[i].l_fork), NULL);
		pthread_mutex_init(&(rules->philo[i].m_check_meals), NULL);
		i++;
	}
}

int	init(t_rules *rules)
{
	if (pthread_mutex_init(&(rules->m_init), NULL))
		return (exit_philo("INIT_MUTEX", "Mutex start failed", THREADS));
	if (pthread_mutex_init(&(rules->m_dead), NULL))
		return (exit_philo("INIT_MUTEX", "Mutex print failed", THREADS));
	if (pthread_mutex_init(&(rules->m_print), NULL))
		return (exit_philo("INIT_MUTEX", "Mutex death failed", THREADS));
	return (0);
}

int	init_arguments(int argc, char **argv, t_rules *rules)
{
	rules->num_philo = (uint64_t)ft_atoi(argv[1]);
	rules->time_of_dead = (uint64_t)ft_atoi(argv[2]);
	rules->time_of_eat = (uint64_t)ft_atoi(argv[3]);
	rules->time_of_sleep = (uint64_t)ft_atoi(argv[4]);
	rules->max_meals = -1;
	rules->count_eats = 0;
	rules->count_deads = 0;
	if (argc == 6)
		rules->max_meals = (uint64_t)ft_atoi(argv[5]);
	if (rules->num_philo == 0)
		return (printf("Error bebe: No hay filosofos 🤭\n"));
	else if (rules->num_philo > 250)
		return (printf("Que fue mano: excediste el numero de threads 😐\n"));
	if (init(rules))
		return (1);
	init_philo(rules);
	time_philo(rules);
	return (0);
}

int	main(int argc, char **argv)
{
	int			i;
	t_rules		rules;

	if (process_arguments(argc, argv))
		return (1);
	if (init_arguments(argc, argv, &rules))
		return (2);
	pthread_mutex_unlock(&(rules.m_dead));
	check_philo(&rules);
	i = 0;
	while (i < rules.num_philo)
	{
		pthread_join(rules.philo[i].id_philo, NULL);
		i++;
	}
	return (philo_destroy(&rules));
}
