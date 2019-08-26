/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 16:19:36 by ayano             #+#    #+#             */
/*   Updated: 2019/08/26 16:19:37 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
** This will call all the error checking
** functions, these include:
**						   verify_start_and_end;
*/											
void		error_checks(void)
{
	verify_start_and_end();
	verify_ants();
}