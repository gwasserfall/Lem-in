/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_data_start_end.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 11:07:50 by ayano             #+#    #+#             */
/*   Updated: 2019/09/04 11:07:51 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void        add_start_data(char *line, t_anthill **anthill)
{	
    add_data_start(line, anthill);
	free(line);
	get_next_line(0, &line);
}

void        add_end_data(char *line, t_anthill **anthill)
{
 		add_data_end(line, anthill);
		free(line);
		get_next_line(0, &line);
}