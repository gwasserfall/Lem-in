#include <lem_in.h>

/*
**	Create a new room link item.
**
**	roomtype rtype :: Distinguish between start (1), end (2), or normal (0) room types
**	char *name     :: Name of this room
**	int x          :: Visualiser x cord
**	int y          :: Visualiser y cord
*/
t_room	*new_room(roomtype rtype, char *name, int x, int y)
{
	t_room *new;

	if (!(new = (t_room *)malloc(sizeof(t_room))))
		return (NULL);
	
	new->linear_next = NULL;
	new->link_count = 0;
	new->name = ft_strdup(name);
	new->is_end = (rtype == END) ? true : false ;
	new->is_start = (rtype == START) ? true : false;
	new->x = x;
	new->y = y;
	new->links = NULL;

	return (new);
}

/*
**	Append a newly created room onto the end of the room linked list.
**
**	t_room *entry_point :: usually the first room ever created
**	t_room *new :: A pointer to the newly created room
*/
void	append_room_linear(t_room *entry_point, t_room *new)
{
	while (entry_point->linear_next)
		entry_point = entry_point->linear_next;

	entry_point->linear_next = new;
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
		entry = entry->linear_next;
	}
}
