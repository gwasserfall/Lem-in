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

t_data		init_data(void)
{
	t_data		*data;

	data = allocate_space();
	// read_into_data(data);
	return (*data);


}

t_data		*allocate_space(void)
{
	t_data		*new;

	if (!(new = malloc(sizeof(t_data))))
		return (false);
	new->line = NULL;
	new->next = NULL;
	return (new);
}

void		read_into_data(t_data *data)
{
	char		*line;
	t_data		*head;

	head = data;
	while (get_next_line(0, &line))
	{
		data->next = allocate_space();
		data->line = ft_strdup(line);
		data = data->next;
		free(line);
	}		
}