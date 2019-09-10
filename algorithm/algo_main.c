#include <lem_in.h>

// We have find room by name so we need to remove this or that.
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
	int i;
	t_roomlist *frontier;
	t_roomlist *next;
	t_roomlist *neighbour;

	i = 1;
	frontier = NULL;
	// frontier = init_roomlist();
	reset_rooms(anthill->linear);
	anthill->start->level = 0;
	append_list(&frontier, make_item(anthill->start));
	while (frontier)
	{
		next = NULL;
		while (frontier)
		{
			neighbour = get_neighbours(frontier->room, anthill->connectors);
			while (neighbour)
			{
				if (neighbour->room->is_end && frontier->room->is_start)
					neighbour = neighbour->next;
				if (neighbour->room->level == -1 && !room_in_pathlist(anthill->paths, neighbour->room))
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
	return (append_to_pathlist(anthill->paths, create_pathlist_item(map_path(anthill->end))));
}