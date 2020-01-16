#ifndef VISUALISER_H
# define VISUALISER_H
# define SPRITE_H 65
# define SPRITE_W 48
# define SPEED 0.01
# define ZOOM_DEFAULT 40
# define ANT_COUNT 1
# define IDENT 2
# define ROOM 3
# define LINK 4
# define COMMENT 5
# define INVLD 6
# define MOVE 7
# define EMPTY 8
# define ZOOM 18
# define X(state, value) calc_x(state, value)
# define Y(state, value) calc_y(state, value)
# include <SDL2/SDL2_gfxPrimitives.h>
# include <SDL2/SDL2_rotozoom.h>
# include <SDL2/SDL_image.h>
# include <SDL2/SDL.h>
# include <stdbool.h>
# include <libft.h>

typedef struct			s_img
{
	SDL_Texture 		*img;
	struct s_img		*next;

}						t_img;

typedef int 			roomtype;
typedef struct			s_room
{
	struct s_room 		*next;
	struct s_room		**links;
	struct s_room		*parent;
	int					level;
	int					link_count;
	double				x;
	double				y;
	char				*name;
	bool				is_start;
	bool				is_end;
	bool				occupied;
	
}						t_room;

typedef struct			s_link
{
	t_room				*to;
	t_room				*from;
	struct s_link		*next;
}						t_link;

typedef enum			e_direction
{
	north,
	east,
	south,
	west
}						t_dir;

typedef struct			s_ant
{
	double				x;
	double				y;
	char 				*name;
	struct s_path		*path;
	t_room				*current;
	t_room				*following;
	t_img				*sprite;
	bool				is_moving;
	int					direction;
	t_dir				dir;
	double				gradient;
	double				distance;
	double				degrees;
	struct s_ant		*next;
}						t_ant;

typedef struct			s_path
{	
	t_room				*room;
	t_ant				*ants;
	int					index;
	struct s_path		*next;
	struct s_path		*prev;
}						t_path;

typedef struct 			s_pathlist
{
	t_path				*path;
	int					length;
	struct s_pathlist	*next;
}						t_pathlist;

typedef struct			s_moves
{
	struct s_moves		*next;
	t_ant				*ant;
	t_room				*to;
}						t_moves;

typedef struct 			s_movelist
{
	t_moves				*moves;
	bool				active;
	bool				complete;
	struct s_movelist	*next;
} 						t_movelist;

typedef struct			s_anthill
{
	t_room				*linear;
	t_room				*start;
	t_room				*end;
	t_link				*connectors;
	t_ant				*colony;
	t_pathlist			*paths;
	int					path_count;
	t_movelist			*movelist;
	int					room_count;
	int					nb_ants;
}						t_anthill;

typedef struct			s_data
{
	char				*line;
	struct s_data		*next;
}						t_data;

typedef struct			s_roomlist
{
	t_room				*room;
	struct s_roomlist	*next;
}						t_roomlist;

typedef	struct			s_state
{
	SDL_Window			*window;
	SDL_Renderer		*renderer;
	SDL_Texture			*background;
	SDL_Texture 		*room_sprite;
	SDL_Texture 		*walkr_static;
	SDL_Texture 		*walkl_static;
	SDL_Event			event;
	t_path				*path;
	t_pathlist			*paths;
	bool				running;
	bool				click;
	int					offset_x;
	int					offset_y;
	int					frame;
	SDL_Rect			*rect;
	int					width;
	int					height;
	int					zoom;
	t_img				*walk_left;
	t_img				*walk_right;
	t_img				*walk_static_l;
	t_img				*walk_static_r;
    t_anthill   	    *anthill;
}						t_state;

int						calc_y(t_state *state, double value);
int						calc_x(t_state *state, double value);
int						hatch_ant(t_anthill *anthill, int x, int y, char *name);
bool					int_string(char *str);
bool					visited(t_path *path, t_room *room);
bool 					set_levels(t_state *s);
bool 					room_in_pathlist(t_pathlist *pathlist, t_room *room);
bool					append_to_pathlist(t_pathlist **s, t_pathlist *item);
t_anthill				*init();
t_link 					*make_link(t_room *from, t_room *to);
t_room 					*get(t_room *start, char *name);
t_room 					*make_room(char *name, bool start, bool end);
t_room					*init_room_g(char *name, int x, int y);
t_roomlist 				*make_item(t_room *room);
t_roomlist 				*get_neighbours(t_room *room, t_link *links);
t_anthill				*get_infos();
t_moves					*deserialise_move(t_anthill *anthill, char *line);
t_path 					*make_path_item(t_room *room);
t_path 					*map_path(t_room *end);
t_pathlist 				*create_pathlist_item(t_path *path_start);
t_state					*init_state();
void					append_list(t_roomlist **start, t_roomlist *new);
void 					append_link(t_link **start, t_link *new);
void					Iappend_room(t_room **start, t_room *new);
void 					append_to_path(t_path **start, t_path *item);
void					reset_rooms(t_state *);
void					append_move(t_moves **start, t_moves *new);
void					draw_links(t_state *s);
void					draw_nodes(t_state *s);
void					draw_stats(t_state *s);
void					draw_ants(t_state *s);
void					append_sprite(t_img **start, t_img *new);
void					load_all_images(t_state *s);
void					update_ant_position(t_ant *ant);
void					free_array(char **str);
void					join_colony(t_anthill **anthill, t_ant *larvae);
void					assign_link(t_anthill *ah, char *str);



t_room *get_room(t_anthill *anthill, char *name);
void	append_room(t_room *entry_point, t_room *new);
void	assign_ants(t_anthill *anthill, char *str);
void	assign_link(t_anthill *ah, char *str);
void	assign_move(t_anthill *anthill, char *str);
void	append_to_movelist(t_movelist **start, t_movelist *new);
t_movelist	*make_movelist_item(t_moves *moves);
t_anthill	*new_anthill(void);
void	place_ants_on_start(t_state *s);

#endif