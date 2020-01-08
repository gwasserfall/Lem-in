#include "./includes/lem_in.h"

t_room	*get_room_neighbour(t_room *node, t_link *link)
{
	while (link)
	{
		if (link->to == node && !link->from->parent && !link->from->is_start)
		{
			link->from->parent = node;
			return (link->from);
		}
		if (link->from == node && !link->to->parent && !link->to->is_start)
		{
			link->to->parent = node;
			return (link->to);
		}
		link = link->next;
	}
	return (NULL);
}

void	graph_traverse(t_room *start_room, t_link *links)
{
	t_fifo	*queue;
	t_room	*node;
	t_room	*neighbour;

	queue = NULL;
	fifo_push(&queue, start_room);
	while ((node = fifo_pop(&queue)))
		while ((neighbour = get_room_neighbour(node, links)))
			fifo_push(&queue, neighbour);
}