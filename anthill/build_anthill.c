/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 16:19:36 by ayano             #+#    #+#             */
/*   Updated: 2019/08/26 16:19:37 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
** This will create the anthills first node and then add nodes for each room.
*/
t_anthill	*build_anthill(void)
{
	t_anthill	*anthill;
	char		*line;
	int			type;

	anthill = init_anthill();
	while (get_next_line(0, &line))
	{
		type = check_line(line);
		pre_add_data(type, line, &anthill);
	}
	if (anthill->nb_ants <= 0)
		print_ant_error();
	return (anthill);
}

/*
** Will check the line and return an int dependant on the type of line it is.
** i.e : 1 == number of ants.
**     : 2 == identifier.
**	   : 3 == room.
**     : 4 == links.
**     : 5 == comment.
**	   : 6 == error/invalid input.
*/
int		check_line(char *line)
{
	int		i;

	i = 0;
	if (line[i] == '#' && line[i + 1] != '#')
		return (5);
	else if (line[i] == '#' && line[i + 1] == '#')
		return (2);
	else if (word_count(line, ' ', 0) == 3)
		return (3);
	else if (word_count(line, '-', 0) == 2)
		return (4);
	else if (only_digit(line) == 1)
		return (1);
	else
		return (6);
}

/*
** This will malloc and set the initial values to all the data held in the struct.
*/
t_anthill	*init_anthill(void)
{
	t_anthill	*anthill;

	if (!(anthill = malloc(sizeof(t_anthill))))
		return false;
	anthill->room_count = 0;
	anthill->linear = NULL;
	anthill->start = NULL;
	anthill->nb_ants = 0;
	anthill->end = NULL;
	return (anthill);
}

/*
** checks if the only info in the line is digits.
*/
int		only_digit(char *line)
{
	int		i;

	i = 0;
	while (line[i] != '\0')
	{
		if (ft_isdigit(line[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}
