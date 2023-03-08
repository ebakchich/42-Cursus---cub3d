/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:30:49 by ebakchic          #+#    #+#             */
/*   Updated: 2023/03/07 23:46:51 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <mlx.h>
# include <math.h>

typedef struct s_list
{
	char	**map;
	void	*mlx;
	void	*win;
	void	*w;
	void	*s;
	int		xc;
	int		yc;
	int		lenx;
	int		leny;
	double	angle;
}	t_list;

void	*ft_calloc(size_t nmemb, size_t size);
void	ft_free_db(char **ptr);
void	ft_run_game(t_list *s);
void	ft_fill_map(t_list *s);
void	ft_put_pixel(t_list *s);

char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);

int	ft_manage_key(int k, t_list *s);
size_t	ft_strlen(const char *s);

void	ft_read_img(t_list *s);
void	ft_fill_map(t_list *s);
void	ft_put_pixel(t_list *s);

#endif