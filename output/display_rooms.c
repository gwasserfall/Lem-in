/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_rooms.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 12:36:05 by ayano             #+#    #+#             */
/*   Updated: 2019/09/04 12:36:06 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
** Displays the rooms in the correct format
** MIGHT NOT NEED
*/
void	display_rooms(t_anthill **anthill)
{
	t_room *current;

	current = (*anthill)->linear;
	while (current)
	{
		if (current->is_start == 1)
			ft_putendl("##start");
		if (current->is_end == 1)
			ft_putendl("##end");
		ft_putstr(current->name);
		ft_putchar(' ');
		ft_putnbr(current->x);
		ft_putchar(' ');
		ft_putnbr(current->y);
		ft_putchar('\n');
		current = current->next;
	}
}