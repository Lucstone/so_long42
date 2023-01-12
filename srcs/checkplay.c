/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkplay.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaidu <lnaidu@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:19:34 by lnaidu            #+#    #+#             */
/*   Updated: 2023/01/11 19:33:49 by lnaidu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	can_it_move(char **v, int x, int y)
{
	int	x_len;
	int	y_len;

	x_len = ft_strlen(v[0]);
	y_len = get_len(v);
	if (x >= 0 && x < x_len && y >= 0 && y < y_len && v[y][x] != '1')
		return (1);
	return (0);
}

int	find_path(char **v, int x, int y, int coins)
{
	static int	e;
	static int	c;

	if (v[y][x] == 'E')
		e++;
	if (v[y][x] == 'C')
		c++;
	v[y][x] = '1';
	if (can_it_move(v, x - 1, y))
		find_path(v, x - 1, y, coins);
	if (can_it_move(v, x, y + 1))
		find_path(v, x, y + 1, coins);
	if (can_it_move(v, x + 1, y))
		find_path(v, x + 1, y, coins);
	if (can_it_move(v, x, y - 1))
		find_path(v, x, y - 1, coins);
	if (e > 0 && c == coins)
		return (1);
	return (0);
}

int	get_player_pos(char **str, int *x, int *y)
{
	int	i;
	int	j;
	int	coins;

	i = 0;
	coins = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'P')
			{
				*y = i;
				*x = j;
			}
			if (str[i][j] == 'C')
				coins ++;
			j++;
		}
		i++;
	}
	return (coins);
}

int	back_tracking(t_data *v, char	*file)
{
	char	**str;
	int		x_p;
	int		y_p;
	int		fd;
	int		k;

	fd = open(file, O_RDONLY);
	k = lengnl(fd);
	str = array(fd, k, file);
	if (!str)
		return (0);
	v->back.coins = get_player_pos(str, &x_p, &y_p);
	if (find_path(str, x_p, y_p, v->back.coins) == 1)
	{
		free_str(str);
		return (1);
	}
	free_str(str);
	return (0);
}
