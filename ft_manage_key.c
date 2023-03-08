/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_key.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 03:18:24 by ebakchic          #+#    #+#             */
/*   Updated: 2023/03/08 00:07:11 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

# define FOV 1.04719755 // 60 degree
# define RIGHT 124
# define LEFT 123

void	draw_ray(t_list *s, double angle)
{
	double x = s->xc;
	double y = s->yc;
	int i = 0;
	while (i < 400)
	{
		mlx_pixel_put(s->mlx, s->win, (int)x, (int)y, 0xffffff);
		x += cos(angle);
		y += sin(angle);
		int index_i = y / 25;
		int index_j = x / 25;
		if (s->map[index_i][index_j] == '1')
			break ;
		i++;
	}
}

void	ft_move(int i, int x, int y, t_list *s)
{
    printf("kkkkk\n");
    (void)i;
    s->xc = x;
    s->yc = y;
    ft_fill_map(s);
	ft_put_pixel(s);
	draw_ray(s, s->angle); // fen kaychof lplayer
	draw_ray(s, s->angle + (FOV / 2));
	draw_ray(s, s->angle - (FOV / 2));
}

void	rotate_right(t_list *s)
{
	s->angle += 0.3;
    ft_fill_map(s);
	ft_put_pixel(s);
	draw_ray(s, s->angle);
	draw_ray(s, s->angle + (FOV / 2));
	draw_ray(s, s->angle - (FOV / 2));
}

void	rotate_left(t_list *s)
{
	s->angle -= 0.3;
    ft_fill_map(s);
	ft_put_pixel(s);
	draw_ray(s, s->angle);
	draw_ray(s, s->angle + (FOV / 2));
	draw_ray(s, s->angle - (FOV / 2));

}

int	ft_manage_key(int k, t_list *s)
{
	if (k == 53)
		exit(EXIT_SUCCESS);
	if (k == 13)
		ft_move(0, s->xc + (10 * cos(s->angle)), s->yc + (10 * sin(s->angle)), s);
	if (k == 1)
		ft_move(1, s->xc - (10 * cos(s->angle)), s->yc - (10 * sin(s->angle)), s);
	if (k == 2)
		ft_move(2, s->xc + (10 * cos(s->angle)), s->yc, s);
	if (k == 0)
		ft_move(3, s->xc - (10 * cos(s->angle)), s->yc, s);
	if (k == RIGHT)
		rotate_right(s);
	if (k == LEFT)
		rotate_left(s);
	printf("%d\n", k);
	return (0);
}