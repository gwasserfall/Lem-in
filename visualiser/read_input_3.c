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

void		move(t_path **callback, t_path *path, t_room *from, t_room *to)
{
	int i;

	i = 0;
	if (from)
		append_path(path, from);
	if (to && to->is_end)
		*callback = path;
	if (*callback)
		return ;
	while (i < to->link_count)
	{
		if (!(visited(path, to->links[i])))
			move(callback, path, to, to->links[i]);
		i++;
	}
}
