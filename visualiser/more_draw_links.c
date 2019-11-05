/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_draw_links.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 12:41:30 by ayano             #+#    #+#             */
/*   Updated: 2019/11/05 12:41:32 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualiser.h"

void	draw_ants(t_state *s)
{
	t_ant		*army;
	SDL_Rect	r;

	army = s->anthill->colony;
	SDL_SetRenderDrawColor(s->renderer, 200, 200, 200, 255);	
	stringRGBA(s->renderer, 5, 40, ft_itoa(s->frame), 255, 255, 255, 255);
	while (army)
	{
		stringRGBA(s->renderer, X(s, army->x) - 35, Y(s, army->y) - SPRITE_H - 10, army->name, 255, 255, 255, 255);
		r.x = X(s, army->x) - SPRITE_W / 2;
		r.y = Y(s, army->y) - SPRITE_H;
		r.h = SPRITE_H;
		r.w = SPRITE_W;
		if (army->sprite)
			if (s->frame % 5 == 0)
			{
				if (army->sprite && army->sprite->next)
				{
					army->sprite = army->sprite->next;
				}
				else
				{
					army->sprite = s->walk_right;
				}
			}
			SDL_RenderCopy(s->renderer, army->sprite->img, NULL, &r);
		army = army->next;
	}
}
