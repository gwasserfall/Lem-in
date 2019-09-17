/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 09:24:44 by ayano             #+#    #+#             */
/*   Updated: 2019/09/10 09:24:47 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

/*
** Sets all the room levels to -1 and all the paretns to NULL.
*/
void	reset_rooms(t_anthill **anthill)
{
	t_room *room;

	room = (*anthill)->linear;

	while (room)
	{
<<<<<<< HEAD
		//printf("Resetting room %s\n", room->name);
=======
		// printf("Resetting room %s\n", room->name);
>>>>>>> 726aea5ee1b853ab98378623e1fecb182a6d5aa1
		room->parent = NULL;
		room->level = -1;
		if (room->is_start)
			room->level = 0;
		room = room->next;
	}
}
