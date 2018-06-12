/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler_objects.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpop <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 01:21:58 by gpop              #+#    #+#             */
/*   Updated: 2018/06/05 01:28:21 by gpop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_OBJECTS_H
# define FILLER_OBJECTS_H

typedef struct		s_size
{
	int				width;
	int				height;
}					t_size;

typedef struct		s_coord
{
	int				i;
	int				j;
	int				score;
}					t_coord;

# define BOOL   unsigned char

BOOL g_p_number;

# define P1                 1
# define P2                 2

# define TRUE               1
# define FALSE              0
# define ERROR              99

# define GNL_ERROR          -1
# define GNL_EMPTY_LINE     0

# define IS_PIECE_BODY(X) ((X) == '*')
# define IS_P1PIECE(X) ((X) == 'O' || (X) == 'o')
# define IS_P2PIECE(X) ((X) == 'X' || (X) == 'x')
# define IS_P1(X) ((X) == P1)
# define IS_P2(X) ((X) == P2)

# define PLAYERNUMBER g_p_number

# define OWN_O_PIECE(X) (IS_P1(PLAYERNUMBER) && IS_P1PIECE(X))
# define OWN_X_PIECE(X) (IS_P2(PLAYERNUMBER) && IS_P2PIECE(X))
# define OPP_O_PIECE(X) (IS_P2(PLAYERNUMBER) && IS_P1PIECE(X))
# define OPP_X_PIECE(X) (IS_P1(PLAYERNUMBER) && IS_P2PIECE(X))

# define OWN_PIECE(X) (OWN_O_PIECE(X) || OWN_X_PIECE(X))
# define OPP_PIECE(X) (OPP_O_PIECE(X) || OPP_X_PIECE(X))

# define ERROR_MESSAGE "Bad player info"

#endif
