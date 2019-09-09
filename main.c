/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <ayano@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 10:25:54 by ayano             #+#    #+#             */
/*   Updated: 2019/09/09 15:18:38 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int main()
{
	t_anthill	*anthill;
	t_data		*data;

	data = init_data();
	read_into_data(&data);
	anthill = build_anthill(&data);
	if (anthill->start == NULL || anthill->end == NULL)
		print_start_end_error();
	index_rooms(&anthill);
	display_input(&data);
	// display_output(&anthill);
	free_data(&data);
	t_link	*current;

	current = anthill->connectors;
	while (current)
	{
		ft_putendl(current->from->name);
		ft_putendl(current->to->name);
		ft_putchar('\n');
		current = current->next;
	}
	return (1);
}
