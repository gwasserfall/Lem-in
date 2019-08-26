/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_start_and_end.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 16:00:33 by ayano             #+#    #+#             */
/*   Updated: 2019/08/26 16:00:34 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
** This function will check to see if there is both a start and end room.
** If both are not given then it will exit using exit(1);
**
** line : will be allocated using get next line and then checked to see if there
** 		  is both start and end, once either is found its int value will be set
** 		  to 1.
*/
void		verify_start_and_end(void)
{
	char	*line;
	int		start;
	int		end;

	start = 0;
	end = 0;
	while (get_next_line(0, &line))
	{
		if (ft_strcmp(line, "##start") == 0)
			start = 1;
		if (ft_strcmp(line, "##end") == 0)
			end = 1;
		free(line);
	}
	if (start != 1 || end != 1)
	{
		ft_putstr(RED);
		if (start == 0)
			ft_putendl("No start room given or it is badly formatted.");
		if (end == 0)
			ft_putendl("No end room given or it is badly formatted.");
		ft_putstr(RESET);
		exit(1);
	}
}