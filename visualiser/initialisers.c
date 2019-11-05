/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 14:19:03 by ayano             #+#    #+#             */
/*   Updated: 2019/11/05 14:19:07 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualiser.h"

t_state		*init_state(void)
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
	return (state);
}
