/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Linsio <Linsio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 20:37:19 by Linsio            #+#    #+#             */
/*   Updated: 2023/11/02 22:57:02 by Linsio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/myeditor.h"
#include <string.h>

void do_swap_line(t_setting *set, char *tab)
{
    FILE *file, *temp;
    int current_line, index1, index2;
    char buf[1024], *line1 = NULL, *line2 = NULL, *temp_line;

    index1 = index_check(tab);
    if (index1 < 0 || index1 > set->line)
	{
		printf("invalid range\n");
        return ;
	}
    scanf("%d", &index2);
    index2--;

    if (index1 == index2)
        return ;
	if (index2 > set->line || index2 < 1)
	{
		printf("invalid range\n");
		return ;
	}
    file = fopen(set->file_name, "r");
    if (file == NULL)
	{
        perror("Error opening file");
        return ;
    }

    temp = fopen("temp.txt", "w");
    if (temp == NULL)
	{
        perror("Error opening temp file");
        fclose(file);
        return ;
    }

    current_line = 0;
    while (fgets(buf, sizeof(buf), file) != NULL)
	{
        if (current_line == index1)
            line1 = ft_strdup(buf);
        else if (current_line == index2)
            line2 = ft_strdup(buf);
        current_line++;
    }
	if (index1 == set->line)
	{
		temp_line = ft_strjoin(line1, "\n");
		free(line1);
		line1 = temp_line;
		line2[strcspn(line2, "\n")] = '\0';
	}
	else if (index2 == set->line)
	{
		temp_line = ft_strjoin(line2, "\n");
		free(line2);
		line2 = temp_line;
		line1[strcspn(line1, "\n")] = '\0';
	}
    rewind(file);
    current_line = 0;
    while (fgets(buf, sizeof(buf), file) != NULL)
	{
        if (current_line == index1)
            fputs(line2, temp);
        else if (current_line == index2)
            fputs(line1, temp);
        else
            fputs(buf, temp);
        current_line++;
    }
    fclose(file);
    fclose(temp);


    free(line1);
    free(line2);
	line1 = NULL;
	line2 = NULL;

    remove(set->file_name);
    rename("temp.txt", set->file_name);

    swap_line_table(set, index1, index2);
}

void	do_del_line(t_setting *set, char *tab)
{
	FILE	*file, *temp;
	int		current_line, index;
	char	buf[1024];

	index = index_check(tab);
	if (index < 0)
		return ;
	file = fopen(set->file_name, "r");
	if (file == NULL)
	{
		perror("Error opening file");
		return ;
	}
	temp = fopen("temp.txt", "w");
	if (temp == NULL)
	{
		perror("Error opening temp file");
		fclose(file);
		return ;
	}
	current_line = 0;

	while (current_line <= set->line)
	{
		fgets(buf, sizeof(buf), file);
		if (current_line + 1 == set->line && current_line + 1 == index)
			buf[strcspn(buf, "\n")] = '\0';
		if (current_line != index)
			fputs(buf, temp);
		current_line++;
	}
	fclose(file);
	fclose(temp);

	remove(set->file_name);
	rename("temp.txt", set->file_name);

	remake_line_table(set, index, LINE_DEL);
}

void	do_add_line(t_setting *set, char *tab)
{
	FILE	*file, *temp;
	int		current_line, index;
	char	buf[1024], *new_line;
	size_t	len;

	index = index_check(tab);
	if (index < -1)
		return ;
	file = fopen(set->file_name, "r");
	if (file == NULL)
	{
		perror("Error opening file");
		return ;
	}
	temp = fopen("temp.txt", "w");
	if (temp == NULL)
	{
		perror("Error opening temp file");
		fclose(file);
		return ;
	}
	new_line = NULL;
	len = 0;
	getline(&new_line, &len, stdin);
	new_line[strcspn(new_line, "\n")] = '\0';
	set->added_length = ft_strlen(new_line);
	current_line = 0;
	while (current_line <= set->line)
	{
		fgets(buf, sizeof(buf), file);
		if (current_line == index + 1)
		{
			fputs(new_line, temp);
			fputc('\n', temp);
		}
		fputs(buf, temp);
		current_line++;
	}
	if (index + 1 >= current_line)
	{
		fputc('\n', temp);
		fputs(new_line, temp);
	}
	fclose(file);
	fclose(temp);

	free(new_line);
	new_line = NULL;

	remove(set->file_name);
	rename("temp.txt", set->file_name);

	remake_line_table(set, index, LINE_ADD);
}
