/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Linsio <Linsio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 22:45:20 by Linsio            #+#    #+#             */
/*   Updated: 2023/11/02 23:43:31 by Linsio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/myeditor.h"
#include <unistd.h>

static t_printmode	check_print_mode(char *str)
{
	int	i, flag1 = 0, flag2 = 0;

	i = ft_strlen(str);
	if (i == 2 && str[0] == '*')
		return (ALL);
	else if (str[0] == '-')
		return (LINE);
	else
	{
		for (int j = 0; j < i - 1; j++)
		{
			if (!ft_isdigit(str[j]))
			{
				if (str[j] == '-')
					flag1++;
				else if (str[j] == ',')
					flag2++;
				else
				{
					printf("input error\n");
					return (ERRORP);
				}
			}
		}
		if (flag1 == 1)
			return (RANGE);
		else if (flag2 > 0)
			return (LIST);
		else if (flag1 > 1)
			return (ERRORP);
		else
			return (LINE);
	}
	return (ERRORP);
}

static void	print_line(t_setting *set, int index, int flag)
{
	FILE	*file;
	int		offset;
	char	c;

	if (index < 0 || index > set->line)
	{
		printf("Invalid line index : %d\n", index + 1);
		return ;
	}

	file = fopen(set->file_name, "r");
	if (!file)
	{
		printf("error3\n");
		perror("Error opening file");
		return ;
	}

	offset = 0;

	if (flag == 1)
	{
		c = fgetc(file);
		for (; c != EOF; c = fgetc(file))
		{
			ft_putchar_fd(c, STDOUT_FILENO);
		}
		ft_putchar_fd('\n', STDOUT_FILENO);
	}
	else
	{
		for (int i = 0; i < index; i++)
			offset += set->line_table[i] + 1;

		fseek(file, offset, SEEK_SET);

		for (int i = 0; i < set->line_table[index]; i++)
		{
			c = fgetc(file);
			ft_putchar_fd(c, STDOUT_FILENO);
		}
		ft_putchar_fd('\n', STDOUT_FILENO);
	}
	fclose(file);
}

static void	print_range(t_setting *set, char *tab)
{
	char **temp;
	int	start, end;

	temp = ft_split(tab, '-');
	start = ft_atoi(temp[0]) - 1;
	end = ft_atoi(temp[1]) - 1;

	for (int i = 0; start + i <= end; i++)
		print_line(set, start + i, 0);
}

static void	print_list(t_setting *set, char *tab)
{
	char **temp;
	int index;

	temp = ft_split(tab, ',');
	for (int i = 0; temp[i] != NULL; i++)
	{
		index = ft_atoi(temp[i]) - 1;
		print_line(set, index, 0);
	}
}

void do_print(t_setting *set, char **tab)
{
	t_printmode	mode;

	mode = check_print_mode(tab[1]);
	if (mode == LINE)
	{
		if (digit_check(tab[1]))
			print_line(set, (ft_atoi(tab[1]) - 1), 0);
		else
			printf("unvalid range\n");
	}
	else if (mode == ALL)
		print_line(set, 1, 1);
	else if (mode == RANGE)
		print_range(set, tab[1]);
	else if (mode == LIST)
		print_list(set, tab[1]);
	else if (mode == ERRORP)
	{
		printf("Usage : p <index>\n");
		return ;
	}
}