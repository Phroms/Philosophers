/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrimald <agrimald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 19:16:11 by agrimald          #+#    #+#             */
/*   Updated: 2024/03/08 15:32:13 by agrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	exit_philo(char *input, char *err_msg, t_error_code err_code)
{
	printf("[%s]: %s\n\n", input, err_msg);
	return (err_code);
}

int	philo_destroy(t_rules *data)
{
	pthread_mutex_destroy(&(data->m_print));
	pthread_mutex_destroy(&(data->m_dead));
	pthread_mutex_destroy(&(data->m_init));
	return (0);
}
