/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfirst_search_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 12:16:14 by ayano             #+#    #+#             */
/*   Updated: 2019/11/05 12:16:16 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualiser.h"

t_link	*make_link(t_room *from, t_room *to)
{
	t_link *new;

	if (!(new = malloc(sizeof(t_link))))
		return (NULL);
	new->from = from;
	new->to = to;
	new->next = NULL;
	return (new);
}

void	append_link(t_link **start, t_link *new)
{
	t_link *link;

	link = *start;
	if (!link)
		*start = new;
	else
	{
		while (link->next)
			link = link->next;
		link->next = new;
	}
}

t_room	*make_room(char *name, bool start, bool end)
{
	t_room *new;

	if (!(new = malloc(sizeof(t_room))))
		return (NULL);
	new->name = ft_strdup(name);
	new->is_end = end;
	new->is_start = start;
	new->next = NULL;
	new->parent = NULL;
	new->level = -1;
	return (new);
}

void	append_room(t_room **start, t_room *new)
{
	t_room *room;

	room = *start;
	if (!room)
		*start = new;
	else
	{
		while (room->next)
			room = room->next;
		room->next = new;
	}
}

t_room	*get(t_room *start, char *name)
{
	while (start)
	{
		if (!(ft_strcmp(start->name, name)))
			return (start);
		start = start->next;
	}
	return (NULL);
}
