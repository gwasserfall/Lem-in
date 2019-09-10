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

	i = 1;
	frontier = NULL;
	// frontier = init_roomlist();
	reset_rooms(anthill->linear);
	anthill->start->level = 0;
	append_list(&frontier, make_item(anthill->start));

	// above has been worked on.
	t_roomlist *next;
	t_roomlist *neighbour;
	// no idea what paths is being used for...
	t_path	*paths;
	// none of this fucking norms man.
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
