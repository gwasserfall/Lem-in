#ifndef LEM_IN_H
# define LEM_IN_H
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "../libft/libft.h"

# define RESET "\033[00m"
# define GREEN "\033[32m"
# define BLUE "\033[34m"
# define WHITE "\033[37m"
# define RED "\033[31m"
# define YELLOW "\033[33m"
# define CYAN "\033[36m"
# define PURPLE "\033[35m"

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

/*
** Preflight prototypes.
*/
int					get_nb_rooms(void);
int					word_count(char *str, char delim, int index);
void				verify_start_and_end(void);
void				error_checks(void);

#endif