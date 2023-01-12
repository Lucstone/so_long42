/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaidu <lnaidu@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:45:09 by lnaidu            #+#    #+#             */
/*   Updated: 2023/01/12 12:00:51 by lnaidu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_actionx1(t_data *program, int x, int i, int j)
{
	program->sprite = ft_new_sprite(program->mlx, "./sprites/player1.xpm");
	program->position.x += program->sprite.size.x;
	mlx_put_image_to_window(program->mlx, program->window.reference,
		program->sprite.reference, program->position.x, program->position.y);
	if ((program->map.map[i][j]) == 'E')
		program->sprite = ft_new_sprite(program->mlx, "./sprites/exit.xpm");
	else
		program->sprite = ft_new_sprite(program->mlx, "./sprites/floor.xpm");
	mlx_put_image_to_window(program->mlx, program->window.reference,
		program->sprite.reference, program->position.x + x,
		program->position.y);
	program->map.count++;
	ft_printf("number keys pressed -> %d\n", program->map.count);
}

void	ft_actionx2(t_data *program, int x, int i, int j)
{
	program->sprite = ft_new_sprite(program->mlx, "./sprites/player1.xpm");
	program->position.x -= program->sprite.size.x;
	mlx_put_image_to_window(program->mlx, program->window.reference,
		program->sprite.reference, program->position.x, program->position.y);
	if ((program->map.map[i][j]) == 'E')
		program->sprite = ft_new_sprite(program->mlx, "./sprites/exit.xpm");
	else
		program->sprite = ft_new_sprite(program->mlx, "./sprites/floor.xpm");
	mlx_put_image_to_window(program->mlx, program->window.reference,
		program->sprite.reference, program->position.x + x,
		program->position.y);
	program->map.count++;
	ft_printf("number keys pressed -> %d\n", program->map.count);
}

void	ft_actiony1(t_data *program, int y, int i, int j)
{
	program->sprite = ft_new_sprite(program->mlx, "./sprites/player1.xpm");
	program->position.y += program->sprite.size.y;
	mlx_put_image_to_window(program->mlx, program->window.reference,
		program->sprite.reference, program->position.x, program->position.y);
	if ((program->map.map[i][j]) == 'E')
		program->sprite = ft_new_sprite(program->mlx, "./sprites/exit.xpm");
	else
		program->sprite = ft_new_sprite(program->mlx, "./sprites/floor.xpm");
	mlx_put_image_to_window(program->mlx, program->window.reference,
		program->sprite.reference, program->position.x,
		program->position.y + y);
	program->map.count++;
	ft_printf("number keys pressed -> %d\n", program->map.count);
}

void	ft_actiony2(t_data *program, int y, int i, int j)
{
	program->sprite = ft_new_sprite(program->mlx, "./sprites/player1.xpm");
	program->position.y -= program->sprite.size.y;
	mlx_put_image_to_window(program->mlx, program->window.reference,
		program->sprite.reference, program->position.x, program->position.y);
	if ((program->map.map[i][j]) == 'E')
		program->sprite = ft_new_sprite(program->mlx, "./sprites/exit.xpm");
	else
		program->sprite = ft_new_sprite(program->mlx, "./sprites/floor.xpm");
	mlx_put_image_to_window(program->mlx, program->window.reference,
		program->sprite.reference, program->position.x,
		program->position.y + y);
	program->map.count++;
	ft_printf("number keys pressed -> %d\n", program->map.count);
}

int	ft_input(int key, void *param)
{
	t_data	*program;
	int		i;
	int		j;

	program = (t_data *)param;
	j = (program->position.x) / 32;
	i = (program->position.y) / 32;
	program->map.coin = ft_count(program->map.map);
	if (key == 2 && !((program->map.map[i][j + 1]) == '1'))
		ft_actionx1(program, -32, i, j);
	else if (key == 0 && !((program->map.map[i][j - 1]) == '1'))
		ft_actionx2(program, +32, i, j);
	else if (key == 1 && !((program->map.map[i + 1][j]) == '1'))
		ft_actiony1(program, -32, i, j);
	else if (key == 13 && !((program->map.map[i - 1][j]) == '1'))
		ft_actiony2(program, +32, i, j);
	else if (key == 53)
		exit(mlx_destroy_window(program->mlx, program->window.reference));
	if ((program->map.map[i][j]) == 'C')
		(program->map.map[i][j]) = '0';
	if (((program->map.map[i][j]) == 'E') && (program->map.coin == 0))
		exit(mlx_destroy_window(program->mlx, program->window.reference));
	/*program->map.count++;
	ft_printf("number keys pressed -> %d\n", program->map.count);*/
	return (0);
}
