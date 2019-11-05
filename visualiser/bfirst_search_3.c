/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfirst_search_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 12:16:27 by ayano             #+#    #+#             */
/*   Updated: 2019/11/05 12:16:28 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualiser.h"

bool	set_levels(t_state *s)
{
	int			i;
	t_roomlist	*next;
	t_roomlist	*neighbour;
	t_roomlist	*frontier;

	reset_rooms(s);
	i = 1;
	frontier = NULL;
	append_list(&frontier, make_item(s->anthill->start));
	while (frontier)
	{
		next = NULL;
		while (frontier)
		{
			neighbour = get_neighbours(frontier->room, s->anthill->connectors);
			while (neighbour)
			{
				if (neighbour->room->is_end && frontier->room->is_start)
				{
					neighbour = neighbour->next;
					continue;
				}
				if (neighbour->room->level == -1 && !room_in_pathlist(s->paths, neighbour->room))
				{
					neighbour->room->level = i;
					neighbour->room->parent = frontier->room;
					append_list(&next, make_item(neighbour->room));
				}
				neighbour = neighbour->next;
			}
			frontier = frontier->next;
		}
		i++;
		frontier = next;
	}
	return (append_to_pathlist(&s->paths, create_pathlist_item(map_path(s->anthill->end))));
}
