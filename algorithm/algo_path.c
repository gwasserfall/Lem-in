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
	while (end->parent)
	{
		append_to_path(&path, make_path_item(end->parent));
		end = end->parent;
	}
	if (!end->is_start)
		return (NULL);
	return (path);
}










































t_pathlist *create_pathlist_item(t_path *path_start)
{
	t_pathlist *new;

	if (!path_start)
		return NULL;

	if (!(new = malloc(sizeof(t_pathlist))))
		return NULL;
	new->path = path_start;
	new->next = NULL;
	return new;
}


/*
** ASK GLEN.
*/
t_roomlist *make_item(t_room *room)
{
	t_roomlist *new;

	if (!(new = malloc(sizeof(t_roomlist))))
		return NULL;
	new->next = NULL;
	new->room = room;
	return new;
}

t_link *make_link(t_room *from, t_room *to)
{
	t_link *new;

	if (!(new = malloc(sizeof(t_link))))
		return NULL;
	new->from = from;
	new->to = to;
	new->next = NULL;
	return new;
}

void append_link(t_link **start, t_link *new)
{
	t_link *link;

	link = *start;
	if (!link)
	{
		printf("t_debug->links was empty attaching link '%s'=>'%s'\n", new->from->name, new->to->name);
		*start = new;
	}
	else
	{
		while (link->next)
			link = link->next;
		printf("Attaching link '%s'=>'%s'\n", new->from->name, new->to->name);
		link->next = new;
	}
}

t_room *make_room(char *name, bool start, bool end)
{
	t_room *new;

	if (!(new = malloc(sizeof(t_room))))
		return NULL;
	new->name = ft_strdup(name);
	new->is_end = end;
	new->is_start = start;
	new->next = NULL;
	new->parent = NULL;
	new->level = -1;
	return new;
}

void	Iappend_room(t_room **start, t_room *new)
{
	t_room *room;

	room = *start;

	if (!room)
	{
		printf("t_debug->rooms was empty, attaching room '%s'\n", new->name);
		*start = new;
	}
	else
	{
		while (room->next)
			room = room->next;
		printf("Room '%s' attached to '%s'\n", new->name, room->name);
		room->next = new;
	}
}


t_room *get(t_room *start, char *name)
{
	while (start)
	{
		if (!(ft_strcmp(start->name, name)))
			return start;
		start = start->next;
	}
	return NULL;
}


t_path *make_path_item(t_room *room)
{
	t_path *new;

	if (!(new = malloc(sizeof(t_path))))
		return NULL;
	new->next = NULL;
	new->prev = NULL;
	new->room = room;
	return new;
}


void append_to_path(t_path **start, t_path *item)
{
	t_path *path;

	path = *start;

	if (!path)
	{
		*start = item;
	}
	else
	{
		while (path->next)
			path = path->next;
		path->next = item;
		item->prev = path;
	}
}

