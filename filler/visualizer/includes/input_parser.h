/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parser.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpop <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 01:22:03 by gpop              #+#    #+#             */
/*   Updated: 2018/06/07 23:56:16 by gpop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_PARSER_H
# define INPUT_PARSER_H

# include "libft.h"
# include "map.h"
# include "visualizer_objects.h"

# define HASPLAYERINFO(X)   (ft_strstr((X), "$$$ exec") != NULL)
# define ISPLAYER1(X)       (ft_strstr((X), "p1") != NULL)
# define ISPLAYER2(X)       (ft_strstr((X), "p2") != NULL)
# define HASPIECECOORD(X)   (ft_strstr((X), "Piece") != NULL)
# define HASGOT(X)          (ft_strstr((X), "got") != NULL)
# define HASEQUAL(X)        (ft_strstr((X), "==") != NULL)

# define TYPE_MAP           1
# define TYPE_PIECE         2
# define TYPE_GOT           3
# define TYPE_EQUAL         4
# define TYPE_ERROR         5

t_map	*get_map(char *line);
void	get_player_names(void);
void	skip_piece(char *line);
int		get_type_of_input();

#endif
