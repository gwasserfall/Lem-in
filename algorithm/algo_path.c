/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <ayano@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 16:16:05 by ayano             #+#    #+#             */
/*   Updated: 2019/09/09 16:20:23 by ayano            ###   ########.fr       */
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

/*
** Works from end and adds nodes to the struct pathlist.
*/
t_path		*map_path(t_room *end)
{
	t_path *path;

	path = NULL;
	append_to_path(&path, make_path_item(end));
	ft_putendl("Mapping p/ath");
	while (end->parent)
	{
		append_to_path(&path, make_path_item(end->parent));
		// printf("%s -> ", end->parent->name);
		end = end->parent;
	}
	// printf("\n");
	if (!end->is_start)
		return (NULL);
	return (path);
}

/*
** creates a new node to the path_start linked list.
*/
t_pathlist		*create_pathlist_item(t_path *path_start)
{
	t_pathlist *new;

	if (!path_start)
		return (NULL);
	if (!(new = malloc(sizeof(t_pathlist))))
		return (NULL);
	new->path = path_start;
	new->next = NULL;
	new->valid = 1;
	return (new);
}

/*
** Mallocs a path node and sets the paths room to the room given as an input.
*/

t_path *make_path_item(t_room *room)
{
	t_path *new;

	if (!(new = malloc(sizeof(t_path))))
		return NULL;
	new->next = NULL;
	new->prev = NULL;
	new->ants = NULL;
	new->room = room;
	return (new);
}

/*
** adds the path node called item to end of the path linked list given as start.
*/

void append_to_path(t_path **start, t_path *item)
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
/*
** adds the node passed as item to the from of the linked list passed as start.
*/

void	prepend_to_path(t_path **start, t_path *item)
{
	t_path *path;

	path = *start;
	if (!path)
		*start = item;
	else
	{
		item->next = path;
		*start = item;
	}
}