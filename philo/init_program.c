/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrimald <agrimald@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 13:04:30 by agrimald          #+#    #+#             */
/*   Updated: 2024/02/27 20:09:43 by agrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*int	time_philo(t_reglas	*rul)
{
	t_philos	*philosophers;
	int			i;

	i = 0;
	philosophers = rul->philo;
	rul->init_time = total_miliseg();  ✅"YA CREAMOS NUESTRO CRONO";
	while (i < rul->num_filosofos)
	{
		pthread_create = (&(philosophers[i].id_of_philo), NULL, sim, (&rul->philo[i]))
		"1. IMPORTANTE: ENTENDER BIEN LA FUNCION PTHREAD_CREATE, ESTO SOLO ES DE EJEMPLO";
		i++;
	}
	"2. LA FUNCION SIN ES LA RUTINA QUE HARA LOS FILOSOFOS, TAMBIEN PUEDE COMENZAR CON LAS VECES QUE COMAN" 
	return (0);
}*/

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
		reglas->philo[i].veces_comidas = 0;
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
	pthread_mutex_init(&(rules->m_inicio), NULL);
	pthread_mutex_init(&(rules->m_muerte), NULL);
	pthread_mutex_init(&(rules->m_impresion), NULL);
	return (0);
}

int	init_arguments(int argc, char **argv, t_reglas *reglas)
{
	reglas->num_filosofos = (uint64_t)ft_atoi(argv[1]);
	reglas->tiempo_para_morir = (uint64_t)ft_atoi(argv[2]);
	reglas->tiempo_para_comer = (uint64_t)ft_atoi(argv[3]);
	reglas->tiempo_para_dormir = (uint64_t)ft_atoi(argv[4]);
	reglas->num_ciclos = -1;
	reglas->count_eats = 0;
	reglas->count_deads = 0;
	if (argc == 6)
		reglas->num_ciclos = (uint64_t)ft_atoi(argv[5]);
	if (reglas->num_filosofos == 0)
		return (printf("Error bebe: No hay filosofos 🤭\n"));
	else if (reglas->num_filosofos > 250)
		return (printf("Que fue mano: exicediste el numero de threads 😐\n"));
	if (init(reglas))
		return (1);
	init_philo(reglas);
	//time_philo();
	return (0);
}
