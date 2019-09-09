#include <lem_in.h>

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
		*start = new;
	else
	{
		while (link->next)
			link = link->next;
		link->next = new;
	}
}

t_room *get_room(t_anthill *anthill, char *name)
{
	t_room *cursor;

	cursor = anthill->linear;

	while (cursor)
	{
		if (!(ft_strcmp(name, cursor->name)))
		{
			return (cursor);
		}
		cursor = cursor->next;
	}
	return (NULL);
}

void	assign_link(t_anthill *ah, char *str)
{
	char **line;
	t_room *from;
	t_room *to;
	t_link *link;
	t_link *cursor;

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

bool set_levels(t_anthill *anthill)
{
	int i = 1;

	// Reset allrooms before running (allows mutiple paths)
	reset_rooms(anthill->linear);

	t_roomlist *frontier = NULL;

	anthill->start->level = 0;

	append_list(&frontier, make_item(s->anthill->start));

	t_roomlist *next;
	t_roomlist *neighbour;

	while (frontier)
	{
		next = NULL;
		while (frontier)
		{
			neighbour = get_neighbours(frontier->room, s->anthill->connectors);
			while (neighbour)
			{
				if (neighbour->room->is_end && frontier->room->is_start)
				{
					neighbour = neighbour->next;
					continue;
				}
				if (neighbour->room->level == -1 && !room_in_pathlist(s->paths, neighbour->room))
				{
					neighbour->room->level = i;
					neighbour->room->parent = frontier->room;
					append_list(&next, make_item(neighbour->room));
				}
				neighbour = neighbour->next;
			}
			frontier = frontier->next;
		}
		i++;
		frontier = next;
	}
	return append_to_pathlist(&s->paths, create_pathlist_item(map_path(s->anthill->end)));
}
