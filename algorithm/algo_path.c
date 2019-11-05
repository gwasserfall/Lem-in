/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <ayano@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 16:16:05 by ayano             #+#    #+#             */
/*   Updated: 2019/11/05 09:31:03 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

/*
** Works from end and adds nodes to the struct pathlist.
*/

t_path			*map_path(t_room *end)
{
	t_path *path;
	t_room *check;

	check = end;
	while (check->parent)
		check = check->parent;
	if (!check->is_start)
		return (NULL);
	path = NULL;
	append_to_path(&path, make_path_item(end));
	while (end->parent)
	{
		append_to_path(&path, make_path_item(end->parent));
		end = end->parent;
	}
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
	new->length = 0;
	return (new);
}

/*
** Mallocs a path node and sets the paths room to the room given as an input.
*/

t_path			*make_path_item(t_room *room)
{
	t_path *new;

	if (!(new = malloc(sizeof(t_path))))
		return (NULL);
	new->next = NULL;
	new->prev = NULL;
	new->ants = NULL;
	new->room = room;
	return (new);
}

/*
** adds the path node called item to end of the path linked list given as start.
*/

void			append_to_path(t_path **start, t_path *item)
{
	t_path	*path;

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

void			prepend_to_path(t_path **start, t_path *item)
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
