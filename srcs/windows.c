/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   windows.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaidu <lnaidu@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:49:24 by lnaidu            #+#    #+#             */
/*   Updated: 2023/01/12 14:18:35 by lnaidu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_background(t_data *img, int height, int width)
{
	img->sprite = ft_new_sprite(img->mlx, "./sprites/floor.xpm");
	img->position.y = 0;
	img->position.x = 0;
	while (img->position.y < (height * 32))
	{
		while (img->position.x < (width * 32))
		{
			mlx_put_image_to_window(img->mlx, img->window.reference,
				img->sprite.reference, img->position.y, img->position.x);
			img->position.x = img->position.x + 32;
		}
		img->position.x = 0;
		img->position.y = img->position.y + 32;
	}
}

void	ft_wall(t_data *img, char **tab, int width, int height)
{
	int	i;
	int	j;

	img->sprite = ft_new_sprite(img->mlx, "./sprites/wall.xpm");
	img->position.y = 0;
	img->position.x = 0;
	i = 0;
	while (img->position.y < (height * 32))
	{
		j = 0;
		while (img->position.x < (width * 32))
		{
			if (tab[i][j] == '1')
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

void	ft_coin(t_data *img, char **tab, int width, int height)
{
	int	i;
	int	j;

	img->sprite = ft_new_sprite(img->mlx, "./sprites/biere.xpm");
	img->position.y = 0;
	img->position.x = 0;
	i = 0;
	while (img->position.y < (height * 32))
	{
		j = 0;
		while (img->position.x < (width * 32))
		{
			if (tab[i][j] == 'C')
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

t_vector	ft_player(t_data *img, char **tab, int width, int height)
{
	int			i;
	int			j;
	t_vector	pos;

	img->sprite = ft_new_sprite(img->mlx, "./sprites/player1.xpm");
	pos.y = 0;
	pos.x = 0;
	i = 0;
	while (pos.y < (height * 32))
	{
		j = 0;
		while (pos.x < (width * 32))
		{
			if (tab[i][j] == 'P')
				return (pos);
			pos.x = pos.x + 32;
			j++;
		}
		pos.x = 0;
		pos.y = pos.y + 32;
		i++;
	}
	return (pos);
}

t_window	ft_windows(void *mlx, int height, int width)
{
	t_window	img;

	height = height * 32;
	width = width * 32;
	img.reference = mlx_new_window(mlx, width, height, "So_long42");
	img.size.x = width;
	img.size.y = height;
	mlx_hook(img.reference, 17, 0, ft_close, 0);
	return (img);
}
