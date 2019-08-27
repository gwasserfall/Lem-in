/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_links.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 12:16:50 by ayano             #+#    #+#             */
/*   Updated: 2019/08/27 12:16:51 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		verify_links(char *line)
{
	if (!line || (word_count(line, '-', 0) != 2))
		print_error_link();


}

/*
** Seriousely bro, it just prints an error message.
*/
void		print_error_link(void)
{
	ft_putstr(RED);
	ft_putendl("Link is not formatted correctly.");
	ft_putstr(RESET);
	exit(1);
}