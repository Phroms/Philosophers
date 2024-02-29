/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrimald <agrimald@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:19:27 by agrimald          #+#    #+#             */
/*   Updated: 2024/02/29 20:24:41 by agrimald         ###   ########.fr       */
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

 #define TENEDOR "tiene el tenedor"
 #define COMER "esta comindo"
 #define DORMIR "esta durmiendo"
 #define PENSAR "esta pensando"
 #define MUERTE "esta muerto"

/*****************************************************
 *						STRUCTS						 *
 *****************************************************/

typedef struct	s_philo
{
	int				id;
	int 			num_veces_comidas;
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
	int				maximo_de_comidas;
	int				count_eats;
	int				count_deads;
	t_philo			philo[250];
}t_reglas;

/*****************************************************
 *						COLORS						 *
 *****************************************************/	

 #define FINAL		"\033[0m"	/*Final*/
 #define BLACK		"\033[30m"	/*Negro*/
 #define RED		"\033[31m"	/*Rojo*/
 #define GREEN		"\033[32m"	/*Verde*/
 #define YELLOW		"\033[33m"	/*Amarillo*/
 #define BLUE		"\033[34m"	/*Azul*/
 #define MAGENTA	"\033[35m"	/*Morado*/
 #define CYAN		"\033[36m"	/*Celeste*/
 #define WHITE		"\033[37m"	/*Blanco*/

/*****************************************************
 *						ARGUMENTS					 *
 *****************************************************/	

int			is_num(char **str);
int			is_letters(char *str);
int			is_max_pos_neg(char *str);
//void		*filosofo(void *argv);
//void		filosofo2(int argc, char **argv);
int			main(int argc, char **argv);

/*****************************************************
 *						INIT_PROGRAM				 *
 *****************************************************/	

int			time_philo(t_reglas *rul);
void		init_philo(t_reglas *reg);
int			init(t_reglas *rules);
int			init_arguments(int argc, char **argv, t_reglas *reglas);

/*****************************************************
 *						RUTINAS						 *
 *****************************************************/	

void		life(t_philo *ph);
void		*rutinas(void *void_philo);

/*****************************************************
 *						UTILS						 *
 *****************************************************/	

void		print_msg(char *color, t_philo *philo, char *s, int dead);
int			ft_atoi(const char *str);
uint64_t	total_miliseg(void);
void		ft_usleep(uint64_t waiting);

#endif
