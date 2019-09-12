#include <lem_in.h>

/*
** Does the same thing as get_room_by_name.
*/

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

/*
** Starts at end and then using a BFS logic will set each room a level
** that is dependant on the amount of steps you will need to reach it from
** that start room.
*/

bool set_levels(t_anthill *anthill)
{
	int i;
	t_roomlist *frontier;
	t_roomlist *next;
	t_roomlist *neighbour;

	i = 1;
	frontier = NULL;
	reset_rooms(&anthill);
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
	return (append_to_pathlist(&anthill->paths, create_pathlist_item(map_path(anthill->end))));
}

/*
** Now that the rooms has levels this will go and find all the valid paths
** and add them to the pathlist struct *Does not include ##start-##end.
*/

bool set_paths(t_anthill *anthill)
{
	t_pathlist *paths;
	t_path *path;
	t_list *moves;
	t_ant *ant;
	int i = 0;
	bool complete = false;
	while ((set_levels(anthill)))
		;
	// Walk ants to death, i mean exit
	while (i < anthill->nb_ants)
		hatch_ant(anthill, 0, 0, ft_itoa(++i));
	while (!ants_are_free(anthill))
	{
		paths = anthill->paths;
		while (paths)
		{
			path = paths->path;
			while (!path->room->is_start)
			{
				if ((ant = ant_here(anthill->colony, path->next->room)))
					ant->current = path->room;
				path = path->next;
			}	
			paths = paths->next;
		}
	}
	return (1);
}

/*
** Checks to see if all the ants are free, ie all the ants are in the ned room.
*/

bool ants_are_free(t_anthill * anthill)
{
	t_ant *ant;
	ant = anthill->colony;

	while (ant)
	{
		if (ant->current != anthill->end)
			return (false);
		ant = ant->next;
	}
	return (true);
}

/*
** Puts the ant in the first room in the pathlist that is not the start room.
*/

t_ant	*ant_here(t_ant *colony, t_room *room)
{
	t_ant *ant;

	ant = colony;
	while (ant)
	{
		if (ant->current == room)
			return (ant);
		ant = ant->next;
	}
	return (NULL);
}
