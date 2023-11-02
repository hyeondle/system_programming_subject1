/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Linsio <Linsio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 22:33:59 by Linsio            #+#    #+#             */
/*   Updated: 2023/11/02 23:43:32 by Linsio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/myeditor.h"

t_setting	*init_set(char *name)
{
	t_setting	*set;

	set = (t_setting *)malloc(sizeof(t_setting));
	if (!set)
	{
		printf("Malloc Error\n");
		exit(1);
	}
	set->file_name = ft_strdup(name);
	set->line = count_file_lines(name);
	set->line_table = (int *)malloc(sizeof(int) * set->line);
	set->line_table_sum = (int *)malloc(sizeof(int) * set->line);
	if (!set->line_table || !set->line_table_sum)
	{
		printf("Malloc Error\n");
		exit(1);
	}
	make_line_table(set);
	set->exit = FALSE;
	return (set);
}
