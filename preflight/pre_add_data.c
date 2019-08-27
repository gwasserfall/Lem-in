/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_add_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 08:55:30 by ayano             #+#    #+#             */
/*   Updated: 2019/08/27 08:55:31 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
** This will take the data we have and then pass it to the appropriate function
** that will add the data to the linear, start or end structs.
**     : 1 == number of ants.
**     : 2 == identifier. (1 == start, 2 == end)
**	   : 3 == room.
**     : 4 == links.
**     : 5 == comment.
**	   : 6 == error/invalid input.
*/
void		pre_add_data(int type, char *line, t_anthill **anthill)
{
	if (type == 1)
	{
		verify_ants(line);
		(*anthill)->nb_ants = ft_atoi(line);
	}
	if (type == 2)
	{
		if (verify_start_and_end(line) == 1)
			// TODO -> room is start should it be a bool in the anthill as well?
		else if (verify_start_and_end(line) == 2)
			// TODO -> room is end should it be a bool in the anthill as well?
		else
			return ;
	}
	if (type == 3)
	{
		verify_room(line);
	}

}