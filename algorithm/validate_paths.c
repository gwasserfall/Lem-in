/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_paths.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 12:29:04 by ayano             #+#    #+#             */
/*   Updated: 2019/09/12 12:29:05 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void		optimise_paths(t_anthill **anthill)
{
	t_pathlist	*current;
	t_path		*current_path;

	current = (*anthill)->paths;
	check_start_end_path(anthill);
	while (current)
	{
		current_path = current->path;
		if (current->length == (*anthill)->nb_ants && (*anthill)->nb_paths > 1)
		{
			current->valid = 0;
			(*anthill)->nb_paths--;
		}
		current = current->next;
	}
}


void		add_start_end_pathlist(t_anthill **anthill)
{
	t_path		*new;

	new = NULL;
	append_to_path(&new, make_path_item((*anthill)->end));
	append_to_path(&new, make_path_item((*anthill)->start));
	append_to_pathlist(&(*anthill)->paths, create_pathlist_item(new));
}

void		check_start_end_path(t_anthill **anthill)
{
	t_room		*start;
	t_room		*end;
	t_link		*link;

	start = (*anthill)->start;
	end = (*anthill)->end;
	link = (*anthill)->connectors;

	while (link)
	{
		if ((link->from == start && link->to == end)
			|| (link->from == end && link->to == start))
			return add_start_end_pathlist(anthill);
		link = link->next;
	}
}

void		order_paths(t_anthill *anthill)
{
	t_pathlist	*current;
	t_pathlist	*temp;
	t_pathlist	*next_temp;

	current = anthill->paths;
	while (current->next)
	{
		if (current->length > current->next->length)
		{
			temp = current;
			next_temp = current->next;
			temp->next = current->next->next;
			next_temp->next = current;
			current = next_temp;
			

		}
		current = current->next;
	}
}