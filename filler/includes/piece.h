/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpop <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 01:22:22 by gpop              #+#    #+#             */
/*   Updated: 2018/06/05 01:25:59 by gpop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIECE_H
# define PIECE_H

# include "libft.h"
# include "filler_objects.h"

typedef struct	s_piece
{
	t_size		size;
	char		**piece;
}				t_piece;

# define HASPIECECOORD(X) ft_strstr((X), "Piece") != NULL

t_piece			*read_piece(void);
void			destroy_piece(t_piece **piece, int successful_lines);

#endif
