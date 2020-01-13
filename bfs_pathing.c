#include "./includes/lem_in.h"

t_path	*new_path_node(t_room *room)
{
	t_path *path;
	
	if (!(path = malloc(sizeof(t_path))))
		return (NULL);
	path->next = NULL;
	path->room = room;
	return (path);
}

void	_append_path(t_path **start, t_room *room)
{
	t_path *head;
	
	if (*start)
	{
		head = *start;
		while (head->next)
			head = head->next;
		head->next = new_path_node(room);
	}
	else
		*start = new_path_node(room);
}

void destroy_unusable_path(t_path *path)
{
	t_path *previous;

	if (!path)
		return ;
	while (path->next)
	{
		printf("Path has been deleted!\n");
		previous = path;
		path = path->next;
		free(previous);
	}
}

bool room_in_any_path(t_anthill *a, t_room *room)
{
	t_pathlist	*pathlist;
	t_path		*path;

	pathlist = a->paths;
	while (pathlist)
	{
		while (path)
		{
			if (path->room == room)
				return true;
			path = path->next;
		}
		path = pathlist->path;
	}
	return false;
}

void mark_rooms_in_path(t_path *path)
{
	while (path)
	{
		path->room->in_path = true;
		path = path->next;
	}
}

t_path *get_shortest_path(t_anthill *a)
{
	t_path *path;
	t_room *end_room;

	end_room = a->end;
	path = NULL;
	a->start->in_path = false;
	a->end->in_path = false;

	while (end_room->parent && !end_room->in_path)
	{
		_append_path(&path, end_room);
		end_room->in_path = true;
		end_room = end_room->parent;
	}

	if (!end_room->is_start)
	{
		destroy_unusable_path(path);
		return NULL;
	}

	t_room *room;

	room = a->linear;
	_append_path(&path, a->start);

	while (room)
	{
		printf("Room %s in path %s\n", room->name, (room->in_path) ? "Yes" : "No");
		room = room->next;
	}

	return (path);
}