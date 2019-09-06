#include <lem_in.h>


int calc_x(t_state *state, int value)
{
	return (state->zoom * value / 2 + state->offset_x) ;
}

int calc_y(t_state *state, int value)
{
	return (state->zoom * value / 2 + state->offset_y);
}

void draw_links(t_state *s)
{
	t_room *rooms;
	int i;

	rooms = s->anthill->linear;
	
	SDL_SetRenderDrawColor(s->renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);

	while (rooms)
	{
		i = 0;
		while (i < rooms->link_count)
		{
			SDL_RenderDrawLine(s->renderer, X(s, rooms->x), Y(s, rooms->y), X(s, rooms->links[i]->x), Y(s, rooms->links[i]->y));
			i++;
		}
		rooms = rooms->next;	
	}
}

void draw_nodes(t_state *s)
{
	t_room *room;

	room = s->anthill->linear;

	SDL_SetRenderDrawColor(s->renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);

	while (room)
	{
		if (room->is_start)
		{
			stringRGBA(s->renderer, X(s, room->x) + 5, Y(s, room->y) - 24, "START", 255, 255, 255, 255);
			filledCircleRGBA(s->renderer, X(s, room->x), Y(s, room->y), 10, 0, 255, 255, 255);
		}
		else if (room->is_end)
		{
			stringRGBA(s->renderer, X(s, room->x) + 5, Y(s, room->y) - 24, "END", 255, 255, 255, 255);
			filledCircleRGBA(s->renderer, X(s, room->x), Y(s, room->y), 10, 255, 0, 255, 255);
		}
		else
		{
			stringRGBA(s->renderer, X(s, room->x) + 5, Y(s, room->y) - 24, room->name, 255, 255, 255, 255);
			filledCircleRGBA(s->renderer, X(s, room->x), Y(s, room->y), 10, 255, 255, 0, 255);
		}
		stringRGBA(s->renderer, X(s, room->x) - 3, Y(s, room->y) - 3, ft_itoa(room->level), 0, 0, 0, 255);
		room = room->next;
	}
}

void	draw_stats(t_state *s)
{
	stringRGBA(s->renderer, 5, 5, "Zoom: ", 255, 255, 255, 255);
	stringRGBA(s->renderer, 50, 5, ft_itoa(s->zoom), 255, 255, 255, 255);
}

void	draw_ants(t_state *s)
{
	t_ant *army;
	SDL_Rect r;

	army = s->anthill->colony;

	SDL_SetRenderDrawColor(s->renderer, 200, 200, 200, 255);
	while (army)
	{
		r.x = X(s, army->x) - 10;
		r.y = Y(s, army->y) - 10;
		r.h = 20;
		r.w = 20;

		SDL_RenderFillRect(s->renderer, &r);
		army = army->next;
	}
}