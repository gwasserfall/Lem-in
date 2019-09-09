/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 10:28:40 by ayano             #+#    #+#             */
/*   Updated: 2019/09/05 10:28:41 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
** Displays all the data we have read in if there are no errors
*/
void		display_input(t_data **data)
{
	t_data	*current;

	current = (*data);
	while (current->next)
	{
		ft_putendl(current->line);
		current = current->next;
	}
}