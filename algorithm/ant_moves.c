/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ant_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 09:19:39 by ayano             #+#    #+#             */
/*   Updated: 2019/11/05 09:19:49 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

t_moves	*make_move(t_ant *ant, t_room *from, t_room *to)
{
	t_moves *move;

	if (!(move = malloc(sizeof(t_moves))))
		return (NULL);
	move->next = NULL;
	move->from = from;
	move->to = to;
	move->ant = ant;
	return (move);
}

void	append_move(t_moves **start, t_moves *new)
{
	t_moves *moves;

	moves = *start;
	if (!moves)
		*start = new;
	else
	{
		while (moves->next)
			moves = moves->next;
		moves->next = new;
	}
}

void	print_move_list(t_moves *moves)
{
	while (moves)
	{
		if (!moves->ant)
			ft_putstr("\n");
		else
		{
			ft_putchar('L');
			ft_putstr(moves->ant->name);
			ft_putchar('-');
			ft_putstr(moves->to->name);
			if (moves->next && moves->next->ant)
				ft_putchar(' ');
		}
		moves = moves->next;
	}
}
