#include <lem_in.h>

int main()
{
	t_anthill	*anthill;
	t_room		*cursor;

	anthill = build_anthill();
	index_rooms(&anthill);
	// create_map(&anthill);
	// cursor = anthill->linear;
	if (anthill->start == NULL || anthill->end == NULL)
		print_start_end_error();
	printf("ANTS : %d\n", anthill->nb_ants);
	printf("ROOM COUNT : %d\n\n", anthill->room_count);
	// while (cursor != NULL)
	// {
	// 	// if (cursor->is_end == 1 || cursor->is_start == 1)
	// 	// {
	// 	printf("NAME : %s\n", cursor->name);
	// 	printf("X POS : %d\n", cursor->x);
	// 	printf("Y POS : %d\n", cursor->y);
	// 	printf("IS_END : %d\n", cursor->is_end);
	// 	printf("IS_START : %d\n", cursor->is_start);
	// 	printf("INDEX : %d\n", cursor->index);
	// 	printf("LINK COUNT : %d\n", cursor->link_count);
	// 	printf("\n\n");
	// 	// }
	// 	cursor = cursor->next;
	// }
	// while (1);
	return (1);
}