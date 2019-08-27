#include <lem_in.h>

int main()
{
	t_anthill	*anthill;
	t_room		*cursor;
	anthill = build_anthill();
	cursor = anthill->linear;
	printf("ANTS : %d\n", anthill->nb_ants);
	printf("ROOM COUNT : %d\n\n", anthill->room_count);
	while (cursor->next != NULL)
	{
		printf("NAME : %s\n", cursor->name);
		printf("X POS : %d\n", cursor->x);
		printf("Y POS : %d\n", cursor->y);
		printf("IS_END : %d\n", cursor->is_end);
		printf("IS_START : %d\n", cursor->is_start);
		printf("LINK COUNT : %d\n", cursor->link_count);
		printf("\n\n");
		cursor = cursor->next;
	}
	return 1;
}