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

void print_path(t_path *path)
{
	while (path)
	{
		printf("%s ->", path->room->name);
		path = path->next;
	}
	printf("\n");
}

t_pathlist *new_path_list(t_path *path)
{
	t_pathlist *pathlist;

	if (!(pathlist = malloc(sizeof(t_pathlist))))
		return (NULL);
	pathlist->next = NULL;
	pathlist->path = path;
	return (pathlist);
}

void append_pathlist_item(t_anthill *a, t_path *path)
{
	t_pathlist *head;

	head = a->paths;
	if (head)
	{
		while (head->next)
			head = head->next;
		head->next = new_path_list(path);
	}
	else
		a->paths = new_path_list(path);
}


bool	populate_pathlist(t_anthill *a)
{
	t_path *path;
	
	graph_traverse(a);

	while ((path = get_shortest_path(a)))
		print_path(path);
	return (true);
}

int		main(void)
{
	t_anthill	*anthill;
	t_data		*data;

	data = read_stdin_to_data();


	anthill = build_anthill(&data);



	// Free data



	if (!anthill->start || !anthill->end)
		print_start_end_error();

	populate_pathlist(anthill);

	index_rooms(&anthill);


	// Run algo here 
	while ((set_levels(anthill)))
		anthill->nb_paths++;
	
	// Create paths

		// If no paths free everything and exit

	// optimise paths
		// Remove any path that is longer than the number of ants
			// Only if there are more than 2 paths
	
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
