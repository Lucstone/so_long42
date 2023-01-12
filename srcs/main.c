/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lnaidu <lnaidu@student.42nice.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:55:24 by lnaidu            #+#    #+#             */
/*   Updated: 2023/01/11 19:34:24 by lnaidu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	program(int argc, char *argv, t_data *prg)
{
	prg->map.map = array(prg->end.fd, argc, argv);
	ft_printmap(prg->map.map);
	prg->mlx = mlx_init();
	prg->window = ft_windows(prg->mlx, (argc),
			ft_strlen(prg->map.map[1]));
	ft_background(prg, ft_strlen(prg->map.map[1]), (argc));
	ft_wall(prg, prg->map.map, ft_strlen(prg->map.map[1]), (argc));
	ft_coin(prg, prg->map.map, ft_strlen(prg->map.map[1]), (argc));
	ft_exit(prg, prg->map.map, ft_strlen(prg->map.map[1]), (argc));
	prg->position = ft_player(prg, prg->map.map,
			ft_strlen(prg->map.map[1]), (argc));
	mlx_put_image_to_window(prg->mlx, prg->window.reference,
		prg->sprite.reference, prg->position.x, prg->position.y);
	prg->map.count = 0;
	mlx_key_hook(prg->window.reference, *ft_input, prg);
}

int	main(int argc, char **argv)
{
	t_data		prg;

	if (argc != 2)
	{
		ft_printf("Error\nWrong number of map\n");
		return (0);
	}
	if ((checkerror(argv) == 1))
		return (0);
	if (back_tracking(&prg, argv[1]) == 0)
	{
		ft_printf("Error\nbacktracking\n");
		return (0);
	}
	prg.end.fd = open(argv[1], O_RDONLY);
	if (argc == 2)
	{
		argc = lengnl(prg.end.fd);
		close (prg.end.fd);
		program(argc, argv[1], &prg);
		mlx_loop(prg.mlx);
	}
	return (0);
}
