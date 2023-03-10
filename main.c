/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebakchic <ebakchic@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:30:26 by ebakchic          #+#    #+#             */
/*   Updated: 2023/03/09 08:04:44 by ebakchic         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

char	**ft_add_map(int fd)
{
	char	**map;
	char	*saver;
	char	*buff;
	int		rb;

	buff = ft_calloc(2, sizeof(char));
	if (!buff)
		return (NULL);
	saver = ft_strdup("");
	rb = 1;
	while (rb != 0)
	{
		rb = read(fd, buff, 1);
		if (rb == -1)
		{
			free(buff);
			return (NULL);
		}
		if (rb != 0)
			saver = ft_strjoin(saver, buff);
	}
	// free(buff);
	map = ft_split(saver, '\n');
	free(saver);
	return (map);
}

int	main(int ac, char **av)
{
	t_list	s;
	int		fd;

	(void)ac;
	s.ang = M_PI_2;
	fd = open(av[1], O_RDONLY);
	s.map = ft_add_map(fd);
	close(fd);
	ft_run_game(&s);
	// ft_free_db(s.map);
	return (0);
}
