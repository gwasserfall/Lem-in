#ifndef VISUALISER_H
# define VISUALISER_H
#include <stdbool.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>

typedef struct svector
{
	int x;
	int y;
}	vector;

typedef struct sroom
{
	struct sroom *next;
	struct sroom **links;
	int link_count;
	char *name;
	vector pos;
}				room;

typedef struct s_hill
{
	room *start;
	room *end;
}			t_anthill;

typedef	struct		s_state
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Event		event;
	bool			running;
	SDL_Rect		*rect;
	int				width;
	int				height;
    t_anthill       *anthill;
}					t_state;

t_anthill *init();
void draw_links(t_state *s);

#endif