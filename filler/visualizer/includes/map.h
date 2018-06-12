/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpop <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 01:22:10 by gpop              #+#    #+#             */
/*   Updated: 2018/06/05 01:23:17 by gpop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include "libft.h"
# include "visualizer_objects.h"

typedef struct		s_map
{
	t_size			size;
	char			**board;
}					t_map;

# define HASMAPCOORD(X) ft_strstr((X), "Plateau") != NULL

t_map				*read_map(char *line);
void				destroy_map(t_map **map, int successful_lines);

#endif
