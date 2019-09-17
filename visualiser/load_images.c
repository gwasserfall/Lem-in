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

void load_sprites(t_state *s)
{
	append_sprite(&s->walk_right, make_sprite(s, "./img/walk_cycle01.png"));
	append_sprite(&s->walk_right, make_sprite(s, "./img/walk_cycle02.png"));
	append_sprite(&s->walk_right, make_sprite(s, "./img/walk_cycle03.png"));
	append_sprite(&s->walk_right, make_sprite(s, "./img/walk_cycle04.png"));
	append_sprite(&s->walk_right, make_sprite(s, "./img/walk_cycle05.png"));
	append_sprite(&s->walk_right, make_sprite(s, "./img/walk_cycle06.png"));
	append_sprite(&s->walk_right, make_sprite(s, "./img/walk_cycle07.png"));
	append_sprite(&s->walk_right, make_sprite(s, "./img/walk_cycle08.png"));
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
	load_sprites(s);
	load_room_sprite(s);
	load_background(s);
}