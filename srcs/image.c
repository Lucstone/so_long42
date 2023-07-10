/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaidu <lnaidu@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:14:18 by lnaidu            #+#    #+#             */
/*   Updated: 2023/01/12 14:19:29 by lnaidu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

t_image	ft_new_sprite(void *mlx, char *path)
{
	t_image	img;

	img.reference = mlx_xpm_file_to_image(mlx, path, &img.size.x, &img.size.y);
	img.pixels = mlx_get_data_addr(img.reference, &img.bits_per_pixel,
			&img.line_length, &img.endian);
	return (img);
}

void	ft_exit(t_data *img, char **tab, int width, int height)
{
	int	i;
	int	j;

	img->sprite = ft_new_sprite(img->mlx, "./sprites/exit.xpm");
	img->position.y = 0;
	img->position.x = 0;
	i = 0;
	while (img->position.y < (height * 32))
	{
		j = 0;
		while (img->position.x < (width * 32))
		{
			if (tab[i][j] == 'E')
				mlx_put_image_to_window(img->mlx, img->window.reference,
					img->sprite.reference, img->position.x, img->position.y);
			img->position.x = img->position.x + 32;
			j++;
		}
		img->position.x = 0;
		img->position.y = img->position.y + 32;
		i++;
	}
}

int	ft_close(void)
{
	exit(0);
}
