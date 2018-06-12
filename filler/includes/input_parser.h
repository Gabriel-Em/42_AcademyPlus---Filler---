/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parser.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpop <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 01:22:03 by gpop              #+#    #+#             */
/*   Updated: 2018/06/05 01:22:52 by gpop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_PARSER_H
# define INPUT_PARSER_H

# include "libft.h"
# include "map.h"
# include "piece.h"
# include "filler_objects.h"

# define HASPLAYERINFO(X) ft_strstr((X), "$$$ exec") != NULL
# define ISPLAYER1(X) ft_strstr((X), "p1") != NULL
# define ISPLAYER2(X) ft_strstr((X), "p2") != NULL

BOOL	get_player_number(void);
t_map	*get_map(void);
t_piece	*get_piece(void);

#endif
