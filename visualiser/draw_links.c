#include "visualiser.h"

#define ZOOM 18

void draw_links(t_state *s)
{
	room *rooms;
	int i;

	rooms = s->anthill->start;
	
	SDL_SetRenderDrawColor(s->renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
	SDL_RenderDrawLine(s->renderer, 320, 200, 300, 240);
	SDL_RenderDrawLine(s->renderer, 300, 240, 340, 240);
	SDL_RenderDrawLine(s->renderer, 340, 240, 320, 200);
	//SDL_RenderPresent(s->renderer);


	while (rooms)
	{
		i = 0;

		while (i < rooms->link_count)
		{
			thickLineRGBA(s->renderer, rooms->pos.x * ZOOM, rooms->pos.y  * ZOOM, rooms->links[i]->pos.x * ZOOM, rooms->links[i]->pos.y * ZOOM, 3, 255, 255, 255, 255);	
			i++;
		}
		rooms = rooms->next;	
	}
}