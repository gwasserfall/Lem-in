#include "visualiser.h"

void	update_ant_position(t_ant *ant)
{
	double gradient;
	double diff_x;
	double diff_y;
	double direction;

	diff_y = (ant->following->y - ant->current->y);
	diff_x = (ant->following->x - ant->current->x);
	direction = (diff_x > 0) ? 1.0 : -1.0;
	gradient = diff_y / diff_x;
	ant->x += (0.05 * 0.6) * direction;
	ant->y += gradient * 0.05 * 0.6;
}