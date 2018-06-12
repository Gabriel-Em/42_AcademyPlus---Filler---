/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpop <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 01:01:46 by gpop              #+#    #+#             */
/*   Updated: 2018/06/08 03:32:11 by gpop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void			destroy_map(t_map **map, int successful_lines)
{
	int i;

	i = 0;
	while (i < successful_lines)
		free((*map)->board[i++]);
	free((*map)->board);
	free(*map);
	*map = NULL;
}

static t_map	*create_map(t_size size)
{
	t_map	*map;
	int		i;

	if (!(map = (t_map*)malloc(sizeof(t_map))))
		return (NULL);
	map->size.height = size.height;
	map->size.width = size.width;
	if (!(map->board = (char**)malloc(sizeof(char*) * size.height)))
	{
		free(map);
		return (NULL);
	}
	i = 0;
	while (i < size.height)
	{
		if (!(map->board[i] = ft_strnew(size.width)))
		{
			destroy_map(&map, i);
			return (NULL);
		}
		i++;
	}
	return (map);
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

static void		read_map_lines(t_map *map)
{
	int		i;
	int		j;
	char	*line;

	get_next_line(0, &line);
	if (line)
		free(line);
	i = 0;
	while (i < map->size.height)
	{
		get_next_line(0, &line);
		if (line)
		{
			j = 0;
			while (line[j] && !ft_isspace(line[j]))
				j++;
			if ((int)ft_strlen(line + j + 1) <= map->size.width)
				ft_strcpy(map->board[i], line + j + 1);
			free(line);
		}
		i++;
	}
}

t_map			*read_map(char *line)
{
	t_map	*map;

	map = create_map(read_coords(line));
	if (line)
		ft_strdel(&line);
	read_map_lines(map);
	return (map);
}
