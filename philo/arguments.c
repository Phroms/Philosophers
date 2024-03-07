/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agrimald <agrimald@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 17:39:12 by agrimald          #+#    #+#             */
/*   Updated: 2024/03/07 15:58:31 by agrimald         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_num(char **str)
{
	int	i;
	int	j;

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
		if ((str[i] >= 'a' && str[i] <= 'z') \
				|| (str[i] >= 'A' && str[i] <= 'Z'))
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

int	process_arguments(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc < 5 || argc > 6)
		return (printf("Falta o hay mas de los argumentos bb 🥶\n"));
	while (argc > i)
	{
		if (is_letters(argv[i]))
			return (printf("Error papi, no se admiten letras 🤥\n"));
		if (is_max_pos_neg(argv[i]))
			exit(1);
		i++;
	}
	return (0);
}
