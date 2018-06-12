/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score_calculator.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpop <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 01:22:30 by gpop              #+#    #+#             */
/*   Updated: 2018/06/05 01:22:34 by gpop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCORE_CALCULATOR_H
# define SCORE_CALCULATOR_H

# include "filler_objects.h"
# include "map.h"
# include "piece.h"
# include "libft.h"

int compute_score(t_map *map, t_piece *piece, int i, int j);

#endif
