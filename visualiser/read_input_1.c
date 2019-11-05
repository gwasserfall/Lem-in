/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 14:32:53 by ayano             #+#    #+#             */
/*   Updated: 2019/11/05 14:38:05 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualiser.h"

#define ANT_COUNT 1
#define IDENT 2
#define ROOM 3
#define LINK 4
#define COMMENT 5
#define INVLD 6
#define MOVE 7
#define EMPTY 8

t_anthill	*init_anthill(void)
{
	t_anthill	*anthill;

	if (!(anthill = malloc(sizeof(t_anthill))))
		return (false);
	anthill->room_count = 0;
	anthill->linear = NULL;
	anthill->colony = NULL;
	anthill->start = NULL;
	anthill->nb_ants = 0;
	anthill->movelist = NULL;
	anthill->connectors = NULL;
	anthill->end = NULL;
	return (anthill);
}

void		append_room(t_room *entry_point, t_room *new)
{
	t_room		*current;

	current = entry_point;
	while (current->next)
		current = current->next;
	current->next = new;
}

t_room		*init_room_g(char *name, int x, int y)
{
	t_room *new;

	if (!(new = (t_room *)malloc(sizeof(t_room))))
		return (NULL);
	new->next = NULL;
	new->link_count = 0;
	new->name = ft_strdup(name);
	new->level = -1;
	new->parent = NULL;
	new->is_end = 0;
	new->is_start = 0;
	new->x = x;
	new->y = y;
	new->links = NULL;
	return (new);
}

bool		int_string(char *str)
{
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (false);
		str++;
	}
	return (true);
}

int			identify_line(char *line)
{
	int line_length;

	line_length = ft_strlen(line);
	if (line_length < 1)
		return (EMPTY);
	else if (line[0] == '#' && line[1] == '#')
		return (IDENT);
	else if (line[0] == '#' && line[1] != '#')
		return (COMMENT);
	else if (int_string(line))
		return (ANT_COUNT);
	else if (ft_strchr(line, ' ') && line[0] != 'L')
		return (ROOM);
	else if (ft_strchr(line, '-') && line[0] != 'L')
		return (LINK);
	else if (line[0] == 'L')
		return (MOVE);
	else
		return (INVLD);
}
