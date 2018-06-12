/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpop <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 23:53:50 by gpop              #+#    #+#             */
/*   Updated: 2018/06/08 00:01:33 by gpop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "drawing.h"

void	draw_horizontal_line(POINT from, POINT to, int color)
{
	while (from.x <= to.x)
	{
		mlx_pixel_put(MLX, WINDOW, from.x, from.y, color);
		from.x++;
	}
}

void	draw_vertical_line(POINT from, POINT to, int color)
{
	while (from.y <= to.y)
	{
		mlx_pixel_put(MLX, WINDOW, from.x, from.y, color);
		from.y++;
	}
}

void	fill_square(POINT square_coord, int color)
{
	POINT from;
	POINT to;

	from.x = square_coord.x + 1;
	from.y = square_coord.y + 1;
	to.x = square_coord.x + SQUARE_SIZE - 1;
	to.y = square_coord.y + 1;
	while (from.y < square_coord.y + SQUARE_SIZE)
	{
		draw_horizontal_line(from, to, color);
		from.y++;
		to.y++;
	}
}
