/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrimald <agrimald@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:04:30 by agrimald          #+#    #+#             */
/*   Updated: 2024/03/01 21:31:54 by agrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	time_philo(t_reglas	*rul)
{
	t_philo	*philosophers;
	int			i;

	i = 0;
	philosophers = rul->philo;
	rul->init_time = total_miliseg();
	while (i < rul->num_filosofos)
	{
		pthread_create(&(philosophers[i].id_of_philo), NULL, rutinas, &(rul->philo[i]));
		i++;
	}
	return (0);
}

void	init_philo(t_reglas *reglas)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&reglas->m_inicio);
	while (i < reglas->num_filosofos)
	{
		reglas->philo[i].id = i + 1;
		reglas->philo[i].reglas = reglas;
		reglas->philo[i].tiempo_muerte = reglas->tiempo_para_morir;
		reglas->philo[i].num_veces_comidas = 0;
		if (i == 0)
			reglas->philo[i].der_tenedor = &(reglas->philo[reglas->num_filosofos - 1].izq_tenedor);
		else
			reglas->philo[i].der_tenedor = &(reglas->philo[i - 1].izq_tenedor);
		pthread_mutex_init(&(reglas->philo[i].izq_tenedor), NULL);
		pthread_mutex_init(&(reglas->philo[i].m_check_comidas), NULL);
		i++;
	}
}

int	init(t_reglas *rules)
{
	if (pthread_mutex_init(&(rules->m_inicio), NULL))
		return (exit_philo("INIT_MUTEX", "Mutex start failed", THREADS));
	if (pthread_mutex_init(&(rules->m_muerte), NULL))
		return (exit_philo("INIT_MUTEX", "Mutex print failed", THREADS));
	if (pthread_mutex_init(&(rules->m_impresion), NULL))
		return (exit_philo("INIT_MUTEX", "Mutex death failed", THREADS));
	return (0);
}

int	init_arguments(int argc, char **argv, t_reglas *reglas)
{
	reglas->num_filosofos = (uint64_t)ft_atoi(argv[1]);
	reglas->tiempo_para_morir = (uint64_t)ft_atoi(argv[2]);
	reglas->tiempo_para_comer = (uint64_t)ft_atoi(argv[3]);
	reglas->tiempo_para_dormir = (uint64_t)ft_atoi(argv[4]);
	reglas->maximo_de_comidas = -1;
	reglas->count_eats = 0;
	reglas->count_deads = 0;
	if (argc == 6)
		reglas->maximo_de_comidas = (uint64_t)ft_atoi(argv[5]);
	if (reglas->num_filosofos == 0)
		return (printf("Error bebe: No hay filosofos 🤭\n"));
	else if (reglas->num_filosofos > 250)
		return (printf("Que fue mano: exicediste el numero de threads 😐\n"));
	if (init(reglas))
		return (1);
	init_philo(reglas);
	time_philo(reglas);
	return (0);
}

int	main(int argc, char **argv)
{
	t_reglas	reglas;
	int			i;

	if (process_arguments(argc, argv))
		return (1);
	if (init_arguments(argc, argv, &reglas))
		return (2);
	pthread_mutex_unlock(&(reglas.m_muerte));
	check_philo(&reglas);
	i = 0;
	while (i < reglas.num_filosofos)
	{
		pthread_join(reglas.philo[i].id_of_philo, NULL);
		i++;
	}
	return (philo_destroy(&reglas));
}
