#include <lem_in.h>

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

bool set_levels(t_anthill *anthill)
{
	t_path	*paths;
	int i = 1;

	// Reset allrooms before running (allows mutiple paths)
	reset_rooms(anthill->linear);

	t_roomlist *frontier = NULL;

	anthill->start->level = 0;

	append_list(&frontier, make_item(anthill->start));

	t_roomlist *next;
	t_roomlist *neighbour;

	while (frontier)
	{
		next = NULL;
		while (frontier)
		{
			neighbour = get_neighbours(frontier->room, anthill->connectors);
			while (neighbour)
			{
				if (neighbour->room->is_end && frontier->room->is_start)
				{
					neighbour = neighbour->next;
					continue;
				}
				if (neighbour->room->level == -1 && !room_in_pathlist(paths, neighbour->room))
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
	return append_to_pathlist(paths, create_pathlist_item(map_path(anthill->end)));
}
