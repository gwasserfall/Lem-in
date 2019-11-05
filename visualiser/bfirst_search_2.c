/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfirst_search_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 12:16:20 by ayano             #+#    #+#             */
/*   Updated: 2019/11/05 12:16:22 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualiser.h"

t_path	*make_path_item(t_room *room)
{
	t_path *new;

	if (!(new = malloc(sizeof(t_path))))
		return (NULL);
	new->next = NULL;
	new->prev = NULL;
	new->room = room;
	return (new);
}

void	append_to_path(t_path **start, t_path *item)
{
	t_path *path;

	path = *start;
	if (!path)
		*start = item;
	else
	{
		while (path->next)
			path = path->next;
		path->next = item;
		item->prev = path;
	}
}

bool	room_in_pathlist(t_pathlist *pathlist, t_room *room)
{
	t_path *path;

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

t_path	*map_path(t_room *end)
{
	t_path *path;

	path = NULL;
	append_to_path(&path, make_path_item(end));
	while (end->parent)
	{
		append_to_path(&path, make_path_item(end->parent));
		end = end->parent;
	}
	if (!end->is_start)
		return (NULL);
	return (path);
}

void	reset_rooms(t_state *s)
{
	t_room *room;

	room = s->anthill->linear;
	while (room)
	{
		room->parent = NULL;
		room->level = -1;
		if (room->is_start)
			room->level = 0;
		room = room->next;
	}
}
