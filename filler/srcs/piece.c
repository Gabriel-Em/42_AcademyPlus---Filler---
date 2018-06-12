/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpop <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 01:02:18 by gpop              #+#    #+#             */
/*   Updated: 2018/06/08 03:00:12 by gpop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "piece.h"

void			destroy_piece(t_piece **piece, int successful_lines)
{
	int i;

	if (!piece || !(*piece))
		return ;
	i = 0;
	if ((*piece)->piece)
	{
		while (i < successful_lines)
		{
			if ((*piece)->piece[i])
				free((*piece)->piece[i]);
			i++;
		}
		free((*piece)->piece);
	}
	free(*piece);
	*piece = NULL;
}

static t_piece	*create_piece(t_size size)
{
	t_piece	*piece;
	int		i;

	if (!(piece = (t_piece*)malloc(sizeof(t_piece))))
		return (NULL);
	piece->size.height = size.height;
	piece->size.width = size.width;
	if (!(piece->piece = (char**)malloc(sizeof(char*) * size.height)))
	{
		free(piece);
		return (NULL);
	}
	i = 0;
	while (i < size.height)
	{
		if (!(piece->piece[i] = ft_strnew(size.width)))
		{
			destroy_piece(&piece, i);
			return (NULL);
		}
		i++;
	}
	return (piece);
}

static void		read_piece_lines(t_piece *piece)
{
	int		i;
	char	*line;

	line = NULL;
	i = 0;
	while (i < piece->size.height)
	{
		get_next_line(0, &line);
		if (line)
		{
			if ((int)ft_strlen(line) == piece->size.width)
				ft_strcpy(piece->piece[i], line);
			ft_strdel(&line);
		}
		i++;
	}
}

static t_size	read_coords(char *line)
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

t_piece			*read_piece(void)
{
	t_piece	*piece;
	char	*line;
	int		result;

	result = get_next_line(0, &line);
	if (result == GNL_EMPTY_LINE || result == GNL_ERROR)
		return (NULL);
	if (HASPIECECOORD(line))
	{
		piece = create_piece(read_coords(line));
		if (line)
			ft_strdel(&line);
		read_piece_lines(piece);
		return (piece);
	}
	else
		return (NULL);
}
