/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rutinas.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrimald <agrimald@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 19:12:39 by agrimald          #+#    #+#             */
/*   Updated: 2024/03/01 20:00:37 by agrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_dead(t_reglas *reglas, int i, uint64_t time)
{
	pthread_mutex_lock(&(reglas->m_muerte));
	if (total_miliseg() - reglas->init_time > time)
	{
		reglas->count_deads = 1;
		pthread_mutex_unlock(&(reglas->m_muerte));
		print_msg(RED, &(reglas->philo[i]), MUERTE, 1);
	}
	else
		pthread_mutex_unlock(&reglas->m_muerte);
}

void	check_philo(t_reglas *reglas)
{
	uint64_t	tiempo;
	int			i;

	i = 0;
	while (reglas->count_deads == 0)
	{
		pthread_mutex_lock(&(reglas->philo[i].m_check_comidas));
		tiempo = reglas->philo[i].tiempo_muerte;
		pthread_mutex_unlock(&(reglas->philo[i].m_check_comidas));
		philo_dead(reglas, i, tiempo);
		pthread_mutex_lock(&(reglas->philo[i].m_check_comidas));
		if (reglas->philo[i].num_veces_comidas == reglas->maximo_de_comidas)
			reglas->todos_comieron++;
		pthread_mutex_unlock(&(reglas->philo[i].m_check_comidas));
		if (reglas->num_filosofos == reglas->todos_comieron)
			break ;
		i++;
		if (i == reglas->num_filosofos)
		{
			i = 0;
			reglas->todos_comieron = 0;
		}
	}
}

void	life(t_philo *ph)
{
	t_reglas	*reglas;

	reglas = ph->reglas;
	pthread_mutex_lock(&(ph->izq_tenedor));
	print_msg(GREEN, ph, TENEDOR, 0);
	if (reglas->num_filosofos == 1)
	{
		ft_usleep(reglas->tiempo_para_morir);
		pthread_mutex_unlock(&(ph->izq_tenedor));
		return;
	}
	pthread_mutex_lock(ph->der_tenedor);
	print_msg(CYAN, ph, TENEDOR, 0);
	pthread_mutex_lock(&(ph->m_check_comidas));
	ph->tiempo_muerte = reglas->tiempo_para_morir + (total_miliseg() - reglas->init_time);
	pthread_mutex_unlock(&(ph->izq_tenedor));
	pthread_mutex_unlock(ph->der_tenedor);
	print_msg(MAGENTA, ph, DORMIR, 0);
	ft_usleep(reglas->tiempo_para_dormir);
	print_msg(YELLOW, ph, PENSAR, 0);
}

void	*rutinas(void *void_philo)
{
	int			finish;
	t_reglas	*reglas;
	t_philo		*philo;

	philo = (t_philo *)void_philo;
	reglas = philo->reglas;
	finish = 0;
	if (philo->id % 2 == 0)
	{
		ft_usleep(reglas->tiempo_para_comer);
	}
	while (finish == 0 && (philo->num_veces_comidas != reglas->maximo_de_comidas))
	{
		life(philo);
		pthread_mutex_lock(&(reglas->m_muerte));
		finish = reglas->count_deads;
		pthread_mutex_unlock(&(reglas->m_muerte));
	}
	return (NULL);
}
