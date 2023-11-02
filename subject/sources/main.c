/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Linsio <Linsio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 20:54:36 by Linsio            #+#    #+#             */
/*   Updated: 2023/11/02 22:14:55 by Linsio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/myeditor.h"

int main(int argc, char **argv)
{
	t_setting	*set;
	char		*input;

	if (argc != 2)
	{
		printf("Usage : %s <textfile>\n", argv[0]);
		return 1;
	}
	set = init_set(argv[1]);
	while (1)
	{
		input = get_input();
		if (!input)
			break ;
		operation(input, set);
		free(input);
		if (set->exit == TRUE)
			break ;
	}
	return (0);
}