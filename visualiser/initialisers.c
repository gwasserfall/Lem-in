#include "visualiser.h"

t_state *init_state()
{
	t_state *state;

	state = malloc(sizeof(t_state));

	state->window = NULL;
	state->renderer = NULL;
	state->running = false;
	state->width = 0;
	state->height = 0;
	state->frame = 0;
	state->path = NULL;
	state->paths = NULL;
	state->click = false;
	state->rect = malloc(sizeof(SDL_Rect));
	state->zoom = ZOOM_DEFAULT;
	state->offset_x = 0;
	state->offset_y = 0;
	state->walk_left = NULL;
	state->walk_right = NULL;
	state->room_sprite = NULL;

	return state;
}