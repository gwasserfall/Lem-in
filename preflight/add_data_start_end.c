/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_data_start_end.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <ayano@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 11:58:31 by ayano             #+#    #+#             */
/*   Updated: 2019/09/09 15:32:47 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

/*
** Takes line and finds the start room then sets its name x and y position.
*/

void	add_data_start(char *line, t_anthill **anthill)
{
	char	**data;
	t_room	*current;

	current = (*anthill)->linear;
	verify_room(line);
	data = ft_strsplit(line, ' ');
	while (current->next != NULL)
	{
		if (current->is_start == 1)
			break ;
		current = current->next;
	}
	current->name = ft_strdup(data[0]);
	current->x = ft_atod(data[1]);
	current->y = ft_atod(data[2]);
	(*anthill)->start = current;
	free_array(data);
}

/*
** Takes line and finds the end room then sets its name x and y position.
*/

void	add_data_end(char *line, t_anthill **anthill)
{
	char	**data;
	t_room	*current;

	current = (*anthill)->linear;
	verify_room(line);
	data = ft_strsplit(line, ' ');
	while (current->next != NULL)
	{
		if (current->is_end == 1)
			break ;
		current = current->next;
	}
	current->name = ft_strdup(data[0]);
	current->x = ft_atod(data[1]);
	current->y = ft_atod(data[2]);
	(*anthill)->end = current;
	free_array(data);
}
