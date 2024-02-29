/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rutinas.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrimald <agrimald@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 19:12:39 by agrimald          #+#    #+#             */
/*   Updated: 2024/02/29 15:10:54 by agrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*rutinas(void *void_philo)
{
	int			finish;
	t_reglas	*rules;
	t_philo		*philo;

	philo = (t_philo)void_philo;
	rules = philo->rules;
	finish = 0;
	if (philo % 2 == 0)
	{
		ft_usleep(reglas->tiempo_para_comer);
	}
	"1. HACER UN BUCLE DONDE VAS A COMPARAR SI LOS FILOFOS NO HAN TERMINADO DE COMER Y VAS A COMPARAR LAS VECES DE COMIDA CON LAS MAXIMA DE VECES QUE PUEDE COMER UN FILO";
	"2. DENTRO DE ESE BUCLE HARAS UNA FUNCION DONDE HARAS UNA LOGICA DONDE LOS FILOSOFOS "VIVEN"QUE TOMARA COMO ARGUMENTOS TUS PHILOS";
	"3. BLOQUEARAS LA REGLA DE QUE LOS FILOSOFOS PUEDAN MORIR";
	"4. DARAS EL VALOR DE LA REGLA DE MORIR A TU VARIABLE FINISH";
	"5. DESBLOQUEARAS LA REGLA DE QUE LOS FILOSOFOS PUEDAN MORIR, PARA QUE ASI OTROS HILOS PUEDAN ENTRAR A ESA REGLA Y MORIR";
	"6. RETORNAR NULL"
}
