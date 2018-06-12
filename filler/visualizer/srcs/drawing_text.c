/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_text.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpop <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 23:53:46 by gpop              #+#    #+#             */
/*   Updated: 2018/06/08 00:00:49 by gpop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "drawing.h"

void	draw_player_names(void)
{
	mlx_string_put(MLX, WINDOW, P1_TITLE_X, P1_TITLE_Y, P1_COLOR, P1_TITLE);
	mlx_string_put(MLX, WINDOW, P2_TITLE_X, P2_TITLE_Y, P2_COLOR, P2_TITLE);
	mlx_string_put(MLX, WINDOW, P1_NAME_X, P1_NAME_Y, P1_COLOR, PLAYER1NAME);
	mlx_string_put(MLX, WINDOW, P2_NAME_X, P2_NAME_Y, P2_COLOR, PLAYER2NAME);
}

void	draw_player_score(int player_number)
{
	if (IS_PLAYER1(player_number))
		mlx_string_put(MLX, WINDOW, P1_SCORE_X, P1_SCORE_Y, P1_COLOR,
				ft_itoa(P1_SCORE));
	else if (IS_PLAYER2(player_number))
		mlx_string_put(MLX, WINDOW, P2_SCORE_X, P2_SCORE_Y, P2_COLOR,
				ft_itoa(P2_SCORE));
}

void	clear_player_score(int player_number)
{
	POINT from;
	POINT to;

	if (IS_PLAYER1(player_number))
	{
		from.x = P1_SCORE_X;
		from.y = P1_SCORE_Y;
		to.x = P1_SCORE_X + SCORE_WIDTH;
		to.y = P1_SCORE_Y + SCORE_HEIGHT;
	}
	else
	{
		from.x = P2_SCORE_X;
		from.y = P2_SCORE_Y;
		to.x = P2_SCORE_X + SCORE_WIDTH;
		to.y = P2_SCORE_Y + SCORE_HEIGHT;
	}
	while (from.y <= to.y)
	{
		draw_horizontal_line(from, to, COLOR_BLACK);
		from.y++;
	}
}
