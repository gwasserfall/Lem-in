/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 14:20:04 by ayano             #+#    #+#             */
/*   Updated: 2019/11/05 14:20:05 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualiser.h"

void	load_sprites_right(t_state *s)
{
	append_sprite(&s->walk_right, make_sprite(s, "./img/walkr_cycle01.png"));
	append_sprite(&s->walk_right, make_sprite(s, "./img/walkr_cycle02.png"));
	append_sprite(&s->walk_right, make_sprite(s, "./img/walkr_cycle03.png"));
	append_sprite(&s->walk_right, make_sprite(s, "./img/walkr_cycle04.png"));
	append_sprite(&s->walk_right, make_sprite(s, "./img/walkr_cycle05.png"));
	append_sprite(&s->walk_right, make_sprite(s, "./img/walkr_cycle06.png"));
	append_sprite(&s->walk_right, make_sprite(s, "./img/walkr_cycle07.png"));
	append_sprite(&s->walk_right, make_sprite(s, "./img/walkr_cycle08.png"));
	append_sprite(&s->walk_static_r, make_sprite(s, "./img/walkr_cycle01.png"));
}

void	load_sprites_left(t_state *s)
{
	append_sprite(&s->walk_left, make_sprite(s, "./img/walkl_cycle01.png"));
	append_sprite(&s->walk_left, make_sprite(s, "./img/walkl_cycle02.png"));
	append_sprite(&s->walk_left, make_sprite(s, "./img/walkl_cycle03.png"));
	append_sprite(&s->walk_left, make_sprite(s, "./img/walkl_cycle04.png"));
	append_sprite(&s->walk_left, make_sprite(s, "./img/walkl_cycle05.png"));
	append_sprite(&s->walk_left, make_sprite(s, "./img/walkl_cycle06.png"));
	append_sprite(&s->walk_left, make_sprite(s, "./img/walkl_cycle07.png"));
	append_sprite(&s->walk_left, make_sprite(s, "./img/walkl_cycle08.png"));
	append_sprite(&s->walk_static_l, make_sprite(s, "./img/walkl_cycle01.png"));
}

void	load_walk_static(t_state *s)
{
	s->walkl_static = IMG_LoadTexture(s->renderer, "./img/walkl_cycle01.png");
	s->walkr_static = IMG_LoadTexture(s->renderer, "./img/walkr_cycle01.png");
}

void	load_background(t_state *s)
{
	s->background = IMG_LoadTexture(s->renderer, "./img/background.png");
}

void	load_room_sprite(t_state *s)
{
	s->room_sprite = IMG_LoadTexture(s->renderer, "./img/room_01.png");
}
