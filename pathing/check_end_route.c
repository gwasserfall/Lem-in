/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_end_route.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 13:28:58 by ayano             #+#    #+#             */
/*   Updated: 2019/08/30 13:28:59 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		check_end_route_head(t_anthill **anthill)
{
	t_room	*t_start;
	t_room	*current;
	int		i;

	t_start = (*anthill)->start;
	i = 0;
	
	while (i < t_start->link_count)
	{
	}
}

int		check_room(t_anthill **anthill, t_room *room, int i)
{
	// t_room	*current;

	// current = room;
	// if (current->links[i] == (*anthill)->end)
	// 	return (1);
	// if (current->links[i] != '\0')
	// 	check_room(anthill, current->links[i], i);
}