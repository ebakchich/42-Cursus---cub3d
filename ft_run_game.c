/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_run_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 21:48:00 by ebakchic          #+#    #+#             */
/*   Updated: 2023/03/08 01:07:58 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_fill_map(t_list *s)
{
	int	i;
	int	j;

	i = 0;
	while (s->map[i])
	{
		j = 0;
		while (s->map[i][j])
		{
			mlx_put_image_to_window(s->mlx, s->win, s->s, j * 25, i * 25);
			if (s->map[i][j] == '1')
				mlx_put_image_to_window (s->mlx, s->win, s->w, j * 25, i * 25);
			j++;
		}
		i++;
	}
}

void	ft_read_img(t_list *s)
{
	int	wid;
	int	hei;

	s->w = mlx_xpm_file_to_image(s->mlx, "./xpm/bleu.xpm", &wid, &hei);
	s->s = mlx_xpm_file_to_image(s->mlx, "./xpm/yellow.xpm", &wid, &hei);
}

void	ft_draw_circle(t_list *s, int x, int y)
{
	mlx_pixel_put(s->mlx, s->win, s->xc + x, s->yc + y, 0x000000);
	mlx_pixel_put(s->mlx, s->win, s->xc - x, s->yc + y, 0x000000);
	mlx_pixel_put(s->mlx, s->win, s->xc + x, s->yc - y, 0x000000);
	mlx_pixel_put(s->mlx, s->win, s->xc - x, s->yc - y, 0x000000);
	mlx_pixel_put(s->mlx, s->win, s->xc + y, s->yc + x, 0x000000);
	mlx_pixel_put(s->mlx, s->win, s->xc - y, s->yc + x, 0x000000);
	mlx_pixel_put(s->mlx, s->win, s->xc + y, s->yc - x, 0x000000);
	mlx_pixel_put(s->mlx, s->win, s->xc - y, s->yc - x, 0x000000);
}

void	ft_put_pixel(t_list *s)
{
	int	r;
	int	x;
	int	y;
	int	d;

	r = 3;
	x = 0;
	y = r;
	d = 3 - (2 * r);
	ft_draw_circle(s, x, y);
	while (y >= x)
	{
		x++;
		if (d > 0)
		{
			y--;
			d = d + 4 * (x - y) + 10;
		}
		else
			d = d + 4 * x + 6;
		ft_draw_circle(s, x, y);
	}
}

void	ft_run_game(t_list *s)
{
	s->leny = 0;
	while (s->map[s->leny])
		s->leny++;
	s->lenx = ft_strlen(s->map[0]);
	s->xc = (s->lenx * 25) / 2;
	s->yc = (s->leny * 25) / 2;
	s->mlx = mlx_init();
	s->win = mlx_new_window(s->mlx, s->lenx * 25, s->leny * 25, "cub");
	ft_read_img(s);
	ft_fill_map(s);
	ft_put_pixel(s);
	// mlx_hook(s->win, 2, 1L << 0, ft_manage_key, s);
	mlx_key_hook(s->win, ft_manage_key, s);
	mlx_loop(s->mlx);
}
