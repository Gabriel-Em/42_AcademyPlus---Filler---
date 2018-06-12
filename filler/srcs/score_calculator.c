/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   score_calculator.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpop <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 01:02:29 by gpop              #+#    #+#             */
/*   Updated: 2018/06/08 02:17:43 by gpop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "score_calculator.h"

static int	compute_manhattan_distance(t_map *map, int i, int j)
{
	int ii;
	int jj;
	int min_distance;

	min_distance = ft_max(map->size.height, map->size.width);
	ii = -1;
	while (++ii < map->size.height)
	{
		jj = -1;
		while (++jj < map->size.width)
			if ((ii != i || jj != j) && OPP_PIECE(map->board[ii][jj]))
				if (ft_abs(i - ii) + ft_abs(j - jj) < min_distance)
					min_distance = ft_abs(i - ii) + ft_abs(j - jj);
	}
	return (min_distance);
}

static void	calculate_adjacent_positions_score(t_map *map, t_coord *piece_info,
		int map_i, int map_j)
{
	if (map_j + piece_info->j > 0
			&& OPP_PIECE(map->board[map_i + piece_info->i][map_j
				+ piece_info->j - 1]))
		piece_info->score += 25;
	if (map_j + piece_info->j < map->size.width - 1
			&& OPP_PIECE(map->board[map_i + piece_info->i][map_j
				+ piece_info->j + 1]))
		piece_info->score += 25;
	if (map_i + piece_info->i > 0
			&& OPP_PIECE(map->board[map_i + piece_info->i - 1][map_j
				+ piece_info->j]))
		piece_info->score += 25;
	if (map_i + piece_info->i < map->size.height - 1
			&& OPP_PIECE(map->board[map_i + piece_info->i + 1][map_j
				+ piece_info->j]))
		piece_info->score += 25;
}

int			compute_score(t_map *map, t_piece *piece, int i, int j)
{
	t_coord	piece_info;
	int		min_distance;
	int		manhattan_distance;

	piece_info.score = 0;
	piece_info.i = -1;
	min_distance = ft_max(map->size.height, map->size.width) * 2;
	while (++(piece_info.i) < piece->size.height)
	{
		piece_info.j = -1;
		while (++(piece_info.j) < piece->size.width)
		{
			if (IS_PIECE_BODY(piece->piece[piece_info.i][piece_info.j])
				&& !OWN_PIECE(map->board[i + piece_info.i][j + piece_info.j]))
			{
				calculate_adjacent_positions_score(map, &piece_info, i, j);
				manhattan_distance = compute_manhattan_distance(map,
						i + piece_info.i, j + piece_info.j);
				if (manhattan_distance < min_distance)
					min_distance = manhattan_distance;
			}
		}
	}
	return (piece_info.score + ft_max(map->size.height, map->size.width) * 2
			- min_distance);
}
