/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_parser.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpop <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 01:22:16 by gpop              #+#    #+#             */
/*   Updated: 2018/06/05 01:24:00 by gpop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OUTPUT_PARSER_H
# define OUTPUT_PARSER_H

# include "libft.h"
# include "map.h"
# include "piece.h"
# include "filler_objects.h"
# include "score_calculator.h"

void	generate_output(BOOL player_number, t_map *map, t_piece *piece);

#endif
