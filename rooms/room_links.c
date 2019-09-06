#include <lem_in.h>

/*
**	Initialise the ->links array within a room if not previously set
**	Will initialize the links variable in all the linear nodes.
**	t_room *room :: Pointer to the room to init
**	int max_links :: Maximum number of possible links (should be room_count)
*/
void	init_roomlink_max(t_anthill **anthill)
{
	t_room	*current;

	current = (*anthill)->linear;
	if (current->links == NULL && current)
	{
		while (current != NULL)
		{
			if (!(current->links = (t_room **)malloc(sizeof(t_room *)
											* ((*anthill)->room_count))))
				print_allocation_fail();
			current = current->next;
		}
	}
}

/*
	Link one room to another, i.e append a pointer onto *from->links array
*/
void	link_rooms(t_anthill *anthill, char *line)
{
	t_room 	*from;
	t_room 	*to;
	char	**data;

	init_roomlink_max(&anthill);
	data = ft_strsplit(line, '-');
	from = find_room_by_name(&anthill, data[0]);
	to = find_room_by_name(&anthill, data[1]);
	if (from && to)
	{
		from->links[from->link_count] = to;
		from->link_count++;
	}
	free_array(data);
}

void	print_allocation_fail(void)
{
	ft_putstr(RED);
	ft_putendl("Allocation Failed.");
	ft_putstr(RESET);
	exit(1);
}