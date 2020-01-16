#include "visualiser.h"
#include <math.h>

bool fbetween(double n, double min, double max)
{
	if (n >= min && n <= max)
		return true;
	return false;
}

bool ant_reached_dest(t_ant *ant)
{
	double cx;
	double cy;
	double dx;
	double dy;

	cx = ant->x;
	cy = ant->y;
	dx = ant->following->x;
	dy = ant->following->y;

	if (ant->following == ant->current)
		return 1;
	if (fbetween(ant->degrees, 270, 360))
	{
		if (cx >= dx && cy >= dy)
			return true;
	}
	else if (fbetween(ant->degrees, 180, 270))
	{	
		if (cx <= dx && cy >= dy)
			return true;
	}
	else if (fbetween(ant->degrees, 90, 180))
	{
		if (cx <= dx && cy <= dy)
			return true;
	}
	else if (fbetween(ant->degrees, -1, 90))
	{
		if (cx >= dx && cy <= dy)
			return true;
	}
	return false;
}

double get_ant_angle(t_ant *ant)
{
	double degree;
	double y = (ant->following->y - ant->current->y) * -1;
	double x = ant->following->x - ant->current->x;

	degree = atan2(y, x) * (180.0 / M_PI);
	if (degree < 0)
		degree += 360.0;
	return (degree);
}

void assign_sprite(t_state *s, t_ant *ant)
{
	if (ant->degrees > 90.0 && ant->degrees < 270.0)
		ant->sprite = s->walk_left;
	else
		ant->sprite = s->walk_right;
}

int set_active_movelist(t_state *s, t_moves *moves)
{
	int moving;

	moving = 0;
	while (moves)
	{
		if (!moves->ant->following)
		{
			moves->ant->following = moves->to;
			moves->ant->degrees = get_ant_angle(moves->ant);
			assign_sprite(s, moves->ant);
		}
		moving++;
		if (ant_reached_dest(moves->ant))
		{
			//printf("Ant %s has reached destination room %s\n", moves->ant->name, moves->to->name);
			moves->ant->x = moves->to->x;
			moves->ant->y = moves->to->y;
			moves->ant->current = moves->ant->following;
			moves->ant->following = NULL;
			moves->ant->is_moving = false;
			
			if (moves->ant->degrees > 90.0 && moves->ant->degrees < 270.0)
			{
				moves->ant->sprite = s->walk_static_l;
			}
			else
			{
				moves->ant->sprite = s->walk_static_r;
			}
			moving--;
		}
		moves = moves->next;
	}
	return (moving);
}

void update_current_move(t_state *s)
{
	t_movelist	*current;
	t_moves		*moves;

	int moving;
	
	current = s->anthill->movelist;

	// Check all move lists
	while (current)
	{
		// If this movelist is active
		if (current->active)
		{
			moves = current->moves;
			// for each move in this movelist

			moving = set_active_movelist(s, current->moves);
			//printf("Moving : %d\n", moving);

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
			//thickLineRGBA(s->renderer, x1, y1, x2, y2, 3, 0, 255, 0, 255);
			//
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

	double x1;
	double x2;
	double y1;
	double y2;

	SDL_SetRenderDrawColor(s->renderer, 0, 255, 0, SDL_ALPHA_OPAQUE);
	while (list)
	{
		path = list->path;
		while (path && path->next)
		{
			x1 = X(s, path->room->x);
			y1 = Y(s, path->room->y);
			x2 = X(s, path->next->room->x);
			y2 = Y(s, path->next->room->y);
			//aalineRGBA(s->renderer, x1, y1, x2, y2, 0, 255, 0, 255);
			SDL_RenderDrawLine(s->renderer, x1, y1, x2, y2);
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

	
	//draw_parents(s);

	// Draw links
	draw_links(s);
	draw_paths(s);
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