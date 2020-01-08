#include "./includes/lem_in.h"

t_path *get_shortest_path(t_room *end_node)
{
	t_path *start;

	start = NULL;
	while (end_node->parent)
	{
		printf("%s => %s, ", end_node->name, end_node->parent->name);
		add_to_path();
		end_node = end_node->parent;
	}
	printf("\n");
}