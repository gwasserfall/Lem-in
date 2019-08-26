#include <lem_in.h>

/*
	Create a new room link item.

	bool is_start : Specify whether this room is the start room
	bool is_end : Specify whether this room is the end room

	A normal room would be new_room(false, false);
*/
t_room	*new_room(bool is_start, bool is_end)
{
	t_room *new;

	if (!(new = (t_room *)malloc(sizeof(t_room))))
		return (NULL);
	
	new->linear_next = NULL;
	new->link_count = 0;
	new->is_end = is_end;
	new->is_start = is_start;
	new->links = NULL;

	return (new);
}

/*
	Append a newly created room onto the end of the room linked list.

	t_room *entry_point :: usually the first room ever created
	t_room *new :: A pointer to the newly created room
*/
void append_room_linear(t_room *entry_point, t_room *new)
{
	while (entry_point->linear_next)
		entry_point = entry_point->linear_next;

	entry_point->linear_next = new;
}

