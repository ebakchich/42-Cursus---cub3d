/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_key.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 03:18:24 by ebakchic          #+#    #+#             */
/*   Updated: 2023/03/10 09:15:33 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_draw_ray(t_list *s, double ang)
{
	double	x;
	double	y;

	(void)ang;
	x = s->xc;
	y = s->yc;
	while (1)
	{
		mlx_pixel_put(s->mlx, s->win, (int)x, (int)y, 0xFFFFFF);
		x += cos(ang);
		y += sin(ang);
		if (s->map[(int)(y / 25)][(int)(x / 25)] == '1')
			break ;
	}
}

void	ft_move(int i, int x, int y, t_list *s)
{
	double	fov;
	double	k;

	fov = 1.04719755;
	k = fov / (25 * s->lenx);
	(void)i;
	if (s->map[(y + 3) / 25][(x + 3) / 25] == '1'
		|| s->map[(y - 3) / 25][(x - 3) / 25] == '1')
		return ;
	s->xc = x;
	s->yc = y;
	ft_fill_map(s);
	ft_put_player(s);
	ft_draw_ray(s, s->ang);
	while (fov / 2 > 0)
	{
		ft_draw_ray(s, s->ang + (fov / 2));
		ft_draw_ray(s, s->ang - (fov / 2));
		fov -= k;
	}
}

int	ft_manage_key(int k, t_list *s)
{
	if (k == 53)
		exit(EXIT_SUCCESS);
	if (k == 13)
		ft_move(0, s->xc + (5 * cos(s->ang)), s->yc + (5 * sin(s->ang)), s);
	if (k == 1)
		ft_move(0, s->xc - (5 * cos(s->ang)), s->yc - (5 * sin(s->ang)), s);
	if (k == 2)
		ft_move(2, s->xc + 4, s->yc, s);
	if (k == 0)
		ft_move(3, s->xc - 4, s->yc, s);
	if (k == 124)
	{
		s->ang += 0.3;
		ft_move(3, s->xc, s->yc, s);
	}
	if (k == 123)
	{
		s->ang -= 0.3;
		ft_move(3, s->xc, s->yc, s);
	}
	return (0);
}
