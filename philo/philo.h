/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrimald <agrimald@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:19:27 by agrimald          #+#    #+#             */
/*   Updated: 2024/02/27 20:09:47 by agrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
 #define PHILO_H

 # include <unistd.h>
 # include <stdio.h>
 # include <string.h>
 # include <stdlib.h>
 # include <pthread.h>
 # include <sys/types.h>
 # include <sys/time.h>
/*****************************************************
 *						STRUCTS						 *
 *****************************************************/

typedef struct	s_philo
{
	int				id;
	int 			veces_comidas;
	uint64_t		tiempo_muerte;
	pthread_mutex_t	*der_tenedor;
	pthread_mutex_t	izq_tenedor;
	pthread_mutex_t	m_check_comidas;
	struct s_reglas	*reglas;
	pthread_t		id_of_philo;
}t_philo;

typedef struct	s_reglas
{
	int				num_filosofos;
	uint64_t		tiempo_para_morir;
	uint64_t		tiempo_para_comer;
	uint64_t		tiempo_para_dormir;
	uint64_t		init_time;
	pthread_mutex_t	m_inicio;
	pthread_mutex_t	m_muerte;
	pthread_mutex_t	m_impresion;
	int				num_ciclos;
	int				count_eats;
	int				count_deads;
	t_philo			philo[250];
}t_reglas;

/*****************************************************
 *						ARGUMENTS					 *
 *****************************************************/	

int			is_num(char **str);
int			is_letters(char *str);
int			is_max_pos_neg(char *str);
void		*filosofo(void *argv);
void		filosofo2(int argc, char **argv);
int			main(int argc, char **argv);

/*****************************************************
 *						INIT_PROGRAM				 *
 *****************************************************/	

int			time_philo(t_reglas *rul);
void		init_philo(t_reglas *reg);
int			init(t_reglas *rules);
int			init_arguments(int argc, char **argv, t_reglas *reglas);

/*****************************************************
 *						ARGUMENTS					 *
 *****************************************************/	

void		*rutinas(void);

/*****************************************************
 *						UTILS						 *
 *****************************************************/	

int			ft_atoi(const char *str);
uint64_t	total_miliseg(void);

#endif
