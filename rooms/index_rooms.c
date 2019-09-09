/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 12:56:25 by ayano             #+#    #+#             */
/*   Updated: 2019/09/03 12:56:26 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
** Indexes all the rooms with start being 0 and end being the max rooms
*/
void        index_rooms(t_anthill **anthill)
{
    t_room  *current;
    int     i;

    current = (*anthill)->linear;
    i = 1;
    while (current)
    {
        if (current->is_end != 1 && current->is_start != 1)
        {
            current->index = i;
            i++;
        }
        current = current->next;
    }
    (*anthill)->start->index = 0;
    (*anthill)->end->index = i;
}