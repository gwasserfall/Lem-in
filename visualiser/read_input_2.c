/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 14:32:53 by ayano             #+#    #+#             */
/*   Updated: 2019/11/05 14:38:05 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualiser.h"

#define ANT_COUNT 1
#define IDENT 2
#define ROOM 3
#define LINK 4
#define COMMENT 5
#define INVLD 6
#define MOVE 7
#define EMPTY 8

void		assign_room(t_anthill *ah, char *str, bool *s, bool *e)
{
	t_room	*room;
	char	**line;

	line = ft_strsplit(str, ' ');
	room = init_room_g(line[0], ft_atoi(line[1]), ft_atoi(line[2]));
	free(line[0]);
	free(line[1]);
	free(line[2]);
	free(line);
	ah->start = (*s) ? room : ah->start;
	ah->end = (*e) ? room : ah->end;
	room->is_start = *s;
	if (room->is_start)
		room->level = 0;
	room->is_end = *e;
	ah->room_count++;
	if (!ah->linear)
		ah->linear = room;
	else
		append_room(ah->linear, room);
	*s = false;
	*e = false;
}

t_room		*get_room(t_anthill *anthill, char *name)
{
	t_room *cursor;

	cursor = anthill->linear;
	while (cursor)
	{
		if (!(ft_strcmp(name, cursor->name)))
			return (cursor);
		cursor = cursor->next;
	}
	return (NULL);
}

void		assign_link(t_anthill *ah, char *str)
{
	char	**line;
	t_room	*from;
	t_room	*to;
	t_link	*link;
	t_link	*cursor;

	line = ft_strsplit(str, '-');
	from = get_room(ah, line[0]);
	to = get_room(ah, line[1]);
	link = malloc(sizeof(t_link));
	link->to = to;
	link->from = from;
	link->next = NULL;
	cursor = ah->connectors;
	if (!cursor)
		ah->connectors = link;
	else
	{
		while (cursor->next)
			cursor = cursor->next;
		cursor->next = link;
	}
}

t_path		*append_path(t_path *path, t_room *room)
{
	t_path *p;
	t_path *cur;

	p = malloc(sizeof(t_path));
	p->next = NULL;
	p->room = room;
	if (!path)
		path = p;
	else
	{
		cur = path;
		while (cur->next)
			cur = cur->next;
		cur->next = p;
	}
	return (path);
}

bool		visited(t_path *path, t_room *room)
{
	t_path *cursor;

	cursor = path;
	while (cursor)
	{
		if (cursor->room == room)
			return (true);
		cursor = cursor->next;
	}
	return (false);
}
