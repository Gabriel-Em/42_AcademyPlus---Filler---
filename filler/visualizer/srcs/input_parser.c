/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpop <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 00:52:54 by gpop              #+#    #+#             */
/*   Updated: 2018/06/08 00:22:40 by gpop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_parser.h"

char			*parse_player_name(char *line)
{
	int		i;
	int		from;
	int		len;
	char	*str;

	i = 0;
	while (line[i] && line[i] != '[')
		i++;
	i++;
	from = i;
	len = 0;
	while (line[i] && line[i] != ']')
	{
		if (line[i] == '/')
		{
			from = i + 1;
			len = -1;
		}
		i++;
		len++;
	}
	if (!(str = ft_strnew(len)))
		return (NULL);
	str = ft_strncpy(str, line + from, len);
	return (str);
}

void			get_player_names(void)
{
	char *line;

	line = NULL;
	while (get_next_line(0, &line))
	{
		if (line)
		{
			if (HASPLAYERINFO(line))
			{
				if (ISPLAYER1(line))
					PLAYER1NAME = parse_player_name(line);
				else if (ISPLAYER2(line))
				{
					PLAYER2NAME = parse_player_name(line);
					ft_strdel(&line);
					return ;
				}
			}
			ft_strdel(&line);
		}
	}
}

static t_size	read_piece_coords(char *line)
{
	int		i;
	t_size	size;

	i = 0;
	while (line[i] && !ft_isdigit(line[i]))
		i++;
	size.height = ft_atoi(line + i);
	while (line[i] && ft_isdigit(line[i]))
		i++;
	while (line[i] && !ft_isdigit(line[i]))
		i++;
	size.width = ft_atoi(line + i);
	return (size);
}

void			skip_piece(char *line)
{
	SIZE	size;
	int		i;

	size = read_piece_coords(line);
	if (line)
		ft_strdel(&line);
	i = 0;
	while (i < size.height)
	{
		get_next_line(0, &line);
		if (line)
			ft_strdel(&line);
		i++;
	}
}

int				get_type_of_input(char **line)
{
	int		result;

	result = get_next_line(0, line);
	if (result == GNL_EMPTY_LINE || result == GNL_ERROR)
		return (FALSE);
	if (line)
	{
		if (HASMAPCOORD(*line))
			result = TYPE_MAP;
		else if (HASPIECECOORD(*line))
			result = TYPE_PIECE;
		else if (HASGOT(*line))
			result = TYPE_GOT;
		else if (HASEQUAL(*line))
			result = TYPE_EQUAL;
		return (result);
	}
	return (TYPE_ERROR);
}
