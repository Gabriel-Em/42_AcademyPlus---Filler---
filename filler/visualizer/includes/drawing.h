/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpop <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 23:53:09 by gpop              #+#    #+#             */
/*   Updated: 2018/06/08 04:30:41 by gpop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAWING_H
# define DRAWING_H

# include "mlx.h"
# include "visualizer_objects.h"
# include "map.h"
# include "input_parser.h"

void							*g_mlx_ptr;
void							*g_win_ptr;

SIZE							g_map_size;
POINT							g_map_coord;
SIZE							g_window_size;
int								g_player1_score;
int								g_player2_score;
int								g_square_size;

# define MLX                    g_mlx_ptr
# define WINDOW                 g_win_ptr

# define BORDER_TOP             70
# define BORDER_BOTTOM          100
# define BORDER_LEFT            23
# define BORDER_RIGHT           23

# define MIN_SQUARE_SIZE        3
# define MAX_SQUARE_SIZE        32

# define OS_TITLE_BAR_HEIGHT	23
# define MAX_HEIGHT 	        1080 - OS_TITLE_BAR_HEIGHT
# define MAX_WIDTH				1920

# define SQUARE_SIZE            g_square_size

# define WINDOW_SIZE            g_window_size
# define WINDOW_HEIGHT          WINDOW_SIZE.height
# define WINDOW_WIDTH           WINDOW_SIZE.width

# define MAP_SIZE               g_map_size
# define MAP_HEIGHT             MAP_SIZE.height
# define MAP_WIDTH              MAP_SIZE.width

# define P1_SCORE               g_player1_score
# define P2_SCORE               g_player2_score

# define MAP_X                  BORDER_LEFT
# define MAP_Y                  BORDER_TOP

# define COLOR_LIGHT_YELLOW     0xffffe0
# define COLOR_GREEN_YELLOW     0xadff2f
# define COLOR_SKY_BLUE         0x7ec0ee
# define COLOR_BLACK            0x0

# define P1_COLOR               COLOR_GREEN_YELLOW
# define P2_COLOR               COLOR_SKY_BLUE

# define TITLE                  "> visualizer <"
# define P1_TITLE               "P1:"
# define P2_TITLE               "P2:"

# define P1_TITLE_X             BORDER_LEFT
# define P1_TITLE_Y             WINDOW_HEIGHT - BORDER_BOTTOM + 23
# define P2_TITLE_X             BORDER_LEFT
# define P2_TITLE_Y             P1_TITLE_Y + 32

# define P1_NAME_X              P1_TITLE_X + 35
# define P1_NAME_Y              P1_TITLE_Y
# define P2_NAME_X              P2_TITLE_X + 35
# define P2_NAME_Y              P2_TITLE_Y

# define P1_SCORE_X             WINDOW_WIDTH - BORDER_RIGHT - 50
# define P1_SCORE_Y             P1_TITLE_Y
# define P2_SCORE_X             P1_SCORE_X
# define P2_SCORE_Y             P2_TITLE_Y

# define SCORE_WIDTH            50
# define SCORE_HEIGHT           20

# define MAP_J_TO_WIN_X(X)      MAP_X + (X) * SQUARE_SIZE
# define MAP_I_TO_WIN_Y(X)      MAP_Y + (X) * SQUARE_SIZE

# define END_MSG_X          	WINDOW_WIDTH / 2 - 60
# define END_MSG_Y          	23

# define P1_END                "Player 1 WINS"
# define P2_END                "Player 2 WINS"

void							draw_map_grid();
void							draw_player_names(void);
void							draw_initial_player_positions(t_map *map);
void							draw_player_score(int player_number);
int								redraw(void *param);
void							draw_horizontal_line(POINT from, POINT to,
		int color);
void							draw_vertical_line(POINT from, POINT to,
		int color);
void							draw_player_names(void);
void							draw_player_score(int player_number);
void							clear_player_score(int player_number);
void							fill_square(POINT square_coord, int color);

#endif
