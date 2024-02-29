/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rutinas.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrimald <agrimald@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 19:12:39 by agrimald          #+#    #+#             */
/*   Updated: 2024/02/29 20:26:14 by agrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
