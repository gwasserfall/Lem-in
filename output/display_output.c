/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_output.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 12:34:01 by ayano             #+#    #+#             */
/*   Updated: 2019/09/04 12:34:02 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

/*
** MIGHT NOT NEED, DUPLICATE OF THE DISPLAY INPUT FUCNTION
*/
void		display_output(t_anthill **anthill)
{
	display_ants(anthill);
	display_rooms(anthill);
	// display_links(anthill);
}