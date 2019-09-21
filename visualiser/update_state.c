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

	direction = (ant->direction == 1) ? 1.0 : -1.0;
	gradient = diff_y / diff_x;
	
	printf("Direction        : %s\n", (ant->direction == 1) ? "Right" : "Left");
	
	printf("XGradient        : %lf\n", (0.05 * 0.6) * direction);
	printf("YGradient        : %lf\n", gradient);
	printf("Moving from      : %s to %s\n", ant->current->name, ant->following->name);
	printf("Updated  X value : %lf\n", ant->x);
	printf("updated  Y value : %lf\n", ant->y);
	printf("Target   X value : %lf\n", ant->following->x);
	printf("Target   Y value : %lf\n", ant->following->y);


	// Get polar coords
	double hypot;

	hypot = sqrt((ant->y * ant->y) + (ant->x * ant->x));
	
	printf("Hypoteneus (dist): %lf\n", hypot);

	direction = (atan2((ant->following->y - ant->y), (ant->following->x - ant->x)) * 180.0) / M_PI;

	if (direction < 0)
		direction += 360.0;

	printf("Following Pos X  : %lf\n", ant->x - ant->following->x);
	printf("Following Pos Y  : %lf\n", ant->y - ant->following->y);
	printf("Degrees          : %lf\n", direction);

	if (direction > 90.0 && direction < 270)
	{
		ant->x -= (0.05 * 0.6);
		ant->y -= gradient * 0.05 * 0.6;	
	}
	else
	{
		ant->x += (0.05 * 0.6);
		ant->y += gradient * 0.05 * 0.6;
	}
}