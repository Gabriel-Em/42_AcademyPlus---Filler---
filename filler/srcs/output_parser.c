/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpop <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 01:02:13 by gpop              #+#    #+#             */
/*   Updated: 2018/06/08 03:18:24 by gpop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "output_parser.h"

static BOOL	can_be_placed(t_map *map, t_piece *piece, int i, int j)
{
	int		i_;
	int		j_;
	BOOL	covered;

	covered = FALSE;
	i_ = -1;
	while (++i_ < piece->size.height)
	{
		j_ = -1;
		while (++j_ < piece->size.width)
			if (IS_PIECE_BODY(piece->piece[i_][j_]))
			{
				if (OWN_PIECE(map->board[i + i_][j + j_]))
				{
					if (covered)
						return (FALSE);
					else
						covered = TRUE;
				}
				else if (OPP_PIECE(map->board[i + i_][j + j_]))
					return (FALSE);
			}
	}
	return (covered);
}

void		look_for_best_place(t_map *map, t_piece *piece, t_coord *best_place)
{
	int		i;
	int		j;
	int		score;

	i = -1;
	while (++i < map->size.height - piece->size.height + 1)
	{
		j = -1;
		while (++j < map->size.width - piece->size.width + 1)
			if (can_be_placed(map, piece, i, j))
			{
				score = compute_score(map, piece, i, j);
				if (score > best_place->score)
				{
					best_place->score = score;
					best_place->i = i;
					best_place->j = j;
				}
			}
	}
}

static void	write_output(int i, int j)
{
	ft_putnbr(i);
	ft_putchar(' ');
	ft_putnbr(j);
	ft_putchar('\n');
}

void		generate_output(BOOL player_number, t_map *map, t_piece *piece)
{
	t_coord	best_place;

	best_place.i = 0;
	best_place.j = 0;
	best_place.score = -1;
	PLAYERNUMBER = player_number;
	look_for_best_place(map, piece, &best_place);
	write_output(best_place.i, best_place.j);
}
