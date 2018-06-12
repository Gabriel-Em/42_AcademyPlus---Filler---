/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpop <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 19:00:33 by gpop              #+#    #+#             */
/*   Updated: 2018/06/08 04:31:37 by gpop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_parser.h"
#include "drawing.h"

static void	scale_to_display(t_map *map)
{
	SQUARE_SIZE = MAX_SQUARE_SIZE;
	while (SQUARE_SIZE * map->size.width + BORDER_LEFT + BORDER_RIGHT >
			MAX_WIDTH
		|| SQUARE_SIZE * map->size.height + BORDER_TOP + BORDER_BOTTOM >
			MAX_HEIGHT)
		SQUARE_SIZE--;
	if (SQUARE_SIZE < MIN_SQUARE_SIZE)
		SQUARE_SIZE = MIN_SQUARE_SIZE;
	MAP_HEIGHT = map->size.height * SQUARE_SIZE;
	MAP_WIDTH = map->size.width * SQUARE_SIZE;
	WINDOW_HEIGHT = BORDER_TOP + MAP_HEIGHT + BORDER_BOTTOM;
	WINDOW_WIDTH = BORDER_LEFT + MAP_WIDTH + BORDER_RIGHT;
}

int			main(void)
{
	t_map	*map;
	char	*line;

	GAME_OVER = FALSE;
	P1_SCORE = 0;
	P2_SCORE = 0;
	get_player_names();
	if (get_type_of_input(&line) != TYPE_MAP)
		return (EXIT_FAILURE);
	map = read_map(line);
	scale_to_display(map);
	MLX = mlx_init();
	WINDOW = mlx_new_window(MLX, WINDOW_WIDTH, WINDOW_HEIGHT, TITLE);
	draw_map_grid(map);
	draw_player_names();
	draw_initial_player_positions(map);
	mlx_loop_hook(MLX, redraw, (void*)0);
	mlx_loop(MLX);
	return (EXIT_SUCCESS);
}
