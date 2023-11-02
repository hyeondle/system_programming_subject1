/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Linsio <Linsio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 20:54:36 by Linsio            #+#    #+#             */
/*   Updated: 2023/11/02 23:40:24 by Linsio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/myeditor.h"

static void	free_set(t_setting *set)
{
	free(set->line_table);
	free(set->line_table_sum);
	free(set->file_name);
	set->file_name = NULL;
	free(set);
}

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
		for (int i = 0; i <= set->line; i++)
			printf("%d|%d|%d\n", i+1,set->line_table[i],set->line_table_sum[i]);
	}
	free_set(set);
	return (0);
}