/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrimald <agrimald@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 19:16:11 by agrimald          #+#    #+#             */
/*   Updated: 2024/03/01 21:35:21 by agrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	exit_philo(char *input, char *err_msg, error_code err_code)
{
	printf("[%s]: %s\n\n", input, err_msg);
	return (err_code);
}

int	philo_destroy(t_reglas *data)
{
	pthread_mutex_destroy(&(data->m_impresion));
	pthread_mutex_destroy(&(data->m_muerte));
	pthread_mutex_destroy(&(data->m_inicio));
	return (0);
}
