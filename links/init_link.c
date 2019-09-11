/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_link.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <ayano@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 14:31:16 by ayano             #+#    #+#             */
/*   Updated: 2019/09/09 15:24:23 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

/*
** Initialize the link struct.
*/
t_link      *init_link(void)
{
	t_link	*new;

	if (!(new = malloc(sizeof(t_link))))
		return (NULL);
	new->from = NULL;
	new->next = NULL;
	new->to = NULL;
	return (new);
}

/*
** MEH, Glens function idk what it does, pretty sure its useless. it replaces the above function which does nothing :D
*/
t_link *make_link(t_room *from, t_room *to)
{
	t_link *new;

	if (!(new = malloc(sizeof(t_link))))
		return (NULL);
	new->from = from;
	new->to = to;
	new->next = NULL;
	return new;
}

/*
** adds the node new to the end of the linked list start.
*/
void append_link(t_link **start, t_link *new)
{
	t_link *link;

	link = *start;
	if (!link)
		*start = new;
	else
	{
		while (link->next)
			link = link->next;
		link->next = new;
	}
}

// void	assign_link(t_anthill *ah, char *str)
// {
// 	char **line;
// 	t_room *from;
// 	t_room *to;
// 	t_link *link;
// 	t_link *cursor;

// 	line = ft_strsplit(str, '-');
// 	from = get_room(ah, line[0]);
// 	to = get_room(ah, line[1]);
	
// 	link = malloc(sizeof(t_link));
// 	link->to = to;
// 	link->from = from;
// 	link->next = NULL;
// 	cursor = ah->connectors;
// 	if (!cursor)
// 		ah->connectors = link;
// 	else
// 	{
// 		while (cursor->next)
// 			cursor = cursor->next;
// 		cursor->next = link;
// 	}
// }