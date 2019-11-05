/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 08:51:29 by ayano             #+#    #+#             */
/*   Updated: 2019/11/05 09:20:35 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

/*
** initialize the roomlist struct.
*/

t_roomlist		*init_roomlist(void)
{
	t_roomlist	*new;

	if (!(new = malloc(sizeof(t_roomlist))))
		return (NULL);
	new->next = NULL;
	new->room = NULL;
	return (new);
}

/*
** Add room_list node to the room list linked list.
*/

void			append_list(t_roomlist **start, t_roomlist *new)
{
	t_roomlist *list;

	list = (*start);
	if (!list)
		*start = new;
	else
	{
		while (list->next)
			list = list->next;
		list->next = new;
	}
}

/*
** Makes a new roomlist node.
*/

t_roomlist		*make_item(t_room *room)
{
	t_roomlist *new;

	if (!(new = malloc(sizeof(t_roomlist))))
		return (NULL);
	new->next = NULL;
	new->room = room;
	return (new);
}

/*
** gets the rooms neighbours, ie the rooms linked to the same parent node.
*/

t_roomlist		*get_neighbours(t_room *room, t_link *links)
{
	t_roomlist *start;

	start = NULL;
	while (links)
	{
		if (room == links->from)
			append_list(&start, make_item(links->to));
		else if (room == links->to)
			append_list(&start, make_item(links->from));
		links = links->next;
	}
	return (start);
}
