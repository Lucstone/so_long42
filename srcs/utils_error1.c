/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_error1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaidu <lnaidu@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 17:51:54 by lnaidu            #+#    #+#             */
/*   Updated: 2023/01/11 19:34:29 by lnaidu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	verifber(char *file)
{
	int		i;

	i = ft_strlen(file);
	i = i - 4;
	if (file[i] == '.' && file[i + 1] == 'b' && file[i + 2] == 'e'
		&& file[i + 3] == 'r')
		return (1);
	ft_printf("Error\nNot a .ber file\n");
	return (0);
}

int	verifchar(char *file, int fd)
{
	char	*gnl;
	int		i;

	fd = open(file, O_RDONLY);
	gnl = get_next_line(fd);
	i = 0;
	while (gnl)
	{
		while (gnl[i] != '\0')
		{
			if (!(gnl[i] == '0') && !(gnl[i] == '1') && !(gnl[i] == 'C')
				&& !(gnl[i] == 'E') && !(gnl[i] == 'P') && !(gnl[i] == '\n'))
			{
				ft_printf("Error\nMap not valid unknown character\n");
				free (gnl);
				return (0);
			}
			i++;
		}
		free (gnl);
		gnl = get_next_line(fd);
		i = 0;
	}
	return (1);
}

int	verifsize(int fd)
{
	char	*gnl;
	char	*tmp;
	size_t	i;
	int		j;

	gnl = get_next_line(fd);
	tmp = ft_strtrim(gnl, "\n");
	i = ft_strlen(tmp);
	j = 0;
	while (gnl)
	{
		j++;
		if (tmp != 0 && i != ft_strlen(tmp))
		{
			ft_printf ("Error\nNot a rectangle\n");
			free (gnl);
			free (tmp);
			return (0);
		}
		free (gnl);
		gnl = get_next_line(fd);
		free (tmp);
		tmp = ft_strtrim(gnl, "\n");
	}
	return (j);
}

int	topend(char *gnl, int i)
{
	int	j;

	j = 0;
	while (gnl && (i - 1) > j)
	{
		if (gnl && gnl[j] != '1' && gnl[j] != '\n')
		{
			ft_printf ("Error\nWalls not valid\n");
			return (0);
		}
		j++;
	}
	return (1);
}

int	verifwall(int fd, int k)
{
	char	*gnl;
	int		i;

	gnl = get_next_line(fd);
	i = ft_strlen(gnl);
	if (topend(gnl, i) == 0)
		return (0);
	free (gnl);
	while (gnl && (k - 2) > 0)
	{
		gnl = get_next_line(fd);
		k--;
		if (gnl && (gnl[0] != '1' || gnl[i - 2] != '1'))
		{
			ft_printf ("Error\nWalls not valid\n");
			free(gnl);
			return (0);
		}
		free (gnl);
	}
	gnl = get_next_line(fd);
	if (topend(gnl, i) == 0)
		return (0);
	free (gnl);
	return (1);
}
