/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_links.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 12:41:24 by ayano             #+#    #+#             */
/*   Updated: 2019/11/05 12:41:25 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualiser.h"

int		calc_x(t_state *state, double value)
{
	return (state->zoom * value / 2 + state->offset_x);
}

int		calc_y(t_state *state, double value)
{
	return (state->zoom * value / 2 + state->offset_y);
}

void	draw_links(t_state *s)
{
	t_link	*link;
	int		x1;
	int		x2;
	int		y1;
	int		y2;

	link = s->anthill->connectors;
	SDL_SetRenderDrawColor(s->renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
	while (link)
	{
		x1 = X(s, link->from->x);
		x2 = X(s, link->to->x);
		y1 = Y(s, link->from->y);
		y2 = Y(s, link->to->y);
		SDL_RenderDrawLine(s->renderer, x1, y1, x2, y2);
		link = link->next;
	}
}

void	draw_nodes(t_state *s)
{
	t_room		*room;
	SDL_Rect	r;

	room = s->anthill->linear;
	SDL_SetRenderDrawColor(s->renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
	while (room)
	{
		r.x = X(s, room->x) - 50;
		r.y = Y(s, room->y) - 15;
		r.h = 30;
		r.w = 100;
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
			SDL_RenderCopy(s->renderer, s->room_sprite, NULL, &r);
		}
		room = room->next;
	}
}

void	draw_stats(t_state *s)
{
	stringRGBA(s->renderer, 5, 5, "Zoom: ", 255, 255, 255, 255);
	stringRGBA(s->renderer, 50, 5, ft_itoa(s->zoom), 255, 255, 255, 255);
}
