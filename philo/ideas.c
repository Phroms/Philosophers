/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrimald <agrimald@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:12:43 by agrimald          #+#    #+#             */
/*   Updated: 2024/02/21 15:00:47 by agrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

void    *filosofo()
{
    printf("Filosofo pensadoooo 🤔....\n");
	sleep(2);
    printf("Filosofo comiendo 🍜....\n");
	printf("Filosofo durmiendo 😴....\n");
    return (NULL);
}

int	is_num(char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			return (1);
		i++;
		//else if
			//return (printf("Que haces papi, aqui ta mal ehhh 🤥....\n"));
	}
	return (0);
}

int is_letters(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
			return (1);
		i++;
	}
	return (0);
}

int main(int argc, char **argv)
{

	int	i;

	i = 1;
	while (argc > i)
	{
		//if (is_letters(argv[i]))
			//return (printf("Mano hay letras, quita quita 🤬...\n"));
		//i++;
		if (is_num(argv[i]))
		{
    		pthread_t thread_id;
			pthread_t thread_id2;
			pthread_t thread_id3;
			//pthread_t thread_id4;

   	 		pthread_create(&thread_id, NULL, filosofo, NULL);
			pthread_create(&thread_id2, NULL, filosofo, NULL);
    		pthread_create(&thread_id3, NULL, filosofo, NULL);
			//pthread_create(&thread_id4, NULL, filosofo, NULL);
			pthread_join(thread_id, NULL);
			//pthread_join(thread_id, NULL);
			//pthread_join(thread_id2, NULL);	
			//if (is_letters(argv[i]))
				//return (printf("Mano hay letras, quita quita 🤬...\n"));
		}
		i++;
	}
    return (0);
}
