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
	t_path		*check;
	t_pathlist	*new;
	int		i;

	i = 0;
	start = (*anthill)->start;
	while (start->links[i] != '\0')
	{
		if (start->links[i] == (*anthill)->end)
		{
			check = make_path_item((*anthill)->start);
			new = create_pathlist_item(check);
			prepend_pathlist(anthill, new);
			(*anthill)->nb_paths++;
		}
	}
}

void		prepend_pathlist(t_anthill **anthill, t_pathlist *to_add)
{
	t_pathlist	*existing;

	existing = (*anthill)->paths;
	(*anthill)->paths = to_add;
	to_add->next = existing;
}