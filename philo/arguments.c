/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrimald <agrimald@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:39:12 by agrimald          #+#    #+#             */
/*   Updated: 2024/02/20 20:37:49 by agrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>

int	is_num(char **str)
{
	int i;
	int j;

	i = 1;
	while (str[i])
	{
		j = 0;
		while (str[i][j] != '\0')
		{
			if (str[i][j] >= '0' && str[i][j] <= '9')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_letters(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
			return (1);
		i++;
	}
	return (0);
}

int	is_max_pos_neg(char *str)
{
	char	*num_pos;
	char	*num_neg;

	num_pos = "2147483647";
	num_neg = "-2147483648";
	if (strcmp(str, num_pos) == 0 || strcmp(str, num_neg) == 0)
	{
		printf("Error bb ☹️ \n");
		exit(1);
	}
	else if (str[0] == '-')
	{
		printf("Error tambien bb 🤕\n");
		exit(1);
	}
	return (0);
}

void	*filosofo()
{
	printf("Filosofo pensandoooo 🤔....\n");
	sleep(2);
	printf("Filosofo comiendo 🍜....\n");
	printf("Filosofo durmiendo 😴....\n");
	return (NULL);
}

void	filosofo2(char *str)
{
	pthread_t hilo1;
	pthread_t hilo2;
	pthread_t hilo3;

	printf("Cosas que hay: %s\n", str);
	pthread_create(&hilo1, NULL, filosofo, NULL);
	pthread_create(&hilo2, NULL, filosofo, NULL);
	pthread_create(&hilo3, NULL, filosofo, NULL);
	pthread_join(hilo1, NULL);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	while (argc > i)
	{
		if (is_letters(argv[i]))
		{
			printf("Error papi, no se admiten letras 🤥\n");
			exit(1);
		}
		if (is_max_pos_neg(argv[i]))
		{
			printf("Error bebe, no puedes exceder de los numeros y tampoco negativos 😖\n");
			exit(1);
		}
		i++;
	}
	i = 1;
	if (argc == 5 || argc == 6)
	{
		while (argc > i)
		{
			if (is_num(&argv[i]))
				filosofo2(argv[i]);
			i++;
		}
	}
	return (0);
}
