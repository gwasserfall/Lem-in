#include <lem_in.h>

/*
** Now that the rooms has levels this will go and find all the valid paths
** and add them to the pathlist struct *Does not include ##start-##end.
*/

void	create_colony(t_anthill *anthill)
{
	int i;

	i = 0;
	while (i < anthill->nb_ants)
		hatch_ant(anthill, ft_itoa(++i));
}