#include "../includes/lem_in.h"
#include <time.h>
#include <stdlib.h>

void	join_colony(t_anthill *anthill, t_ant *larvae)
{
	t_ant	*nurse;
	
	printf("%p\n", anthill->colony);

	if (!anthill->colony)
		anthill->colony = larvae;
	else
	{
		nurse = anthill->colony;
		while (nurse->next)
			nurse = nurse->next;
		nurse->next = larvae;
	}
}

int		hatch_ant(t_anthill *anthill, int x, int y, char *name)
{
	t_ant *egg;

	if (!(egg = malloc(sizeof(t_ant))))
		return (0);
	egg->x = x;
	egg->y = y;
	egg->next = NULL;
	egg->name = ft_strdup(name);
	join_colony(anthill, egg);
	return (1);
}

t_state *init_state()
{
	t_state *state;

	state = malloc(sizeof(t_state));

	state->window = NULL;
	state->renderer = NULL;
	state->running = false;
	state->width = 0;
	state->height = 0;
	state->path = NULL;
	state->click = false;
	state->rect = malloc(sizeof(SDL_Rect));
	state->zoom = ZOOM_DEFAULT;
	state->rect->h = 20;
	state->rect->w = 20;
	state->rect->x = 600 / 2;
	state->rect->y = 800 / 2;
	state->offset_x = 0;
	state->offset_y = 0;

	return state;
}

void explore_map(t_state *s, t_path *path)
{
	// ALways go to end of paff
	while (path->next)
		path = path->next;

	if (path->room == s->anthill->end)
		return;

	// printf("Path at this point is %s index[%d] linkcount[%d]\n", path->room->name, path->index, path->room->link_count);

	// Backtrack if needed
	if (path->room->link_count <= path->index || visited(s->path, path->room->links[path->index]))
	{
		path->prev->index++;
		path->prev->next = NULL;
		free(path);
		
	}
	else
	{
		// Forward she goes!
		path->next = malloc(sizeof(t_path));
		path->next->prev = path;
		path->next->next = NULL;
		path->next->index = 0;
		path->next->room = path->room->links[path->index];
	}
	SDL_Delay(300);
}

void	update_state(t_state *s)
{
	t_ant *army;

	army = s->anthill->colony;
	while (army)
	{
		if (!army->x)
			army->x = s->anthill->start->x;
		if (!army->y)
			army->y = s->anthill->start->y;
		army = army->next;
	}
	explore_map(s, s->path);

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


typedef struct s_frontier
{
	t_room				*room;
	struct s_frontier	*next;
}	t_frontier;


/*
level = {s : 0}
parent = {s : None}

i = 1
frontier = [s]

while frontier:
	next = []
	for u in frontier:

		for v in u.neighbours:

			if v not in level:
				level[v] = i
				parent[v] = u
				next.append(v)

	frontier = next
	i += 1
*/

void append_roomz(t_frontier **front, t_room *room)
{
	t_frontier *cur;
	t_frontier *new;

	cur = *front;

	if (!cur)
	{
		*front = malloc(sizeof(t_frontier));
		(*front)->next = NULL;
		(*front)->room = room;
	}
	else
	{
		while (cur->next)
		{
			cur = cur->next;
		}
		new =  malloc(sizeof(t_frontier));
		new->room = room;
		new->next = NULL;
		cur->next = new;
	}
}

bool has_vertices(t_frontier *frontier)
{
	if (frontier)
		return true;
	return false;
}


void	append_frontier(t_frontier **current, t_frontier *next)
{
	t_frontier *cur;

	cur = *current;

	if (!cur)
		*current = next;
	else
	{
		while (cur->next)
			cur = cur->next;
		cur->next = next;
		next->next = NULL;
	}
}


t_frontier *get_neighbours(t_link *links, t_frontier *front)
{
	t_room *room = front->room;
	t_frontier *neighs;
	t_frontier *neigh1;
	t_frontier *neigh2;

	neighs = NULL;

	while (links)
	{
		if (links->from == front->room)
		{
			append_roomz(&neighs, links->to);
		}	
		else if (links->to == front->room)
		{
			append_roomz(&neighs, links->from);
		}
		links = links->next;
	}
	return neighs;
}


void	set_levels(t_state *s)
{
	t_frontier *frontier;
	t_frontier *next;
	t_frontier *neighbour;
	int i = 1;

	frontier = NULL;

	append_roomz(&frontier, s->anthill->start);

	while (has_vertices(frontier))
	{
		next = NULL;
		while (frontier)
		{
			neighbour = get_neighbours(s->anthill->connectors, frontier);
			while (neighbour)
			{
				if (neighbour->room->level == -1)
				{
					neighbour->room->level = i;
					neighbour->room->parent = frontier->room;
					append_frontier(&next, neighbour);
				}
				neighbour = neighbour->next;
			}
			frontier = frontier->next;
		}
		i++;
		frontier = next;
	}
}

void	render_state(t_state *s)
{
	SDL_RenderClear(s->renderer);

	// Draw links
	//draw_links(s);
	draw_nodes(s);

	// Draw Stats
	draw_stats(s);

	// Draw ants
	draw_ants(s);

	// Draw current path
	draw_path(s);

	// Devy
	draw_links_list(s);
	

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
}

void handle_events(t_state *s)
{
	while (SDL_PollEvent(&s->event))
	{
		if (s->event.type == SDL_QUIT)
			s->running = false;
		if (s->event.type == SDL_KEYDOWN)
		{
			if (s->event.key.keysym.sym == SDLK_w)
				change_zoom(s, -1);
			if (s->event.key.keysym.sym == SDLK_a)
				change_zoom(s, 1);
		}
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
		{
			if (s->event.button.button == SDL_BUTTON_LEFT)
			{
				s->click = true;	
			}
		}
		if (s->click)
		{
			if (s->event.type == SDL_MOUSEMOTION)
			{
				s->offset_x += s->event.motion.xrel;
				s->offset_y += s->event.motion.yrel;
			}
		}
		if (s->event.type == SDL_MOUSEBUTTONUP)
		{
			s->click = false;
		}
	}
}

int main(void)
{
	t_state *state = init_state();
	state->anthill = get_infos();

	SDL_Init(SDL_INIT_EVERYTHING);

	state->window = SDL_CreateWindow("Lem-in", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 960, SDL_WINDOW_SHOWN);
	state->renderer = SDL_CreateRenderer(state->window, -1, SDL_RENDERER_ACCELERATED);
	state->running = true;

	state->path = malloc(sizeof(t_path));
	state->path->room = state->anthill->start;
	state->path->index = 0;
	state->path->next = NULL;
	state->path->prev = NULL;

	SDL_SetRenderDrawColor(state->renderer, 0, 0, 0, 255);
	SDL_RenderClear(state->renderer);
	SDL_RenderPresent(state->renderer);

	set_levels(state);

	while (state->running)
	{
		// Events
		handle_events(state);

		// Update State
		update_state(state);

		// Render State
		render_state(state);

		SDL_Delay(1);
	}
}