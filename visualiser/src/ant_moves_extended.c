#include <visualiser.h>

void update_current_move(t_state *s)
{
	t_movelist	*current;
	t_moves		*moves;

	int moving;
	
	current = s->anthill->movelist;

	// Check all move lists
	while (current)
	{
		// If this movelist is active
		if (current->active)
		{
			moves = current->moves;
			// for each move in this movelist

			moving = set_active_movelist(s, current->moves);
			//printf("Moving : %d\n", moving);

			if (!moving)
			{
				current->active = false;
				if (current->next)
				{
					current->next->active = true;
				}
			}
		}
		current = current->next;
	}
}

double get_ant_angle(t_ant *ant)
{
	double degree;
	double y = (ant->following->y - ant->current->y) * -1;
	double x = ant->following->x - ant->current->x;

	degree = atan2(y, x) * (180.0 / M_PI);
	if (degree < 0)
		degree += 360.0;
	return (degree);
}

bool ant_reached_dest(t_ant *ant)
{
	double cx;
	double cy;
	double dx;
	double dy;

	cx = ant->x;
	cy = ant->y;
	dx = ant->following->x;
	dy = ant->following->y;

	if (ant->following == ant->current)
		return 1;
	if (fbetween(ant->degrees, 270, 360))
	{
		if (cx >= dx && cy >= dy)
			return true;
	}
	else if (fbetween(ant->degrees, 180, 270))
	{	
		if (cx <= dx && cy >= dy)
			return true;
	}
	else if (fbetween(ant->degrees, 90, 180))
	{
		if (cx <= dx && cy <= dy)
			return true;
	}
	else if (fbetween(ant->degrees, -1, 90))
	{
		if (cx >= dx && cy <= dy)
			return true;
	}
	return false;
}