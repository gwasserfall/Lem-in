#ifndef VISUALISER_H
# define VISUALISER_H
# include <SDL2/SDL.h>
# include <SDL2/SDL_image.h>
# include <SDL2/SDL2_gfxPrimitives.h>
# include <lem_in.h>


# define SPRITE_H 65
# define SPRITE_W 48
# define SPEED 0.01
# define ZOOM_DEFAULT 40

#define ZOOM 18
#define X(state, value) calc_x(state, value)
#define Y(state, value) calc_y(state, value)

typedef	struct		s_state
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Texture		*background;
	SDL_Event		event;
	t_path			*path;
	t_pathlist		*paths;
	bool			running;
	bool			click;
	int				offset_x;
	int				offset_y;
	int				frame;
	SDL_Rect		*rect;
	int				width;
	int				height;
	int				zoom;
	t_img			*walk_left;
	t_img			*walk_right;
	
    t_anthill       *anthill;
}					t_state;

int calc_y(t_state *state, double value);
int calc_x(t_state *state, double value);

t_anthill *get_infos();
t_anthill *init();
void draw_links(t_state *s);
void draw_nodes(t_state *s);
void draw_stats(t_state *s);
void	draw_ants(t_state *s);
bool visited(t_path *path, t_room *room);

void				join_colony(t_anthill *anthill, t_ant *larvae);
int				hatch_ant(t_anthill *anthill, int x, int y, char *name);
bool set_levels(t_state *s);

t_pathlist 		*create_pathlist_item(t_path *path_start);
bool			append_to_pathlist(t_pathlist **start, t_pathlist *item);
t_roomlist 		*make_item(t_room *room);
void			 append_list(t_roomlist **start, t_roomlist *new);
t_roomlist 		*get_neighbours(t_room *room, t_link *links);
t_link 			*make_link(t_room *from, t_room *to);
void 			append_link(t_link **start, t_link *new);
t_room 			*make_room(char *name, bool start, bool end);
void			Iappend_room(t_room **start, t_room *new);
t_room 			*get(t_room *start, char *name);
t_path 			*make_path_item(t_room *room);
void 			append_to_path(t_path **start, t_path *item);
bool 			room_in_pathlist(t_pathlist *pathlist, t_room *room);
t_path 			*map_path(t_room *end);
void			reset_rooms(t_state *);

#endif