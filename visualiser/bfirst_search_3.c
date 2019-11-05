/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfirst_search_3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 12:16:27 by ayano             #+#    #+#             */
/*   Updated: 2019/11/05 14:07:38 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualiser.h"

bool	set_levels(t_state *s)
{
	int			i;
	t_roomlist	*next;
	t_roomlist	*neighbour;
	t_roomlist	*frontier;

	INIT_SL2;
	while (frontier)
	{
		next = NULL;
		while (frontier)
		{
			neighbour = get_neighbours(frontier->room, s->anthill->connectors);
			while (neighbour)
			{
				if (neighbour->room->is_end && frontier->room->is_start)
					NEIGHCONT;
				if (STAT1 && STAT3)
					NEIGHAPPL;
				neighbour = neighbour->next;
			}
			frontier = frontier->next;
		}
		FRONT_NEXT;
	}
	return (append_to_pathlist(&s->paths, RETFUNC2));
}
