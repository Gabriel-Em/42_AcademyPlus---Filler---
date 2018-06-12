/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpop <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 19:00:33 by gpop              #+#    #+#             */
/*   Updated: 2018/06/08 01:42:07 by gpop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input_parser.h"
#include "output_parser.h"

int	main(void)
{
	BOOL	player_number;
	t_map	*map;
	t_piece	*piece;

	player_number = get_player_number();
	if (player_number == ERROR)
	{
		ft_putendl(ERROR_MESSAGE);
		return (EXIT_FAILURE);
	}
	while ((map = get_map()))
	{
		if (!(piece = get_piece()))
			break ;
		generate_output(player_number, map, piece);
		destroy_map(&map, map->size.height);
		destroy_piece(&piece, piece->size.height);
	}
	return (EXIT_SUCCESS);
}
