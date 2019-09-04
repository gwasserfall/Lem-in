/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_end_route.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 13:28:58 by ayano             #+#    #+#             */
/*   Updated: 2019/08/30 13:28:59 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int		create_map(t_anthill **anthill)
{
	char	**map;
	int		i;
	int 	j;

	i = 0;
	map = (char **)malloc(sizeof(char *) * ((*anthill)->room_count + 1));
	map[(*anthill)->room_count + 1] = 0;
	while (i <= (*anthill)->room_count)
	{
		map[i] = ft_strnew((*anthill)->room_count + 1);
		i++;
	}
	i = 0;
	while (i <= (*anthill)->room_count)
	{
		j = 0;
		while (j <= (*anthill)->room_count)
		{
			map[i][j] = 'A';
			j++;
		}
		i++;
	}
	i = 0;
	while (i <= (*anthill)->room_count)
	{
		ft_putendl(map[i]);
		i++;
	}
	ft_putchar('\n');
	// map_links(map, anthill);
	return (1);
}

// void		map_links(char **map, t_anthill **anthill)
// {
// 	t_room	*current;
// 	int		room_index;
// 	int		room_link_index;
// 	int		room_link_count;

// 	current = (*anthill)->linear;
// 	room_index = current->index;
// 	room_link_index = current->links[room_link_count]->index;
// 	room_link_count = 0;
// }