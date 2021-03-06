/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swapstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpop <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 18:03:28 by gpop              #+#    #+#             */
/*   Updated: 2018/02/09 18:05:43 by gpop             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swapstr(char **str1, char **str2)
{
	char *ptr;

	ptr = *str1;
	*str1 = *str2;
	*str2 = ptr;
}
