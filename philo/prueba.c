/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrimald <agrimald@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:49:28 by agrimald          #+#    #+#             */
/*   Updated: 2024/02/27 15:40:48 by agrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdint.h>
#include <sys/time.h>

int	main()
{
	struct timeval current_time;

	gettimeofday(&current_time, NULL);
	return (printf("Tiempo transcurrido: %llu\n", (uint64_t)current_time.tv_sec * 1000 + (uint64_t)current_time.tv_usec));
}
