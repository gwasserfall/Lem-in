#include <visualiser.h>

int set_active_movelist(t_state *s, t_moves *moves)
{
	int moving;

	moving = 0;
	while (moves)
	{
		if (!moves->ant->following)
		{
			moves->ant->following = moves->to;
			moves->ant->degrees = get_ant_angle(moves->ant);
			assign_sprite(s, moves->ant);
		}
		moving++;
		if (ant_reached_dest(moves->ant))
		{
			//printf("Ant %s has reached destination room %s\n", moves->ant->name, moves->to->name);
			moves->ant->x = moves->to->x;
			moves->ant->y = moves->to->y;
			moves->ant->current = moves->ant->following;
			moves->ant->following = NULL;
			moves->ant->is_moving = false;
			
			if (moves->ant->degrees > 90.0 && moves->ant->degrees < 270.0)
			{
				moves->ant->sprite = s->walk_static_l;
			}
			else
			{
				moves->ant->sprite = s->walk_static_r;
			}
			moving--;
		}
		moves = moves->next;
	}
	return (moving);
}