/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verifdobl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaidu <lnaidu@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:41:23 by lnaidu            #+#    #+#             */
/*   Updated: 2023/01/11 19:34:34 by lnaidu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	count(char *gnl, int i, t_cerror *obj)
{
	while (gnl[i] != '\0')
	{
		if (gnl[i] == 'C')
			obj->c++;
		if (gnl[i] == 'P')
			obj->p++;
		if (gnl[i] == 'E')
			obj->e++;
		i++;
	}
}

int	verifdbl(char *file, int fd)
{
	char		*gnl;
	int			i;
	t_cerror	obj;

	obj.c = 0;
	obj.p = 0;
	obj.e = 0;
	fd = open(file, O_RDONLY);
	gnl = get_next_line(fd);
	i = 0;
	while (gnl)
	{
		count(gnl, i, &obj);
		free (gnl);
		gnl = get_next_line(fd);
		i = 0;
	}
	if ((obj.c < 1) || (obj.p != 1) || (obj.e != 1))
	{
		ft_printf("Error\nCharacter not correct!\n");
		free (gnl);
		return (0);
	}		
	return (1);
}
