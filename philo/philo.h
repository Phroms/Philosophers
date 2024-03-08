/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrimald <agrimald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:19:27 by agrimald          #+#    #+#             */
/*   Updated: 2024/03/08 16:06:24 by agrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/types.h>
# include <sys/time.h>

# define FORK "Has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DIED "died"

/*****************************************************
 *						COLORS						 *
 *****************************************************/	

# define FINAL		"\033[0m"	/*Final*/
# define BLACK		"\033[30m"	/*Negro*/
# define RED		"\033[31m"	/*Rojo*/
# define GREEN		"\033[32m"	/*Verde*/  //este verde esa feo
# define YELLOW		"\033[33m"	/*Amarillo*/
# define BLUE		"\033[34m"	/*Azul*/
# define MAGENTA	"\033[35m"	/*Morado*/
# define CYAN		"\033[36m"	/*Celeste*/
# define WHITE		"\033[97m"	/*Blanco*/

/*****************************************************
 *						STRUCTS						 *
 *****************************************************/

typedef struct s_philo
{
	int				id;
	int				num_meals;
	uint64_t		time_dead;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	l_fork;
	pthread_mutex_t	m_check_meals;
	struct s_rules	*rules;
	pthread_t		id_philo;
}	t_philo;

typedef struct s_rules
{
	int				num_philo;
	uint64_t		time_of_dead;
	uint64_t		time_of_eat;
	uint64_t		time_of_sleep;
	uint64_t		init_time;
	pthread_mutex_t	m_init;
	pthread_mutex_t	m_dead;
	pthread_mutex_t	m_print;
	int				max_meals;
	int				count_eats;
	int				count_deads;
	int				all_eat;
	t_philo			philo[250];
}	t_rules;

typedef enum s_errors
{
	BAD_INPUT = 1,
	MALLOC = 2,
	MUTEX = 3,
	THREADS = 4,
	TIME = 5,		
}	t_error_code;

/*****************************************************
 *						ARGUMENTS					 *
 *****************************************************/	

int			is_num(char **str);
int			is_letters(char *str);
int			is_max_pos_neg(char *str);
int			process_arguments(int argc, char **argv);

/*****************************************************
 *						INIT_PROGRAM				 *
 *****************************************************/	

int			time_philo(t_rules *rul);
void		init_philo(t_rules *reg);
int			init(t_rules *rules);
int			init_arguments(int argc, char **argv, t_rules *rules);

/*****************************************************
 *						rutin						 *
 *****************************************************/	

void		philo_dead(t_rules *rules, int i, uint64_t time);
void		check_philo(t_rules *rules);
void		life(t_philo *ph);
void		*rutin(void *void_philo);

/*****************************************************
 *						EXIT						 *
 *****************************************************/	

int			exit_philo(char *input, char *err_msg, t_error_code err_code);
int			philo_destroy(t_rules *data);

/*****************************************************
 *						UTILS						 *
 *****************************************************/	

void		print_msg(char *color, t_philo *philo, char *s, int dead);
int			ft_atoi(const char *str);
int			ft_strcmp(char *s1, char *s2);
uint64_t	total_miliseg(void);
void		ft_usleep(uint64_t waiting);

#endif
