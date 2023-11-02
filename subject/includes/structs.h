/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Linsio <Linsio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:07:11 by Linsio            #+#    #+#             */
/*   Updated: 2023/11/02 21:58:19 by Linsio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;


typedef struct s_setting
{
	int		line;
	int		*line_table;
	int		*line_table_sum;
	int		added_length;
	char	*file_name;
	t_bool	exit;
}	t_setting;

typedef enum e_printmode
{
	LINE,
	LIST,
	RANGE,
	ALL,
	ERRORP
}	t_printmode;

typedef enum e_editmode
{
	PRINT,
	LINE_DEL,
	LINE_ADD,
	LINE_SWAP,
	EXIT,
	ERRORE
}	t_editmode;

#endif