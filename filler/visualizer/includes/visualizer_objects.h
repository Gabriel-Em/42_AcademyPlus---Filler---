/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer_objects.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpop <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 23:53:33 by gpop              #+#    #+#             */
/*   Updated: 2018/06/07 23:55:57 by gpop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALIZER_OBJECTS_H
# define VISUALIZER_OBJECTS_H

typedef struct		s_size
{
	int				width;
	int				height;
}					t_size;

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

# define BOOL   unsigned char

char				*g_player1_name;
char				*g_player2_name;
BOOL				g_game_over;

# define GAME_OVER			 g_game_over

# define PLAYER1NAME		g_player1_name
# define PLAYER2NAME		g_player2_name

# define IS_PLAYER1(X)		((X) == 1)
# define IS_PLAYER2(X)		((X) == 2)

# define P1					1
# define P2					2

# define TRUE               1
# define FALSE              0
# define ERROR              99

# define IS_GAME_OVER		(GAME_OVER == TRUE)

# define GNL_ERROR			-1
# define GNL_EMPTY_LINE		0

# define IS_EMPTY(X)			((X) == '.')
# define IS_P1PIECE(X)			((X) == 'O' || (X) == 'o')
# define IS_P2PIECE(X)			((X) == 'X' || (X) == 'x')
# define IS_P1_SMALL_PIECE(X)	((X) == 'o')
# define IS_P2_SMALL_PIECE(X)	((X) == 'x')

# define POINT				t_point
# define SIZE				t_size

#endif
