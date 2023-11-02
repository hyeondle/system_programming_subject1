/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Linsio <Linsio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 20:40:27 by Linsio            #+#    #+#             */
/*   Updated: 2023/11/02 22:29:03 by Linsio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/myeditor.h"

void execute(char **tab, int order, t_setting *set)
{
	if (order == PRINT)
		do_print(set, tab);
	else if (order == LINE_DEL)
		do_del_line(set, tab[1]);
	else if (order == LINE_ADD)
		do_add_line(set, tab[1]);
	else if (order == LINE_SWAP)
		do_swap_line(set, tab[1]);
	else if (order == EXIT)
		set->exit = TRUE;
	else
	{
		return ;
	}
}

int	find_func(char *str)
{
	if (ft_strlen(str) != 1)
	{
		if (str[0] == 'q')
			return (EXIT);
		else
			return (ERRORE);
	}
	if (str[0] == 'p')
		return (PRINT);
	else if (str[0] == 'd')
		return (LINE_DEL);
	else if (str[0] == 'a')
		return (LINE_ADD);
	else if (str[0] == 's')
		return (LINE_SWAP);
	else
		return (ERRORE);
}

void	operation(char *input, t_setting *set)
{
	char	**tokenized_str;
	int		mode;

	tokenized_str = ft_split(input, ' ');
	mode = find_func(tokenized_str[0]);
	execute(tokenized_str, mode, set);
	free_tab(tokenized_str);
}