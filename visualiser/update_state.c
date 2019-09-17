#include "visualiser.h"

void	update_ant_position(t_ant *ant)
{
	double gradient;
	double diff_x;
	double diff_y;
	double direction;

	printf("\n============================================\n");
	printf("===================== %s ====================\n", ant->name);

	printf("Original X value : %lf\n", ant->x);
	printf("Original Y value : %lf\n", ant->y);

	diff_y = (ant->following->y - ant->current->y);
	diff_x = (ant->following->x - ant->current->x);

	printf("Difference X     : %lf\n", diff_x);
	printf("Difference Y     : %lf\n", diff_y);

	direction = (diff_x > 0) ? 1.0 : -1.0;
	gradient = diff_y / diff_x;
	
	printf("Direction        : %s\n", (direction == 1) ? "Left" : "Right");
	printf("Gradient         : %lf\n", gradient);
	
	ant->x += (0.05 * 0.6) * direction;
	ant->y += gradient * 0.05 * 0.6;

	printf("Updated  X value : %lf\n", ant->x);
	printf("updated  Y value : %lf\n", ant->y);



}