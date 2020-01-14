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

#include <lem_in.h>

/*
** This function will check to see if there is either a start or an end room.
** Returns (1) if start or (2) if end and (0) if no line or the
** identifier is unknown.
*/

int		verify_start_and_end(char *line)
{
	if (!line)
		return (0);
	if (ft_strcmp(line, "##start") == 0)
		return (1);
	if (ft_strcmp(line, "##end") == 0)
		return (2);
	else
		return (0);
}

/*
** Seriousely bro, it just prints an error.
**
** It also exits the program
*/

void	print_start_end_error(void)
{
	ft_putstr(RED);
	ft_putendl("No Start or End room given.");
	ft_putstr(RESET);
	
	
	//TODO fi this up to release any data on failure
	exit(1);
}
