/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 13:00:32 by ayano             #+#    #+#             */
/*   Updated: 2019/09/04 13:00:33 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_data		*init_data(void)
{
	t_data		*new;

	if (!(new = malloc(sizeof(t_data))))
		return (false);
	new->line = NULL;
	new->next = NULL;
	return (new);
}

void		read_into_data(t_data **data)
{
	char		*line;
	t_data		*current;

	current = (*data);
	while (get_next_line(0, &line))
	{
		current->line = ft_strdup(line);
		add_data_node(&current);
		current = current->next;
		free(line);
	}
}

void		add_data_node(t_data **data)
{
	t_data	*current;
	t_data	*new;

	new = init_data();
	current = (*data);
	while (current->next != NULL)
		current = current->next;
	current->next = new;
}