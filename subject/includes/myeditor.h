/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myeditor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Linsio <Linsio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:01:34 by Linsio            #+#    #+#             */
/*   Updated: 2023/11/02 22:04:17 by Linsio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYEDITOR_H
# define MYEDITOR_H

# include "./headers.h"
# include "./structs.h"


/*	init		*/
t_setting	*init_set(char *name);

/*	operation	*/
void	operation(char *input, t_setting *set);
int		find_func(char *str);
void	execute(char **tab, int order, t_setting *set);

/*	print		*/
void	do_print(t_setting *set, char **tab);

/*	edit		*/
void	do_del_line(t_setting *set, char *tab);
void	do_add_line(t_setting *set, char *tab);
void	do_swap_line(t_setting *set, char *tab);

/*	utils		*/
void	free_tab(char	**str);
char	*get_input();
t_bool	digit_check(char *str);
int		index_check(char *tab);

void	remake_line_table_add_line(t_setting *set, int index);
void	remake_line_table_del_line(t_setting *set, int index);
void	remake_line_table(t_setting *set, int index, int mode);
void	swap_line_table(t_setting *set, int index, int index2);
void	make_line_table(t_setting *set);
int		count_file_lines(char *name);


#endif