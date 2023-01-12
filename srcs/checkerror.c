/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkerror.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaidu <lnaidu@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 13:29:52 by lnaidu            #+#    #+#             */
/*   Updated: 2023/01/11 19:33:42 by lnaidu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	checkerror(char **argv)
{
	int	fd;
	int	k;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nFile not available\n");
		return (0);
	}
	if (verifber(argv[1]) == 0)
		return (1);
	if (verifchar(argv[1], fd) == 0)
		return (1);
	if (verifdbl(argv[1], fd) == 0)
		return (1);
	k = verifsize(fd);
	if (k < 3)
		return (1);
	close (fd);
	fd = open(argv[1], O_RDONLY);
	if (verifwall (fd, k) == 0)
		return (1);
	return (0);
}
