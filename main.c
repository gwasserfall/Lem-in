#include <lem_in.h>

int main()
{
	t_anthill *anthill;
	printf("Room count : %d\n", get_nb_rooms());
	anthill = create_anthill();
	db_print_linear(anthill);
	return 1;
}