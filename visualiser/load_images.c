#include "visualiser.h"

t_img	*make_sprite(t_state *s, char *filename)
{
	t_img *new;

	if (!(new = malloc(sizeof(t_img))))
		return NULL;
	new->img = IMG_LoadTexture(s->renderer, filename);
	new->next = NULL;
	return new;
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

void load_sprites_right(t_state *s)
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

void load_sprites_left(t_state *s)
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

void load_walk_static(t_state *s)
{
	s->walkl_static = IMG_LoadTexture(s->renderer, "./img/walkl_cycle01.png");
	s->walkr_static = IMG_LoadTexture(s->renderer, "./img/walkr_cycle01.png");
}

void load_background(t_state *s)
{
	s->background = IMG_LoadTexture(s->renderer, "./img/background.png");
}

void load_room_sprite(t_state *s)
{
	s->room_sprite = IMG_LoadTexture(s->renderer, "./img/room_01.png");
}

void load_all_images(t_state *s)
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