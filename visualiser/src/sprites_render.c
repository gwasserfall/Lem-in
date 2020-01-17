#include <visualiser.h>

void assign_sprite(t_state *s, t_ant *ant)
{
	if (ant->degrees > 90.0 && ant->degrees < 270.0)
		ant->sprite = s->walk_left;
	else
		ant->sprite = s->walk_right;
}
