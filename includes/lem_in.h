#ifndef LEM_IN_H
# define LEM_IN_H
# define NORMAL 0
# define START 1
# define END 2
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

typedef int roomtype;

typedef struct		s_room
{
	struct s_room 	*next;
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
	int				nb_ants;
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
void				new_room(roomtype rtype, char *line, t_anthill **anthill);
void				append_room_linear(t_room *entry_point, t_room *new);
void				init_roomlink_max(t_anthill **anthill);
t_room				*find_room_by_name(t_anthill **anthill, char *name);
void				link_rooms(t_anthill *anthill, char *line);
t_room				*init_room(void);

/*
** Preflight prototypes.
*/
t_anthill			*build_anthill(void);
t_anthill			*init_anthill(void);
int					word_count(char *str, char delim, int index);
int					verify_start_and_end(char *line);
void				verify_ants(char *line);
void				verify_room(char *line);
int					get_nb_rooms(void);
void				verify_coordinates(char **data);
void				verify_first_char(char **data);
void				free_array(char **str);
void				print_error_room(void);
void				print_error_link(void);
void				verify_links(char *line, t_anthill **anthill);
void				print_allocation_fail(void);
void				print_invalid_input(void);
void				pre_add_data(int type, char *line, t_anthill **anthill);
int					check_line(char *line);
int					only_digit(char *line);
void				print_ant_error(void);

#endif