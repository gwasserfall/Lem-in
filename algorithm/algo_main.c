/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 09:40:11 by ayano             #+#    #+#             */
/*   Updated: 2019/11/05 10:53:54 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

/*
** Does the same thing as get_room_by_name.
*/

t_room	*get_room(t_anthill *anthill, char *name)
{
	t_room *cursor;

	cursor = anthill->linear;
	while (cursor)
	{
		if (!(ft_strcmp(name, cursor->name)))
		{
			return (cursor);
		}
		cursor = cursor->next;
	}
	return (NULL);
}

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

bool	create_move_list(t_anthill *anthill)
{
	t_pathlist	*paths;
	t_path		*path;
	t_list		*moves;
	t_ant		*ant;

	while (!ants_are_free(anthill))
	{
		paths = anthill->paths;
		while (paths)
		{
			path = paths->path;
			if (paths->valid)
				while (!path->room->is_start)
				{
					if ((ant = ant_here(anthill->colony, path->next->room)))
						CURR_AP;
					path = path->next;
				}
			paths = paths->next;
		}
		append_move(&anthill->moves, make_move(NULL, NULL, NULL));
	}
	return (1);
}

/*
** Checks to see if all the ants are free, ie all the ants are in the ned room.
*/

bool	ants_are_free(t_anthill *anthill)
{
	t_ant	*ant;

	ant = anthill->colony;
	while (ant)
	{
		if (ant->current != anthill->end)
			return (false);
		ant = ant->next;
	}
	return (true);
}

/*
** Puts the ant in the first room in the pathlist that is not the start room.
*/

t_ant	*ant_here(t_ant *colony, t_room *room)
{
	t_ant *ant;

	ant = colony;
	while (ant)
	{
		if (ant->current == room)
			return (ant);
		ant = ant->next;
	}
	return (NULL);
}
