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
					printf("Setting %s to level : %d\n", neighbour->room->name, i);
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
	ft_putendl("Got here");
	return (append_to_pathlist(&anthill->paths, create_pathlist_item(map_path(anthill->end))));
}

bool ants_are_free(t_anthill * anthill)
{
	t_ant *ant;
	ant = anthill->colony;

	while (ant)
	{
		if (ant->current != anthill->end)
			return false;
		ant = ant->next;
	}
	return true;
}

t_ant	*ant_here(t_anthill *anthill, t_room *room)
{
	t_ant *ant;

	ant = anthill->colony;
	while (ant)
	{
		if (ant->current == room)
			return (ant);
		ant = ant->next;
	}
	return NULL;
}

bool set_paths(t_anthill *anthill)
{
	while ((set_levels(anthill)))
		;

	// Walk ants to death, i mean exit
	int i = 0;
	t_pathlist *paths;

	while (i < anthill->nb_ants)
	{
		ft_putendl("Hatching ant");
		hatch_ant(anthill, 0, 0, ft_itoa(++i));
	}

	t_ant *ant;
	bool complete = false;

	paths = anthill->paths;
	while (paths)
	{
		printf("Path : -> %p\n", paths->path);
		paths = paths->next;
	}

	ant = anthill->colony;
	paths = anthill->paths;
	while (ant)
	{
		if (!ant->path)
		{
			ant->path = paths->path;
			if (paths->next)
				paths = paths->next;
			else
				paths = anthill->paths;	
		}
		ant = ant->next;
	}

	t_path *path;
	t_list *moves;

	while (!ants_are_free(anthill))
	{
		paths = anthill->paths;
		while (paths)
		{
			path = paths->path;
			// get to empty room;
			while (!path->room->is_start)
			{
				if ((ant = ant_here(anthill, path->next->room)))
				{

					printf("L%s-%s", ant->name, path->room->name);
					ant->current = path->room;
					printf(" ");
				}
				path = path->next;
			}
			printf("\n");
			paths = paths->next;
		}
	}
	return 1;
}