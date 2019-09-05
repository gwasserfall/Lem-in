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
	int				index;
	int				level;
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

typedef struct		s_data
{
	char			*line;
	struct s_data	*next;
}					t_data;

/*
** Debug 
*/
void				db_print_linear(t_anthill *anthill);

/*
** Anthill prototypes
*/
t_anthill			*build_anthill(void);
t_anthill			*init_anthill(void);
void				read_loop(t_anthill *anthill, t_data **data);

/*
** Room prototypes
*/
void				new_room(roomtype rtype, char *line, t_anthill **anthill);
void				append_room_linear(t_room **entry_point, t_room *new);
void				init_roomlink_max(t_anthill **anthill);
t_room				*find_room_by_name(t_anthill **anthill, char *name);
void				link_rooms(t_anthill *anthill, char *line);
t_room				*init_room(void);

/*
** Error prints.
*/
void				print_allocation_fail(void);
void				print_ant_error(void);
void				print_error_link(void);
void				print_invalid_input(void);
void				print_error_room(void);
void				print_start_end_error(void);

/*
** (Leaks). Freeing prototypes.
*/
void				free_array(char **str);
void				free_data(t_data **data);

/*
** Preflight prototypes.
*/
int					check_line(char *line);
int					get_nb_rooms(void);
int					only_digit(char *line);
int					verify_start_and_end(char *line);
int					word_count(char *str, char delim, int index);
void				add_data_end(char *line, t_anthill **anthill);
void				add_data_start(char *line, t_anthill **anthill);
void				pre_add_data(int type, char *line, t_anthill **anthill);
void				verify_ants(char *line);
void				verify_coordinates(char **data);
void				verify_first_char(char **data);
void				verify_links(char *line, t_anthill **anthill);
void				verify_room(char *line);
void				index_rooms(t_anthill **anthill);
void				add_start_data(char *line, t_anthill **anthill);
void				add_end_data(char *line, t_anthill **anthill);

/*
** Pathing prototypes.
*/
int					check_end_route_head(t_anthill **anthill);
int					create_map(t_anthill **anthill);

/*
** Output prototypes.
*/
void				display_ants(t_anthill **anthill);
void				display_output(t_anthill **anthill);
void				display_rooms(t_anthill **anthill);
void				display_links(t_anthill **anthill);

/*
** Data prototypes.
*/
t_data				*init_data(void);
void				read_into_data(t_data **data);
void				add_data_node(t_data **data);

#endif