/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpop <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 23:53:43 by gpop              #+#    #+#             */
/*   Updated: 2018/06/08 00:20:18 by gpop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "drawing.h"

void	draw_map_grid(void)
{
	POINT from;
	POINT to;

	from.x = MAP_X;
	from.y = MAP_Y;
	to.x = MAP_X + MAP_WIDTH;
	to.y = MAP_Y;
	while (from.y <= MAP_Y + MAP_HEIGHT)
	{
		draw_horizontal_line(from, to, COLOR_LIGHT_YELLOW);
		from.y += SQUARE_SIZE;
	}
	from.y = MAP_Y;
	to.x = MAP_X;
	to.y = MAP_Y + MAP_HEIGHT;
	while (from.x <= MAP_X + MAP_WIDTH)
	{
		draw_vertical_line(from, to, COLOR_LIGHT_YELLOW);
		from.x += SQUARE_SIZE;
	}
}

void	draw_initial_player_positions(t_map *map)
{
	int		i;
	int		j;
	POINT	square_coord;

	i = -1;
	while (++i < map->size.height)
	{
		j = -1;
		while (++j < map->size.width)
		{
			if (!IS_EMPTY(map->board[i][j]))
			{
				square_coord.x = MAP_J_TO_WIN_X(j);
				square_coord.y = MAP_I_TO_WIN_Y(i);
				if (IS_P1PIECE(map->board[i][j]))
					fill_square(square_coord, P1_COLOR);
				else
					fill_square(square_coord, P2_COLOR);
			}
		}
	}
}

void	update_square(t_map *map, int i, int j, int *player_number)
{
	POINT square;

	if (IS_P1_SMALL_PIECE(map->board[i][j])
			|| IS_P2_SMALL_PIECE(map->board[i][j]))
	{
		square.x = MAP_J_TO_WIN_X(j);
		square.y = MAP_I_TO_WIN_Y(i);
		if (IS_P1_SMALL_PIECE(map->board[i][j]))
		{
			fill_square(square, P1_COLOR);
			*player_number = P1;
		}
		else
		{
			fill_square(square, P2_COLOR);
			*player_number = P2;
		}
	}
}

void	update_window(t_map *map)
{
	int i;
	int j;
	int player_number;

	player_number = ERROR;
	i = -1;
	while (++i < map->size.height)
	{
		j = -1;
		while (++j < map->size.width)
			update_square(map, i, j, &player_number);
	}
	if (IS_PLAYER1(player_number))
	{
		P1_SCORE++;
		clear_player_score(P1);
		draw_player_score(P1);
	}
	else if (IS_PLAYER2(player_number))
	{
		P2_SCORE++;
		clear_player_score(P2);
		draw_player_score(P2);
	}
}

int		redraw(void *param)
{
	t_map	*map;
	char	*line;
	int		type;

	(void)param;
	if (IS_GAME_OVER)
		return (EXIT_SUCCESS);
	type = get_type_of_input(&line);
	if (type == TYPE_MAP)
	{
		map = read_map(line);
		update_window(map);
		destroy_map(&map, map->size.height);
	}
	else if (type == TYPE_PIECE)
		skip_piece(line);
	else if (type == TYPE_EQUAL)
	{
		if (P1_SCORE > P2_SCORE)
			mlx_string_put(MLX, WINDOW, END_MSG_X, END_MSG_Y, P1_COLOR, P1_END);
		else
			mlx_string_put(MLX, WINDOW, END_MSG_X, END_MSG_Y, P2_COLOR, P2_END);
		GAME_OVER = TRUE;
	}
	return (EXIT_SUCCESS);
}
