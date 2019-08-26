#ifndef LEM_IN_H
# define LEM_IN_H
# define NORMAL 0
# define START 1
# define END 2
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "../libft/libft.h"

typedef int roomtype;

typedef struct		s_room
{
	struct s_room 	*linear_next;
	struct s_room	**links;
	int				link_count;
	int				x;
	int				y;
	char			*name;
	bool			is_start;
	bool			is_end;
	
}					t_room;

typedef struct		s_anthill
{
	t_room			*linear;
	t_room			*start;
	t_room			*end;
	int				room_count;
}					t_anthill;

/*
** Debug 
*/
void				db_print_linear(t_anthill *anthill);

/*
** Anthill prototypes
*/
t_anthill			*create_anthill(void);

/*
** Room prototypes
*/
t_room				*new_room(roomtype rtype, char *name, int x, int y);
void				append_room_linear(t_room *entry_point, t_room *new);
void				init_roomlink_max(t_room *room, int max_links);

/*
** Preflight prototypes.
*/
int					get_nb_rooms(void);
int					word_count(char *str, char delim, int index);

#endif