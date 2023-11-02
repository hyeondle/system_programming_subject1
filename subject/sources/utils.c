/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Linsio <Linsio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 22:56:58 by Linsio            #+#    #+#             */
/*   Updated: 2023/11/02 23:43:30 by Linsio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/myeditor.h"

void	free_tab(char	**str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
}

char	*get_input()
{
	char	*input;

	write(STDOUT_FILENO, ">>", 3);
	input = get_next_line(STDIN_FILENO);
	if (!input)
	{
		printf("input error occured\n");
		exit(1);
	}
	return (input);
}

t_bool digit_check(char *str)
{
	for (int i = 0; i < (int)ft_strlen(str); i++)
	{
		if (ft_isdigit(str[i]) || str[i] == '\n')
			continue;
		else
			return (FALSE);
	}
	return (TRUE);
}

int	index_check(char *tab)
{
	if (!digit_check(tab))
	{
		printf("unvalid input\n");
		return (-2);
	}
	return (ft_atoi(tab) - 1);
}