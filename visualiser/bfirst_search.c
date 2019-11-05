/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfirst_search.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 12:15:04 by ayano             #+#    #+#             */
/*   Updated: 2019/11/05 12:15:05 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualiser.h"

t_pathlist	*create_pathlist_item(t_path *path_start)
{
	t_pathlist *new;

	if (!path_start)
		return (NULL);
	if (!(new = malloc(sizeof(t_pathlist))))
		return (NULL);
	new->path = path_start;
	new->next = NULL;
	return (new);
}

bool		append_to_pathlist(t_pathlist **start, t_pathlist *item)
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

t_roomlist	*make_item(t_room *room)
{
	t_roomlist *new;

	if (!(new = malloc(sizeof(t_roomlist))))
		return (NULL);
	new->next = NULL;
	new->room = room;
	return (new);
}

void		append_list(t_roomlist **start, t_roomlist *new)
{
	t_roomlist *list;

	list = *start;
	if (!list)
		*start = new;
	else
	{
		while (list->next)
			list = list->next;
		list->next = new;
	}
}

t_roomlist	*get_neighbours(t_room *room, t_link *links)
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
