/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_path_more.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 09:24:31 by ayano             #+#    #+#             */
/*   Updated: 2019/11/05 09:28:33 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

/*
** Checks to see if the room is in the pathlist, ie room has been visited
*/

bool	room_in_pathlist(t_pathlist *pathlist, t_room *room)
{
	t_path		*path;

	while (pathlist)
	{
		path = pathlist->path;
		while (path)
		{
			if (path->room->is_start || path->room->is_end)
			{
				path = path->next;
				continue;
			}
			if (path->room == room)
				return (true);
			path = path->next;
		}
		pathlist = pathlist->next;
	}
	return (false);
}

/*
** Adds item to the end of the pathlist linked list named start.
** Adding a new node to the visited nodes.
*/

bool	append_to_pathlist(t_pathlist **start, t_pathlist *item)
{
	t_pathlist *list;

	if (!item)
		return (false);
	list = *start;
	if (!list)
		*start = item;
	else
	{
		while (list->next)
			list = list->next;
		list->next = item;
	}
	return (true);
}

void	prepend_to_pathlist(t_pathlist **start, t_pathlist *new)
{
	t_pathlist *list;

	list = *start;
	if (!list)
		*start = new;
	else
	{
		new->next = list;
		*start = new;
	}
}
