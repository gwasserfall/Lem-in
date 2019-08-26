#ifndef LEM_IN_H
# define LEM_IN_H
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "../libft/libft.h"

typedef struct		s_room
{
	struct s_room 	*linear_next;
	struct s_room	**links;
	int				link_count;
	int				x;
	int				y;
	bool			is_start;
	bool			is_end;
	
}					t_room;

#endif