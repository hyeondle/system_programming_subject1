/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Linsio <Linsio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 20:37:36 by Linsio            #+#    #+#             */
/*   Updated: 2023/11/02 23:42:15 by Linsio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/myeditor.h"

void	remake_line_table_add_line(t_setting *set, int index)
{
	int	*table, *table_sum;

	table = (int *)malloc(sizeof(int) * (set->line + 1));
	table_sum = (int *)malloc(sizeof(int) * (set->line + 1));
	if (!table || !table_sum)
	{
		perror("malloc error");
		exit(1);
	}
	index++;
	if (index > set->line)
		index = set->line;
	for (int i = 0; i < index; i++)
	{
		table[i] = set->line_table[i];
		table_sum[i] = set->line_table_sum[i];
	}
	table[index] = set->added_length;
	table_sum[index] = set->added_length + set->line_table_sum[index - 1];
	for (int i = index; i <= set->line; i++)
	{
		table[i + 1] = set->line_table[i];
		table_sum[i + 1] = table_sum[i] + set->line_table[i];
	}
	set->line++;
	free(set->line_table);
	free(set->line_table_sum);
	set->line_table = table;
	set->line_table_sum = table_sum;
}

void	remake_line_table_del_line(t_setting *set, int index)
{
	int	*table, *table_sum;

	if (index > set->line || index < 0)
	{
		printf("Invalid range to delete\n");
		return ;
	}
	if (set->line - 1 < 0)
	{
		printf("no more lines\n");
		return ;
	}
	table = (int *)malloc(sizeof(int) * (set->line - 1));
	table_sum = (int *)malloc(sizeof(int) * (set->line - 1));
	if (!table || !table_sum)
	{
		perror("malloc error");
		exit(1);
	}
	for (int i = 0; i < index; i++)
	{
		table[i] = set->line_table[i];
		table_sum[i] = set->line_table_sum[i];
	}
	for (int i = index; i < set->line - 1; i++)
	{
		table[i] = set->line_table[i + 1];
		table_sum[i] = (set->line_table_sum[i + 1] - set->line_table[index]);
	}
	set->line--;
	free(set->line_table);
	free(set->line_table_sum);
	set->line_table = table;
	set->line_table_sum = table_sum;
}

void	remake_line_table(t_setting *set, int index, int mode)
{
	if (mode == LINE_DEL)
		remake_line_table_del_line(set, index);
	if (mode == LINE_ADD)
		remake_line_table_add_line(set, index);
}

void swap_line_table(t_setting *set, int index, int index2)
{
	int temp1, temp2;

	temp1 = set->line_table[index];
	temp2 = set->line_table_sum[index];
	set->line_table[index] = set->line_table[index2];
	set->line_table_sum[index] = set->line_table_sum[index2];
	set->line_table[index2] = temp1;
	set->line_table_sum[index2] = temp2;
}

static void make_line_table_sum(t_setting *set)
{
	set->line_table_sum[0] = set->line_table[0];
	for (int i = 1; i <= set->line; i++)
		set->line_table_sum[i] = set->line_table[i] + set->line_table_sum[i - 1];
}

void	make_line_table(t_setting *set)
{
	FILE	*file;
	char	ch;
	int		i, j;

	file  = fopen(set->file_name, "r");
	if (!file)
	{
		printf("error2\n");
		perror("Error opening file");
		exit (1);
	}
	i = 0;
	j = 0;
	while ((ch = fgetc(file)) != EOF)
	{
		if (ch == '\n')
		{
			set->line_table[i] = j;
			i++;
			j = -1;
		}
		j++;
	}
	set->line_table[i] = j;
	fclose(file);
	make_line_table_sum(set);
}

int	count_file_lines(char *name)
{
	FILE	*file = fopen(name, "r");
	char	ch;
	int		line;

	if (!file)
	{
		printf("error1\n");
		perror("Error opening file");
		exit (1);
	}
	line = 0;
	while ((ch = fgetc(file)) != EOF)
	{
		if (ch == '\n')
			line++;
	}
	fclose(file);

	return (line);
}
