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

t_pathlist *new_path_list(t_path *path)
{
	t_pathlist *pathlist;

	if (!(pathlist = malloc(sizeof(t_pathlist))))
		return (NULL);
	pathlist->next = NULL;
	pathlist->valid = true;
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

void	populate_pathlist(t_anthill *a)
{
	t_path *path;
	
	graph_traverse(a);
	while ((path = get_shortest_path(a, a->end)))
	{
		append_pathlist_item(a, path);
		graph_traverse(a);
	}
}

int	pathcount(t_anthill *hill)
{
	t_pathlist *paths;
	int			count;

	paths = hill->paths;
	count = 0;
	while (paths)
	{
		if (paths->valid)
			count++;
		paths = paths->next;
	}
	return count;
}

int		main(void)
{
	t_anthill	*anthill;
	t_data		*data;

	data = read_stdin_to_data();
	anthill = build_anthill(&data);
	if (!anthill->start || !anthill->end)
		print_start_end_error();
	populate_pathlist(anthill);
	check_start_end_path(&anthill);
	if (pathcount(anthill) > 0)
	{
		display_input_and_free(data);
		create_colony(anthill);		
		optimise_paths(anthill);
		create_move_list(anthill);
		print_move_list(anthill->moves);
	}
	else
		ft_putendl(RED "Error" RESET " : No valid path");
	return (0);
}