/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrimald <agrimald@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 15:19:27 by agrimald          #+#    #+#             */
/*   Updated: 2024/02/23 16:08:14 by agrimald         ###   ########.fr       */
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
/*****************************************************
 *						STRUCTS						 *
 *****************************************************/

typedef struct	

/*****************************************************
 *						ARGUMENTS					 *
 *****************************************************/	

int		is_num(char **str);
int		is_letters(char *str);
int		is_max_pos_neg(char *str);
void	*filosofo(void *argv);
void	filosofo2(char *str);
int		main(int argc, char **argv);

#endif
