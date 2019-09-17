#include "visualiser.h"
#include <math.h>

void	place_ants_on_start(t_state *s)
{
	t_ant *ant;

	ant = s->anthill->colony;
	while (ant)
	{
		ant->x = s->anthill->start->x;
		ant->y = s->anthill->start->y;
		ant->sprite = s->walk_right;
		ant->current = s->anthill->start;
		ant = ant->next;
	}
}


void update_current_move(t_state *s)
{
	t_movelist	*current;
	t_moves		*moves;

	int moving = 0;
	
	current = s->anthill->movelist;

	while (current)
	{
		if (current->active)
		{
			moves = current->moves;
			while (moves)
			{
				moves->ant->following = moves->to;
				moving++;
				if (moves->ant->x > moves->ant->following->x)
				{
					moves->ant->current = moves->ant->following;
					moves->ant->following = NULL;
					moving--;
				}
				moves = moves->next;
			}
			printf("Moving count == %d\n", moving);
			if (!moving)
			{
				current->active = false;
				if (current->next)
				{
					current->next->active = true;
				}
			}
		}
		
		current = current->next;
	}
}

void	update_state(t_state *s)
{
	t_ant *army;

	update_current_move(s);
	army = s->anthill->colony;
	while (army)
	{
		if (army->following)
			update_ant_position(army);

		// if (army->path)
		// {
		// 	if (!(army->x > army->following->x))
		// 	{
				
		// 		army->is_moving = false;
			
		// 		diffy = (army->following->y - army->current->y);
		// 		diffx = (army->following->x - army->current->x);
		// 		gradient = diffy / diffx;
		// 		distance = pow((pow(diffy, 2.0) + pow(diffx, 2.0)), 0.5);
				
		// 		// printf("distance : %lf\n", distance);
		// 		// printf("gradient : %lf\n", gradient);
		// 		// printf("differy  : %lf\n", diffy);
		// 		// printf("differx  : %lf\n", diffx);
		// 		// printf("current: %s-x : %lf\n", army->current->name, army->current->x);
		// 		// printf("current: %s-y : %lf\n", army->current->name, army->current->y);
		// 		// printf("following: %s-x : %lf\n", army->following->name, army->following->x);
		// 		// printf("following: %s-y : %lf\n", army->following->name, army->following->y);
		// 		// printf("\n");
		// 		army->x += 0.05 * 0.6;
		// 		army->y += gradient * 0.05 * 0.6;
		// 	}
		// 	else
		// 	{
		// 		if (army->path->prev)
		// 		{
		// 			army->current = army->following;
		// 			army->following = army->path->room;
		// 		}
		// 		else
		// 		{
		// 			army->current = army->following;
		// 			army->following = s->anthill->end;
		// 		}
		// 	}
			
		// }
		army = army->next;
	}
}

void	draw_path(t_state *s)
{
	t_path *route;
	int x1;
	int x2;
	int y1;
	int y2;

	route = s->path;
	SDL_SetRenderDrawColor(s->renderer, 0, 255, 0, SDL_ALPHA_OPAQUE);
	while (route)
	{
		if (route->next)
		{
			x1 = X(s, route->room->x);
			x2 = X(s, route->next->room->x);
			y1 = Y(s, route->room->y);
			y2 = Y(s, route->next->room->y);
			thickLineRGBA(s->renderer, x1, y1, x2, y2, 3, 0, 255, 0, 255);
		}
		route = route->next;
	}
}

void 	draw_links_list(t_state *s)
{
	int y = 20;
	t_link *cur = s->anthill->connectors;
	char *str;
	char *str2;

	while (cur)
	{
		str = ft_strjoin(cur->from->name, " => ");
		str2 = ft_strjoin(str, cur->to->name);
		stringRGBA(s->renderer, 5, y, str2, 255, 255, 255, 255);
		free(str);
		free(str2);
		y += 10;
		cur = cur->next;
	}
}


void	draw_paths(t_state *s)
{
	t_pathlist *list;
	t_path *path;

	int i = 0;
	list = s->paths;

	while (list)
	{
		path = list->path;
		while (path && path->next)
		{
			thickLineRGBA(s->renderer, X(s, path->room->x), Y(s, path->room->y), X(s, path->next->room->x), Y(s, path->next->room->y), 3, 0, 255, 0, 255);
			path = path->next;
		}
		i++;
		list = list->next;
	}
	char *str = ft_strjoin("Path count : ", ft_itoa(i));
	stringRGBA(s->renderer, 5, 20, str, 255, 255, 255, 255);
	free(str);

}

void	render_state(t_state *s)
{
	SDL_RenderClear(s->renderer);
	SDL_RenderCopy(s->renderer, s->background, NULL, NULL);

	draw_paths(s);
	//draw_parents(s);

	// Draw links
	draw_links(s);
	draw_nodes(s);

	// Draw Stats
	draw_stats(s);

	// Draw ants
	draw_ants(s);


	//SDL_RenderFillRect(s->renderer, s->rect);
	SDL_SetRenderDrawColor(s->renderer, 0, 0, 0, 255);
	// SDL_SetRenderDrawColor(s->renderer, 0, 0, 0, 255);
	
	SDL_RenderPresent(s->renderer);
}

void change_zoom(t_state *s, int z)
{
	if (s->zoom > 1 && z < 0)
		s->zoom--;
	if (z > 0)
		s->zoom++;
	if (s->zoom < 0)
		s->zoom = 0;
}

void handle_events(t_state *s)
{
	while (SDL_PollEvent(&s->event))
	{
		if (s->event.type == SDL_QUIT)
			s->running = false;
		// if (s->event.type == SDL_KEYDOWN)
		// {
		// 	if (s->event.key.keysym.sym == SDLK_w)
		// 		change_zoom(s, -1);
		// 	if (s->event.key.keysym.sym == SDLK_a)
		// 		change_zoom(s, 1);
		// }
		if(s->event.type == SDL_MOUSEWHEEL)
		{
			if(s->event.wheel.y > 0)
			{
				s->offset_x -= s->event.motion.x;
				s->offset_y -= s->event.motion.y;
				s->zoom++;
			}
			else if(s->event.wheel.y < 0)
			{
				s->offset_x -= s->event.motion.x;
				s->offset_y -= s->event.motion.y;
				s->zoom--;
			}
		}
		if (s->event.type == SDL_MOUSEBUTTONDOWN)
			if (s->event.button.button == SDL_BUTTON_LEFT)
				s->click = true;	
		if (s->click)
		{
			if (s->event.type == SDL_MOUSEMOTION)
			{
				s->offset_x += s->event.motion.xrel;
				s->offset_y += s->event.motion.yrel;
			}
		}
		if (s->event.type == SDL_MOUSEBUTTONUP)
			s->click = false;
	}
}

void animation_loop(t_state *state)
{
	int start;
    int time;
    int sleepTime;

	while (state->running)
	{
		start = SDL_GetTicks();
		// Events
		handle_events(state);

		// Update State
		update_state(state);

		// Render State
		render_state(state);

		time = SDL_GetTicks() - start;
		if (time < 0)
			continue;

		sleepTime = 16 - time;
		if (sleepTime > 0)
        	SDL_Delay(sleepTime);
		if (state->frame > 60)
			state->frame = 0;
		state->frame++;
	}
}

int main(void)
{
	t_state *state = init_state();
	state->anthill = get_infos();

	SDL_Init(SDL_INIT_EVERYTHING);

	state->window = SDL_CreateWindow("Lem-in", 
		SDL_WINDOWPOS_CENTERED, 
		SDL_WINDOWPOS_CENTERED, 
		1280, 960, 
		SDL_WINDOW_SHOWN);
	state->renderer = SDL_CreateRenderer(state->window, -1,
	 	SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	state->running = true;

	SDL_SetRenderDrawColor(state->renderer, 0, 0, 0, 255);
	SDL_RenderClear(state->renderer);
	SDL_RenderPresent(state->renderer);

	while (set_levels(state))
		state->anthill->path_count++;

	load_all_images(state);
	place_ants_on_start(state);
	
	state->anthill->movelist->active = true;
	animation_loop(state);
}