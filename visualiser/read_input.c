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

void		assign_ants(t_anthill *anthill, char *str)
{
	int i;

	anthill->nb_ants = ft_atoi(str);
	i = 0;
	while (i < anthill->nb_ants)
	{
		hatch_ant(anthill, 0, 0, ft_itoa(i + 1));
		i++;
	}
}

t_movelist	*make_movelist_item(t_moves *moves)
{
	t_movelist *new;

	if (!(new = malloc(sizeof(t_movelist))))
		return (NULL);
	new->next = NULL;
	new->active = false;
	new->complete = false;
	new->moves = moves;
	return (new);
}

void		append_to_movelist(t_movelist **start, t_movelist *new)
{
	t_movelist *mvlist;

	mvlist = *start;
	if (!mvlist)
		*start = new;
	else
	{
		while (mvlist->next)
			mvlist = mvlist->next;
		mvlist->next = new;
	}
}

void		assign_move(t_anthill *anthill, char *str)
{
	char	**line;
	int		i;
	t_moves *moves;

	moves = NULL;
	line = ft_strsplit(str, ' ');
	i = 0;
	while (line[i])
		append_move(&moves, deserialise_move(anthill, line[i++]));
	append_to_movelist(&anthill->movelist, make_movelist_item(moves));
}

t_anthill	*get_infos(void)
{
	char		*line;
	int			line_type;
	t_anthill	*anthill;
	bool		next_start;
	bool		next_end;

	INIT_INFO;
	while (get_next_line(0, &line) > 0)
	{
		line_type = identify_line(line);
		if (line_type == IDENT && ft_strchr(line, 'e'))
			next_end = true;
		else if (line_type == IDENT && ft_strchr(line, 's'))
			next_start = true;
		else if (line_type == ROOM)
			assign_room(anthill, line, &next_start, &next_end);
		else if (line_type == LINK)
			assign_link(anthill, line);
		else if (line_type == ANT_COUNT)
			assign_ants(anthill, line);
		else if (line_type == MOVE)
			assign_move(anthill, line);
		free(line);
	}
	return (anthill);
}
