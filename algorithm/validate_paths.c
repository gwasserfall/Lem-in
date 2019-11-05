/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_paths.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 12:29:04 by ayano             #+#    #+#             */
/*   Updated: 2019/11/05 09:18:58 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void		optimise_paths(t_anthill **anthill)
{
	t_pathlist	*current;
	t_path		*current_path;

	current = (*anthill)->paths;
	while (current)
	{
		current_path = current->path;
		if (current->length > (*anthill)->nb_ants
			&& (*anthill)->nb_paths > 1)
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
	prepend_to_pathlist(&(*anthill)->paths, create_pathlist_item(new));
	(*anthill)->nb_paths++;
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
			return (add_start_end_pathlist(anthill));
		link = link->next;
	}
}
