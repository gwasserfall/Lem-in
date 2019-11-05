/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_state.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 14:47:17 by ayano             #+#    #+#             */
/*   Updated: 2019/11/05 14:47:24 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualiser.h"
#define ANTX ant->x -= (0.05 * 0.6)
#define ANTY ant->y -= gradient * 0.05 * 0.6
#define ANTS {ANTX;ANTY}

void	update_ant_position(t_ant *ant)
{
	double gradient;
	double diff_x;
	double diff_y;
	double direction;

	diff_y = (ant->following->y - ant->current->y);
	diff_x = (ant->following->x - ant->current->x);
	if (diff_x == 0)
	{
		if (diff_y < 0)
			ant->y -= (0.05 * 0.6);
		else
			ant->y += (0.05 * 0.6);
		return ;
	}
	gradient = diff_y / diff_x;
	if (ant->degrees >= 90.0 && ant->degrees <= 270)
		ANTS;
	else
	{
		ant->x += (0.05 * 0.6);
		ant->y += gradient * 0.05 * 0.6;
	}
}
