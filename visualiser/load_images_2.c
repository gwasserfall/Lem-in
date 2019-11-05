/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 14:20:12 by ayano             #+#    #+#             */
/*   Updated: 2019/11/05 14:20:15 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualiser.h"

t_img	*make_sprite(t_state *s, char *filename)
{
	t_img *new;

	if (!(new = malloc(sizeof(t_img))))
		return (NULL);
	new->img = IMG_LoadTexture(s->renderer, filename);
	new->next = NULL;
	return (new);
}

void	append_sprite(t_img **start, t_img *new)
{
	t_img *sprite;

	sprite = *start;
	if (!sprite)
		*start = new;
	else
	{
		while (sprite->next)
			sprite = sprite->next;
		sprite->next = new;
	}
}

void	loop_sprites(t_img *start)
{
	t_img *cursor;

	cursor = start;
	while (cursor->next)
		cursor = cursor->next;
	cursor->next = start;
}

void	load_all_images(t_state *s)
{
	load_sprites_right(s);
	load_sprites_left(s);
	load_room_sprite(s);
	load_background(s);
	loop_sprites(s->walk_left);
	loop_sprites(s->walk_right);
	loop_sprites(s->walk_static_r);
	loop_sprites(s->walk_static_l);
}
