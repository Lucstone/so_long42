/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaidu <lnaidu@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 10:47:44 by lnaidu            #+#    #+#             */
/*   Updated: 2023/01/11 19:33:33 by lnaidu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	lengnl(int fd)
{
	char	*gnl;
	int		j;

	gnl = get_next_line(fd);
	j = 0;
	while (gnl)
	{
		j++;
		free (gnl);
		gnl = get_next_line(fd);
	}
	return (j);
}

char	**array(int fd, int k, char *file)
{
	char	**tab;
	char	*gnl;
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	fd = open(file, O_RDONLY);
	tab = malloc(sizeof(char *) * (k + 1));
	gnl = get_next_line(fd);
	while (gnl)
	{
		j = 0;
		tmp = ft_strtrim(gnl, "\n");
		tab[i] = tmp;
		while (tab[i][j])
			j++;
		free (gnl);
		gnl = get_next_line(fd);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

void	**ft_printmap(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			ft_printf("|%c|", tab[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
	return (0);
}

int	ft_count(char **tab)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}
