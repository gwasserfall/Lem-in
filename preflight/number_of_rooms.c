/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_of_rooms.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 14:44:44 by ayano             #+#    #+#             */
/*   Updated: 2019/08/26 14:44:47 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
** This function will get the amount of rooms by checking each line for 3 words.
** (3 words for format of input means it must be a room with its co-ordinates).
** 
** Reads in a get next line loop and when it finds 3 words incriments
** room counter.
*/
int		get_nb_rooms(void)
{
	char	*line;
	int		nb_rooms;
	int		words;

	nb_rooms = 0;
	words = 0;
	while (get_next_line(0, &line))
	{
		if ((words = word_count(line, ' ', 0)) == 3)
			nb_rooms += 1;
		free(line);
	}
	return (nb_rooms);
}

/*
** This function will get the amount of words by deliminating by spaces.
**
** str : line variable read by get_next_line.
** delim : will always be a " ", used to seperate room number and
** 		   x & y co-orsinates.
** index : will always be 0 but needs to be passed so function has an
**		   exit condition.
*/
int		word_count(char *str, char delim, int index)
{
	int			count;

	if (!(str[index]))
		return (0);
	count = 0;
	while (str[index] == delim)
		index++;
	while (str[index] != '\0' && str[index] != delim)
	{
		index++;
		count = 1;
	}
	return (count + word_count(str, delim, index));
}