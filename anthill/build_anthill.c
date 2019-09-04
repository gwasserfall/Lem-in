/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_anthill.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <ayano@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 16:19:36 by ayano             #+#    #+#             */
/*   Updated: 2019/09/02 15:51:37 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
** This will create the anthills first node and then add nodes for each room.
*/

t_anthill	*build_anthill(void)
{
	t_anthill	*anthill;

	anthill = init_anthill();
	read_loop(anthill);
	index_rooms(&anthill);
	// create_map(&anthill);
	if (anthill->nb_ants <= 0)
		print_ant_error();
	return (anthill);
}

void		read_loop(t_anthill *anthill)
{
	char	*line;
	char	*temp;
	int		link;
	int		type;

	while (get_next_line(0, &line))
	{
		ft_putendl("HERE10");
		if (line[0] != '\0')
			temp = ft_strdup(line);
		ft_putendl("HERE");
		if (line[0] == '\0')
			print_invalid_input();
		ft_putendl("HERE1");
		if (ft_strcmp(temp, "##start") == 0 && ft_strcmp(line, "##start") != 0)
		{
			add_start_data(line, &anthill);
			free(temp);
		}
		ft_putendl("HERE2");
		if (ft_strcmp(temp, "##end") == 0 && ft_strcmp(line, "##end") != 0)
		{
			add_data_end(line, &anthill);
			free(line);
			get_next_line(0, &line);
			free(temp);
			temp = ft_strdup(line);
		}
		ft_putendl("HERE3");
		type = check_line(line);
		ft_putendl("HERE4");
		if (type == 4)
			link = 1;
		ft_putendl("HERE5");
		if (type == 3 && link == 1)
			print_invalid_input();
		ft_putendl("HERE6");
		free(temp);
		ft_putendl("HERE7");
		// temp = ft_strdup(line);
		pre_add_data(type, line, &anthill);
		ft_putendl("HERE8");
		free(line);
		ft_putendl("HERE9");
	}
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

int			check_line(char *line)
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
** This will malloc and set the initial values to all
** the data held in the struct.
*/

t_anthill	*init_anthill(void)
{
	t_anthill	*anthill;

	if (!(anthill = malloc(sizeof(t_anthill))))
		return (false);
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

int			only_digit(char *line)
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
