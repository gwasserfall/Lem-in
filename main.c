#include <lem_in.h>

int main()
{
	t_anthill	*anthill;
	t_data		*data;

	data = init_data();
	read_into_data(&data);
	anthill = build_anthill(&data);
	if (anthill->start == NULL || anthill->end == NULL)
		print_start_end_error();
	index_rooms(&anthill);
	// display_output(&anthill);
	free_data(&data);
	return (1);
}