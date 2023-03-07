/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_key.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 03:18:24 by ebakchic          #+#    #+#             */
/*   Updated: 2023/03/07 03:45:32 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_move(int i, int x, int y, t_list *s)
{
    (void)i;
    s->xc = x;
    s->yc = y;
    ft_fill_map(s);
	// ft_put_pixel(s);
}

int	ft_manage_key(int k, t_list *s)
{
    printf("k = %d\n", k);
	if (k == 53)
		exit(EXIT_SUCCESS);
	if (k == 13)
		ft_move(0, s->xc, s->yc - 1, s);
	if (k == 1)
		ft_move(1, s->xc, s->yc + 1, s);
	if (k == 2)
		ft_move(2, s->xc + 1, s->yc, s);
	if (k == 0)
		ft_move(3, s->xc - 1, s->yc, s);
	return (0);
}