/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpop <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 00:52:54 by gpop              #+#    #+#             */
/*   Updated: 2018/06/05 01:01:26 by gpop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_parser.h"

BOOL	get_player_number(void)
{
	char *line;

	line = NULL;
	get_next_line(0, &line);
	if (!line)
		return (ERROR);
	if (HASPLAYERINFO(line))
	{
		if (ISPLAYER1(line))
		{
			ft_strdel(&line);
			return (P1);
		}
		else if (ISPLAYER2(line))
		{
			ft_strdel(&line);
			return (P2);
		}
	}
	return (ERROR);
}

t_map	*get_map(void)
{
	return (read_map());
}

t_piece	*get_piece(void)
{
	return (read_piece());
}
