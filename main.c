/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <ayano@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 10:25:54 by ayano             #+#    #+#             */
/*   Updated: 2019/11/05 09:15:53 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

int		main(void)
{
	t_anthill	*anthill;
	t_data		*data;

	// Satisfied!
	data = read_stdin_to_data();

	anthill = build_anthill(&data);

	if (anthill->start == NULL || anthill->end == NULL)
		print_start_end_error();





	index_rooms(&anthill);
	while ((set_levels(anthill)))
		anthill->nb_paths++;
	
	
	
	// while(1);
	
	
	check_start_end_path(&anthill);
	
	
	if (anthill->nb_paths)
	{
		display_input_and_free(data);


		create_colony(anthill);
		set_path_length(anthill);
		optimise_paths(&anthill);
		create_move_list(anthill);
		print_move_list(anthill->moves);
	}
	else
		ft_putendl(RED "Error :" RESET " No valid path");
	
	return (1);
}
