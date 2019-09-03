#include <lem_in.h>

/*
**	Create a new room link item.
**
**	roomtype rtype :: Distinguish between start (1), end (2), or normal (0) room types
**	char *line     :: will be split to get name, x, and y values
**	t_anthill      :: The anthill struct whose lineat will get the new room.
*/
void	new_room(roomtype rtype, char *line, t_anthill **anthill)
{
	t_room	*new;
	t_room	*current;
	char	**data;

	new = init_room();
	current = (*anthill)->linear;
	data = NULL;
	if (rtype == START || rtype == END)
	{
		new->is_end = (rtype == END) ? true : false ;
		new->is_start = (rtype == START) ? true : false;
	}
	else
	{
		data = ft_strsplit(line, ' ');
		new->name = ft_strdup(data[0]);
		new->x = ft_atoi(data[1]);
		new->y = ft_atoi(data[2]);
		free_array(data);
	}
	append_room_linear(&(*anthill)->linear, new);
}

/*
** initializes the rooms values and mallocs the struct.
*/
t_room	*init_room(void)
{
	t_room *new;

	if (!(new = (t_room *)malloc(sizeof(t_room))))
		return (NULL);
	new->next = NULL;
	new->link_count = 0;
	new->name = NULL;
	new->is_end = 0;
	new->is_start = 0;
	new->x = 0;
	new->y = 0;
	new->index = 0;
	new->links = NULL;
	return (new);
}

/*
**	Append a newly created room onto the end of the room linked list.
**
**	t_room *entry_point :: usually the first room ever created
**	t_room *new :: A pointer to the newly created room
*/
void	append_room_linear(t_room **entry_point, t_room *new)
{
	t_room		*current;

	current = (*entry_point);
	if (current == NULL)
	{
		(*entry_point) = new;
		return ;
	}
	else
	{
		while (current->next != NULL)
			current = current->next;
	}
	current->next = new;
}

/*
**	Get the room allocated as the start (bool is_start), this will be the start of the linked list from ant's perspective
**
**	t_room *entry :: First entry in the linear linked list
**	t_room *entry :: First entry in the linear linked list
*/
void	set_start_room(t_anthill *hill, t_room *entry)
{
	while (entry)
	{
		if (entry->is_start)
		{
			hill->start = entry;
			return ;
		}
		entry = entry->next;
	}
}


/*
	Find room by name

	TODO :: Comments here, may not need this
*/
t_room *find_room_by_name(t_anthill **anthill, char *name)
{
	t_room *cursor;

	cursor = (*anthill)->linear;

	while (cursor)
	{
		if ((ft_strequ(name, cursor->name)) == 1)
		{
			return (cursor);
		}
		cursor = cursor->next;
	}
	return (NULL);
}