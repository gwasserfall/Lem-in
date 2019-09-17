/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <ayano@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 10:25:54 by ayano             #+#    #+#             */
/*   Updated: 2019/09/09 15:36:07 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

int main(void)
{
	t_anthill	*anthill;
	t_data		*data;

	data = NULL;
	read_into_data(&data);
	anthill = build_anthill(&data);
	if (anthill->start == NULL || anthill->end == NULL)
		print_start_end_error();
	index_rooms(&anthill);
	display_input(&data);
	while ((set_levels(anthill)))
		anthill->nb_paths++;
	if (anthill->nb_paths)
	{
		create_colony(anthill);
		optimise_paths(&anthill);
		create_move_list(anthill);
		print_move_list(anthill->moves);
	}
	free_data(&data);
	return (1);
}
