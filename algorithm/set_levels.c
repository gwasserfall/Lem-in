/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_levels.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 09:34:43 by ayano             #+#    #+#             */
/*   Updated: 2019/11/05 09:36:09 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

/*
** Starts at end and then using a BFS logic will set each room a level
** that is dependant on the amount of steps you will need to reach it from
** that start room.
*/

bool	set_levels(t_anthill *anthill)
{
	int			i;
	t_roomlist	*frontier;
	t_roomlist	*next;
	t_roomlist	*neighbour;

	INIT_SL;
	while (frontier)
	{
		next = NULL;
		while (frontier)
		{
			neighbour = get_neighbours(frontier->room, anthill->connectors);
			while (neighbour)
			{
				if (neighbour->room->is_end && frontier->room->is_start)
					NEIGHCONT;
				if (STAT1 && STAT2)
					NEIGHAPPL;
				neighbour = neighbour->next;
			}
			frontier = frontier->next;
		}
		FRONT_NEXT;
	}
	return (append_to_pathlist(&anthill->paths, RETFUNC));
}
