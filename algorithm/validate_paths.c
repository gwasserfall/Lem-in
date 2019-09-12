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
	start_end_path(anthill);
	while (current)
	{
		(*anthill)->nb_paths++;
		current = current->next;
	}
	current = (*anthill)->paths;
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

void		start_end_path(t_anthill **anthill)
{
	t_room		*start;
	t_room		*end;
	t_link		*link;

	start = (*anthill)->start;
	end = (*anthill)->end;
	link = (*anthill)->connectors;

	while (link)
	{
		if ((link->from == (*anthill)->start && link->to == (*anthill)->end)
			|| (link->from == (*anthill)->end && link->to == (*anthill)->start))
		{
			prepend_pathlist(anthill);
			break ;
		}
	}
}

void		prepend_pathlist(t_anthill **anthill)
{
	t_pathlist	*existing;
	t_pathlist	*new_pathlist;
	t_path		*new;

	new = make_path_item((*anthill)->start);
	new->next = (*anthill)->end;
	new_pathlist = create_pathlist_item(new);
	existing = (*anthill)->paths;
	(*anthill)->paths = new_pathlist;
	new_pathlist->next = existing;
}