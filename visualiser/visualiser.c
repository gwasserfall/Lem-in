#include "visualiser.h"
#include <time.h>
#include <stdlib.h>


t_state *init_state()
{
	t_state *state;

	state = malloc(sizeof(t_state));

	state->window = NULL;
	state->renderer = NULL;
	state->running = false;
	state->width = 0;
	state->height = 0;

	state->rect = malloc(sizeof(SDL_Rect));

	state->rect->h = 20;
	state->rect->w = 20;
	state->rect->x = 600 / 2;
	state->rect->y = 800 / 2;

	return state;
}

void	update_state(t_state *s)
{

	if (s->rect->x > 800)
		s->rect->x = 0;
	else if (s->rect->y < 0)
		s->rect->y = 600;
	else
	{
		s->rect->x += rand() % 5;
		s->rect->y -= rand() % 5;
	}
}

void	render_state(t_state *s)
{
	SDL_RenderClear(s->renderer);

	// Draw links
	draw_links(s);

	// Draw nodes
	//draw_nodes(s);

	// Draw lemmings
	SDL_SetRenderDrawColor(s->renderer, 255, 0, 0, 255);
	SDL_RenderFillRect(s->renderer, s->rect);
	SDL_SetRenderDrawColor(s->renderer, 0, 0, 0, 255);
	SDL_RenderPresent(s->renderer);
}

int main(void)
{
	t_state *state = init_state();
	state->anthill = init();

	SDL_Init(SDL_INIT_EVERYTHING);

	state->window = SDL_CreateWindow("asd", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
	state->renderer = SDL_CreateRenderer(state->window, -1, SDL_RENDERER_ACCELERATED);

	state->running = true;

	SDL_SetRenderDrawColor(state->renderer, 0, 0, 0, 255);
	SDL_RenderClear(state->renderer);
	SDL_RenderPresent(state->renderer);

	while (state->running)
	{
		// Events
		while (SDL_PollEvent(&state->event))
		{
			if (state->event.type == SDL_KEYDOWN)
				state->running = false;
		}

		// Update State
		update_state(state);

		// Render State
		render_state(state);

		SDL_Delay(1);
	}
}