#include <lem_in.h>

/*
** Create the master level "object" to contain all room and any other flags
*/

/*
t_anthill *create_anthill(void)
{
	char *line;
	char **rm;
	t_anthill *hill;
	t_room *temp;
	bool next_start;
	bool next_end;

	next_start = false;
	next_end = false;
	
	printf("Creating anthill\n");

	if (!(hill = malloc(sizeof(t_anthill))))
		return false;

	hill->linear = NULL;
	hill->room_count = get_nb_rooms();

	printf("Malloc anthill\n");

	while (get_next_line(0, &line) > 0)
	{
		if (!(ft_strcmp(line, "##start")))
			next_start = true;
		
		printf("Post start check\n");

		if (!(ft_strcmp(line, "##end")))
			next_end = true;

		if (word_count(line, ' ', 0) == 3)
		{
			rm = ft_strsplit(line, ' ');
			if (!hill->linear)
			{
				if (next_start)
				{
					hill->linear = new_room(START, rm[0], ft_atoi(rm[1]), ft_atoi(rm[2]));
					next_start = false;
				}
				else if (next_end)
				{
					hill->linear = new_room(END, rm[0], ft_atoi(rm[1]), ft_atoi(rm[2]));
					next_end = false;
				}
				else
					hill->linear = new_room(NORMAL, rm[0], ft_atoi(rm[1]), ft_atoi(rm[2]));
			}
			else
			{
				temp = NULL;
				if (next_start)
				{
					temp = new_room(START, rm[0], ft_atoi(rm[1]), ft_atoi(rm[2]));
					append_room_linear(hill->linear, temp);
					next_start = false;
				}
				else if (next_end)
				{
					temp = new_room(END, rm[0], ft_atoi(rm[1]), ft_atoi(rm[2]));
					append_room_linear(hill->linear, temp);
					next_end = false;
				}
				else
				{
					temp = new_room(NORMAL, rm[0], ft_atoi(rm[1]), ft_atoi(rm[2]));
					append_room_linear(hill->linear, temp);
				}
			}
		}

		if ((ft_strchr(line, '-') != NULL))
		{
			rm = ft_strsplit(line, '-');
			link_rooms(hill, rm[0], rm[1]);
		}
		free(line);
	}
	return hill;
}
*/



/*
** DEBUG FUNCTIONS :: TO BE DELETED
*/
/*
void db_print_linear(t_anthill *anthill)
{
	t_room *cursor;

	cursor = anthill->linear;

	while (cursor)
	{
		printf("\n\nname = %s\n", cursor->name);
		printf("is_start = %d\n", cursor->is_start);
		printf("is_end = %d\n", cursor->is_end);
		printf("x = %d\n", cursor->x);
		printf("y = %d\n", cursor->y);
		printf("link_count = %d\n", cursor->link_count);

		cursor = cursor->linear_next;
	}
}
*/