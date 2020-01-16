#include <lem_in.h>

/*
** This will create the anthills first node and then add nodes for each room.
*/

t_anthill	*build_anthill(t_data **data)
{
	t_anthill	*anthill;

	anthill = new_anthill();
	read_loop(anthill, data);
	if (anthill->nb_ants <= 0)
		print_ant_error();
	return (anthill);
}