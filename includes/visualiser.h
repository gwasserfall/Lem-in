
# include <SDL2/SDL.h>
# include <lem_in.h>
typedef	struct		s_state
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Event		event;
	t_path			*path;
	t_pathlist		*paths;
	bool			running;
	bool			click;
	int				offset_x;
	int				offset_y;
	SDL_Rect		*rect;
	int				width;
	int				height;
	int				zoom;
    t_anthill       *anthill;
}					t_state;


int calc_y(t_state *state, int value);
int calc_x(t_state *state, int value);

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